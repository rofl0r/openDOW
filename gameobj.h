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
	OBJ_FLAME,
	OBJ_GRENADE,
	OBJ_GRENADE_EXPLOSION,
	OBJ_ROCKET,
	OBJ_BIG_EXPLOSION,
	OBJ_ENEMY_SHOOTER,
	OBJ_ENEMY_BOMBER,
	OBJ_JEEP,
	OBJ_TANK_SMALL,
	OBJ_TANK_BIG,
	OBJ_TRANSPORTER,
	OBJ_GUNTURRET_MOVABLE_MAN,
	OBJ_GUNTURRET_MOVABLE_MACHINE,
	OBJ_MINE_FLAT,
	OBJ_MINE_CROSSED,
	OBJ_FLAMETURRET,
	OBJ_GUNTURRET_FIXED_SOUTH,
	OBJ_GUNTURRET_FIXED_NORTH,
	OBJ_BUNKER1,
	OBJ_BUNKER2,
	OBJ_BUNKER3,
	OBJ_BUNKER4,
	OBJ_BUNKER5,
	OBJ_BOSS,
};

typedef uint8_t anim_step;
#define ANIM_STEP_INIT (anim_step) -1

typedef struct gameobj {
	vec2f pos;
	vec2f vel;
	enum sprite_index spritemap_id;
	anim_step anim_curr;
	enum animation_id animid;
	uint8_t anim_frame;
	enum objtype objtype;
	union objspec {
		struct {
			int step_max;
			int step_curr;
		} bullet;
		struct enemy enemy;
		struct {
			unsigned score;
		} playerdata;
	} objspecific;
} gameobj;

int gameobj_alloc(void);
void gameobj_free(int id);

void gameobj_start_anim(int obj_id, enum animation_id aid);
void gameobj_init(int id, vec2f *pos, vec2f* vel, 
		  enum sprite_index spritemap_id,
		  enum animation_id animid, enum objtype objtype);

void gameobj_init_bulletdata(int id, int steps);


#define OBJ_MAX 255
extern gameobj objs[OBJ_MAX];
extern uint8_t obj_slot_used[OBJ_MAX];
extern uint8_t obj_count;

//RcB: DEP "gameobj.c"

#endif
