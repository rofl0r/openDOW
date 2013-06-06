#include "../lib/include/timelib.h"
#include "../lib/include/macros.h"
#include <stdio.h>
#include <stdlib.h>
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
#include "sdl_rgb.h"
#include "audio.h"
#include "muzzle_tab.h"
#include "spritemaps.h"
#include "enemy.h"

#include <SDL/SDL.h>

#ifndef IN_KDEVELOP_PARSER
#include "../lib/include/bitarray.h"
#include "weapon_sprites.c"
#include "music/dogsofwar.c"
extern const unsigned char dogsofwar_dw[];
extern const unsigned long dogsofwar_dw_size;

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
#if 0
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
#endif

static vec2f get_sprite_center(const struct palpic *p) {
	vec2f res;
	res.x = palpic_getspritewidth(p) * SCALE / 2;
	res.y = palpic_getspriteheight(p) * SCALE / 2;
	return res;
}

static SDL_Surface *surface;
static bool fullscreen_active = false;
static int player_ids[2];
static int crosshair_id;
static enum weapon_id player_weapons[2][WP_MAX];
static int weapon_count[2];
static enum weapon_id weapon_active[2]; // index into player_weapons[playerno]
static int player_ammo[2][AMMO_MAX];
static enum weapon_id get_active_weapon_id(int player_no);
static void switch_anim(int obj_id, int aid);
static vec2f get_vel_from_direction(enum direction dir, float speed);

#define SCREEN_MIN_X 64*SCALE
#define SCREEN_MAX_X VMODE_W - 64*SCALE
#define SCREEN_MIN_Y 0
#define SCREEN_MAX_Y 200*SCALE

static void draw_status_bar(void) {
	enum weapon_id wid = get_active_weapon_id(0);
	int x, y;
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	unsigned pitch = surface->pitch/4;
	for(y = SCREEN_MAX_Y; y < VMODE_H; y++)
		for (x = SCREEN_MIN_X; x < SCREEN_MAX_X; x++)
			ptr[y*pitch + x] = SRGB_BLACK;
		
	blit_sprite(((320 / 2) - (59 / 2)) * SCALE, (200 + (40/2) - (16/2)) * SCALE,
	            surface->pixels, surface->pitch, SCALE, &weapon_sprites.header, wid);
}

static void clear_screen(void) {
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	unsigned pitch = surface->pitch/4;
	unsigned x, y;
	for(y = 0; y < VMODE_H; y++) for (x = 0; x < VMODE_W; x++)
		ptr[y*pitch + x] = SRGB_BLACK;
}

static void redraw_bg() {
	unsigned lineoffset = 0, x, y;
	(void) lineoffset;
	sdl_rgb_t *ptr = (sdl_rgb_t *) surface->pixels;
	unsigned pitch = surface->pitch/4;
	srand(1);
	for(y = SCREEN_MIN_Y; y < SCREEN_MAX_Y; y++) {
		//unsigned lineoffset = y * (surface->pitch / 4);
		for(x = SCREEN_MIN_X; x < SCREEN_MAX_X; x++) {
			//ptr[lineoffset + x] = SRGB_BLUE;
			if(rand()%16 == 1) ptr[y*pitch + x] = SRGB(0x55, 0x77, 0x77);
			else ptr[y*pitch + x] = SRGB(0x33, 0x55, 0x55);
		}
	}
	draw_status_bar();
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
	objs[pid].pos = VEC( SCREEN_MIN_X, SCREEN_MAX_Y - (25 * SCALE) );
	objs[pid].vel = VEC( 0, 0 );
	objs[pid].spritemap_id = SI_PLAYERS;
	start_anim(pid, player_no == 0 ? ANIM_P1_MOVE_N : ANIM_P2_MOVE_N);
	player_weapons[player_no][0] = WP_COLT45;
	weapon_count[player_no] = 1;
	weapon_active[player_no] = 0;
	size_t i = 0;
	for(; i < AMMO_MAX; i++)
		player_ammo[player_no][i] = 50000;
	return pid;
}

static vec2f *mousepos;
static int init_crosshair() {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	crosshair_id = id;
	objs[id].objtype = OBJ_CROSSHAIR;
	mousepos = &objs[id].pos;
	objs[id].vel = VEC(0, 0);
	objs[id].spritemap_id = SI_CROSSHAIR;
	start_anim(id, ANIM_CROSSHAIR);
	return id;
}

