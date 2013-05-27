#include "audio.h"
#include "../c-flod/backends/aowriter.h"
#include "../c-flod/neoart/flod/core/CorePlayer.h"
#include "../c-flod/neoart/flod/whittaker/DWPlayer.h"
#include "../c-flod/flashlib/ByteArray.h"
#include "../c-flod/neoart/flod/core/Amiga.h"
#include <assert.h>

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
};

static struct AudioPlayer playa;

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
}

int audio_open_music(const char* filename, int track) {
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
	if(CoreMixer_get_complete(&playa.hardware.core)) return -1;
	playa.hardware.core.accurate(&playa.hardware.core);
	int res = 1;
	if(playa.out_wave.pos) {
		AoWriter_write(&playa.writer.backend, playa.wave_buffer, playa.out_wave.pos);
		res = 0;
	}
	playa.out_wave.pos = 0;
	return res;
}



