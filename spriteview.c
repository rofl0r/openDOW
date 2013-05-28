#include "../lib/include/timelib.h"
#include "../lib/include/macros.h"
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "vec2f.h"
#include "anim.h"
#include "gameobj.h"
#include "video.h"
#include "direction.h"
#include "weapon.h"
#include "palpic.h"
#include "audio.h"

#include <SDL/SDL.h>

#ifndef IN_KDEVELOP_PARSER
#include "../lib/include/bitarray.h"
#include "players.c"
#include "bullet.c"
#include "crosshair4.c"
#include "flash.c"
#endif

enum mousebutton {
	MB_LEFT = 0,
	MB_RIGHT,
};

// 1 if button down, 0 if not, >1 to count ms pressed
unsigned long mousebutton_down[] = {
	[MB_LEFT] = 0,
	[MB_RIGHT] = 0,
};

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

const struct palpic *spritemaps[] = { &players.header, &bullet.header, &crosshair4.header, &flash.header };
SDL_Surface *surface;
bool fullscreen_active = false;
int player_ids[2];
int crosshair_id;
enum weapon_id player_weapons[2][WP_MAX];
int weapon_count[2];
enum weapon_id weapon_active[2]; // index into player_weapons[playerno]
int player_ammo[2][AMMO_MAX];

void redraw_bg() {
	unsigned lineoffset = 0, x, y;
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	srand(1);
	for(y = 0; y < VMODE_H; y++) {
		//unsigned lineoffset = y * (surface->pitch / 4);
		for(x = 0; x < VMODE_W; x++) {
			if(x < 64*SCALE || x > VMODE_W - 64*SCALE || y > 200*SCALE)
				*ptr++ = SRGB_BLACK;
			else 
			//ptr[lineoffset + x] = SRGB_BLUE;
			if(rand()%16 == 1) *ptr++ = SRGB(0x55, 0x77, 0x77);
			else *ptr++ = SRGB(0x33, 0x55, 0x55);
		}
	}
}

static void start_anim(int obj_id, enum animation_id aid) {
	if(obj_id == -1) return;
	objs[obj_id].animid = aid;
	objs[obj_id].anim_curr = animations[aid].first;
}

static int init_player(int player_no) {
	assert(player_no == 0 || player_no == 1);
	int pid = gameobj_alloc();
	if(pid == -1) return -1;
	player_ids[player_no] = pid;
	objs[pid].objtype = player_no == 0 ? OBJ_P1 : OBJ_P2;
	objs[pid].pos = VEC( 10, 10 );
	objs[pid].vel = VEC( 0, 0 );
	objs[pid].spritemap_id = 0;
	start_anim(pid, player_no == 0 ? ANIM_P1_MOVE_N : ANIM_P2_MOVE_N);
	player_weapons[player_no][0] = WP_COLT45;
	weapon_count[player_no] = 1;
	weapon_active[player_no] = 0;
	size_t i = 0;
	for(; i < AMMO_MAX; i++)
		player_ammo[player_no][i] = 50000;
	return pid;
}

