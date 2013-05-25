#ifndef ANIM_H
#define ANIM_H

#include <stdint.h>

typedef struct anim {
	uint16_t first;
	uint16_t last;
} anim;

enum __attribute__ ((__packed__)) animation_id {
	ANIM_P1_MOVE_N = 0,
	ANIM_P1_MOVE_NW,
	ANIM_P1_MOVE_W,
	ANIM_P1_MOVE_SW,
	ANIM_P1_MOVE_S,
	ANIM_P1_MOVE_SO,
	ANIM_P1_MOVE_O,
	ANIM_P1_MOVE_NO,
	ANIM_P1_DIE,
	ANIM_P1_THROW_N,
	ANIM_P1_THROW_NW,
	ANIM_P1_THROW_W,
	ANIM_P1_THROW_SW,
	ANIM_P1_THROW_S,
	ANIM_P1_THROW_SO,
	ANIM_P1_THROW_O,
	ANIM_P1_THROW_NO,
	ANIM_P2_MOVE_N,
	ANIM_P2_MOVE_NW,
	ANIM_P2_MOVE_W,
	ANIM_P2_MOVE_SW,
	ANIM_P2_MOVE_S,
	ANIM_P2_MOVE_SO,
	ANIM_P2_MOVE_O,
	ANIM_P2_MOVE_NO,
	ANIM_P2_DIE,
	ANIM_P2_THROW_N,
	ANIM_P2_THROW_NW,
	ANIM_P2_THROW_W,
	ANIM_P2_THROW_SW,
	ANIM_P2_THROW_S,
	ANIM_P2_THROW_SO,
	ANIM_P2_THROW_O,
	ANIM_P2_THROW_NO,
	ANIM_BULLET,
	ANIM_CROSSHAIR,
	ANIM_MAX,
	ANIM_INVALID = ANIM_MAX
};

#define ANIM(a, b, c) [a] = {b, b + c - 1}

extern const struct anim animations[];
//RcB: DEP "anim.c"

#endif
