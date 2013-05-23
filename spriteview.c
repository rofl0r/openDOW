#include "../lib/include/timelib.h"
#include <stdint.h>

#include <SDL/SDL.h>
#ifndef IN_KDEVELOP_PARSER
#include "../lib/include/bitarray.h"
#include "../lib/include/macros.h"

#include "palpic.h"

#include "players.c"
#include "bullet.c"
#endif

//RcB: LINK "-lSDL"

#ifndef IN_KDEVELOP_PARSER

typedef union {
	struct {
#ifdef IS_LITTLE_ENDIAN
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
#else
		unsigned char a;
		unsigned char r;
		unsigned char g;
		unsigned char b;
#endif
	} colors;
	uint32_t asInt;
} sdl_rgb_t;


#define SRGB(R, G, B) ((sdl_rgb_t) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0})
#define SRGB_BLUE SRGB(0x0,0x0,0xFF)

//#define SRGB2(R, G, B) ((union { struct {uint8_t b;uint8_t g;uint8_t r;uint8_t a;} colors; uint32_t asInt; }) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0})
#define SRGB_WHITE SRGB(0xFF,0xFF,0xFF)
#define SRGB_BLACK SRGB(0x00,0x00,0x00)

#endif

//const struct palpic* spritemap = &players.header;
const struct palpic* spritemap = &bullet.header;

static sdl_rgb_t convert_prgb(prgb col) {
	sdl_rgb_t ret;
	ret.colors.r = col.colors.r;
	ret.colors.g = col.colors.g;
	ret.colors.b = col.colors.b;
	ret.colors.a = 0;
	return ret;
}

void blit_sprite(unsigned x_pos, unsigned y_pos, void *video_mem, unsigned videomem_pitch, 
	         unsigned scale, const struct palpic* pic, uint16_t spritenum) {
	unsigned sprite_width = palpic_getspritewidth(pic);
	unsigned sprite_height = palpic_getspriteheight(pic);
	const prgb* palette = palpic_getpalette(pic);
	const uint8_t *bitmap = palpic_getspritedata(pic, spritenum);
	unsigned int scale_y, scale_x, y, x;
	unsigned lineoffset = y_pos * (videomem_pitch / 4);
	unsigned pixel_start = 0;
	static const sdl_rgb_t mask_colors_transp[2] = {
		[0] = (SRGB_BLACK),
		[1] = (SRGB_WHITE),
	};
	static const sdl_rgb_t mask_colors_non_transp[2] = {
		[0] = (SRGB_BLACK),
		[1] = (SRGB_BLACK),
	};
	const sdl_rgb_t *mask_colors = (pic->flags & PPF_TRANSPARENT ? mask_colors_transp : mask_colors_non_transp);
	for (y = 0; y < sprite_height; y++) {
		for(scale_y = 0; scale_y < scale; scale_y++) {
			sdl_rgb_t *ptr = &((sdl_rgb_t *) video_mem)[lineoffset + x_pos];
			const uint8_t *p = &bitmap[pixel_start];
			for (x = 0; x < sprite_width; x++) {
				prgb col = palette[*p++];
				uint32_t mask = mask_colors[(col.val == palette[0].val)].asInt;
				for(scale_x = 0; scale_x < scale; scale_x++) {
					ptr[0].asInt &= mask;
					ptr[0].asInt |= convert_prgb(col).asInt;
					ptr++;
				}
			}
			lineoffset += videomem_pitch / 4;
		}
		pixel_start += sprite_width;
	}
}

static void get_last_move_event(SDL_Event* e) {
#define numpeek 32
	SDL_Event peek[numpeek];
	SDL_Event* last_event = NULL;
	int i, results;
	results = SDL_PeepEvents(peek, numpeek, SDL_PEEKEVENT, (uint32_t) ~0);
	if(results == -1) return;
	for(i = 0; i < results; i++) {
		if(peek[i].type == SDL_MOUSEMOTION)
			last_event = &peek[i];
		else
			break;
	}
	if(last_event) {
		*e = *last_event;
		SDL_PeepEvents(peek, i + 1, SDL_GETEVENT, (uint32_t) ~0);
	}
#undef numpeek
}

#define VMODE_W 640
#define VMODE_H 480

void redraw_bg(SDL_Surface *surface) {
	unsigned lineoffset = 0, x, y;
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	for(y = 0; y < VMODE_H; y++) {
		//unsigned lineoffset = y * (surface->pitch / 4);
		for(x = 0; x < VMODE_W; x++)
			//ptr[lineoffset + x] = SRGB_BLUE;
			*ptr++ = SRGB_BLUE;
	}
}

static uint16_t sprite_number = 0;