static int init_bullet(vec2f *pos, vec2f *vel, int steps) {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	objs[id].objtype = OBJ_BULLET;
	objs[id].spritemap_id = SI_BULLET;
	objs[id].vel = *vel;
	objs[id].pos = *pos;
	start_anim(id, ANIM_BULLET);
	objs[id].objspecific.bullet.step_curr = 0;
	objs[id].objspecific.bullet.step_max = steps;
	return id;
}

static int init_grenade(vec2f *pos, vec2f *vel, int steps) {
	int id = init_bullet(pos, vel, steps);
	if(id == -1) return -1;
	objs[id].objtype = OBJ_GRENADE;
	objs[id].spritemap_id = SI_GRENADE;
	start_anim(id, ANIM_GRENADE_SMALL);
	return id;
}

static int init_grenade_explosion(vec2f *pos) {
	const int ticks_per_anim_frame = 4;
	const int expl_anim_frames = 11;
	vec2f grenade_center = get_sprite_center(spritemaps[SI_GRENADE_EXPLOSION]);
	vec2f mypos = vecsub(pos, &grenade_center);
	int id = init_bullet(&mypos, &VEC(0,0), expl_anim_frames*ticks_per_anim_frame -4);
	if(id == -1) return -1;
	objs[id].spritemap_id = SI_GRENADE_EXPLOSION;
	start_anim(id, ANIM_GRENADE_EXPLOSION);
	audio_play_wave_resource(wavesounds[WS_GRENADE_EXPLOSION]);
	return id;
}

static int init_flame(enum direction dir, vec2f *pos, vec2f *vel, int steps) {
	static const vec2f flame_origin[] = {
		[DIR_O] = { 4.0, 8.0 },
		[DIR_NO] = { 5.0, 11.0 },
		[DIR_N] = { 7.5, 12.0 },
		[DIR_NW] = { 10.0, 11.0 },
		[DIR_W] = { 11.0, 8.0 },
		[DIR_SW] = { 10.0, 5.0 },
		[DIR_S] = { 7.5, 3.0 },
		[DIR_SO] = { 4.0, 4.0 },
	};
	vec2f mypos = *pos;
	mypos.x -= flame_origin[dir].x * SCALE;
	mypos.y -= flame_origin[dir].y * SCALE;
	int id = init_bullet(&mypos, vel, steps);
	objs[id].spritemap_id = SI_FLAME;
	start_anim(id, ANIM_FLAME);
	return id;
}

#define ENEMY_SPEED 1
static vec2f get_enemy_vel(struct enemy *e) {
	int i = ENEMY_MAX_ROUTE -1;
	enum direction dir;
	for(; i >= 0; i--)
		if(e->curr_step >= e->route[i].start_step) {
			dir = e->route[i].dir;
			break;
		}
	return get_vel_from_direction(dir, ENEMY_SPEED);
}

static int init_enemy(enum direction face_dir, vec2f *pos, struct enemy* enemy, int is_bomber) {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	const enum objtype enemy_objtype_lut[] = { [0] = OBJ_ENEMY_SHOOTER, [1] = OBJ_ENEMY_BOMBER };
	const enum animation_id enemy_animation_lut[2][DIR_MAX] = { 
		[0] = {
			[DIR_S] = ANIM_ENEMY_GUNNER_DOWN, [DIR_O] = ANIM_ENEMY_GUNNER_RIGHT, [DIR_W] = ANIM_ENEMY_GUNNER_LEFT
		},
		[1] = {
			[DIR_S] = ANIM_ENEMY_BOMBER_DOWN, [DIR_O] = ANIM_ENEMY_BOMBER_RIGHT, [DIR_W] = ANIM_ENEMY_BOMBER_LEFT
		},
	};
	objs[id].objtype = enemy_objtype_lut[is_bomber];
	switch_anim(id, enemy_animation_lut[is_bomber][face_dir]);
	objs[id].pos = *pos;
	objs[id].objspecific.enemy = *enemy;
	objs[id].spritemap_id = SI_ENEMIES;
	objs[id].vel = get_enemy_vel(enemy);
	return id;
}

static int enemy_fires(struct enemy *e) {
	int i;
	for(i = 0; i < ENEMY_MAX_SHOT; i++)
		if(e->curr_step == e->shots[i]) return 1;
	return 0;
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
	return dir_to_anim[dir];
}

static int init_flash(vec2f *pos, enum direction dir) {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	objs[id].objtype = OBJ_BULLET;
	objs[id].spritemap_id = SI_FLASH;
	objs[id].pos = *pos;
	objs[id].vel = VEC(0, 0);
	start_anim(id, get_flash_animation_from_direction(dir));
	objs[id].objspecific.bullet.step_curr = 0;
	objs[id].objspecific.bullet.step_max = 2;
	return id;
}

