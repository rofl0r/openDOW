#include "music.h"
#include "audio.h"

#include "music/dogsofwar.c"

static enum tune_index current_tune;

int music_play(enum tune_index track) {
	if(track != TUNE_INVALID) current_tune = track;
	return audio_open_music_resource(dogsofwar_dw, dogsofwar_dw_size, current_tune);
}

int music_restart(void) {
	return music_play(TUNE_INVALID);
}