#define SCALE 4
void redraw(SDL_Surface *surface, int startx, int starty) {
	redraw_bg(surface);
	blit_sprite(startx, starty, surface->pixels, surface->pitch, SCALE, spritemap, sprite_number);
	SDL_UpdateRect(surface, 0 ,0, VMODE_W, VMODE_H);
	//SDL_UpdateRect(surface, startx ,starty, SPRITE_WIDTH * SCALE, palpic_getspriteheight(spritemap) * SCALE);
}

typedef struct { float x, y; } vec2f;

static vec2f velocity(vec2f* from, vec2f* to) {
	vec2f res = { .x = to->x - from->x, .y = to->y - from->y};
	return res;
}

#include <math.h>
static float calculateDistance(vec2f* a, vec2f* b) {
	vec2f vel = velocity(a, b);
	return (float) sqrtf((vel.x * vel.x) + (vel.y * vel.y));
}

static void shoot_bullet(SDL_Surface *surface, int *start_x, int *start_y, unsigned dest_x, unsigned dest_y) {
	vec2f from = { .x = *start_x, .y = *start_y };
	vec2f to = { .x = dest_x, .y = dest_y };
	float dist = calculateDistance(&from, &to);
	vec2f vel = velocity(&from, &to);
	static const float bullet_speed = 40.0;
	float steps = dist / bullet_speed;
	vel.x /= steps;
	vel.y /= steps;
	float dist_taken = 0;
	unsigned frames = 0;
	struct timeval timer;
	gettimestamp(&timer);
	while(dist_taken < dist && from.x >= 0 && from.y >= 0 && from.x < VMODE_W && from.y < VMODE_H) {
		vec2f nu = { .x = from.x + vel.x, .y = from.y + vel.y };
		dist_taken += calculateDistance(&(vec2f) {.x = 0, .y = 0}, &vel);
		struct timeval it_time;
		gettimestamp(&it_time);
		if( ( (int) nu.x != (int)from.x) || ((int) nu.y != (int)from.y) )
			redraw(surface, from.x, from.y);
		//SDL_Delay(1000/60 - mspassed(&it_time));
		//SDL_Delay(1000/60);
		frames++;
		from = nu;
	}
	long passed = mspassed(&timer);
	printf("fps: %.4f\n", frames * 1000.f / passed);
	
	*start_x = from.x;
	*start_y = from.y;
}

enum cursor {
	c_down,
	c_up,
	c_left,
	c_right,
};

enum cursor cursor_lut[] = {
	[SDLK_UP] = c_up,
	[SDLK_DOWN] = c_down,
	[SDLK_LEFT] = c_left,
	[SDLK_RIGHT] = c_right,
};

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	
	int startx = 10;
	int starty = 10;
	
	redraw(surface, startx, starty);
	
	char cursors_pressed[] = {
		[c_up] = 0,
		[c_down] = 0,
		[c_left] = 0,
		[c_right] = 0,
	};
	
	struct { int *target; int dir; int max;} moves[] = {
		[c_up] = {&starty, SCALE * -1, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_down] = {&starty, SCALE, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_left] = {&startx, SCALE * -1, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
		[c_right] = {&startx, SCALE, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
	};
	
	SDL_Delay(1);
	SDL_Event sdl_event;
	while(1) {
		unsigned need_redraw = 0;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEBUTTONDOWN:
					shoot_bullet(surface, &startx, &starty, sdl_event.button.x, sdl_event.button.y);
					break;
				case SDL_QUIT:
					return 0;
				case SDL_KEYDOWN:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT:
							cursors_pressed[cursor_lut[sdl_event.key.keysym.sym]] = 1;
							break;
						case SDLK_KP_PLUS:
							sprite_number++;
							sprite_number_overflow_check:
							if(sprite_number >= palpic_getspritecount(spritemap))
								sprite_number = 0;
							printf("%d\n", sprite_number);
							need_redraw = 1;
							break;
						case SDLK_KP_MINUS:
							sprite_number--;
							goto sprite_number_overflow_check;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT:
							cursors_pressed[cursor_lut[sdl_event.key.keysym.sym]] = 0;
							break;
						default:
							break;
					}
				default:
					break;
			}
		}
		unsigned i;
		for (i = 0; i < ARRAY_SIZE(cursors_pressed); i++) {
			if(cursors_pressed[i]) {
				*moves[i].target += moves[i].dir;
				if(*moves[i].target < 0) *moves[i].target = 0;
				if(*moves[i].target > moves[i].max) *moves[i].target = moves[i].max;
				need_redraw = 1;
			}
		}
		if(need_redraw) redraw(surface, startx, starty);

		SDL_Delay(1);
	}

	return 0;
};
