#include "../palpic.h"
#include <assert.h>

#include <SDL/SDL.h>
#pragma RcB2 LINK "-lSDL"
#include "../sdl_rgb.h"
#include "../vec2f.h"
#define VMODE_W 320
#define VMODE_H 240

#define SCALE 2

SDL_Surface *surface;
struct vo_desc video;
#include "../sprites/map_urban.c"
const struct palpic *sprite = &map_urban.header;

static void init_video() {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	video.mem = surface->pixels;
	video.pitch = surface->pitch;
	video.width = VMODE_W;
	video.height = VMODE_H;
}

static void update_screen() {
	SDL_UpdateRect(surface, 0, 0, VMODE_W, VMODE_H);
}

static void clear() {
	uint_fast16_t x, w = VMODE_W;
	uint_fast16_t y, h = VMODE_H;
	sdl_rgb_t *pix, *ptr = pix = (sdl_rgb_t*) surface->pixels;
	uint_fast32_t pitch = surface->pitch / 4, inc = pitch - VMODE_W;
	for(y=0;y<h;y++) {
		for(x=0;x<w;x++) *ptr++ = SRGB(0,0,0);
		ptr+=inc;
	}
}

static void draw() {
	clear();
	blit_sprite(315,240-16, &video, SCALE, sprite, 35*5, 0);
	update_screen();
	SDL_Delay(20);
}

int main() {
	init_video();
	while(1) draw();
}
