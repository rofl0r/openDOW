#include "audio.h"

#if AUDIO_BACKEND == AUDIO_BACKEND_AO
#include "../c-flod/backends/aowriter.h"
#define BACKEND_STRUCT AoWriter
#define BACKEND_INIT AoWriter_init
#define BACKEND_CLOSE AoWriter_close
#define BACKEND_WRITE AoWriter_write
#elif AUDIO_BACKEND == AUDIO_BACKEND_SDL
#include "../c-flod/backends/sdlwriter.h"
#define BACKEND_STRUCT SdlWriter
#define BACKEND_INIT SdlWriter_init
#define BACKEND_CLOSE SdlWriter_close
#define BACKEND_WRITE SdlWriter_write

#endif

#if AUDIO_BACKEND == AUDIO_BACKEND_NONE
void audio_init(void) {}
int audio_open_music_resource(const unsigned char* data, size_t data_size, int track) { return 0; }
int audio_open_music(const char* filename, int track) { return 0; }
void audio_play_wave_resource(const WAVE_HEADER_COMPLETE* wave) {}
int audio_process(void) { return -1; }
#else
#include "../c-flod/backends/wave_format.h"
#include "../c-flod/neoart/flod/core/CorePlayer.h"
#include "../c-flod/neoart/flod/whittaker/DWPlayer.h"
#include "../c-flod/flashlib/ByteArray.h"
#include "../c-flod/neoart/flod/core/Amiga.h"
#include <assert.h>
#include <pthread.h>
#include <errno.h>
#include "../lib/include/timelib.h"
#pragma RcB2 LINK "-lpthread"

enum thread_status {
	TS_WAITING,
	TS_PLAYING,
	TS_DONE,
	TS_STOPPING,
};

struct AudioPlayer {
	union {
		struct CorePlayer core;
		struct DWPlayer dw;
	} player;
	union {
		struct CoreMixer core;
		struct Amiga amiga;
	} hardware;
	union {
		struct Backend backend;
		struct BACKEND_STRUCT ao;
	} writer;
	struct ByteArray music_stream;
	struct ByteArray wave_streams[2];
	WAVE_HEADER_COMPLETE wavhdr;
	struct ByteArray out_wave;
	char wave_buffer[COREMIXER_MAX_BUFFER * 2 * sizeof(float)];
	pthread_attr_t attr;
	pthread_t thread;
	pthread_mutex_t music_mutex;
	pthread_mutex_t sound_mutex;
	enum thread_status thread_music_status;
	int free_waveslot;
	int play_waveslot;
	int empty_track_active;
};

static struct AudioPlayer playa;

#define mlock() pthread_mutex_lock(&playa.music_mutex)
#define munlock() pthread_mutex_unlock(&playa.music_mutex)
#define slock() pthread_mutex_lock(&playa.sound_mutex)
#define sunlock() pthread_mutex_unlock(&playa.sound_mutex)

static int handle_overflow(int *sample) {
	if(*sample > 32767) {
		*sample = 32767;
		return 1;
	} else if (*sample < -32768) {
		*sample = -32768;
		return -1;
	}
	return 0;
}

#define MUSIC_FINISHED() (!playa.empty_track_active && CoreMixer_get_complete(&playa.hardware.core))
#define GEN_MUSIC() do{ \
			if(!playa.empty_track_active) playa.hardware.core.accurate(&playa.hardware.core); \
			else { assert(sizeof(playa.wave_buffer) >= 1024*3); \
			       memset(playa.wave_buffer, 0, 1024*3); playa.out_wave.pos = 1024*3;}  \
		      } while (0)
#define MUSIC_AVAIL() (playa.out_wave.pos)
#define GET_MUSIC_WORD() (playa.empty_track_active ? 0 : ByteArray_readShort(out))
#define MUSIC_REWIND_WORD() do { if(!playa.empty_track_active) ByteArray_set_position_rel(out, -2); } while (0)

