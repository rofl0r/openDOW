#include "../lib/include/timelib.h"
#include "../lib/include/macros.h"
#include <stdint.h>
#include <assert.h>
#include "vec2f.h"
#include "anim.h"
#include "gameobj.h"
#include "video.h"
#include "direction.h"
#include "palpic.h"

#include <SDL/SDL.h>
#ifndef IN_KDEVELOP_PARSER
#include "../lib/include/bitarray.h"




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

static sdl_rgb_t convert_prgb(prgb col) {
	sdl_rgb_t ret;
	ret.colors.r = col.colors.r;
	ret.colors.g = col.colors.g;
	ret.colors.b = col.colors.b;
	ret.colors.a = 0;
	return ret;
}

void blit_sprite(int x_pos, int y_pos, void *video_mem, unsigned videomem_pitch, 
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

const struct palpic *spritemaps[2] = { &players.header, &bullet.header };
SDL_Surface *surface;

void redraw_bg() {
	unsigned lineoffset = 0, x, y;
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	for(y = 0; y < VMODE_H; y++) {
		//unsigned lineoffset = y * (surface->pitch / 4);
		for(x = 0; x < VMODE_W; x++)
			//ptr[lineoffset + x] = SRGB_BLUE;
			*ptr++ = SRGB_BLUE;
	}
}

static void start_anim(int obj_id, enum animation_id aid) {
	if(obj_id == -1) return;
	objs[obj_id].animid = aid;
	objs[obj_id].anim_curr = animations[aid].first;
}

static int init_player(int no) {
	int pid = gameobj_alloc();
	if(pid == -1) return -1;
	objs[pid].objtype = no == 1 ? OBJ_P1 : OBJ_P2;
	objs[pid].pos = VEC( 10, 10 );
	objs[pid].vel = VEC( 0, 0 );
	objs[pid].spritemap_id = 0;
	start_anim(pid, no == 1 ? ANIM_P1_MOVE_N : ANIM_P2_MOVE_N);
	return pid;
}

static int init_bullet(vec2f *pos, vec2f *vel, int steps) {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	objs[id].objtype = OBJ_BULLET;
	objs[id].spritemap_id = 1;
	objs[id].vel = *vel;
	objs[id].pos = *pos;
	start_anim(id, ANIM_BULLET);
	objs[id].objspecific.bullet.step_curr = 0;
	objs[id].objspecific.bullet.step_max = steps;
	return id;
}

static vec2f get_player_center(int player_id) {
	vec2f res = objs[player_id].pos;
	res.x += palpic_getspritewidth(spritemaps[objs[player_id].spritemap_id]) * SCALE / 2;
	res.y += palpic_getspriteheight(spritemaps[objs[player_id].spritemap_id]) * SCALE / 2;
	return res;
}

void switch_anim(int playerid, int aid);
enum direction get_direction_from_vec(vec2f *vel);
enum animation_id get_anim_from_direction(enum direction dir, int player);

static void fire_bullet(int player_id, int dx, int dy, float speed, float range) {
	vec2f from = get_player_center(player_id);
	//get_anim_from_vel(0, objs[player].
	vec2f to = VEC(dx, dy);
	vec2f vel = velocity(&from, &to);
	enum direction dir = get_direction_from_vec(&vel);
	if(dir != -1) {
		enum animation_id aid = get_anim_from_direction(dir, player_id);
		if(aid != -1) switch_anim(player_id, aid);
	}
	float dist = veclength(&vel);
	if(dist != range) dist = range;
	float steps = dist / speed;
	vel.x /= steps;
	vel.y /= steps;
	init_bullet(&from, &vel, steps);
}

static int init_game_objs() {
	return init_player(1);
}

static int get_next_anim_frame(enum animation_id aid, int curr) {
	curr++;
	if(curr > animations[aid].last) return animations[aid].first;
	return curr;
}

static void game_tick(int force_redraw) {
	size_t obj_visited = 0;
	size_t obj_count_copy = obj_count;
	int background_painted = 0;
	const int fps = 60;
	struct timeval timer;
	int paint_objs[OBJ_MAX];
	size_t paint_obj_count = 0, i;
	for(i = 0; obj_visited < obj_count_copy && i < OBJ_MAX; i++) {
		if(obj_slot_used[i]) {
			obj_visited++;
			if(objs[i].objtype == OBJ_BULLET) {
				if(objs[i].objspecific.bullet.step_curr >= objs[i].objspecific.bullet.step_max) {
					gameobj_free(i);
					force_redraw = 1;
					continue;
				}
				else objs[i].objspecific.bullet.step_curr++;
			}
			paint_objs[paint_obj_count++] = i;
			if(objs[i].vel.x != 0 || objs[i].vel.y != 0) {
				objs[i].pos.x += objs[i].vel.x;
				objs[i].pos.y += objs[i].vel.y;
				objs[i].anim_curr = get_next_anim_frame(objs[i].animid, objs[i].anim_curr);
				force_redraw = 1;
			}
		}
	}
	long ms_used = 0;
	if(force_redraw) {
		gettimestamp(&timer);
		redraw_bg();
		for(i = 0; i < paint_obj_count; i++) {
			blit_sprite(objs[paint_objs[i]].pos.x, objs[paint_objs[i]].pos.y, surface->pixels, surface->pitch,
			            SCALE, spritemaps[objs[paint_objs[i]].spritemap_id], objs[paint_objs[i]].anim_curr);
		}
		SDL_UpdateRect(surface, 0 ,0, VMODE_W, VMODE_H);
		ms_used = mspassed(&timer);
	}
	long sleepms = 1000/fps - ms_used;
	if(sleepms >= 0) SDL_Delay(sleepms);
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

char cursors_pressed[] = {
	[c_up] = 0,
	[c_down] = 0,
	[c_left] = 0,
	[c_right] = 0,
};

vec2f get_vel_from_anim(int aid, float speed) {
#define VELLUT(a, b, c) [a] = VEC(b, c)
	static const vec2f vel_lut[] = {
		VELLUT(ANIM_P1_MOVE_NW, -1, -1),
		VELLUT(ANIM_P1_MOVE_NO, 1, -1),
		VELLUT(ANIM_P1_MOVE_N, 0, -1),
		VELLUT(ANIM_P1_MOVE_SW, -1, 1),
		VELLUT(ANIM_P1_MOVE_SO, 1, 1),
		VELLUT(ANIM_P1_MOVE_S, 0, 1),
		VELLUT(ANIM_P1_MOVE_W, -1, 0),
		VELLUT(ANIM_P1_MOVE_O, 1, 0),
	};
#undef VELLUT
	vec2f v = vel_lut[aid];
	v.x *= speed;
	v.y *= speed;
	return v;
}

enum direction get_direction_from_vec(vec2f *vel) {
	float deg = atan2(vel->y, vel->x);
	if(deg < 0) deg *= -1.f;
	else deg = M_PI + (M_PI - deg); // normalize atan2 result to scale from 0 to 2 pi
	int hexadrant = (int)(deg / ((1.0/16.0f)*2*M_PI));
	assert(hexadrant >= 0 && hexadrant < 16);
	static const enum direction rad_lut[] = {
		DIR_O,
		DIR_NO, DIR_NO,
		DIR_N, DIR_N,
		DIR_NW, DIR_NW,
		DIR_W, DIR_W,
		DIR_SW, DIR_SW,
		DIR_S, DIR_S,
		DIR_SO, DIR_SO,
		DIR_O
	};
	return rad_lut[hexadrant];
}

enum direction get_direction_from_cursor(void) {
	enum direction dir = -1;
	if(cursors_pressed[c_up]) {
		if(cursors_pressed[c_left]) dir = DIR_NW;
		else if(cursors_pressed[c_right]) dir = DIR_NO;
		else dir = DIR_N;
	} else if (cursors_pressed[c_down]) {
		if(cursors_pressed[c_left]) dir = DIR_SW;
		else if(cursors_pressed[c_right]) dir = DIR_SO;
		else dir = DIR_S;
	} else if (cursors_pressed[c_left]) {
		dir = DIR_W;
	} else if (cursors_pressed[c_right]) {
		dir = DIR_O;
	}
	return dir;
}

enum animation_id get_anim_from_direction(enum direction dir, int player) {
	#define DIRMAP(a, b) [a] = b
	static const enum animation_id dir_map_p1[] = {
		DIRMAP(DIR_N, ANIM_P1_MOVE_N),
		DIRMAP(DIR_NW, ANIM_P1_MOVE_NW),
		DIRMAP(DIR_W, ANIM_P1_MOVE_W),
		DIRMAP(DIR_SW, ANIM_P1_MOVE_SW),
		DIRMAP(DIR_S, ANIM_P1_MOVE_S),
		DIRMAP(DIR_SO, ANIM_P1_MOVE_SO),
		DIRMAP(DIR_O, ANIM_P1_MOVE_O),
		DIRMAP(DIR_NO, ANIM_P1_MOVE_NO),
	};
	static const enum animation_id dir_map_p2[] = {
		DIRMAP(DIR_N, ANIM_P2_MOVE_N),
		DIRMAP(DIR_NW, ANIM_P2_MOVE_NW),
		DIRMAP(DIR_W, ANIM_P2_MOVE_W),
		DIRMAP(DIR_SW, ANIM_P2_MOVE_SW),
		DIRMAP(DIR_S, ANIM_P2_MOVE_S),
		DIRMAP(DIR_SO, ANIM_P2_MOVE_SO),
		DIRMAP(DIR_O, ANIM_P2_MOVE_O),
		DIRMAP(DIR_NO, ANIM_P2_MOVE_NO),
	};
	#undef DIRMAP
	const enum animation_id *dir_map = player == 0 ? dir_map_p1 : dir_map_p2;
	return dir_map[dir];
}

int get_anim_from_cursor(void) {
	enum direction dir = get_direction_from_cursor();
	if(dir == -1) return -1;
	enum animation_id aid = get_anim_from_direction(dir, 0);
	return aid;
}

int get_anim_from_vel(int player, vec2f *vel, vec2f *origin) {
	enum direction dir = get_direction_from_vec(vel);
	if(dir == -1) return -1;
	return get_anim_from_direction(dir, player);
}

void switch_anim(int playerid, int aid) {
	if(objs[playerid].animid == aid) return;
	start_anim(playerid, aid);
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	
	int startx = 10;
	int starty = 10;
	
	//redraw(surface, startx, starty);
	
	const struct palpic* spritemap = &players.header;
	struct { int *target; int dir; int max;} moves[] = {
		[c_up] = {&starty, SCALE * -1, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_down] = {&starty, SCALE, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_left] = {&startx, SCALE * -1, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
		[c_right] = {&startx, SCALE, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
	};
	
	SDL_Delay(1);
	
	int player = init_game_objs();
	game_tick(1);
	
	SDL_Event sdl_event;
	while(1) {
		unsigned need_redraw = 0;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEBUTTONDOWN:
					
					fire_bullet(player, sdl_event.button.x, sdl_event.button.y, 1, 100);
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
							check_anim:
							{
								int aid = get_anim_from_cursor();
								if(aid != -1) {
									switch_anim(player, aid);
									objs[player].vel = get_vel_from_anim(aid, 20);
								} else {
									objs[player].vel = VEC(0,0);
								}
							}
							break;
						case SDLK_KP_PLUS:
						case SDLK_KP_MINUS:
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
							goto check_anim;
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
		game_tick(need_redraw);
	}

	return 0;
};
