#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include "palpic.h"
#include "vec2f.h"
#include "enemy.h"

enum map_scrolldir {
	MS_UP,
	MS_LEFT,
	MS_RIGHT,
};

struct map_fglayer {
	uint8_t fg[12][12];
};

struct map_bglayer {
	uint8_t bg[6][3];
};

struct map_screen {
	struct map_bglayer bg;
	struct map_fglayer fg;
};

enum map_type {
	MT_FOREST = 0,
	MT_URBAN,
	MT_DESERT,
	MT_MAX,
};

typedef uint8_t mapscreen_index;
#define MAPSCREEN_BLOCKED ((mapscreen_index) -1)

struct map {
	enum map_type maptype;
	enum enemy_type enemy_type;
	const char mission_text[5][34];
	vec2f worldmap_coords;
	mapscreen_index screen_map[28][7];
	uint8_t client_face;
	uint8_t mini_pic;
	uint8_t bonuslayer_count;
	uint8_t rewardk; /* reward in 1000$ */
	uint8_t boss_id;
	prgb enemy_palette[8];
};

#endif
