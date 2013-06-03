#include "spritemaps.h"

#include "players.c"
#include "bullet.c"
#include "crosshair4.c"
#include "flash.c"
#include "flame.c"

#define spritemap_entry(x, y) [ x ] = &(y .header)
const struct palpic *spritemaps[] = { 
	spritemap_entry(SI_PLAYERS, players),
	spritemap_entry(SI_BULLET, bullet),
	spritemap_entry(SI_CROSSHAIR, crosshair4),
	spritemap_entry(SI_FLASH, flash),
	spritemap_entry(SI_FLAME, flame),
};
