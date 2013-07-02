#include "../enemy.h"

#define NUM_SCREENS 38
#define MAP_NAME australia
#ifndef SPAWN_ENTRY
#define PASTE4(a, b, c, d) a ## b ## c ## d
#define SPAWN_ENTRY2(mapname, index) PASTE4(spawn_,mapname,_screen,index)
#define SPAWN_ENTRY(index) SPAWN_ENTRY2(MAP_NAME, index)
#define PASTE2(a, b) a ## b
#define SPAWN_MAP1(mapname) PASTE2(spawn_screens_, mapname)
#define SPAWN_MAP SPAWN_MAP1(MAP_NAME)
#endif

static const struct enemy_spawn SPAWN_ENTRY(1)[] = {
	[0] = {
		.scroll_line = 1,
		.weapon = EW_GUN,
		.x = 100,
		.y = 100,
		.route = {
			[3] = {
				.shape = ES_JEEP,
				.dir = DIR16_WNW,
				.start_step = 0,
				.vel = 2,
			},
			[4] = {
				.shape = ES_SOLDIER1_RIGHT,
				.dir = DIR16_NNW,
				.start_step = 128,
				.vel = 2,
			},
			
		},
	},
};

const struct enemy_spawn_screen SPAWN_MAP[NUM_SCREENS] = {
	[0] = {
		.num_spawns = 0,
		.spawns = 0,
	},
	[1] = {
		.num_spawns = 1,
		.spawns = SPAWN_ENTRY(1),
	},
};

#undef MAP_NAME
