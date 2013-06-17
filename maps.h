#ifndef MAPS_H
#define MAPS_H

#include "map.h"

enum map_index {
	MI_ITALY = 0,
	MI_PAKISTAN,
	MI_ENGLAND,
};

extern const struct map *maps[];
extern const struct map_screen *map_screens[];
extern const mapscreen_index *map_bonus_layer_indices[];
extern const struct map_fglayer *map_bonus_screens[];

//RcB: DEP "maps.c"
#endif
