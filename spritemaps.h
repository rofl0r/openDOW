#ifndef SPRITEMAPS_H
#define SPRITEMAPS_H

enum __attribute__ ((__packed__)) sprite_index {
	SI_PLAYERS = 0,
	SI_BULLET,
	SI_CROSSHAIR,
	SI_FLASH,
	SI_FLAME,
	SI_GRENADE,
	SI_GRENADE_EXPLOSION,
	SI_ROCKET,
	SI_BIG_EXPLOSION,
	SI_ENEMY_WESTERN,
	SI_ENEMY_ASIAN,
	SI_WORLDMAP,
	SI_CLIENTS,
	SI_MAPBLINK,
};

#include "palpic.h"

extern const struct palpic *spritemaps[];

//RcB: DEP "spritemaps.c"

#endif
