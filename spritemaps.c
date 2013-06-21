#include "spritemaps.h"

#include "sprites/players.c"
#include "sprites/bullet.c"
#include "sprites/crosshair4.c"
#include "sprites/flash.c"
#include "sprites/flame.c"
#include "sprites/grenade.c"
#include "sprites/grenade_explosion.c"
#include "sprites/rocket.c"
#include "sprites/enemies.c"
#include "sprites/enemies_b.c"
#include "sprites/bigexpl.c"
#include "sprites/worldmap.c"
#include "sprites/clients.c"
#include "sprites/mapblink.c"
#include "sprites/frame_vertical.c"
#include "sprites/frame_horizontal.c"

#define spritemap_entry(x, y) [ x ] = &(y .header)
const struct palpic *spritemaps[] = { 
	spritemap_entry(SI_PLAYERS, players),
	spritemap_entry(SI_BULLET, bullet),
	spritemap_entry(SI_CROSSHAIR, crosshair4),
	spritemap_entry(SI_FLASH, flash),
	spritemap_entry(SI_FLAME, flame),
	spritemap_entry(SI_GRENADE, grenade),
	spritemap_entry(SI_GRENADE_EXPLOSION, grenade_explosion),
	spritemap_entry(SI_ENEMY_WESTERN, enemies),
	spritemap_entry(SI_ENEMY_ASIAN, enemies_b),
	spritemap_entry(SI_ROCKET, rocket),
	spritemap_entry(SI_BIG_EXPLOSION, bigexpl),
	spritemap_entry(SI_WORLDMAP, worldmap),
	spritemap_entry(SI_CLIENTS, clients),
	spritemap_entry(SI_MAPBLINK, mapblink),
	spritemap_entry(SI_PICFRAME_HORIZ, frame_horizontal),
	spritemap_entry(SI_PICFRAME_VERT, frame_vertical),
};
