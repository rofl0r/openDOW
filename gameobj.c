#include "gameobj.h"
#include <stddef.h>
#include <assert.h>

gameobj objs[OBJ_MAX];
uint8_t obj_slot_used[OBJ_MAX];
uint8_t obj_count;
// return -1 on error or gameobj slot id.
int gameobj_alloc(void) {
	if(obj_count >= OBJ_MAX) return -1;
	// fast path: try next slot
	size_t i = obj_count;
	if(!obj_slot_used[i]) {
		return_slot:
		obj_slot_used[i] = 1;
		obj_count++;
		return i;
	}
		
	for (i = 0; i < OBJ_MAX; i++) {
		if(!obj_slot_used[i]) goto return_slot;
	}
	return -1;
}

void gameobj_free(int id) {
	assert(obj_slot_used[id] == 1);
	obj_slot_used[id] = 0;
	obj_count--;
}

void gameobj_start_anim(int obj_id, enum animation_id aid) {
	if(obj_id == -1) return;
	objs[obj_id].animid = aid;
	objs[obj_id].anim_curr = animations[aid].first;
}

void gameobj_init(int id, vec2f *pos, vec2f* vel, 
		  enum sprite_index spritemap_id,
		  enum animation_id animid, enum objtype objtype) {
	if(id == -1) return;
	struct gameobj *o = &objs[id];
	o->pos = *pos;
	o->vel = *vel;
	o->spritemap_id = spritemap_id;
	gameobj_start_anim(id, animid);
	o->objtype = objtype;
}

void gameobj_init_bulletdata(int id, int steps) {
	if(id == -1) return;
	struct gameobj *o = &objs[id];
	o->objspecific.bullet.step_curr = 0;
	o->objspecific.bullet.step_max = steps;
}
