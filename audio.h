#ifndef AUDIO_H
#define AUDIO_H

#define AUDIO_BACKEND_NONE 0
#define AUDIO_BACKEND_AO 1
#define AUDIO_BACKEND_SDL 2
#ifndef AUDIO_BACKEND
#define AUDIO_BACKEND AUDIO_BACKEND_AO
#endif

#include <stddef.h>
#if AUDIO_BACKEND != AUDIO_BACKEND_NONE
//RcB: SKIPON "AUDIO_BACKEND=AUDIO_BACKEND_NONE"
#include "../c-flod/backends/wave_format.h"
//RcB: SKIPOFF "AUDIO_BACKEND=AUDIO_BACKEND_NONE"
#else
#define WAVE_HEADER_COMPLETE int
#endif

void audio_init(void);
int audio_open_music(const char* filename, int track);
int audio_open_music_resource(const unsigned char* data, size_t data_size, int track);
int audio_process(void);

void audio_play_wav(const char* filename);
void audio_play_wave_resource(const WAVE_HEADER_COMPLETE* wave);
void audio_close(void);

//RcB: DEP "audio.c"
#endif
