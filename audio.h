#ifndef AUDIO_H
#define AUDIO_H

#include "../c-flod/backends/wave_format.h"

void audio_init(void);
int audio_open_music(const char* filename, int track);
int audio_process(void);

void audio_play_wav(const char* filename);
void audio_play_wave_resource(const WAVE_HEADER_COMPLETE* wave);
void audio_close(void);

//RcB: DEP "audio.c"

#endif
