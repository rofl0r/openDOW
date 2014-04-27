#ifndef WAVESOUNDS_H
#define WAVESOUNDS_H

enum __attribute__((__packed__)) wavesound_id {
	WS_NONE = 0,
	WS_PISTOL,
	WS_GUN,
	WS_MACHINEGUN,
	WS_FLAMETHROWER,
	WS_GRENADE_EXPLOSION,
	WS_SCREAM,
	WS_SCREAM2,
	WS_DROPSHOT,
	WS_COUNTDOWN,
	WS_MISSIONBONUS,
	WS_FAIL,
	WS_SUCCESS,
};

#include "audio.h"

#if AUDIO_BACKEND != AUDIO_BACKEND_NONE
//RcB: SKIPON "AUDIO_BACKEND=AUDIO_BACKEND_NONE"
#include "../c-flod/backends/wave_format.h"
//RcB: SKIPOFF "AUDIO_BACKEND=AUDIO_BACKEND_NONE"
#else
#define WAVE_HEADER_COMPLETE int
#endif
extern const WAVE_HEADER_COMPLETE* wavesounds[];
//RcB: DEP "wavesounds.c"

#endif
