#ifndef VIDEO_H
#define VIDEO_H

#ifndef SCALE
#define SCALE 2
#endif
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
void video_save_rect(int x, int y, int w, int h, void* buf);
void video_restore_rect(int x, int y, int w, int h, const void* buf);

#pragma RcB2 DEP "video.c"

#endif
