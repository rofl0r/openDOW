#include "audio.h"
#include "../c-flod/backends/aowriter.h"
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
	struct ByteArray wave_stream;
	struct ByteArray out_wave;
	unsigned char wave_buffer[COREMIXER_MAX_BUFFER * 2 * sizeof(float)];
	pthread_attr_t attr;
	pthread_t thread;
	pthread_mutex_t mutex;
	enum thread_status thread_music_status;
};

static struct AudioPlayer playa;

#define lock() pthread_mutex_lock(&playa.mutex)
#define unlock() pthread_mutex_unlock(&playa.mutex)

static void thread_func(void* data) {
	while(1) {
		lock();
		if(playa.thread_music_status == TS_STOPPING) {
			playa.thread_music_status = TS_WAITING;
			unlock();
			msleep(1);
			continue;
		} else if(playa.thread_music_status == TS_DONE || playa.thread_music_status == TS_WAITING) {
			unlock();
			msleep(4);
			continue;
		}
		unlock();
		if(CoreMixer_get_complete(&playa.hardware.core)) {
			lock();
			playa.thread_music_status = TS_DONE;
			unlock();
			continue;
		}
		playa.hardware.core.accurate(&playa.hardware.core);
		if(playa.out_wave.pos) {
			dprintf(2, "writing %zu bytes...\n", (size_t) playa.out_wave.pos);
			AoWriter_write(&playa.writer.backend, playa.wave_buffer, playa.out_wave.pos);
			dprintf(2, "done\n");
		}
		playa.out_wave.pos = 0;
	}
}

void audio_init(void) {
	Amiga_ctor(&playa.hardware.amiga);
	DWPlayer_ctor(&playa.player.core, &playa.hardware.core);
	AoWriter_init(&playa.writer.backend, "");
	ByteArray_ctor(&playa.music_stream);
	ByteArray_ctor(&playa.wave_stream);
	ByteArray_ctor(&playa.out_wave);
	playa.out_wave.endian = BAE_LITTLE;
	ByteArray_open_mem(&playa.out_wave, playa.wave_buffer, sizeof(playa.wave_buffer));
	playa.hardware.core.wave = &playa.out_wave;
	
	playa.thread_music_status = TS_WAITING;
	errno = pthread_mutex_init(&playa.mutex, 0);
	if(errno) perror("1");
	errno = pthread_attr_init(&playa.attr);
	if(errno) perror("2");
	errno = pthread_attr_setstacksize(&playa.attr, 128*1024);
	if(errno) perror("3");
	errno = pthread_create(&playa.thread, &playa.attr, thread_func, 0);
	if(errno) perror("4");
}

int audio_open_music(const char* filename, int track) {
	lock();
	if(playa.thread_music_status != TS_WAITING) {
		playa.thread_music_status = TS_STOPPING;
		unlock();
		int done = 0;
		do {
			lock();
			if(playa.thread_music_status == TS_WAITING) done = 1;
			unlock();
			if(!done) msleep(1);
		} while(!done);
		lock();
	}
	unlock();
	ByteArray_open_file(&playa.music_stream, filename);
	CorePlayer_load(&playa.player.core, &playa.music_stream);
	assert(playa.player.core.version);
	playa.player.core.initialize(&playa.player.core);
	if(track > playa.player.core.lastSong) return -1;
	playa.player.core.playSong = track;
	return 0;
}

// return -1: when track is finished, 0 if something was played, 1 if nothing was played.
int audio_process(void) {
	lock();
	if(playa.thread_music_status == TS_DONE) {
		unlock();
		return -1;
	} else if (playa.thread_music_status == TS_WAITING) {
		playa.thread_music_status = TS_PLAYING;
	}
	unlock();
	return 0;
}



