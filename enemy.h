#ifndef ENEMY_H
#define ENEMY_H

#include "direction.h"
#include <stdint.h>

enum __attribute__ ((__packed__)) enemy_shape {
	ES_FIRST = 0,
	ES_SOLDIER1_DOWN = ES_FIRST,
	ES_SOLDIER1_LEFT,
	ES_SOLDIER1_RIGHT,
	ES_SOLDIER2_DOWN,
	ES_SOLDIER2_LEFT,
	ES_SOLDIER2_RIGHT,
	ES_GUNTURRET_MOVABLE_MAN,
	ES_GUNTURRET_MOVABLE_MACHINE,
	ES_JEEP,
	ES_TANK_SMALL,
	ES_TANK_BIG,
	ES_TRANSPORTER,
	ES_BUNKER_1,
	ES_BUNKER_2,
	ES_BUNKER_3,
	ES_BUNKER_4,
	ES_BUNKER_5,
	ES_MINE_FLAT,
	ES_MINE_CROSS,
	ES_FLAMETURRET,
	ES_GUNTURRET_FIXED_SOUTH,
	ES_GUNTURRET_FIXED_NORTH,
	ES_BOSS,
	ES_MAX,
	ES_INVALID = ES_MAX,
};

// shotdirection is derived from the shape

enum __attribute__ ((__packed__)) enemy_type {
	ET_WESTERN = 0,
	ET_ASIAN,
};

enum __attribute__ ((__packed__)) enemy_weapon {
	EW_GUN = 0,
	EW_GRENADE,
};

struct enemy_route {
	uint8_t start_step;
	enum direction16 dir;
	uint8_t vel;
	enum enemy_shape shape;
};

#define ENEMY_MAX_ROUTE 5
#define ENEMY_MAX_SHOT 5

struct enemy_spawn {
	uint8_t scroll_line;
	enum enemy_weapon weapon;
	int16_t x;
	int16_t y;
	struct enemy_route route[ENEMY_MAX_ROUTE];
	uint8_t shots[ENEMY_MAX_SHOT];
};

struct enemy_spawn_screen {
	uint16_t num_spawns;
	const struct enemy_spawn *spawns;
};

struct enemy {
	int curr_step;
	const struct enemy_spawn* spawn;
};


#endif
