#include "gameobj.h"
#include <stddef.h>

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
		return obj_count - 1;
	}
		
	for (i = 0; i < OBJ_MAX; i++) {
		if(!obj_slot_used[i]) goto return_slot;
	}
	return -1;
}

void gameobj_free(int id) {
	obj_slot_used[id] = 0;
	obj_count--;
}
