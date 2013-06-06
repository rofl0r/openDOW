#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "vec2f.h"
#include "anim.h"
#include "spritemaps.h"
#include "enemy.h"
#include <stdint.h>

enum objtype {
	OBJ_P1 = 0,
	OBJ_P2,
	OBJ_BULLET,
	OBJ_CROSSHAIR,
	OBJ_FLASH,
	OBJ_GRENADE,
	OBJ_ENEMY_SHOOTER,
	OBJ_ENEMY_BOMBER,
};

typedef struct gameobj {
	vec2f pos;
	vec2f vel;
	enum sprite_index spritemap_id;
	uint8_t anim_curr;
	enum animation_id animid;
	enum objtype objtype;
	union objspec {
		struct {
			int step_max;
			int step_curr;
		} bullet;
		struct enemy enemy;
	} objspecific;
} gameobj;

int gameobj_alloc(void);
void gameobj_free(int id);

#define OBJ_MAX 255
extern gameobj objs[OBJ_MAX];
extern uint8_t obj_slot_used[OBJ_MAX];
extern uint8_t obj_count;

//RcB: DEP "gameobj.c"

#endif
