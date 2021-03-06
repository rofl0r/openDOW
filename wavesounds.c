#include "wavesounds.h"
#if AUDIO_BACKEND == AUDIO_BACKEND_NONE
#define WAVSOUND(x, y) [x] = 0
#else
#include "sounds/pistol.c"
#include "sounds/gun.c"
#include "sounds/machinegun.c"
#include "sounds/flamethrower.c"
#include "sounds/grenade_sound.c"
#include "sounds/scream.c"
#include "sounds/scream2.c"
#include "sounds/dropshot.c"
#include "sounds/countdown.c"
#include "sounds/missionbonus.c"
#include "sounds/fail.c"
#include "sounds/success.c"
#define WAVSOUND(x, y) [x] = &(y .header)
#endif
const WAVE_HEADER_COMPLETE* wavesounds[] = {
	[WS_NONE] = 0,
	WAVSOUND(WS_PISTOL, pistol),
	WAVSOUND(WS_GUN, gun),
	WAVSOUND(WS_MACHINEGUN, machinegun),
	WAVSOUND(WS_FLAMETHROWER, flamethrower),
	WAVSOUND(WS_GRENADE_EXPLOSION, grenade_sound),
	WAVSOUND(WS_SCREAM, scream),
	WAVSOUND(WS_SCREAM2, scream2),
	WAVSOUND(WS_DROPSHOT, dropshot),
	WAVSOUND(WS_COUNTDOWN, countdown),
	WAVSOUND(WS_MISSIONBONUS, missionbonus),
	WAVSOUND(WS_FAIL, fail),
	WAVSOUND(WS_SUCCESS, success),
};

