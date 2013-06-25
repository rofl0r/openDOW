#ifndef MUSIC_H
#define MUSIC_H

//RcB: DEP "music.c"
enum tune_index {
	TUNE_FIGHTING = 0,
	TUNE_MAP,
	TUNE_2,
	TUNE_3,
	TUNE_4,
	TUNE_HIGHSCORE,
	TUNE_6,
	TUNE_7,
	TUNE_INVALID,
	TUNE_MAX = TUNE_INVALID
};

int music_play(enum tune_index track);
int music_restart(void);

#endif
