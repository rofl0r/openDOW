#ifndef WALLS_H
#define WALLS_H

#include "map.h"

enum __attribute__ ((__packed__)) walltype {
	WT_NONE = 0,
	WT_SOLID = 1,
	WT_BULLETS_PASS = 2,
};

extern const enum walltype walls[MT_MAX][210];

//RcB: DEP "walls.c"
#endif
