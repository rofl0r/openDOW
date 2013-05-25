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

#endif
