#include "audio.h"
#include "../c-flod/backends/aowriter.h"
#include "../c-flod/backends/wave_format.h"
#include "../c-flod/neoart/flod/core/CorePlayer.h"
#include "../c-flod/neoart/flod/whittaker/DWPlayer.h"
#include "../c-flod/flashlib/ByteArray.h"
#include "../c-flod/neoart/flod/core/Amiga.h"
#include <assert.h>
#include <pthread.h>
#include <errno.h>
#include "../lib/include/timelib.h"
//RcB: LINK "-lpthread"

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
		struct AoWriter ao;
	} writer;
	struct ByteArray music_stream;
	struct ByteArray *wave_stream;
	struct ByteArray wave_streams[2];
	struct ByteArray out_wave;
	unsigned char wave_buffer[COREMIXER_MAX_BUFFER * 2 * sizeof(float)];
	pthread_attr_t attr;
	pthread_t thread;
	pthread_mutex_t music_mutex;
	pthread_mutex_t sound_mutex;
	enum thread_status thread_music_status;
	int free_waveslot;
	int play_waveslot; 
};

static struct AudioPlayer playa;

#define mlock() pthread_mutex_lock(&playa.music_mutex)
#define munlock() pthread_mutex_unlock(&playa.music_mutex)
#define slock() pthread_mutex_lock(&playa.sound_mutex)
#define sunlock() pthread_mutex_unlock(&playa.sound_mutex)

static void thread_func(void* data) {
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
		if(CoreMixer_get_complete(&playa.hardware.core)) {
			mlock();
			playa.thread_music_status = TS_DONE;
			munlock();
			continue;
		}
		playa.hardware.core.accurate(&playa.hardware.core);
		if(playa.out_wave.pos) {
			//dprintf(2, "writing %zu bytes...\n", (size_t) playa.out_wave.pos);
			slock();
			if(playa.play_waveslot != -1) {
				struct ByteArray* mine = &playa.wave_streams[playa.play_waveslot];
				if(!mine->bytesAvailable(mine)) {
					playa.play_waveslot = -1;
					goto mixin_done;
				}
				off_t savepos = playa.out_wave.pos;
				ByteArray_set_position(&playa.out_wave, 0);
				size_t i, avail = mine->bytesAvailable(mine);
				for(i = 0; i < savepos && i < avail; i+= 2) {
					int16_t music = ByteArray_readShort(&playa.out_wave);
					int16_t sound = (float)ByteArray_readShort(mine) * 0.30;
					int32_t sample = music + sound;
					int overflow = 0;
					if(sample > 32767) {
						overflow = 1;
						sample = 32767;
					} else if (sample < -32768) {
						overflow = 1;
						sample = -32768;
					}
					ByteArray_set_position_rel(&playa.out_wave, -2);
					if(overflow) dprintf(2, "overflow\n");
					ByteArray_writeShort(&playa.out_wave, sample);
				}
				ByteArray_set_position(&playa.out_wave, savepos);
			}
			mixin_done:
			sunlock();
			AoWriter_write(&playa.writer.backend, playa.wave_buffer, playa.out_wave.pos);
			//dprintf(2, "done\n");
			playa.out_wave.pos = 0;
		}
		
	}
}

void audio_init(void) {
	Amiga_ctor(&playa.hardware.amiga);
	DWPlayer_ctor(&playa.player.core, &playa.hardware.core);
	AoWriter_init(&playa.writer.backend, "");
	ByteArray_ctor(&playa.music_stream);
	ByteArray_ctor(&playa.wave_streams[0]);
	ByteArray_ctor(&playa.wave_streams[1]);
	playa.wave_stream = &playa.wave_streams[0];
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

static void close_all_but_playing_slot() {
	size_t i;
	for(i = 0; i < ARRAY_SIZE(playa.wave_streams); i++) {
		/*if(i != playa.play_waveslot) */
			ByteArray_close_file(&playa.wave_streams[i]);
	}
}

void audio_play_wav(const char* filename) {
	slock();
	if(playa.free_waveslot >= ARRAY_SIZE(playa.wave_streams)) {
		playa.free_waveslot = 0;
		close_all_but_playing_slot();
	}
	struct ByteArray *mine = &playa.wave_streams[playa.free_waveslot];
	if(!ByteArray_open_file(mine, filename)) {
		perror("open");
		abort();
	}
	/* assuming 16bit, 44khz stereo wav for the beginning. */
	ByteArray_set_position(mine, sizeof(WAVE_HEADER_COMPLETE));
	ByteArray_set_endian(mine, BAE_LITTLE);
	playa.play_waveslot = playa.free_waveslot;
	playa.free_waveslot++;
	sunlock();
}


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



