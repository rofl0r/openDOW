#ifndef SPRITEMAPS_H
#define SPRITEMAPS_H

enum __attribute__ ((__packed__)) sprite_index {
	SI_PLAYERS = 0,
	SI_BULLET,
	SI_CROSSHAIR,
	SI_FLASH,
	SI_FLAME,
	SI_GRENADE,
};

#include "palpic.h"

extern const struct palpic *spritemaps[];

//RcB: DEP "spritemaps.c"

#endif
