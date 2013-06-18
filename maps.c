#include "maps.h"
#include "maps/map_italy.c"
#include "maps/map_pakistan.c"
#include "maps/map_england.c"
#include "maps/map_peru.c"
#include "maps/map_florida.c"

const struct map *maps[] = {
	[MI_ITALY] = &map_italy.header,
	[MI_PAKISTAN] = &map_pakistan.header,
	[MI_ENGLAND] = &map_england.header,
	[MI_PERU] = &map_peru.header,
	[MI_FLORIDA] = &map_florida.header,
};

const struct map_screen *map_screens[] = {
	[MI_ITALY] = map_italy.screens,
	[MI_PAKISTAN] = map_pakistan.screens,
	[MI_ENGLAND] = map_england.screens,
	[MI_PERU] = map_peru.screens,
	[MI_FLORIDA] = map_florida.screens,
};

const mapscreen_index *map_bonus_layer_indices[] = {
	[MI_ITALY] = map_italy.bonus_index,
	[MI_PAKISTAN] = map_pakistan.bonus_index,
	[MI_ENGLAND] = map_england.bonus_index,
	[MI_PERU] = map_peru.bonus_index,
	[MI_FLORIDA] = map_florida.bonus_index,
};
	
const struct map_fglayer *map_bonus_screens[] = {
	[MI_ITALY] = map_italy.bonus_screens,
	[MI_PAKISTAN] = map_pakistan.bonus_screens,
	[MI_ENGLAND] = map_england.bonus_screens,
	[MI_PERU] = map_peru.bonus_screens,
	[MI_FLORIDA] = map_florida.bonus_screens,
};