vec2f *mousepos;
static int init_crosshair() {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	crosshair_id = id;
	objs[id].objtype = OBJ_CROSSHAIR;
	mousepos = &objs[id].pos;
	objs[id].vel = VEC(0, 0);
	objs[id].spritemap_id = 2;
	start_anim(id, ANIM_CROSSHAIR);
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

static enum animation_id get_flash_animation_from_direction(enum direction dir) {
	#define ANIMF(dir, anim) [dir] = anim
	static const enum animation_id dir_to_anim[] = {
		ANIMF(DIR_O, ANIM_FLASH_O),
		ANIMF(DIR_NO, ANIM_FLASH_NO),
		ANIMF(DIR_N, ANIM_FLASH_N),
		ANIMF(DIR_NW, ANIM_FLASH_NW),
		ANIMF(DIR_W, ANIM_FLASH_W),
		ANIMF(DIR_SW, ANIM_FLASH_SW),
		ANIMF(DIR_S, ANIM_FLASH_S),
		ANIMF(DIR_SO, ANIM_FLASH_SO),
	};
	#undef ANIMF
	assert(dir >= 0 && dir < DIR_MAX);
	return dir_to_anim[dir];
	
}

static int init_flash(vec2f *pos, enum direction dir) {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	objs[id].objtype = OBJ_BULLET;
	objs[id].spritemap_id = 3;
	objs[id].pos = *pos;
	objs[id].vel = VEC(0, 0);
	start_anim(id, get_flash_animation_from_direction(dir));
	objs[id].objspecific.bullet.step_curr = 0;
	objs[id].objspecific.bullet.step_max = 2;
}

static vec2f get_sprite_center(int obj_id) {
	vec2f res = objs[obj_id].pos;
	res.x += palpic_getspritewidth(spritemaps[objs[obj_id].spritemap_id]) * SCALE / 2;
	res.y += palpic_getspriteheight(spritemaps[objs[obj_id].spritemap_id]) * SCALE / 2;
	return res;
}

void switch_anim(int playerid, int aid);
enum direction get_direction_from_vec(vec2f *vel);
enum animation_id get_anim_from_direction(enum direction dir, int player);

static enum weapon_id get_active_weapon_id(int player_no) {
	return player_weapons[player_no][weapon_active[player_no]];
}

static struct weapon* get_active_weapon(int player_no) {
	return &weapons[get_active_weapon_id(player_no)];
}

static void fire_bullet(int player_no) {
	struct weapon *pw = get_active_weapon(player_no);
	if(player_ammo[player_no][pw->ammo] == 0) return;
	vec2f from = get_sprite_center(player_ids[player_no]);
	//get_anim_from_vel(0, objs[player].
	vec2f to = get_sprite_center(crosshair_id);
	srand(time(0) ^ player_ammo[player_no][pw->ammo]);
	to.x += 4*SCALE - rand()%8*SCALE;
	to.y += 4*SCALE - rand()%8*SCALE;
	vec2f vel = velocity(&from, &to);
	enum direction dir = get_direction_from_vec(&vel);
	if(dir != DIR_INVALID) {
		#define MUZZ(a, b, c) [a] = VEC(b, c)
		static const vec2f muzzle[] = {
			MUZZ(DIR_N, 5, -10),
			MUZZ(DIR_NW, -7, -9),
			MUZZ(DIR_W, -12, -1),
			MUZZ(DIR_SW, -9, 5),
			MUZZ(DIR_S, -6, 6),
			MUZZ(DIR_SO, 3, 6),
			MUZZ(DIR_O, 10, 2),
			MUZZ(DIR_NO, 8, -7),
		};
		
		from.x += muzzle[dir].x * SCALE;
		from.y += muzzle[dir].y * SCALE;
		vel = velocity(&from, &to);
		enum animation_id aid = get_anim_from_direction(dir, player_no);
		if(aid != ANIM_INVALID) switch_anim(player_ids[player_no], aid);
		static const vec2f flash_start[] = {
			MUZZ(DIR_N, -1.5, -7.5),
			MUZZ(DIR_NW, -5, -5.5),
			MUZZ(DIR_W, -6, -0.5),
			MUZZ(DIR_SW, -3, 1),
			MUZZ(DIR_S, -1.5, 1),
			MUZZ(DIR_SO, 0.5, 1.5),
			MUZZ(DIR_O, 1, -1.5),
			MUZZ(DIR_NO, 1.5, -5.5),
		};
		#undef MUZZ
		vec2f ffrom = from;
		ffrom.x += flash_start[dir].x * SCALE;
		ffrom.y += flash_start[dir].y * SCALE;
		init_flash(&ffrom, dir);
	}
	float dist = veclength(&vel);
	float speed = pw->bullet_speed * SCALE;
	const uint16_t range_tab[] = {0,   0,   64, 80, 118, 118, 118, 118, 118, 118, 
	                              200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 320 };
	float range = range_tab[pw->range] * SCALE;
	if(dist > range) 
		dist = range;
	float steps = dist / speed;
	float deg = atan2(vel.y, vel.x);
	vel.x = cos(deg) * speed;
	vel.y = sin(deg) * speed;
	int bid = init_bullet(&from, &vel, steps);
	player_ammo[player_no][pw->ammo]--;
	const char *wf = weapon_sound_filename(pw->sound);
	if(pw->sound != WS_NONE)
		audio_play_wav(wf);
}

static void init_game_objs() {
	init_player(0);
	init_crosshair();
}

static int get_next_anim_frame(enum animation_id aid, int curr) {
	curr++;
	if(curr > animations[aid].last) return animations[aid].first;
	return curr;
}

static void game_tick(int force_redraw) {
	static uint32_t tickcounter = 0;
	size_t obj_visited = 0;
	int background_painted = 0;
	const int fps = 64;
	struct timeval timer;
	int paint_objs[OBJ_MAX];
	size_t paint_obj_count = 0, i;
	if(mousebutton_down[MB_LEFT] > 1) {
		const int player_no = 0;
		struct weapon *pw = get_active_weapon(player_no);
		//if(get_active_weapon_id(player_no) == WP_M134) __asm__("int3");
		if (pw->flags & WF_AUTOMATIC) {
			float shots_per_second = pw->rpm / 60.f;
			float shotinterval = fps / shots_per_second;
			if((int)((float)mousebutton_down[MB_LEFT] / shotinterval) != (int)((float)(mousebutton_down[MB_LEFT]-1) / shotinterval))
				fire_bullet(player_no);
		}
	}
	size_t obj_count_copy = obj_count;
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
				if(tickcounter % 4 == 0)
					objs[i].anim_curr = get_next_anim_frame(objs[i].animid, objs[i].anim_curr);
				force_redraw = 1;
			}
		}
	}
	long ms_used = 0;
	gettimestamp(&timer);
	if(force_redraw) {
		redraw_bg();
		for(i = 0; i < paint_obj_count; i++) {
			blit_sprite(objs[paint_objs[i]].pos.x, objs[paint_objs[i]].pos.y, surface->pixels, surface->pitch,
			            SCALE, spritemaps[objs[paint_objs[i]].spritemap_id], objs[paint_objs[i]].anim_curr);
		}
		SDL_UpdateRect(surface, 0 ,0, VMODE_W, VMODE_H);
	}
	int res = -2;
	//if(tickcounter % 16 == 0)
		res = audio_process();
	if(res == -1) audio_open_music("DogsOfWar.DW", 1);
	ms_used = mspassed(&timer);
	printf("audio processed: %d, ms_used %ld\n", res, ms_used);
	long sleepms = 1000/fps - ms_used;
	if(sleepms >= 0) SDL_Delay(sleepms);
	if(mousebutton_down[MB_LEFT]) mousebutton_down[MB_LEFT]++;
	for(i = 0; i < paint_obj_count; i++)
		if(objs[paint_objs[i]].objtype == OBJ_FLASH)
			gameobj_free(paint_objs[i]);
	tickcounter++;
}

