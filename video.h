#ifndef VIDEO_H
#define VIDEO_H

#define SCALE 2
#define VMODE_W 320*SCALE
#define VMODE_H 240*SCALE

#include "palpic.h"
#include <SDL/SDL.h>

extern struct vo_desc video;

void video_init(void);
void video_cleanup(void);
void toggle_fullscreen(void);
void clear_screen(void);
void video_update_region(int x, int y, int w, int h);
void video_update(void);
void video_darken_screen(void);

//RcB: DEP "video.c"

#endif
