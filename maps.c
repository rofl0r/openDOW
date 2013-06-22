#include "maps.h"
#include "maps/map_italy.c"
#include "maps/map_pakistan.c"
#include "maps/map_england.c"
#include "maps/map_peru.c"
#include "maps/map_florida.c"
#include "maps/map_vietnam.c"
#include "maps/map_texas.c"
#include "maps/map_canada.c"

const struct map *maps[] = {
	[MI_ITALY] = &map_italy.header,
	[MI_PAKISTAN] = &map_pakistan.header,
	[MI_ENGLAND] = &map_england.header,
	[MI_PERU] = &map_peru.header,
	[MI_FLORIDA] = &map_florida.header,
	[MI_VIETNAM] = &map_vietnam.header,
	[MI_TEXAS] = &map_texas.header,
	[MI_CANADA] = &map_canada.header,
};

const struct map_screen *map_screens[] = {
	[MI_ITALY] = map_italy.screens,
	[MI_PAKISTAN] = map_pakistan.screens,
	[MI_ENGLAND] = map_england.screens,
	[MI_PERU] = map_peru.screens,
	[MI_FLORIDA] = map_florida.screens,
	[MI_VIETNAM] = map_vietnam.screens,
	[MI_TEXAS] = map_texas.screens,
	[MI_CANADA] = map_canada.screens,
};

const mapscreen_index *map_bonus_layer_indices[] = {
	[MI_ITALY] = map_italy.bonus_index,
	[MI_PAKISTAN] = map_pakistan.bonus_index,
	[MI_ENGLAND] = map_england.bonus_index,
	[MI_PERU] = map_peru.bonus_index,
	[MI_FLORIDA] = map_florida.bonus_index,
	[MI_VIETNAM] = map_vietnam.bonus_index,
	[MI_TEXAS] = map_texas.bonus_index,
	[MI_CANADA] = map_canada.bonus_index,
};
	
const struct map_fglayer *map_bonus_screens[] = {
	[MI_ITALY] = map_italy.bonus_screens,
	[MI_PAKISTAN] = map_pakistan.bonus_screens,
	[MI_ENGLAND] = map_england.bonus_screens,
	[MI_PERU] = map_peru.bonus_screens,
	[MI_FLORIDA] = map_florida.bonus_screens,
	[MI_VIETNAM] = map_vietnam.bonus_screens,
	[MI_TEXAS] = map_texas.bonus_screens,
	[MI_CANADA] = map_canada.bonus_screens,
};
