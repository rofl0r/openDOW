#include "../lib/include/timelib.h"
#include "../lib/include/macros.h"
#include "../lib/include/sblist.h"
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
#include "font.h"
#include "maps.h"
#include "mapsprites.h"
#include "walls.h"
#include "music.h"

#include <SDL/SDL.h>

#ifndef IN_KDEVELOP_PARSER
#include "../lib/include/bitarray.h"
#include "weapon_sprites.c"

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

static int player_ids[2];
static int crosshair_id;
static enum weapon_id player_weapons[2][WP_MAX];
static int weapon_count[2];
static enum weapon_id weapon_active[2]; // index into player_weapons[playerno]
static int player_ammo[2][AMMO_MAX];
static enum weapon_id get_active_weapon_id(int player_no);
static void switch_anim(int obj_id, int aid);
static vec2f get_vel_from_direction(enum direction dir, float speed);
static vec2f get_vel_from_direction16(enum direction16 dir, float speed);
// used by game_tick
static sblist go_player_bullets;
static sblist go_enemy_bullets;
static sblist go_explosions;
static sblist go_walls;
static sblist go_enemies;
static sblist go_players;
static sblist go_flames;
static sblist go_explosives;
static void add_pbullet(uint8_t bullet_id) {
	sblist_add(&go_player_bullets, &bullet_id);
}
static void add_ebullet(uint8_t bullet_id) {
	sblist_add(&go_enemy_bullets, &bullet_id);
}
static void add_player(uint8_t player_id) {
	sblist_add(&go_players, &player_id);
}
static void add_enemy(uint8_t enem_id) {
	sblist_add(&go_enemies, &enem_id);
}
static void add_explosion(uint8_t expl_id) {
	sblist_add(&go_explosions, &expl_id);
}
static void add_wall(uint8_t wall_id) {
	sblist_add(&go_walls, &wall_id);
}
static void add_flame(uint8_t id) {
	sblist_add(&go_flames, &id);
}
static void add_explosive(uint8_t id) {
	sblist_add(&go_explosives, &id);
}
static void golist_remove(sblist *l, uint8_t objid) {
	size_t i;
	uint8_t *itemid;
	sblist_iter_counter2(l, i, itemid) {
		if(*itemid == objid) {
			sblist_delete(l, i);
			return;
		}
	}
}

static int get_next_anim_frame(enum animation_id aid, anim_step curr) {
	if(curr == ANIM_STEP_INIT) return animations[aid].first;
	curr++;
	if(curr > animations[aid].last) return animations[aid].first;
	return curr;
}

#define SCREEN_MIN_X 64*SCALE
#define SCREEN_MAX_X VMODE_W - 64*SCALE
#define SCREEN_MIN_Y 0
#define SCREEN_MAX_Y 200*SCALE

static void draw_status_bar(void) {
	enum weapon_id wid = get_active_weapon_id(0);
	int x, y;
	sdl_rgb_t *ptr = (sdl_rgb_t *) video.mem;
	unsigned pitch = video.pitch/4;
	for(y = SCREEN_MAX_Y; y < VMODE_H; y++)
		for (x = SCREEN_MIN_X; x < SCREEN_MAX_X; x++)
			ptr[y*pitch + x] = SRGB_BLACK;
		
	blit_sprite(((320 / 2) - (59 / 2)) * SCALE, (200 + (40/2) - (16/2)) * SCALE,
	            &video, SCALE, &weapon_sprites.header, wid, 0);
	
	char buf[16];
	snprintf(buf, 16, "%.6u", objs[player_ids[0]].objspecific.playerdata.score);
	font_print(SCREEN_MIN_X + 8, SCREEN_MAX_Y + 8, buf, 6, 1 * SCALE, PRGB(255,255,255));
}

enum map_index current_map = MI_VIETNAM;
const struct map *map;
const struct map_screen* map_scr;
const struct palpic *map_bg;
const struct palpic *map_fg;
const mapscreen_index *map_bonus_indices;
const struct map_fglayer *map_bonus_scr;

int mapscreen_yoff, mapscreen_xoff;
struct { int x,y; } mapsquare;
enum map_scrolldir mapscrolldir;
unsigned map_spawn_screen_index;
unsigned map_spawn_line;
unsigned map_spawn_current;
#include "maps/spawn_australia.c"
const struct enemy_spawn **spawn_map = spawn_australia;

static void init_map(enum map_index mapindex) {
	map = maps[mapindex];
	map_scr = map_screens[mapindex];
	map_bg = map_bg_sprites[map->maptype];
	map_fg = map_fg_sprites[map->maptype];
	map_bonus_scr = map_bonus_screens[mapindex];
	map_bonus_indices = map_bonus_layer_indices[mapindex];
	mapscreen_yoff = 0;
	mapscreen_xoff = 0;
	mapsquare.x = 5;
	mapsquare.y = 26;
	mapscrolldir = MS_UP;
	map_spawn_screen_index = 0;
	map_spawn_line = 0;
	map_spawn_current = 0;
}

static mapscreen_index get_bonus_layer_index(mapscreen_index screen) {
	unsigned i;
	for (i = 0; i < map->bonuslayer_count; i++) 
		if(map_bonus_indices[i] == screen) return i;
	return MAPSCREEN_BLOCKED;
}

static mapscreen_index screen_to_mapscreen(int *x, int *y) {
	*x = ((int) *x - SCREEN_MIN_X) / SCALE;
	*y = ((int) *y - SCREEN_MIN_Y) / SCALE;
	int yscr = (*y + mapscreen_yoff) / 192;
	*y = (*y + mapscreen_yoff) - yscr*192;
	int xscr = (*x + mapscreen_xoff) / 192;
	*x = (*x + mapscreen_xoff) - xscr*192;
	return map->screen_map[mapsquare.y + yscr][mapsquare.x + xscr];
}

