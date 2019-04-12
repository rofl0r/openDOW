#ifndef DIRECTION_H
#define DIRECTION_H

enum __attribute__ ((__packed__)) direction {
	DIR_N = 0,
	DIR_NW,
	DIR_W,
	DIR_SW,
	DIR_S,
	DIR_SO,
	DIR_O,
	DIR_NO,
	DIR_MAX,
	DIR_INVALID = DIR_MAX
};

static inline const char* dir_name(enum direction dir) {
	#define DIRNAME(a) [ a ] = #a
	static const char* dir_names[] = {
		DIRNAME(DIR_N),
		DIRNAME(DIR_NW),
		DIRNAME(DIR_W),
		DIRNAME(DIR_SW),
		DIRNAME(DIR_S),
		DIRNAME(DIR_SO),
		DIRNAME(DIR_O),
		DIRNAME(DIR_NO),
	};
	#undef DIRNAME
	return dir_names[dir];
}

enum __attribute__ ((__packed__)) direction_bits {
	DIRB_INVALID = 0,
	DIRB_N = 1 << 0,
	DIRB_S = 1 << 1,
	DIRB_O = 1 << 2,
	DIRB_W = 1 << 3,
	DIRB_NW = DIRB_N | DIRB_W,
	DIRB_SW = DIRB_S | DIRB_W,
	DIRB_SO = DIRB_S | DIRB_O,
	DIRB_NO = DIRB_N | DIRB_O,
};

extern const enum direction_bits direction_directionbit_lut[];
extern const enum direction directionbit_direction_lut[];
#define direction_to_directionbit(dir) direction_directionbit_lut[dir]
#define directionbit_to_direction(db) direction_directionbit_lut[db]

enum __attribute__ ((__packed__)) direction16 {
	DIR16_N = 0,
	DIR16_NNW,
	DIR16_NW,
	DIR16_WNW,
	DIR16_W,
	DIR16_WSW,
	DIR16_SW,
	DIR16_SSW,
	DIR16_S,
	DIR16_SSO,
	DIR16_SO,
	DIR16_OSO,
	DIR16_O,
	DIR16_ONO,
	DIR16_NO,
	DIR16_NNO,
	DIR16_MAX,
	DIR16_INVALID = DIR16_MAX
};

#pragma RcB2 DEP "direction.c"

#endif
