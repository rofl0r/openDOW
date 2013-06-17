#ifndef MAPS_H
#define MAPS_H

#include "map.h"

enum map_index {
	MI_ITALY = 0,
	MI_PAKISTAN,
};

extern const struct map *maps[];
extern const struct map_screen *map_screens[];

//RcB: DEP "maps.c"
#endif
