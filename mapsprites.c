#include "mapsprites.h"
#include "sprites/bg_desert.c"
#include "sprites/bg_urban.c"
#include "sprites/bg_forest.c"
#include "sprites/map_desert.c"
#include "sprites/map_urban.c"
#include "sprites/map_forest.c"

const struct palpic *map_fg_sprites[] = {
	[MT_DESERT] = &map_desert.header,
	[MT_URBAN] = &map_urban.header,
	[MT_FOREST] = &map_forest.header,
};

const struct palpic *map_bg_sprites[] = {
	[MT_DESERT] = &bg_desert.header,
	[MT_URBAN] = &bg_urban.header,
	[MT_FOREST] = &bg_forest.header,
};