static vec2f get_gameobj_pos(int obj_id) {
	return objs[obj_id].pos;
}

static vec2f get_gameobj_center(int obj_id) {
	vec2f res = objs[obj_id].pos;
	vec2f add = get_sprite_center(spritemaps[objs[obj_id].spritemap_id]);
	return vecadd(&res, &add);
}

static enum direction get_direction_from_vec(vec2f *vel);
static enum animation_id get_anim_from_direction(enum direction dir, int player, int throwing);

static enum weapon_id get_active_weapon_id(int player_no) {
	return player_weapons[player_no][weapon_active[player_no]];
}

static const struct weapon* get_active_weapon(int player_no) {
	return &weapons[get_active_weapon_id(player_no)];
}

static void fire_bullet(int player_no) {
	const struct weapon *pw = get_active_weapon(player_no);
	if(player_ammo[player_no][pw->ammo] == 0) return;
	vec2f from = get_gameobj_center(player_ids[player_no]);
	//get_anim_from_vel(0, objs[player].
	vec2f to = get_gameobj_center(crosshair_id);
	srand(time(0) ^ player_ammo[player_no][pw->ammo]);
	to.x += 4*SCALE - rand()%8*SCALE;
	to.y += 4*SCALE - rand()%8*SCALE;
	vec2f vel = velocity(&from, &to);
	enum direction dir = get_direction_from_vec(&vel);
	if(dir != DIR_INVALID) {
		enum animation_id aid = get_anim_from_direction(dir, player_no, pw->ammo == AMMO_GRENADE);
		if(aid != ANIM_INVALID) switch_anim(player_ids[player_no], aid);
		vec2f muzzle = muzzle_tab[objs[player_ids[player_no]].anim_curr];
		
		from = get_gameobj_pos(player_ids[player_no]);
		from.x += muzzle.x * SCALE;
		from.y += muzzle.y * SCALE;

		if(pw->flags & WF_MUZZLEFLASH) {
			static const vec2f flash_start[] = {
				[DIR_O] = { 0.0, 1.0 },
				[DIR_NO] = { 0.5, 6.0 },
				[DIR_N] = { 1.0, 7.5 },
				[DIR_NW] = { 6.0, 6.0 },
				[DIR_W] = { 7.5, 1.0 },
				[DIR_SW] = { 4.5, 0.0 },
				[DIR_S] = { 1.0, 0.0 },
				[DIR_SO] = { 0.0, 0.0 },
			};
			vec2f ffrom = from;
			ffrom.x -= flash_start[dir].x * SCALE;
			ffrom.y -= flash_start[dir].y * SCALE;
			init_flash(&ffrom, dir);
		}
		vel = velocity(&from, &to);		
	}
	float dist = veclength(&vel);
	float speed = pw->bullet_speed * SCALE;
	const uint16_t range_tab[] = {0,   80,   66, 80, 118, 118, 118, 118, 118, 118, 
	                              200, 200, 240, 240, 240, 240, 240, 240, 240, 240, 320 };
	float range = range_tab[pw->range] * SCALE;
	if(dist > range) 
		dist = range;
	float steps = dist / speed;
	float deg = atan2(vel.y, vel.x);
	vel.x = cos(deg) * speed;
	vel.y = sin(deg) * speed;
	switch(pw->shot) {
		case ST_LAUNCHER:
		case ST_BULLET:
			init_bullet(&from, &vel, steps);
			break;
		case ST_FLAMES:
			init_flame(dir, &from, &vel, steps);
			break;
		case ST_GRENADE:
			init_grenade(&from, &vel, steps);
			break;
		default:
			abort();
	}
	player_ammo[player_no][pw->ammo]--;
	const WAVE_HEADER_COMPLETE *wf = wavesounds[pw->sound];
	if(pw->sound != WS_NONE)
		audio_play_wave_resource(wf);
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
	const int fps = 64;
	int paint_objs[OBJ_MAX];
	size_t paint_obj_count = 0, i;
	if(mousebutton_down[MB_LEFT] > 1) {
		const int player_no = 0;
		const struct weapon *pw = get_active_weapon(player_no);
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
			if(objs[i].objtype == OBJ_BULLET || objs[i].objtype == OBJ_GRENADE) {
				if(objs[i].objspecific.bullet.step_curr >= objs[i].objspecific.bullet.step_max) {
					if(objs[i].objtype == OBJ_GRENADE) {
						vec2f nextpos = vecadd(&objs[i].pos, &objs[i].vel);
						init_grenade_explosion(&nextpos);
						obj_count_copy++;
					}
					gameobj_free(i);
					force_redraw = 1;
					continue;
				}
				else objs[i].objspecific.bullet.step_curr++;
				if(objs[i].objtype == OBJ_GRENADE) {
					if(objs[i].objspecific.bullet.step_curr >= 32) objs[i].animid = ANIM_GRENADE_SMALL;
					else if(objs[i].objspecific.bullet.step_curr >= 8) objs[i].animid = ANIM_GRENADE_BIG;
				}
			} else if (objs[i].objtype == OBJ_ENEMY_SHOOTER || objs[i].objtype == OBJ_ENEMY_BOMBER) {
				objs[i].objspecific.enemy.curr_step++;
				objs[i].vel = get_enemy_vel(&objs[i].objspecific.enemy);
				if(enemy_fires(&objs[i].objspecific.enemy)) {
					//fire_bullet();
				}
			}
			paint_objs[paint_obj_count++] = i;
			if((objs[i].objtype != OBJ_P1 &&  objs[i].objtype != OBJ_P2) || objs[i].vel.x != 0 || objs[i].vel.y != 0) {
				objs[i].pos.x += objs[i].vel.x;
				objs[i].pos.y += objs[i].vel.y;
				if((objs[i].objtype == OBJ_ENEMY_BOMBER || objs[i].objtype == OBJ_ENEMY_SHOOTER) && (
					objs[i].pos.x < SCREEN_MIN_X || objs[i].pos.x > SCREEN_MAX_X ||
					objs[i].pos.y < SCREEN_MIN_Y || objs[i].pos.y > SCREEN_MAX_Y) )
				{
					dprintf(2, "removed enemy from %.2f,%.2f\n", objs[i].pos.x, objs[i].pos.y);
					gameobj_free(i);
					force_redraw = 1;
					continue;
				}
				if(tickcounter % 4 == 0)
					objs[i].anim_curr = get_next_anim_frame(objs[i].animid, objs[i].anim_curr);
				force_redraw = 1;
			}
		}
	}
	long ms_used = 0;
	struct timeval timer;
	gettimestamp(&timer);
	if(force_redraw) {
		redraw_bg();
		for(i = 0; i < paint_obj_count; i++) {
			blit_sprite(objs[paint_objs[i]].pos.x, objs[paint_objs[i]].pos.y, surface->pixels, surface->pitch,
			            SCALE, spritemaps[objs[paint_objs[i]].spritemap_id], objs[paint_objs[i]].anim_curr);
		}
		SDL_UpdateRect(surface, SCREEN_MIN_X ,SCREEN_MIN_Y , SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
	}

	ms_used = mspassed(&timer);
	//if(ms_used) printf("repaint took: ms_used %ld\n", ms_used);
	int res = audio_process();
	if(res == -1) audio_open_music_resource(dogsofwar_dw, dogsofwar_dw_size, 1);
	ms_used = mspassed(&timer);
	//if(ms_used) printf("audio processed: %d, ms_used %ld\n", res, ms_used);
	
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

static enum cursor cursor_lut[] = {
	[SDLK_UP] = c_up,
	[SDLK_DOWN] = c_down,
	[SDLK_LEFT] = c_left,
	[SDLK_RIGHT] = c_right,
	[SDLK_w] = c_up,
	[SDLK_a] = c_left,
	[SDLK_s] = c_down,
	[SDLK_d] = c_right,
};

static char cursors_pressed[] = {
	[c_up] = 0,
	[c_down] = 0,
	[c_left] = 0,
	[c_right] = 0,
};

static vec2f get_vel_from_direction(enum direction dir, float speed) {
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

static enum direction get_direction_from_vec(vec2f *vel) {
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

static enum direction get_direction_from_cursor(void) {
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

static enum animation_id get_anim_from_direction(enum direction dir, int player_no, int throwing) {
	#define DIRMAP(a, b) [a] = b
	if(!throwing) {
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
		const enum animation_id *dir_map = player_no == 0 ? dir_map_p1 : dir_map_p2;
		return dir_map[dir];
	} else {
		static const enum animation_id dir_map_p1_g[] = {
			DIRMAP(DIR_N, ANIM_P1_THROW_N),
			DIRMAP(DIR_NW, ANIM_P1_THROW_NW),
			DIRMAP(DIR_W, ANIM_P1_THROW_W),
			DIRMAP(DIR_SW, ANIM_P1_THROW_SW),
			DIRMAP(DIR_S, ANIM_P1_THROW_S),
			DIRMAP(DIR_SO, ANIM_P1_THROW_SO),
			DIRMAP(DIR_O, ANIM_P1_THROW_O),
			DIRMAP(DIR_NO, ANIM_P1_THROW_NO),
		};
		static const enum animation_id dir_map_p2_g[] = {
			DIRMAP(DIR_N, ANIM_P2_THROW_N),
			DIRMAP(DIR_NW, ANIM_P2_THROW_NW),
			DIRMAP(DIR_W, ANIM_P2_THROW_W),
			DIRMAP(DIR_SW, ANIM_P2_THROW_SW),
			DIRMAP(DIR_S, ANIM_P2_THROW_S),
			DIRMAP(DIR_SO, ANIM_P2_THROW_SO),
			DIRMAP(DIR_O, ANIM_P2_THROW_O),
			DIRMAP(DIR_NO, ANIM_P2_THROW_NO),
		};
		const enum animation_id *dir_map = player_no == 0 ? dir_map_p1_g : dir_map_p2_g;
		return dir_map[dir];
	}
	#undef DIRMAP
}

#if 0
static enum animation_id get_anim_from_cursor(void) {
	enum direction dir = get_direction_from_cursor();
	if(dir == DIR_INVALID) return ANIM_INVALID;
	return get_anim_from_direction(dir, 0, 0);
}
/* playerno is either 0 or 1, not player_id! */
static enum animation_id get_anim_from_vel(int player_no, vec2f *vel) {
	enum direction dir = get_direction_from_vec(vel);
	if(dir == DIR_INVALID) return ANIM_INVALID;
	return get_anim_from_direction(dir, player_no, 0);
}
#endif

static void switch_anim(int obj_id, int aid) {
	if(objs[obj_id].animid == aid) return;
	start_anim(obj_id, aid);
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	SDL_ShowCursor(0);
	
	audio_init();
	audio_open_music_resource(dogsofwar_dw, dogsofwar_dw_size, 1);
	
	
	int startx = 10;
	int starty = 10;
	
	//redraw(surface, startx, starty);
	const float player_speed = 1.25f;
	const struct palpic* spritemap = spritemaps[SI_PLAYERS];
	struct { int *target; int dir; int max;} moves[] = {
		[c_up] = {&starty, SCALE * -1, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_down] = {&starty, SCALE, VMODE_H - (palpic_getspriteheight(spritemap) * SCALE)},
		[c_left] = {&startx, SCALE * -1, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
		[c_right] = {&startx, SCALE, VMODE_W - (palpic_getspritewidth(spritemap) * SCALE)},
	};
	
	//SDL_Delay(1);
	clear_screen();
	
	init_game_objs();
	int player_no = 0;
	int player_id = player_ids[player_no];
	
	game_tick(1);
	
	SDL_Event sdl_event;
	while(1) {
		unsigned need_redraw = 0;
		int weapon_inc = 0;
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
						case SDLK_e: {
							srand(time(0));
							const enum direction face_dir[] = { DIR_S, DIR_O, DIR_W };
							struct enemy e;
							e.curr_step = 0;
							e.route[0].start_step = 0;
							e.route[1].start_step = 0;
							e.route[2].start_step = 0;
							e.route[2].dir = DIR_SO;
							e.route[3].start_step = 64;
							e.route[3].dir = DIR_O;
							e.shots[0] = 0;
							e.shots[1] = 0;
							e.shots[2] = 0;
							e.shots[3] = 0;
							init_enemy(face_dir[rand()%3], &VEC(SCREEN_MIN_X, SCREEN_MIN_Y), &e, rand()%2);
						} break;
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
										enum animation_id aid = get_anim_from_direction(dir, player_no, 0);
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
								clear_screen();
								SDL_UpdateRect(surface,0,0,VMODE_W,VMODE_H);
								fullscreen_active = !fullscreen_active;
							}
							break;
						case SDLK_KP_PLUS:
							weapon_inc = 1;
							goto toggle_weapon;
						case SDLK_KP_MINUS:
							if((int)player_weapons[player_no][0] == 0)
								weapon_inc = WP_MAX-1;
							else weapon_inc = -1;
							toggle_weapon:
							player_weapons[player_no][0] += weapon_inc;
							if(player_weapons[player_no][0] == WP_INVALID)
								player_weapons[player_no][0] = 0;
							printf("%s\n", weapon_name(player_weapons[player_no][0]));
							need_redraw = 1;
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
