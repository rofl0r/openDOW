#include "../enemy.h"

#define SPAWN(args...) (const struct enemy_spawn){ args }
const struct enemy_spawn *spawn_australia[38] = {
	[1] = {
		&SPAWN(
		.scroll_line = 1,
		.weapon = EW_GUN,
		.x = 100,
		.y = 100,
		.route = {
			[3] = {
				.shape = ES_SOLDIER1_DOWN,
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
		)
	},
};
