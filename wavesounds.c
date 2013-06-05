#include "wavesounds.h"
#include "sounds/pistol.c"
#include "sounds/gun.c"
#include "sounds/machinegun.c"
#include "sounds/flamethrower.c"
#include "sounds/grenade_sound.c"

#define WAVSOUND(x, y) [x] = &(y .header)
const WAVE_HEADER_COMPLETE* wavesounds[] = {
	[WS_NONE] = 0,
	WAVSOUND(WS_PISTOL, pistol),
	WAVSOUND(WS_GUN, gun),
	WAVSOUND(WS_MACHINEGUN, machinegun),
	WAVSOUND(WS_FLAMETHROWER, flamethrower),
	WAVSOUND(WS_GRENADE_EXPLOSION, grenade_sound),
};

