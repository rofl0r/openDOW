#include "direction.h"

const enum direction directionbit_direction_lut[] = {
	[DIRB_INVALID] = DIR_INVALID,
	[DIRB_N] = DIR_N,
	[DIRB_S] = DIR_S,
	[DIRB_O] = DIR_O,
	[DIRB_W] = DIR_W,
	[DIRB_NW] = DIR_NW,
	[DIRB_SW] = DIR_SW,
	[DIRB_SO] = DIR_SO,
	[DIRB_NO] = DIR_NO,
};

const enum direction_bits direction_directionbit_lut[] = {
	[DIR_INVALID] = DIRB_INVALID,
	[DIR_N] = DIRB_N,
	[DIR_S] = DIRB_S,
	[DIR_O] = DIRB_O,
	[DIR_W] = DIRB_W,
	[DIR_NW] = DIRB_NW,
	[DIR_SW] = DIRB_SW,
	[DIR_SO] = DIRB_SO,
	[DIR_NO] = DIRB_NO,
};
