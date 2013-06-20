#ifndef ENEMY_H
#define ENEMY_H

#include "direction.h"
#include <stdint.h>

enum enemy_type {
	ET_WESTERN = 0,
	ET_ASIAN,
};

struct enemy_route {
	enum direction dir;
	uint8_t start_step;
};

#define ENEMY_MAX_ROUTE 4
#define ENEMY_MAX_SHOT 4
struct enemy {
	struct enemy_route route[ENEMY_MAX_ROUTE];
	uint8_t shots[ENEMY_MAX_SHOT];
	int curr_step;
};

#endif
