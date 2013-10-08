#include "spawnmaps.h"

#include "maps/spawn_australia.c"
#include "maps/spawn_russia.c"

const struct enemy_spawn_screen *spawn_maps[MI_MAX] = {
	[MI_ITALY] = spawn_screens_australia, // FIXME
	[MI_PAKISTAN] = spawn_screens_australia, // FIXME
	[MI_ENGLAND] = spawn_screens_australia, // FIXME
	[MI_PERU] = spawn_screens_australia, // FIXME
	[MI_FLORIDA] = spawn_screens_australia, // FIXME
	[MI_VIETNAM] = spawn_screens_australia, // FIXME
	[MI_TEXAS] = spawn_screens_australia, // FIXME
	[MI_CANADA] = spawn_screens_australia, // FIXME
	[MI_SAFRICA] = spawn_screens_australia, // FIXME
	[MI_FRANCE] = spawn_screens_australia, // FIXME
	[MI_AUSTRALIA] = spawn_screens_australia,
	[MI_RUSSIA] = spawn_screens_russia, // FIXME
};
