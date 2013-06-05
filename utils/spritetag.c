#include <stdint.h>
#include <SDL/SDL.h>
//RcB: LINK "-lSDL"
#include "../vec2f.h"
#define VMODE_W 1200
#define VMODE_H 800
int SCALE = 16;

#include "../sprites/flame.c"
#include "../palpic.h"
const struct palpic* pic = &flame.header;

SDL_Surface *surface;
vec2f mousepos;
vec2f tag;
int activesprite;
int fullscreen_active;

#include "../sdl_rgb.h"

static void update_screen() {
	uint_fast16_t w = palpic_getspritewidth(pic);
	uint_fast16_t h = palpic_getspriteheight(pic);
	SDL_UpdateRect(surface, 0, 0, w* SCALE, h*SCALE);	
}

static void clear() {
	uint_fast16_t x, w = palpic_getspritewidth(pic);
	uint_fast16_t y, h = palpic_getspriteheight(pic);
	sdl_rgb_t *pix, *ptr = pix = (sdl_rgb_t*) surface->pixels;
	uint_fast32_t pitch = surface->pitch / 4, inc = pitch - w*SCALE;
	for(y=0;y<h*SCALE;y++) {
		for(x=0;x<w*SCALE;x++) *ptr++ = SRGB(0,0,0);
		ptr+=inc;
	}
}

static float rounddot5(float f) {
	int r = f;
	if (f-r >= 0.5) return r + 0.5;
	return r;
}

static void sprint_tag(char* buf) {
	sprintf(buf, "[%d] = { %.1f, %.1f },\n", activesprite, rounddot5(tag.x / SCALE), rounddot5(tag.y / SCALE)); 
}

static void print_spriteinfo() {
	char buf[128];
	char buf2[128];
	sprint_tag(buf2);;
	snprintf(buf, sizeof buf, "sprite %d/%u mouse: %u,%u scale:%dX ::: %s", 
		 activesprite, palpic_getspritecount(pic),
		 (int) (mousepos.x / SCALE), (int) (mousepos.y / SCALE), SCALE, buf2);
	SDL_WM_SetCaption(buf, 0);
}


static void print_tag() {
	char buf[128];
	sprint_tag(buf);
	printf("%s", buf);
}

static void draw_grid() {
	int x, w = palpic_getspritewidth(pic);
	int y, h = palpic_getspriteheight(pic);
	sdl_rgb_t *pix = (sdl_rgb_t*) surface->pixels;
	unsigned pitch = surface->pitch / 4;
	for(y = 0; y <= h * SCALE; y += SCALE) for(x = 0; x <= w * SCALE; x++) 
		pix[y * pitch + x] = SRGB(255,255,255);
	for(y = 0; y <= h * SCALE; y ++) for(x = 0; x <= w * SCALE; x += SCALE) 
		pix[y * pitch + x] = SRGB(255,0,255);
}

static int grid_enabled = 0;

static void draw() {
	int x, w = palpic_getspritewidth(pic);
	int y, h = palpic_getspriteheight(pic);
	sdl_rgb_t *pix = (sdl_rgb_t*) surface->pixels;
	unsigned pitch = surface->pitch / 4;
	
	clear();
	
	blit_sprite(0, 0, surface->pixels, surface->pitch, SCALE, pic, activesprite);
	
	if(grid_enabled) draw_grid();
	
	if(tag.x >= 0 && tag.y >= 0)
		pix[(int) (tag.y * pitch) + (int) (tag.x)] = SRGB(255, 0, 0);
	update_screen();
	print_spriteinfo();
}

static void switch_sprite(int dir) {
	activesprite += dir;
	if(activesprite < 0) activesprite = pic->spritecount - 1;
	else if(activesprite >= pic->spritecount) activesprite = 0;
	tag.x = -1;
	tag.y = -1;
	draw();
}

static void tick(unsigned need_redraw) {
	if(need_redraw) draw();
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	tick(1);
	while(1) {
		SDL_Event sdl_event;
		unsigned need_redraw = 0;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					mousepos.x = sdl_event.motion.x;
					mousepos.y = sdl_event.motion.y;
					print_spriteinfo();
					break;
				case SDL_MOUSEBUTTONDOWN:
					mousepos.x = sdl_event.button.x;
					mousepos.y = sdl_event.button.y;
					if(sdl_event.button.button == SDL_BUTTON_WHEELUP) {
						SCALE++;
						if(SCALE * palpic_getspritewidth(pic) < VMODE_W &&
						   SCALE * palpic_getspriteheight(pic) < VMODE_H); else SCALE--;
					} else if(sdl_event.button.button == SDL_BUTTON_WHEELDOWN) {
						clear();
						update_screen();
						SCALE--;
						if (SCALE == 0) SCALE = 1;
					} else {
						tag = mousepos;
					}
					need_redraw = 1;
					break;
				case SDL_MOUSEBUTTONUP:
					mousepos.x = sdl_event.button.x;
					mousepos.y = sdl_event.button.y;
					print_spriteinfo();
					break;
				case SDL_QUIT:
					dun_goofed:
					// restore desktop video mode correctly...
					if(fullscreen_active)
						SDL_WM_ToggleFullScreen(surface);
					return 0;
				case SDL_KEYDOWN:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_g:
							grid_enabled = !grid_enabled;
							need_redraw = 1;
							break;
						case SDLK_ESCAPE:
							goto dun_goofed;
						case SDLK_w: case SDLK_a: case SDLK_s: case SDLK_d:
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT: 
						case SDLK_RETURN:
							if((sdl_event.key.keysym.mod & KMOD_LALT) ||
							   (sdl_event.key.keysym.mod & KMOD_RALT)) {
								SDL_WM_ToggleFullScreen(surface);
								fullscreen_active = !fullscreen_active;
							} else {
								print_tag();
							}
							break;
						case SDLK_KP_PLUS:
							switch_sprite(+1);
							break;
						case SDLK_KP_MINUS:
							switch_sprite(-1);
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_w: case SDLK_a: case SDLK_s: case SDLK_d:
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT:
						default:
							break;
					}
				default:
					break;
			}
		}
		tick(need_redraw);
	}
	//SDL_ShowCursor(0);
	
}