static int is_wall(vec2f *pos) {
	int x = pos->x;
	int y = pos->y;
	mapscreen_index scr_idx = screen_to_mapscreen(&x, &y);
	/* can happen when a bullet goes partially off-screen */
	if(scr_idx == MAPSCREEN_BLOCKED) return 0;
	uint8_t spriteno = map_scr[scr_idx].fg.fg[y/16][x/16];
	if(spriteno && walls[map->maptype][spriteno]) return 1;
	scr_idx = get_bonus_layer_index(scr_idx);
	if(scr_idx == MAPSCREEN_BLOCKED) return 0;
	spriteno = map_bonus_scr[scr_idx].fg[y/16][x/16];
	if(spriteno && walls[map->maptype][spriteno]) return 1;
	return 0;
}

static void draw_map() {
	int y, x, my, mx;
	unsigned map_off = 192-mapscreen_yoff;
	unsigned vis_x = 192-mapscreen_xoff;
	int x_iter_max16 = 192/16;
	int x_iter_max64 = 192/64;
	unsigned x_iter_start64 = x_iter_max64 - (vis_x / 64 + !!(vis_x % 64));
	unsigned x_iter_start16 = x_iter_max16 - (vis_x / 16 + !!(vis_x % 16));
	
	int x_screen_start64 = -(!!(vis_x%64)*64-(vis_x%64));
	int x_screen_start16 = -(!!(vis_x%16)*16-(vis_x%16));

	unsigned x_screen_iter;
	for(x_screen_iter = 0; x_screen_iter <= !!mapscreen_xoff; x_screen_iter++) {
		mapscreen_index bonus_layer;
		if(x_screen_iter) {
			x_screen_start16 = x_screen_start16+(x_iter_max16-x_iter_start16)*16;
			x_screen_start64 = x_screen_start64+(x_iter_max64-x_iter_start64)*64;
			x_iter_max16 = mapscreen_xoff / 16 + !!(mapscreen_xoff % 16);
			x_iter_max64 = mapscreen_xoff / 64 + !!(mapscreen_xoff % 64);
			x_iter_start16 = 0;
			x_iter_start64 = 0;
			assert(map->screen_map[mapsquare.y][mapsquare.x+x_screen_iter] != MAPSCREEN_BLOCKED);
		}
		uint8_t spriteno;

		for(my = 6-map_off/32-!!(map_off%32), y = SCREEN_MIN_Y + (!!(map_off%32)*32-(map_off%32))*-SCALE; my < 6; my++, y+=32*SCALE)
			for(mx = x_iter_start64, x = SCREEN_MIN_X + x_screen_start64*SCALE; mx < x_iter_max64; mx++, x += 64*SCALE) {
				spriteno = map_scr[map->screen_map[mapsquare.y][mapsquare.x+x_screen_iter]].bg.bg[my][mx];
				blit_sprite(x, y, &video,
					SCALE, map_bg, spriteno, 0);
			}
		for(my = 12-map_off/16-!!(map_off%16), y = SCREEN_MIN_Y + (!!(map_off%16)*16-(map_off%16))*-SCALE; my < 12; my++, y+=16*SCALE)
			for(mx = x_iter_start16, x = SCREEN_MIN_X + x_screen_start16*SCALE; mx < x_iter_max16; mx++, x += 16*SCALE) {
				spriteno = map_scr[map->screen_map[mapsquare.y][mapsquare.x+x_screen_iter]].fg.fg[my][mx];
				if(spriteno) blit_sprite(x, y, &video, SCALE, map_fg, spriteno, 0);
			}
		bonus_layer = get_bonus_layer_index(map->screen_map[mapsquare.y][mapsquare.x+x_screen_iter]);
		if(bonus_layer != MAPSCREEN_BLOCKED) {
			for(my = 12-map_off/16-!!(map_off%16), y = SCREEN_MIN_Y + (!!(map_off%16)*16-(map_off%16))*-SCALE; my < 12; my++, y+=16*SCALE)
				for(mx = x_iter_start16, x = SCREEN_MIN_X + x_screen_start16*SCALE; mx < x_iter_max16; mx++, x += 16*SCALE) {
					spriteno = map_bonus_scr[bonus_layer].fg[my][mx];
					if(spriteno) blit_sprite(x, y, &video, SCALE, map_fg, spriteno, 0);
				}
		}
		
		
		int yleft = 200-map_off;
		if(yleft > 192) yleft = 192;
		for(my = 0, y = SCREEN_MIN_Y + (map_off * SCALE); my < yleft/32+!!(yleft%32); my++, y+=32*SCALE)
			for(mx = x_iter_start64, x = SCREEN_MIN_X + x_screen_start64*SCALE; mx < x_iter_max64; mx++, x += 64*SCALE) {
				spriteno = map_scr[map->screen_map[mapsquare.y+1][mapsquare.x+x_screen_iter]].bg.bg[my][mx];
				blit_sprite(x, y, &video, SCALE, map_bg, spriteno, 0);
			}
		for(my = 0, y = SCREEN_MIN_Y + (map_off * SCALE); my < yleft/16+!!(yleft%16); my++, y+=16*SCALE)
			for(mx = x_iter_start16, x = SCREEN_MIN_X + x_screen_start16*SCALE; mx < x_iter_max16; mx++, x += 16*SCALE) {
				spriteno = map_scr[map->screen_map[mapsquare.y+1][mapsquare.x+x_screen_iter]].fg.fg[my][mx];
				if(spriteno) blit_sprite(x, y, &video, SCALE, map_fg, spriteno, 0);
			}
		
		bonus_layer = get_bonus_layer_index(map->screen_map[mapsquare.y+1][mapsquare.x+x_screen_iter]);
		if(bonus_layer != MAPSCREEN_BLOCKED) {
			for(my = 0, y = SCREEN_MIN_Y + (map_off * SCALE); my < yleft/16+!!(yleft%16); my++, y+=16*SCALE)
				for(mx = x_iter_start16, x = SCREEN_MIN_X + x_screen_start16*SCALE; mx < x_iter_max16; mx++, x += 16*SCALE) {
					spriteno = map_bonus_scr[bonus_layer].fg[my][mx];
					if(spriteno) blit_sprite(x, y, &video, SCALE, map_fg, spriteno, 0);
				}
		}
				
		/* this is never triggered when mapscreen_xoff != 0 */
		if(mapscreen_yoff > 192 - 8) {
			for(mx = 0, x = SCREEN_MIN_X + x_screen_start64*SCALE; mx < 3; mx++, x += 64*SCALE)
				blit_sprite(x, SCALE*(192*2-mapscreen_yoff), &video,
					SCALE, map_bg, map_scr[map->screen_map[mapsquare.y+2][mapsquare.x]].bg.bg[0][mx], 0);
			for(mx = 0, x = SCREEN_MIN_X + x_screen_start16*SCALE; mx < 12; mx++, x += 16*SCALE) {
				spriteno = map_scr[map->screen_map[mapsquare.y+2][mapsquare.x]].fg.fg[0][mx];
				if(spriteno) blit_sprite(x, SCALE*(192*2-mapscreen_yoff), &video, SCALE, map_fg, spriteno, 0);
			}
			bonus_layer = get_bonus_layer_index(map->screen_map[mapsquare.y+2][mapsquare.x]);
			if(bonus_layer != MAPSCREEN_BLOCKED) {
				for(mx = 0, x = SCREEN_MIN_X + x_screen_start16*SCALE; mx < 12; mx++, x += 16*SCALE) {
					spriteno = map_bonus_scr[bonus_layer].fg[0][mx];
					if(spriteno) blit_sprite(x, SCALE*(192*2-mapscreen_yoff), &video, SCALE, map_fg, spriteno, 0);
				}
			}
		}
	}
}

