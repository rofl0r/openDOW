#include "video.h"
#include <stdbool.h>

SDL_Surface *surface;
bool fullscreen_active;
struct vo_desc video;

void video_init(void) {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	video.mem = surface->pixels;
	video.pitch = surface->pitch;
	video.width = VMODE_W;
	video.height = VMODE_H;
	fullscreen_active = 0;
}

void video_cleanup(void) {
	if(fullscreen_active) SDL_WM_ToggleFullScreen(surface);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void video_update_region(int x, int y, int w, int h) {
	SDL_UpdateRect(surface, x, y, w, h);
}

void video_update(void) {
	SDL_UpdateRect(surface, 0, 0, video.width, video.height);
}

#include "sdl_rgb.h"
void video_darken_screen(void) {
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	unsigned pitch = surface->pitch/4;
	unsigned x, y;
	for(y = 0; y < VMODE_H; y++) for (x = 0; x < VMODE_W; x++) {
		sdl_rgb_t col = ptr[y*pitch + x];
		col.colors.r /= 2;
		col.colors.g /= 2;
		col.colors.b /= 2;
		ptr[y*pitch + x] = col;
	}
}

void clear_screen(void) {
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	unsigned pitch = surface->pitch/4;
	unsigned x, y;
	for(y = 0; y < VMODE_H; y++) for (x = 0; x < VMODE_W; x++)
		ptr[y*pitch + x] = SRGB_BLACK;
}

void toggle_fullscreen(void) {
	fullscreen_active = !fullscreen_active;
	SDL_WM_ToggleFullScreen(surface);
	SDL_Delay(1);
	clear_screen();
	SDL_UpdateRect(surface,0,0,VMODE_W,VMODE_H);
	SDL_Delay(1);
}
