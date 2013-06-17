#include "maps.h"
#include "maps/map_italy.c"
#include "maps/map_pakistan.c"

const struct map *maps[] = {
	[MI_ITALY] = &map_italy.header,
	[MI_PAKISTAN] = &map_pakistan.header,
};

const struct map_screen *map_screens[] = {
	[MI_ITALY] = &map_italy.screens,
	[MI_PAKISTAN] = &map_pakistan.screens,
};