static void *thread_func(void* data) {
	(void) data;
	while(1) {
		mlock();
		if(playa.thread_music_status == TS_STOPPING) {
			playa.thread_music_status = TS_WAITING;
			munlock();
			msleep(1);
			continue;
		} else if(playa.thread_music_status == TS_DONE || playa.thread_music_status == TS_WAITING) {
			munlock();
			msleep(4);
			continue;
		}
		munlock();
		if(MUSIC_FINISHED()) {
			mlock();
			playa.thread_music_status = TS_DONE;
			munlock();
			continue;
		}
		GEN_MUSIC();
		if(MUSIC_AVAIL()) {
			//dprintf(2, "writing %zu bytes...\n", (size_t) playa.out_wave.pos);
			slock();
			if(playa.play_waveslot != -1) {
				struct ByteArray* mine = &playa.wave_streams[playa.play_waveslot];
				if(!mine->bytesAvailable(mine)) {
					playa.play_waveslot = -1;
					goto mixin_done;
				}
				struct ByteArray* out = &playa.out_wave;
				off_t savepos = out->pos;
				size_t avail = mine->bytesAvailable(mine);
				size_t upsample_factor = 44100 / playa.wavhdr.wave_hdr.samplerate;
				size_t processed_m = 0, processed_w = 0;
				size_t readbytes = playa.wavhdr.wave_hdr.bitwidth == 8 ? 1 : 2;
				int chan[2] = { 0, 0 };
				int next[2];
				ByteArray_set_position(out, 0);
				while(processed_m < (size_t)savepos && processed_w < avail) {
					size_t c, u;
					for(c = 0; c < 2; c++) {
						if(c < playa.wavhdr.wave_hdr.channels) {
							if(readbytes == 1) next[c] = ((uint8_t) ByteArray_readByte(mine) - 128) * 256;
							else next[c] = ByteArray_readShort(mine);
							handle_overflow(&next[c]);
						} else 
							next[c] = next[c - 1];
						processed_w += readbytes;
					}
					for(u = 0; u < upsample_factor; u++) {
						for(c = 0; c < 2; c++) {
							int interpolated = u == 0 ? chan[c] : 
								chan[c] + ((next[c]-chan[c]) * ((float)u/(float)upsample_factor));
							interpolated = (float) interpolated * 0.3; // decrease volume to avoid overflow
							int music = GET_MUSIC_WORD();
							int sample = music + interpolated;
							if(handle_overflow(&sample)) dprintf(2, "overflow\n");
							MUSIC_REWIND_WORD();
							ByteArray_writeShort(out, sample);
							processed_m += 2;
						}
					}
					for (c=0; c<2; c++) chan[c] = next[c];
				}
				ByteArray_set_position(out, savepos);
			}
			mixin_done:
			sunlock();
			BACKEND_WRITE(&playa.writer.ao, playa.wave_buffer, playa.out_wave.pos);
			//dprintf(2, "done\n");
			playa.out_wave.pos = 0;
		}
	}
	return 0;
}

void audio_init(void) {
	Amiga_ctor(&playa.hardware.amiga);
	DWPlayer_ctor(&playa.player.dw, &playa.hardware.amiga);
	BACKEND_INIT(&playa.writer.ao, 0);
	ByteArray_ctor(&playa.music_stream);
	ByteArray_ctor(&playa.wave_streams[0]);
	ByteArray_ctor(&playa.wave_streams[1]);
	ByteArray_ctor(&playa.out_wave);
	playa.out_wave.endian = BAE_LITTLE;
	ByteArray_open_mem(&playa.out_wave, playa.wave_buffer, sizeof(playa.wave_buffer));
	playa.hardware.core.wave = &playa.out_wave;
	
	playa.thread_music_status = TS_WAITING;
	errno = pthread_mutex_init(&playa.music_mutex, 0);
	if(errno) perror("1");
	errno = pthread_mutex_init(&playa.sound_mutex, 0);
	if(errno) perror("1.5");
	errno = pthread_attr_init(&playa.attr);
	if(errno) perror("2");
	errno = pthread_attr_setstacksize(&playa.attr, 128*1024);
	if(errno) perror("3");
	errno = pthread_create(&playa.thread, &playa.attr, thread_func, 0);
	if(errno) perror("4");
	playa.free_waveslot = 0;
	playa.play_waveslot = -1;
}