enum cursor {
	c_down = 0,
	c_up,
	c_left,
	c_right,
};

enum cursor cursor_lut[] = {
	[SDLK_UP] = c_up,
	[SDLK_DOWN] = c_down,
	[SDLK_LEFT] = c_left,
	[SDLK_RIGHT] = c_right,
	[SDLK_w] = c_up,
	[SDLK_a] = c_left,
	[SDLK_s] = c_down,
	[SDLK_d] = c_right,
};

char cursors_pressed[] = {
	[c_up] = 0,
	[c_down] = 0,
	[c_left] = 0,
	[c_right] = 0,
};

vec2f get_vel_from_direction(enum direction dir, float speed) {
#define VELLUT(a, b, c) [a] = VEC(b, c)
	static const vec2f vel_lut[] = {
		VELLUT(DIR_O, 1, 0),
		VELLUT(DIR_NO, 0.7071067769704655, -0.7071067769704655),
		VELLUT(DIR_N, 0, -1),
		VELLUT(DIR_NW, -0.7071067769704655, -0.7071067769704655),
		VELLUT(DIR_W, -1, 0),
		VELLUT(DIR_SW, -0.7071067769704655, 0.7071067769704655),
		VELLUT(DIR_S, 0, 1),
		VELLUT(DIR_SO, 0.7071067769704655, 0.7071067769704655),
	};
#undef VELLUT
	vec2f v = vel_lut[dir];
	v.x *= speed * SCALE;
	v.y *= speed * SCALE;
	return v;
}

