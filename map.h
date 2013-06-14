#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include "palpic.h"
#include "vec2f.h"

enum mapscreen_scrolldir {
	MS_UP,
	MS_LEFT,
	MS_RIGHT,
};

struct map_screen {
	enum mapscreen_scrolldir scrolldir;
	uint8_t bg[6][3];
	uint8_t fg[12][12];
};

enum map_type {
	MT_FOREST,
	MT_URBAN,
	MT_DESERT,
};

struct map {
	enum map_type maptype;
	uint8_t screen_count;
	const char *mission_text;
	const struct palpic *client_face;
	const struct palpic *mini_pic;
	vec2f map_coords;
};

#endif