int audio_open_music_resource(const unsigned char* data, size_t data_size, int track) {
	mlock();
	if(playa.thread_music_status != TS_WAITING) {
		playa.thread_music_status = TS_STOPPING;
		munlock();
		int done = 0;
		do {
			mlock();
			if(playa.thread_music_status == TS_WAITING) done = 1;
			munlock();
			if(!done) msleep(1);
		} while(!done);
		mlock();
	}
	playa.empty_track_active = 0;
	munlock();
	if(track == -1) { /* "empty" track */
		playa.empty_track_active = 1;
		memset(playa.wave_buffer, 0, sizeof(playa.wave_buffer));
		return 0;
	}
	ByteArray_open_mem(&playa.music_stream, (void*) data, data_size);
	CorePlayer_load(&playa.player.core, &playa.music_stream);
	assert(playa.player.core.version);
	if(track > playa.player.core.lastSong) return -1;
	playa.player.core.playSong = track;
	playa.player.core.initialize(&playa.player.core);
	return 0;
}

#if 0
//FIXME: does not close file handle
int audio_open_music(const char* filename, int track) {
	mlock();
	if(playa.thread_music_status != TS_WAITING) {
		playa.thread_music_status = TS_STOPPING;
		munlock();
		int done = 0;
		do {
			mlock();
			if(playa.thread_music_status == TS_WAITING) done = 1;
			munlock();
			if(!done) msleep(1);
		} while(!done);
		mlock();
	}
	munlock();
	ByteArray_open_file(&playa.music_stream, filename);
	CorePlayer_load(&playa.player.core, &playa.music_stream);
	assert(playa.player.core.version);
	playa.player.core.initialize(&playa.player.core);
	if(track > playa.player.core.lastSong) return -1;
	playa.player.core.playSong = track;
	return 0;
}
#endif


void audio_play_wave_resource(const WAVE_HEADER_COMPLETE* wave) {
	if(!wave) return;
	slock();
	if(playa.free_waveslot >= (int) ARRAY_SIZE(playa.wave_streams)) {
		playa.free_waveslot = 0;
	}
	struct ByteArray *mine = &playa.wave_streams[playa.free_waveslot];
	if(!ByteArray_open_mem(mine, waveheader_get_data(wave), waveheader_get_datasize(wave))) {
		abort();
	}
	ByteArray_set_endian(mine, BAE_LITTLE);
	playa.wavhdr = *wave;
	
	playa.play_waveslot = playa.free_waveslot;
	playa.free_waveslot++;
	sunlock();
}

#if 0
static void close_all_but_playing_slot() {
	size_t i;
	for(i = 0; i < ARRAY_SIZE(playa.wave_streams); i++) {
		/*if(i != playa.play_waveslot) */
			ByteArray_close_file(&playa.wave_streams[i]);
	}
}
void audio_play_wav(const char* filename) {
	slock();
	if(playa.free_waveslot >= (int) ARRAY_SIZE(playa.wave_streams)) {
		playa.free_waveslot = 0;
		close_all_but_playing_slot();
	}
	struct ByteArray *mine = &playa.wave_streams[playa.free_waveslot];
	if(!ByteArray_open_file(mine, filename)) {
		perror("open");
		abort();
	}
	ByteArray_set_endian(mine, BAE_LITTLE);
	/* assuming 16bit, 44khz stereo wav for the beginning. */
	ByteArray_readMultiByte(mine, (void*) &playa.wavhdr, sizeof(WAVE_HEADER_COMPLETE));
	//ByteArray_set_position(mine, sizeof(WAVE_HEADER_COMPLETE));
	
	playa.play_waveslot = playa.free_waveslot;
	playa.free_waveslot++;
	sunlock();
}
#endif

// return -1: when track is finished, 0 if something was played, 1 if nothing was played.
int audio_process(void) {
	mlock();
	if(playa.thread_music_status == TS_DONE) {
		munlock();
		return -1;
	} else if (playa.thread_music_status == TS_WAITING) {
		playa.thread_music_status = TS_PLAYING;
	}
	munlock();
	return 0;
}

#endif /* AUDIO_BACKEND != AUDIO_BACKEND_NONE */