enum direction get_direction_from_vec(vec2f *vel) {
	float deg_org, deg = atan2(vel->y, vel->x);
	deg_org = deg;
	if(deg < 0) deg *= -1.f;
	else if(deg > 0) deg = M_PI + (M_PI - deg); // normalize atan2 result to scale from 0 to 2 pi
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
	enum direction dir = DIR_INVALID;
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

enum animation_id get_anim_from_direction(enum direction dir, int player_no) {
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
	const enum animation_id *dir_map = player_no == 0 ? dir_map_p1 : dir_map_p2;
	return dir_map[dir];
}

enum animation_id get_anim_from_cursor(void) {
	enum direction dir = get_direction_from_cursor();
	if(dir == DIR_INVALID) return ANIM_INVALID;
	return get_anim_from_direction(dir, 0);
}
/* playerno is either 0 or 1, not player_id! */
enum animation_id get_anim_from_vel(int player_no, vec2f *vel, vec2f *origin) {
	enum direction dir = get_direction_from_vec(vel);
	if(dir == DIR_INVALID) return ANIM_INVALID;
	return get_anim_from_direction(dir, player_no);
}

void switch_anim(int player_id, int aid) {
	if(objs[player_id].animid == aid) return;
	start_anim(player_id, aid);
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	SDL_ShowCursor(0);
	
	audio_init();
	audio_open_music("DogsOfWar.DW", 1);
	
	
	int startx = 10;
	int starty = 10;
	
	//redraw(surface, startx, starty);
	const float player_speed = 1.25f;
	const struct palpic* spritemap = &players.header;
	struct { int *target; int dir; int max;} moves[] = {
		[c_up] = {&starty, SCALE * -1, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_down] = {&starty, SCALE, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_left] = {&startx, SCALE * -1, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
		[c_right] = {&startx, SCALE, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
	};
	
	SDL_Delay(1);
	
	init_game_objs();
	int player_no = 0;
	int player_id = player_ids[player_no];
	
	game_tick(1);
	
	SDL_Event sdl_event;
	while(1) {
		unsigned need_redraw = 0;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					mousepos->x = sdl_event.motion.x;
					mousepos->y = sdl_event.motion.y;
					need_redraw = 1;
					break;
				case SDL_MOUSEBUTTONDOWN:
					mousepos->x = sdl_event.button.x;
					mousepos->y = sdl_event.button.y;
					mousebutton_down[MB_LEFT] = 1;
					fire_bullet(player_no);
					break;
				case SDL_MOUSEBUTTONUP:
					mousepos->x = sdl_event.button.x;
					mousepos->y = sdl_event.button.y;
					mousebutton_down[MB_LEFT] = 0;
					break;
				case SDL_QUIT:
					dun_goofed:
					// restore desktop video mode correctly...
					if(fullscreen_active)
						SDL_WM_ToggleFullScreen(surface);
					return 0;
				case SDL_KEYDOWN:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_ESCAPE:
							goto dun_goofed;
						case SDLK_w: case SDLK_a: case SDLK_s: case SDLK_d:
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT: 
							cursors_pressed[cursor_lut[sdl_event.key.keysym.sym]] = 1;
							check_anim: {
								enum direction dir = get_direction_from_cursor();
								if(dir != DIR_INVALID) {
									if(!mousebutton_down[MB_LEFT]) {
										// change animation according to cursors,
										// unless we're in automatic fire mode.
										enum animation_id aid = get_anim_from_direction(dir, player_no);
										if(aid != ANIM_INVALID) switch_anim(player_id, aid);
									}
									objs[player_id].vel = get_vel_from_direction(dir, player_speed);
								} else {
									objs[player_id].vel = VEC(0,0);
								}
							}
							break;
						case SDLK_RETURN:
							if((sdl_event.key.keysym.mod & KMOD_LALT) ||
							   (sdl_event.key.keysym.mod & KMOD_RALT)) {
								SDL_WM_ToggleFullScreen(surface);
								fullscreen_active = !fullscreen_active;
							}
							break;
						case SDLK_KP_PLUS:
						case SDLK_KP_MINUS:
							player_weapons[player_no][0]++;
							if(player_weapons[player_no][0] == WP_INVALID)
								player_weapons[player_no][0] = 0;
							printf("%s\n", weapon_name(player_weapons[player_no][0]));
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