#define VSCROLL_TRESHOLD (200-64)
#define HSCROLLR_TRESHOLD 64
#define HSCROLLL_TRESHOLD 128
static int scroll_needed() {
	struct gameobj *player = &objs[player_ids[0]];
	if(mapscrolldir == MS_UP && player->pos.y < VSCROLL_TRESHOLD*SCALE) {
			return 1;
	} else if((mapscrolldir == MS_RIGHT && player->pos.x - SCREEN_MIN_X > HSCROLLR_TRESHOLD*SCALE) ||
		  (mapscrolldir == MS_LEFT  && player->pos.x - SCREEN_MIN_X < HSCROLLL_TRESHOLD*SCALE)) {
		return 1;
	}
	return 0;
}

static void scroll_gameobjs(int scroll_step) {
	if(!scroll_step) return;
	unsigned i, avail = obj_count;
	for(i = 0; i < OBJ_MAX && avail; i++) {
		if(!obj_slot_used[i]) continue;
		avail--;
		if(objs[i].objtype == OBJ_CROSSHAIR) continue;
		
		if(mapscrolldir == MS_UP)
			objs[i].pos.y += scroll_step*SCALE;
		else if(mapscrolldir == MS_LEFT)
			objs[i].pos.x += scroll_step*SCALE;
		else if(mapscrolldir == MS_RIGHT)
			objs[i].pos.x -= scroll_step*SCALE;
	}
}

static void next_screen() {
	map_spawn_screen_index++;
	map_spawn_line = 0;
	map_spawn_current = 0;
}

static int init_enemy(const struct enemy_spawn *spawn);
static void handle_spawns(int scrollstep) {
	unsigned i;
	if(!spawn_map[map_spawn_screen_index]) return;
	for(i = 0; i < scrollstep; i++) {
		if(map_spawn_line+i == spawn_map[map_spawn_screen_index][map_spawn_current].scroll_line) {
			init_enemy(&spawn_map[map_spawn_screen_index][map_spawn_current]);
			map_spawn_current++;
		}
	}
	map_spawn_line += scrollstep;
}

static int scroll_map() {
	int ret = 0;
	int scroll_step = 1;
	if(scroll_needed()) {
		if(mapscrolldir == MS_UP) {
			mapscreen_yoff -= scroll_step;
			if(mapscreen_yoff < 0) {
				next_screen();
				mapsquare.y--;
				if(map->screen_map[mapsquare.y][mapsquare.x] == MAPSCREEN_BLOCKED) {
					scroll_step = -mapscreen_yoff;
					mapscreen_yoff = 0;
					mapsquare.y++;
					scroll_gameobjs(scroll_step);
					if(map->screen_map[mapsquare.y][mapsquare.x+1] == MAPSCREEN_BLOCKED) {
						mapscrolldir = MS_LEFT;
					} else {
						mapscrolldir = MS_RIGHT;
					}
					scroll_step = 0;
				} else {
					mapscreen_yoff += 192;
				}
			}
			handle_objs:;
			handle_spawns(scroll_step);
			scroll_gameobjs(scroll_step);
			ret = 1;
		} else if(mapscrolldir == MS_LEFT) {
			mapscreen_xoff -= scroll_step;
			if(mapscreen_xoff < 0) {
				mapsquare.x--;
				if(map->screen_map[mapsquare.y][mapsquare.x] == MAPSCREEN_BLOCKED) {
					scroll_step = -mapscreen_xoff;
					mapscreen_xoff = 0;
					mapscreen_yoff = 0;
					mapsquare.x++;
					scroll_gameobjs(scroll_step);
					mapscrolldir = MS_UP;
					scroll_step = 0;
				} else {
					mapscreen_xoff += 192;
				}
			} 
			goto handle_objs;
		} else if(mapscrolldir == MS_RIGHT) {
			mapscreen_xoff += scroll_step;
			if(mapscreen_xoff >= 192) {
				mapsquare.x++;
				if(map->screen_map[mapsquare.y][mapsquare.x+1] == MAPSCREEN_BLOCKED) {
					scroll_step = mapscreen_xoff - 192;
					mapscreen_xoff = 0;
					mapscreen_yoff = 0;
					scroll_gameobjs(scroll_step);
					mapscrolldir = MS_UP;
					scroll_step = 0;
				} else {
					mapscreen_xoff -= 192;
				}
			} 
			goto handle_objs;
		}
	}
	return ret;
}

