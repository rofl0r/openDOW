#include "spritemaps.h"

#include "sprites/players.c"
#include "sprites/bullet.c"
#include "sprites/crosshair4.c"
#include "sprites/flash.c"
#include "sprites/flame.c"
#include "sprites/grenade.c"

#define spritemap_entry(x, y) [ x ] = &(y .header)
const struct palpic *spritemaps[] = { 
	spritemap_entry(SI_PLAYERS, players),
	spritemap_entry(SI_BULLET, bullet),
	spritemap_entry(SI_CROSSHAIR, crosshair4),
	spritemap_entry(SI_FLASH, flash),
	spritemap_entry(SI_FLAME, flame),
	spritemap_entry(SI_GRENADE, grenade),
};
