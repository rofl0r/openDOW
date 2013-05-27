#ifndef AUDIO_H
#define AUDIO_H

void audio_init(void);
int audio_open_music(const char* filename, int track);
int audio_process(void);

void audio_play_wav(const char* filename);
void audio_close(void);

//RcB: DEP "audio.c"

#endif
