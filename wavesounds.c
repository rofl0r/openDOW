#include "wavesounds.h"
#include "sounds/pistol.c"
#include "sounds/gun.c"
#include "sounds/machinegun.c"
#include "sounds/flamethrower.c"

#define WAVSOUND(x, y) [x] = &(y .header)
const WAVE_HEADER_COMPLETE* wavesounds[] = {
	[WS_NONE] = 0,
	WAVSOUND(WS_PISTOL, pistol),
	WAVSOUND(WS_GUN, gun),
	WAVSOUND(WS_MACHINEGUN, machinegun),
	WAVSOUND(WS_FLAMETHROWER, flamethrower),
};

