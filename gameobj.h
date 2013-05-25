#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "vec2f.h"
#include "anim.h"
#include <stdint.h>

enum objtype {
	OBJ_P1 = 0,
	OBJ_P2,
	OBJ_BULLET,
	OBJ_CROSSHAIR,
};

typedef struct gameobj {
	vec2f pos;
	vec2f vel;
	uint8_t spritemap_id;
	uint8_t anim_curr;
	enum animation_id animid;
	enum objtype objtype;
	union objspec {
		struct {
			int step_max;
			int step_curr;
		} bullet;
	} objspecific;
} gameobj;

int gameobj_alloc(void);
void gameobj_free(int id);

#define OBJ_MAX 256
extern gameobj objs[OBJ_MAX];
extern uint8_t obj_slot_used[OBJ_MAX];
extern uint8_t obj_count;

//RcB: DEP "gameobj.c"

#endif