static void redraw_bg() {
	draw_map();
	draw_status_bar();
}

static int init_player(int player_no) {
	assert(player_no == 0 || player_no == 1);
	int pid = gameobj_alloc();
	gameobj_init(pid, &VEC( SCREEN_MIN_X, SCREEN_MAX_Y - (25 * SCALE) ), &VEC( 0, 0 ), 
		     SI_PLAYERS, player_no == 0 ? ANIM_P1_MOVE_N : ANIM_P2_MOVE_N, player_no == 0 ? OBJ_P1 : OBJ_P2);
	if(pid == -1) return -1;
	player_ids[player_no] = pid;
	objs[pid].objspecific.playerdata.score = 0;
	player_weapons[player_no][0] = WP_COLT45;
	weapon_count[player_no] = 1;
	weapon_active[player_no] = 0;
	size_t i = 0;
	for(; i < AMMO_MAX; i++)
		player_ammo[player_no][i] = 50000;
	add_player(pid);
	return pid;
}

static vec2f *mousepos;
static int init_crosshair() {
	int id = gameobj_alloc();
	gameobj_init(id, &VEC(VMODE_W/2, VMODE_H/2), &VEC(0,0), SI_CROSSHAIR, ANIM_CROSSHAIR, OBJ_CROSSHAIR);
	if(id == -1) return -1;
	crosshair_id = id;
	mousepos = &objs[id].pos;
	return id;
}

static int init_bullet(vec2f *pos, vec2f *vel, int steps) {
	int id = gameobj_alloc();
	gameobj_init(id, pos, vel, SI_BULLET, ANIM_BULLET, OBJ_BULLET);
	gameobj_init_bulletdata(id, steps);
	return id;
}

static int init_grenade(vec2f *pos, vec2f *vel, int steps) {
	int id = gameobj_alloc();
	gameobj_init(id, pos, vel, SI_GRENADE, ANIM_GRENADE_SMALL, OBJ_GRENADE);
	gameobj_init_bulletdata(id, steps);
	add_explosive(id);
	return id;
}

static int init_grenade_explosion(vec2f *pos) {
	const int ticks_per_anim_frame = 4;
	const int expl_anim_frames = 11;
	vec2f grenade_center = get_sprite_center(spritemaps[SI_GRENADE_EXPLOSION]);
	vec2f mypos = vecsub(pos, &grenade_center);
	int id = gameobj_alloc();
	if(id == -1) return -1;
	gameobj_init(id, &mypos, &VEC(0,0), SI_GRENADE_EXPLOSION, ANIM_GRENADE_EXPLOSION, OBJ_GRENADE_EXPLOSION);
	gameobj_init_bulletdata(id, expl_anim_frames*ticks_per_anim_frame -1);
	audio_play_wave_resource(wavesounds[WS_GRENADE_EXPLOSION]);
	add_explosion(id);
	return id;
}

static int init_big_explosion(vec2f *pos) {
	const int ticks_per_anim_frame = 8;
	const int expl_anim_frames = 5;
	vec2f rocket_center = get_sprite_center(spritemaps[SI_BIG_EXPLOSION]);
	vec2f mypos = vecsub(pos, &rocket_center);
	int id = gameobj_alloc();
	if(id == -1) return -1;
	gameobj_init(id, &mypos, &VEC(0,0), SI_BIG_EXPLOSION, ANIM_BIG_EXPLOSION, OBJ_BIG_EXPLOSION);
	gameobj_init_bulletdata(id, expl_anim_frames*ticks_per_anim_frame -1);
	audio_play_wave_resource(wavesounds[WS_GRENADE_EXPLOSION]);
	add_explosion(id);
	return id;
}

static int init_rocket_explosion(vec2f *pos) {
	vec2f ax = vecadd(pos, &VEC(-15*SCALE, 9*SCALE));
	vec2f bx = vecadd(pos, &VEC(1*SCALE, -6*SCALE));
	vec2f cx = vecadd(pos, &VEC(-8*SCALE, -8*SCALE));
	vec2f dx = vecadd(pos, &VEC(8*SCALE, 8*SCALE));
	int ret = 0;
	ret += init_grenade_explosion(&ax) != -1;
	ret += init_grenade_explosion(&bx) != -1;
	ret += init_big_explosion(&cx) != -1;
	ret += init_big_explosion(&dx) != -1;
	return ret;
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
	int id = gameobj_alloc();
	if(id == -1) return -1;
	gameobj_init(id, &mypos, vel, SI_FLAME, ANIM_FLAME, OBJ_FLAME);
	gameobj_init_bulletdata(id, steps);
	add_flame(id);
	return id;
}

