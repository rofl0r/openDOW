#include "video.h"
#include "palpic.h"
#include "spritemaps.h"
#include "maps.h"
#include "font.h"
#include "audio.h"
#include "music.h"
#include "SDL/SDL.h"

static void draw_world(const struct palpic *w, int x, int y) {
	blit_sprite(x*SCALE, y*SCALE, &video, SCALE, w, 0, 0);
}

static unsigned map_ticks;
static struct { int x, y; } cursor;
static enum map_index cursor_on_map(int x, int y) {
	enum map_index i, ret = MI_INVALID;
	vec2f c = { .x = cursor.x - x*SCALE, .y = cursor.y - y*SCALE};
	vec2f p;
	for(i = 0; i < MI_MAX; i++) {
		p = vecadd(&maps[i]->worldmap_coords, &VEC(2,2));
		p.x *= SCALE;
		p.y *= SCALE;
		p = vecadd(&p, &VEC(SCALE/2,SCALE/2));
		if(vecdist(&p, &c) <= 3*SCALE) { ret = i; goto done; }
	}
	done:
	return ret;
}

static void draw_blinky(const struct palpic *b, int x, int y) {
	enum map_index i;
	vec2f p;
	for(i = 0; i < MI_MAX; i++) {
		p = maps[i]->worldmap_coords;
		blit_sprite((x+p.x)*SCALE, (y+p.y)*SCALE, &video, SCALE, b, map_ticks%7, 0);
	}
}

static void draw_dot(int x, int y) {
	static const struct {
		struct palpic header;
		prgb palette[1];
		uint8_t data[1];
	} dot = { 
		{ {'p', 'P', 'i', 'C', }, 1, 1, 1, 1, 1, 0, 0 },
		{ PRGB(254, 0, 0) },
		{ 1 },
	};
	enum map_index i;
	vec2f p;
	for(i = 0; i < MI_MAX; i++) {
		p = maps[i]->worldmap_coords;
		blit_sprite((x+p.x+2)*SCALE, (y+p.y+2)*SCALE, &video, SCALE, &dot.header, map_ticks%7, 0);
	}
}

static void draw_face(const struct map *map) {
#define FACE_X 10
#define FACE_Y 10
#define FACE_H 32
#define FACE_W 32
	blit_sprite(FACE_X*SCALE, FACE_Y*SCALE, &video, SCALE, spritemaps[SI_CLIENTS], map->client_face, 0);
}

static void draw_maptext(const struct map *map) {
	unsigned i;
#define TEXT_X 48
#define TEXT_Y (FACE_Y - 6)
#define TEXT_H 8
	for(i = 0; i < 5; i++) {
		font_print(TEXT_X*SCALE, TEXT_Y*SCALE + i*(TEXT_H+1)*SCALE, 
		           map->mission_text[i], 33, SCALE, PRGB(0xdd,0xbb,0x00));
	}
}

static void draw_frame() {
	blit_sprite((FACE_X-2)*SCALE, (FACE_Y-2)*SCALE, &video, SCALE, spritemaps[SI_PICFRAME_HORIZ], 0, 0);
	blit_sprite((FACE_X-2)*SCALE, (FACE_Y+FACE_H)*SCALE, &video, SCALE, spritemaps[SI_PICFRAME_HORIZ], 1, 0);
	blit_sprite((FACE_X-2)*SCALE, FACE_Y*SCALE, &video, SCALE, spritemaps[SI_PICFRAME_VERT], 0, 0);
	blit_sprite((FACE_X+FACE_W)*SCALE, FACE_Y*SCALE, &video, SCALE, spritemaps[SI_PICFRAME_VERT], 1, 0);
}

static void draw_stuff(const struct palpic *world, int x, int y) {
	clear_screen();
	draw_world(world, x, y);
	const struct palpic *blinky = spritemaps[SI_MAPBLINK];
	draw_blinky(blinky, x, y);
	draw_dot(x,y);
	enum map_index m = cursor_on_map(x, y);
	if(m != MI_INVALID) {
		const struct map *map = maps[m];
		draw_frame();
		draw_face(map);
		draw_maptext(map);
	}
	video_update();
}

static void map_tick(const struct palpic *world, int x, int y) {
	static unsigned tc;
	draw_stuff(world, x, y);
	if(tc%6==0) map_ticks++;
	tc++;
	if (audio_process() == -1) audio_open_music_resource(dogsofwar_dw, dogsofwar_dw_size, TUNE_MAP);
	SDL_Delay(20);
}
#include <stdio.h>
enum map_index choose_mission() {
	/* background music for mission selection screen */
	audio_open_music_resource(dogsofwar_dw, dogsofwar_dw_size, TUNE_MAP);

	const struct palpic *world = spritemaps[SI_WORLDMAP];
	int x = (320 - palpic_getspritewidth(world))/2;
	int y = ((240 - palpic_getspriteheight(world))/2)+16;
	enum map_index ret = MI_INVALID;
	
	SDL_Event sdl_event;
	while(1) {
		while (SDL_PollEvent(&sdl_event)) {
			ret = MI_INVALID;
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					cursor.x = sdl_event.motion.x;
					cursor.y = sdl_event.motion.y;
					break;
				case SDL_MOUSEBUTTONDOWN:
					dprintf(2, "click on %d,%d\n", cursor.x/SCALE-x, cursor.y/SCALE-y);
					if((ret = cursor_on_map(x, y)) != MI_INVALID) goto dun_goofed;
					break;
				case SDL_QUIT:
					goto dun_goofed;
				case SDL_KEYDOWN:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_RETURN:
							if((sdl_event.key.keysym.mod & KMOD_LALT) ||
							   (sdl_event.key.keysym.mod & KMOD_RALT)) {
								toggle_fullscreen();
								SDL_Delay(1);
							}
							break;
						case SDLK_ESCAPE:
							goto dun_goofed;
						default: 
							break;
					}
				default:
					break;
			}
			
		}
		map_tick(world, x, y);
	}
	dun_goofed:
	clear_screen();
	video_update();
	return ret;
}
