#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include "palpic.h"
#include "vec2f.h"

enum map_scrolldir {
	MS_UP,
	MS_LEFT,
	MS_RIGHT,
};

struct map_screen {
	uint8_t bg[6][3];
	uint8_t fg[12][12];
};

enum map_type {
	MT_FOREST,
	MT_URBAN,
	MT_DESERT,
};

typedef uint8_t mapscreen_index;
#define MAPSCREEN_BLOCKED ((mapscreen_index) -1)

struct map {
	enum map_type maptype;
	const char *mission_text;
	const struct palpic *client_face;
	const struct palpic *mini_pic;
	vec2f worldmap_coords;
	mapscreen_index screen_map[28][7];
	uint8_t bonuslayer[12][12];
	mapscreen_index bonuslayer_index;
};

#endif