static int init_rocket(enum direction dir, vec2f *pos, vec2f *vel, int steps) {
	static const vec2f rocket_origin[] = {
		[DIR_N] = { 1.0, 10.0 },
		[DIR_S] = { 1.0, 0.0 },
		[DIR_O] = { 0.0, 1.0 },
		[DIR_W] = { 10.0, 1.0 },
		[DIR_NO] = { 0.0, 7.0 },
		[DIR_SO] = { 0.0, 0.0 },
		[DIR_SW] = { 7.0, 0.0 },
		[DIR_NW] = { 7.0, 7.0 },
	};
	static const enum animation_id rocket_anim[] = {
		[DIR_N] = ANIM_ROCKET_N,
		[DIR_S] = ANIM_ROCKET_S,
		[DIR_O] = ANIM_ROCKET_O,
		[DIR_W] = ANIM_ROCKET_W,
		[DIR_NO] = ANIM_ROCKET_NO,
		[DIR_SO] = ANIM_ROCKET_SO,
		[DIR_SW] = ANIM_ROCKET_SW,
		[DIR_NW] = ANIM_ROCKET_NW,
	};
	vec2f mypos = *pos;
	mypos.x -= rocket_origin[dir].x * SCALE;
	mypos.y -= rocket_origin[dir].y * SCALE;
	int id = gameobj_alloc();
	if(id == -1) return -1;
	gameobj_init(id, &mypos, vel, SI_ROCKET, rocket_anim[dir], OBJ_ROCKET);
	gameobj_init_bulletdata(id, steps);
	add_explosive(id);
	return id;
}


static const struct enemy_route* get_enemy_current_route(int curr_step, const struct enemy_spawn *spawn) {
	int i = ENEMY_MAX_ROUTE -1;
	for(; i >= 0; i--) if(curr_step >= spawn->route[i].start_step) return &spawn->route[i];
	return 0;
}

static vec2f get_enemy_vel(int curr_step, const struct enemy_spawn *spawn) {
	const struct enemy_route *route = get_enemy_current_route(curr_step, spawn);
	return get_vel_from_direction16(route->dir, (float)route->vel/4.f);
}

static int init_enemy(const struct enemy_spawn *spawn) {
	vec2f spawnpos = VEC(SCREEN_MIN_X + spawn->x*SCALE, SCREEN_MIN_Y + spawn->y*SCALE);
	int id = gameobj_alloc();
	if(id == -1) return -1;
	const enum objtype enemy_objtype_lut[] = { [0] = OBJ_ENEMY_SHOOTER, [1] = OBJ_ENEMY_BOMBER };
	const enum animation_id enemy_animation_lut[] = { 
		[ES_SOLDIER1_DOWN] = ANIM_ENEMY_GUNNER_DOWN,
		[ES_SOLDIER1_RIGHT] = ANIM_ENEMY_GUNNER_RIGHT,
		[ES_SOLDIER1_LEFT] = ANIM_ENEMY_GUNNER_LEFT,
		[ES_SOLDIER2_DOWN] = ANIM_ENEMY_BOMBER_DOWN,
		[ES_SOLDIER2_RIGHT] = ANIM_ENEMY_BOMBER_RIGHT,
		[ES_SOLDIER2_LEFT] = ANIM_ENEMY_BOMBER_LEFT
	};
	const struct enemy_route* route_curr = get_enemy_current_route(0, spawn);
	vec2f vel = get_enemy_vel(0, spawn);
	enum sprite_index enemy_sprite_lut[] = {[ET_ASIAN] = SI_ENEMY_ASIAN, [ET_WESTERN] = SI_ENEMY_WESTERN, };
	gameobj_init(id, &spawnpos, &vel, 
		     enemy_sprite_lut[map->enemy_type],
	             enemy_animation_lut[route_curr->shape], 
	             enemy_objtype_lut[spawn->weapon]);
	objs[id].objspecific.enemy.curr_step = 0;
	objs[id].objspecific.enemy.spawn = spawn;
	add_enemy(id);
	return id;
}

