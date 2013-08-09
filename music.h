#ifndef MUSIC_H
#define MUSIC_H

//RcB: DEP "music.c"
enum tune_index {
	TUNE_EMPTY = -1,
	TUNE_FIGHTING = 0,
	TUNE_MAP,
	TUNE_2,
	TUNE_LEVEL_FINISHED,
	TUNE_4,
	TUNE_HIGHSCORE,
	TUNE_TITLE, // played at title screen and when a map is finished
	TUNE_7,
	TUNE_INVALID,
	TUNE_MAX = TUNE_INVALID
};

int music_play(enum tune_index track);
int music_restart(void);

#endif
