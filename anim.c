#include "anim.h"

const struct anim animations[] = {
	ANIM(ANIM_P1_MOVE_N, 40, 4),
	ANIM(ANIM_P1_MOVE_NW, 64, 4),
	ANIM(ANIM_P1_MOVE_W, 48, 4),
	ANIM(ANIM_P1_MOVE_SW, 60, 4),
	ANIM(ANIM_P1_MOVE_S, 44, 4),
	ANIM(ANIM_P1_MOVE_SO, 56, 4),
	ANIM(ANIM_P1_MOVE_O, 52, 4),
	ANIM(ANIM_P1_MOVE_NO, 68, 4),
	ANIM(ANIM_P1_DIE, 80, 8),
	ANIM(ANIM_P1_THROW_N, 72, 1),
	ANIM(ANIM_P1_THROW_NW, 78, 1),
	ANIM(ANIM_P1_THROW_W, 74, 1),
	ANIM(ANIM_P1_THROW_SW, 77, 1),
	ANIM(ANIM_P1_THROW_S, 73, 1),
	ANIM(ANIM_P1_THROW_SO, 76, 1),
	ANIM(ANIM_P1_THROW_O, 75, 1),
	ANIM(ANIM_P1_THROW_NO, 79, 1),
	ANIM(ANIM_P2_MOVE_N, 0, 4),
	ANIM(ANIM_P2_MOVE_NW, 24, 4),
	ANIM(ANIM_P2_MOVE_W, 8, 4),
	ANIM(ANIM_P2_MOVE_SW, 20, 4),
	ANIM(ANIM_P2_MOVE_S, 4, 4),
	ANIM(ANIM_P2_MOVE_SO, 16, 4),
	ANIM(ANIM_P2_MOVE_O, 12, 4),
	ANIM(ANIM_P2_MOVE_NO, 28, 4),
	ANIM(ANIM_P2_DIE, 88, 4), // FIXME: the last 4 sprites are from ANIM_P1_DIE, so it's actually 8
	ANIM(ANIM_P2_THROW_N, 32, 1),
	ANIM(ANIM_P2_THROW_NW, 38, 1),
	ANIM(ANIM_P2_THROW_W, 34, 1),
	ANIM(ANIM_P2_THROW_SW, 37, 1),
	ANIM(ANIM_P2_THROW_S, 33, 1),
	ANIM(ANIM_P2_THROW_SO, 36, 1),
	ANIM(ANIM_P2_THROW_O, 35, 1),
	ANIM(ANIM_P2_THROW_NO, 39, 4),
	ANIM(ANIM_BULLET, 1, 1),
	ANIM(ANIM_CROSSHAIR, 0, 1),
	ANIM(ANIM_FLASH_O, 0, 1),
	ANIM(ANIM_FLASH_NO, 1, 1),
	ANIM(ANIM_FLASH_N, 2, 1),
	ANIM(ANIM_FLASH_NW, 3, 1),
	ANIM(ANIM_FLASH_W, 4, 1),
	ANIM(ANIM_FLASH_SW, 5, 1),
	ANIM(ANIM_FLASH_S, 6, 1),
	ANIM(ANIM_FLASH_SO, 7, 1),
};