static int enemy_fires(struct enemy *e) {
	int i;
	for(i = 0; i < ENEMY_MAX_SHOT; i++)
		if(e->curr_step == e->spawn->shots[i]) return 1;
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
	gameobj_init(id, pos, &VEC(0, 0), SI_FLASH, get_flash_animation_from_direction(dir), OBJ_FLASH);
	gameobj_init_bulletdata(id, 2);
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
	to.x += 4*SCALE - rand()%8*SCALE;
	to.y += 4*SCALE - rand()%8*SCALE;
	vec2f vel = velocity(&from, &to);
	enum direction dir = get_direction_from_vec(&vel);
	if(dir != DIR_INVALID) {
		enum animation_id aid = get_anim_from_direction(dir, player_no, pw->ammo == AMMO_GRENADE);
		if(aid != ANIM_INVALID) switch_anim(player_ids[player_no], aid);
		anim_step curranim = objs[player_ids[player_no]].anim_curr;
		if(curranim == ANIM_STEP_INIT) curranim = get_next_anim_frame(objs[player_ids[player_no]].animid, ANIM_STEP_INIT);
		vec2f muzzle = muzzle_tab[curranim];
		
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
	int id;
	switch(pw->shot) {
		case ST_LAUNCHER:
			id = init_rocket(dir, &from, &vel, steps);
			break;
		case ST_BULLET:
			id = init_bullet(&from, &vel, steps);
			if(id != -1) add_pbullet(id);
			break;
		case ST_FLAMES:
			id = init_flame(dir, &from, &vel, steps);
			break;
		case ST_GRENADE:
			id = init_grenade(&from, &vel, steps);
			break;
		default:
			abort();
	}
	player_ammo[player_no][pw->ammo]--;
	const WAVE_HEADER_COMPLETE *wf = wavesounds[pw->sound];
	if(id != -1 && pw->sound != WS_NONE)
		audio_play_wave_resource(wf);
}

static void init_game_objs() {
	sblist_init(&go_players, 1, 4);
	sblist_init(&go_player_bullets, 1, 32);
	sblist_init(&go_flames, 1, 32);
	sblist_init(&go_enemy_bullets, 1, 32);
	sblist_init(&go_explosions, 1, 16);
	sblist_init(&go_explosives, 1, 16);
	sblist_init(&go_walls, 1, 32);
	sblist_init(&go_enemies, 1, 32);
	init_player(0);
	init_crosshair();
	init_map(current_map);
}

static int point_in_mask(vec2f *point, int obj_id) {
	vec2f pos_in_pic = VEC((point->x - objs[obj_id].pos.x) / SCALE,
			       (point->y - objs[obj_id].pos.y) / SCALE);
	const struct palpic *p = spritemaps[objs[obj_id].spritemap_id];
	unsigned h = palpic_getspriteheight(p), w = palpic_getspritewidth(p);
	if(pos_in_pic.x < 0 || pos_in_pic.y < 0 || pos_in_pic.x > w || pos_in_pic.y > h) return 0;
	assert(objs[obj_id].anim_curr != ANIM_STEP_INIT);
	anim_step curranim = objs[obj_id].anim_curr;
	if(curranim == ANIM_STEP_INIT) curranim = get_next_anim_frame(objs[obj_id].animid, ANIM_STEP_INIT);
	uint8_t *data = palpic_getspritedata(p, curranim);
	if(data[(unsigned) pos_in_pic.y * w + (unsigned) pos_in_pic.x] != 0) return 1;
	return 0;
}

static enum animation_id get_die_anim(unsigned id) {
	if(objs[id].objtype == OBJ_P1)
		return ANIM_P1_DIE;
	else if(objs[id].objtype == OBJ_P1)
		return ANIM_P2_DIE;
	else if(objs[id].animid == ANIM_ENEMY_BOMBER_DOWN ||
	        objs[id].animid == ANIM_ENEMY_BOMBER_LEFT || 
	        objs[id].animid == ANIM_ENEMY_BOMBER_RIGHT)
		return ANIM_ENEMY_BOMBER_DIE;
	return ANIM_ENEMY_GUNNER_DIE;
}

/* remove bullets that have reached their maximum number of steps */
static int remove_bullets(sblist *list) {
	int res = 0;
	uint8_t *item_id;
	ssize_t li;
	sblist_iter_counter2s(list, li, item_id) {
		struct gameobj *bullet = &objs[*item_id];
		if(bullet->objspecific.bullet.step_curr >= bullet->objspecific.bullet.step_max) {
			gameobj_free(*item_id);
			sblist_delete(list, li);
			li--;
		} else {
			bullet->objspecific.bullet.step_curr++;
		}
		res = 1;
	}
	return res;
}

static int remove_explosives(void) {
	sblist *list = &go_explosives;
	int res = 0;
	uint8_t *item_id;
	ssize_t li;
	sblist_iter_counter2s(list, li, item_id) {
		struct gameobj *go = &objs[*item_id];
		if(go->objspecific.bullet.step_curr >= go->objspecific.bullet.step_max) {
			if(go->objtype == OBJ_GRENADE) init_grenade_explosion(&go->pos);
			else init_rocket_explosion(&go->pos);
			gameobj_free(*item_id);
			sblist_delete(list, li);
			li--;
		} else  {
			go->objspecific.bullet.step_curr++;
			if(go->objtype == OBJ_GRENADE) {
				if(go->objspecific.bullet.step_curr >= 32) go->animid = ANIM_GRENADE_SMALL;
				else if(go->objspecific.bullet.step_curr >= 8) go->animid = ANIM_GRENADE_BIG;
			}
		}
		res = 1;
	}
	return res;
}

static int is_death_anim(enum animation_id anim) {
	return anim == ANIM_ENEMY_BOMBER_DIE || anim == ANIM_ENEMY_GUNNER_DIE || 
	       anim == ANIM_ENEMY_BURNT || anim == ANIM_P1_DIE || anim == ANIM_P2_DIE;
}

// removes bullets and other objects if they collide. return 1 if anything happened
static int hit_bullets(sblist *bullet_list, sblist *target_list) {
	uint8_t *bullet_id;
	ssize_t li;
	int res = 0;
	enum bulletsubtype {
		BS_BULLET = 0,
		BS_FLAME = 1,
		BS_GRENADE_EXPL = 2,
		BS_BIG_EXPL = 3,
	} bullet_subtybe = BS_BULLET;
	
	sblist_iter_counter2s(bullet_list, li, bullet_id) {
		struct gameobj *bullet = &objs[*bullet_id];
		if(bullet->objtype == OBJ_FLAME) bullet_subtybe = BS_FLAME;
		else if(bullet->objtype == OBJ_GRENADE_EXPLOSION) {
			/* grenade kills only in the explosion, not in the smoke phase */
			if(bullet->objspecific.bullet.step_curr > 22) continue;
			bullet_subtybe = BS_GRENADE_EXPL;
		} else if(bullet->objtype == OBJ_BIG_EXPLOSION) {
			bullet_subtybe = BS_BIG_EXPL;
		}
		
		vec2f bullet_center = get_gameobj_center(*bullet_id);
		if(bullet_list == &go_player_bullets || bullet_list == &go_flames) {
			if(is_wall(&bullet_center)) goto remove_bullet;
		}
		
		const float bullet_radius[] = { [BS_BULLET] = 1.f, [BS_FLAME] = 6.f, 
		                                [BS_GRENADE_EXPL] = 16.f, [BS_BIG_EXPL] = 19.f };

		size_t lj;
		uint8_t *target_id;
		sblist_iter_counter2(target_list, lj, target_id) {
			struct gameobj *target = &objs[*target_id];
			if(is_death_anim(target->animid)) continue;
			vec2f temp = get_gameobj_center(*target_id);
			float dist1 = vecdist(&bullet_center, &temp) - bullet_radius[bullet_subtybe] * SCALE;
			vec2f newpos = vecadd(&bullet_center, &bullet->vel);
			float dist2 = vecdist(&newpos, &temp) - bullet_radius[bullet_subtybe] * SCALE;
			
			unsigned w = palpic_getspritewidth(spritemaps[target->spritemap_id]),
			         h = palpic_getspriteheight(spritemaps[target->spritemap_id]);
			float longest_side_div2 = ((float) MAX(h, w) / 2) * SCALE;
			if(dist1 < 1.f*SCALE || dist2 < 1.f*SCALE) { dprintf(2, "hit1\n"); goto hit; }
			if(dist1 < longest_side_div2 || dist2 < longest_side_div2) {
				vec2f velquarter = VEC(bullet->vel.x * 0.25, bullet->vel.y * 0.25);
				vec2f point = bullet_center;
				size_t k;
				for(k = 0; k < 4; k++) {
					if(point_in_mask(&point, *target_id)) {
						hit:
						;
						if(bullet_list == &go_player_bullets) {
							objs[player_ids[0]].objspecific.playerdata.score += 50;
						}
						enum animation_id death_anim = bullet_subtybe == BS_FLAME ? ANIM_ENEMY_BURNT : get_die_anim(*target_id);
						switch_anim(*target_id, death_anim);
						const enum wavesound_id wid[] = { WS_SCREAM, WS_SCREAM2 };
						audio_play_wave_resource(wavesounds[wid[rand()%2]]);
						if(bullet_subtybe == BS_BULLET) {
							remove_bullet:
							gameobj_free(*bullet_id);
							sblist_delete(bullet_list, li);
							li--;
							goto next_bullet;
						} else break;
					}
					point = vecadd(&point, &velquarter);
				}
			}
		}
		next_bullet:
		res = 1;
	}
	return res;
}

uint32_t tickcounter;

static int advance_animations(void) {
	size_t i, obj_visited;
	int res = 0;
	for(i = 0, obj_visited = 0; obj_visited < obj_count && i < OBJ_MAX; i++) {
		if(!obj_slot_used[i]) continue;
		struct gameobj *go = &objs[i];
		if(go->anim_curr == ANIM_STEP_INIT || (go->vel.x != 0 || go->vel.y != 0) || (go->objtype != OBJ_P1 && go->objtype != OBJ_P2) || is_death_anim(go->animid)) {
			unsigned anim_delay = go->objtype == OBJ_BIG_EXPLOSION ? 8 : 4;
			if(go->anim_curr == ANIM_STEP_INIT || tickcounter % anim_delay == go->anim_frame) {
				anim_step last_anim = go->anim_curr;
				go->anim_curr = get_next_anim_frame(go->animid, go->anim_curr);
				if(last_anim != go->anim_curr) res = 1;
			}
		}
		obj_visited++;
	}
	return res;
}

static void game_tick(int force_redraw) {
	int need_redraw = force_redraw;
	size_t obj_visited;
	const int fps = 64;
	size_t i;
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
	/* 1) remove bullets/rockets hitting walls (and spawn expl in the latter case)- TODO
	 * 2) check player bullets against enemies, remove bullets and enemies
	 * 3) check enemy bullets against players, remove bullets and players
	 * 4) bullets: move* 
	 * 5) check grenades, remove and spawn exposions if necessary
	 * 6) enemies: move, kill player on hit
	 * 7) player: move
	 */
	/*
	// remove dead enemies
	sblist_iter_counter2(&go_enemies, li, &item_id) {
		if(objs[item_id].anim_curr == animations[objs[item_id].animid].last &&
		   (objs[item_id].animid == ANIM_ENEMY_BOMBER_DIE || objs[item_id].animid == ANIM_ENEMY_GUNNER_DIE))
	}
	*/
	if(advance_animations()) need_redraw = 1;
	if(hit_bullets(&go_player_bullets, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_flames, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_enemy_bullets, &go_players)) need_redraw = 1;
	if(remove_bullets(&go_player_bullets)) need_redraw = 1;
	if(remove_bullets(&go_flames)) need_redraw = 1;
	if(remove_bullets(&go_explosions)) need_redraw = 1;
	if(remove_bullets(&go_enemy_bullets)) need_redraw = 1;
	if(remove_explosives()) need_redraw = 1;
	if(tickcounter % 2 == 0 && scroll_map()) need_redraw = 1;
	
	size_t obj_count_copy = obj_count;
	for(i = 0, obj_visited = 0; obj_visited < obj_count_copy && i < OBJ_MAX; i++) {
		if(obj_slot_used[i]) {
			struct gameobj *go = &objs[i];
			obj_visited++;
			if(go->anim_curr == ANIM_STEP_INIT) need_redraw = 1;
			if(go->objtype == OBJ_FLASH) {
				if(go->objspecific.bullet.step_curr >= go->objspecific.bullet.step_max) {
					gameobj_free(i);
					need_redraw = 1;
					continue;
				} else go->objspecific.bullet.step_curr++;
			} else if (go->objtype == OBJ_ENEMY_SHOOTER || go->objtype == OBJ_ENEMY_BOMBER) {
				if (tickcounter % 4 == go->anim_frame) go->objspecific.enemy.curr_step++;
				if(!is_death_anim(go->animid)) go->vel = get_enemy_vel(go->objspecific.enemy.curr_step, go->objspecific.enemy.spawn);
				else go->vel = VEC(0, 0);
				if(enemy_fires(&go->objspecific.enemy)) {
					//fire_bullet();
				}
			}
			int ismoving = 0;
			if(go->vel.x != 0 || go->vel.y != 0) {
				ismoving = 1;
				vec2f oldpos = go->pos;
				go->pos.x += go->vel.x;
				go->pos.y += go->vel.y;
				if(go->objtype == OBJ_ENEMY_BOMBER || go->objtype == OBJ_ENEMY_SHOOTER) {
					if(go->pos.x < SCREEN_MIN_X || go->pos.x > SCREEN_MAX_X ||
					   go->pos.y < SCREEN_MIN_Y-22*SCALE || go->pos.y > SCREEN_MAX_Y) {
						remove_enemy:
						dprintf(2, "removed enemy from %.2f,%.2f\n", go->pos.x, go->pos.y);
						gameobj_free(i);
						golist_remove(&go_enemies, i);
						need_redraw = 1;
						continue;
					}
				}
				if(go->objtype == OBJ_P1 || go->objtype == OBJ_P2) {
					if(go->pos.y < SCREEN_MIN_Y) go->pos.y = SCREEN_MIN_Y;
					else if(go->pos.y+25*SCALE > SCREEN_MAX_Y) go->pos.y = SCREEN_MAX_Y-25*SCALE;
					if(go->pos.x < SCREEN_MIN_X) go->pos.x = SCREEN_MIN_X;
					else if(go->pos.x+32*SCALE > SCREEN_MAX_X) go->pos.x = SCREEN_MAX_X-32*SCALE;
					vec2f center = get_sprite_center(spritemaps[go->spritemap_id]);
					center = vecadd(&center, &go->pos);
					if(is_wall(&center)) {
						go->pos = oldpos;
						go->vel = VEC(0,0);
					}
				}
				
				need_redraw = 1;
			}
			if((go->objtype == OBJ_ENEMY_BOMBER || go->objtype == OBJ_ENEMY_SHOOTER) &&
			   go->anim_curr == animations[go->animid].last &&
					  (go->animid == ANIM_ENEMY_BOMBER_DIE || 
					   go->animid == ANIM_ENEMY_GUNNER_DIE || 
					   go->animid == ANIM_ENEMY_BURNT))
				goto remove_enemy;
		}
	}
	long ms_used = 0;
	struct timeval timer;
	gettimestamp(&timer);
	if(need_redraw) {
		redraw_bg();
		for(i = 0, obj_visited = 0; obj_visited < obj_count && i < OBJ_MAX; i++) {
			if(!obj_slot_used[i]) continue;
			struct gameobj *o = &objs[i];
			const prgb *palette = (o->objtype == OBJ_ENEMY_BOMBER || o->objtype == OBJ_ENEMY_SHOOTER) ? map->enemy_palette : 0;
			blit_sprite(o->pos.x, o->pos.y, &video,
			            SCALE, spritemaps[o->spritemap_id], 
			            o->anim_curr == ANIM_STEP_INIT ? get_next_anim_frame(o->animid, o->anim_curr) : o->anim_curr, palette);
			obj_visited++;
		}
		video_update_region(SCREEN_MIN_X ,SCREEN_MIN_Y , SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
	}

	ms_used = mspassed(&timer);
	//if(ms_used) printf("repaint took: ms_used %ld\n", ms_used);
	int res = audio_process();
	if(res == -1) music_restart();
	ms_used = mspassed(&timer);
	//if(ms_used) printf("audio processed: %d, ms_used %ld\n", res, ms_used);
	
	long sleepms = 1000/fps - ms_used;
	if(sleepms >= 0) SDL_Delay(sleepms);
	if(mousebutton_down[MB_LEFT]) mousebutton_down[MB_LEFT]++;
	
	tickcounter++;

	char buf [128];
	snprintf(buf, 128, "objs: %d, map x,y %d/%d, index %d, xoff %d, yoff %d", (int) obj_count, 
		 (int)mapsquare.x, (int)mapsquare.y, (int)map->screen_map[mapsquare.y][mapsquare.x], (int)mapscreen_xoff, (int)mapscreen_yoff);
	SDL_WM_SetCaption(buf, 0);
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

static vec2f get_vel_from_direction16(enum direction16 dir, float speed) {
#define VELLUT(a, b, c) [a] = VEC(b, c)
#define ANK90 0.7071067769704655
#define GK90 ANK90
#define ANK45 0.9238795042037964
#define GK45 0.3826834261417389
	static const vec2f vel_lut[] = {
		VELLUT(DIR16_O, 1, 0),
		VELLUT(DIR16_ONO, ANK45, -GK45),
		VELLUT(DIR16_NO, ANK90, -ANK90),
		VELLUT(DIR16_NNO, GK45, -ANK45),
		VELLUT(DIR16_N, 0, -1),
		VELLUT(DIR16_NNW, -GK45, -ANK45),
		VELLUT(DIR16_NW, -ANK90, -ANK90),
		VELLUT(DIR16_WNW, -ANK45, -GK45),
		VELLUT(DIR16_W, -1, 0),
		VELLUT(DIR16_WSW, -ANK45, GK45),
		VELLUT(DIR16_SW, -ANK90, ANK90),
		VELLUT(DIR16_SSW, -GK45, ANK45),
		VELLUT(DIR16_S, 0, 1),
		VELLUT(DIR16_SSO, GK45, ANK45),
		VELLUT(DIR16_SO, ANK90, ANK90),
		VELLUT(DIR16_OSO, ANK45, GK45),
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
	gameobj_start_anim(obj_id, aid);
}

enum map_index choose_mission(void);
//RcB: DEP "mission_select.c"

int main() {
	video_init();
	clear_screen();
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	
	audio_init();
	
	/* background music for mission selection screen */
	music_play(TUNE_MAP);

	if((current_map = choose_mission()) == MI_INVALID) goto dun_goofed;
	
	music_play(TUNE_FIGHTING);

	SDL_ShowCursor(0);

	
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
	
	init_game_objs();
	int player_no = 0;
	int player_id = player_ids[player_no];
	
	game_tick(1);
	
	SDL_Event sdl_event;
	while(1) {
		unsigned need_redraw = 0;
		int weapon_inc = 0;
		while (SDL_PollEvent(&sdl_event)) {
			need_redraw = 0;
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					if((int)mousepos->x != sdl_event.motion.x || (int)mousepos->y != sdl_event.motion.y)
						need_redraw = 1;
					mousepos->x = sdl_event.motion.x;
					mousepos->y = sdl_event.motion.y;
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
					video_cleanup();
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
								toggle_fullscreen();
								SDL_Delay(1);
								game_tick(1);
								need_redraw = 1;
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
