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
#include "spawnmaps.h"

#include <SDL/SDL.h>

#ifndef IN_KDEVELOP_PARSER
#include "../lib/include/bitarray.h"

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

#pragma RcB2 LINK "-lSDL"
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
	assert(p->spritecount);
	vec2f res;
	res.x = palpic_getspritewidth(p) * SCALE / 2;
	res.y = palpic_getspriteheight(p) * SCALE / 2;
	return res;
}

static int player_ids[2];
static int player_kills[2];
static int player_score[2];
static int player_cash[2];
static enum weapon_id player_weapons[2][WP_MAX];
static int weapon_count[2];
static int weapon_active[2]; // index into player_weapons[playerno]
static int player_ammo[2][AMMO_MAX];
static enum weapon_id get_active_weapon_id(int player_no);
static void switch_anim(int obj_id, int aid);
static vec2f get_vel_from_direction(enum direction dir, float speed);
static vec2f get_vel_from_direction16(enum direction16 dir, float speed);
// used by game_tick
static sblist go_player_bullets;
static sblist go_enemy_bullets;
static sblist go_explosions;
static sblist go_enemy_explosions;
static sblist go_enemies;
static sblist go_players;
static sblist go_flames;
static sblist go_enemy_flames;
static sblist go_rockets;
static sblist go_grenades;
static sblist go_enemy_grenades;
static sblist go_vehicles;
static sblist go_mines;
static sblist go_turrets;
static sblist go_bunkers;
static sblist go_boss;
static sblist go_crosshair;
static sblist go_muzzleflash;
static sblist go_blood;
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
static void add_enemy_explosion(uint8_t expl_id) {
	sblist_add(&go_enemy_explosions, &expl_id);
}
static void add_flame(uint8_t id) {
	sblist_add(&go_flames, &id);
}
static void add_grenade(uint8_t id) {
	sblist_add(&go_grenades, &id);
}
static void add_enemy_grenade(uint8_t id) {
	sblist_add(&go_enemy_grenades, &id);
}
static void add_rocket(uint8_t id) {
	sblist_add(&go_rockets, &id);
}
static void add_vehicle(uint8_t id) {
	sblist_add(&go_vehicles, &id);
}
static void add_mine(uint8_t id) {
	sblist_add(&go_mines, &id);
}
static void add_turret(uint8_t id) {
	sblist_add(&go_turrets, &id);
}
static void add_bunker(uint8_t id) {
	sblist_add(&go_bunkers, &id);
}
static void add_boss(uint8_t id) {
	sblist_add(&go_boss, &id);
}
static void add_crosshair(uint8_t id) {
	sblist_add(&go_crosshair, &id);
}
static void add_muzzleflash(uint8_t id) {
	sblist_add(&go_muzzleflash, &id);
}
static void add_blood(uint8_t id) {
	sblist_add(&go_blood, &id);
}
static void add_enemy_flame(uint8_t id) {
	sblist_add(&go_enemy_flames, &id);
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
	            &video, SCALE, spritemaps[SI_WEAPONS], wid, 0);
	
	char buf[16];
	snprintf(buf, 16, "%.6u", player_score[0]);
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

static const int fps = 64;

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

static enum walltype is_wall(vec2f *pos) {
	int x = pos->x;
	int y = pos->y;
	mapscreen_index scr_idx = screen_to_mapscreen(&x, &y);
	/* can happen when a bullet goes partially off-screen */
	if(scr_idx == MAPSCREEN_BLOCKED) return WT_NONE;
	uint8_t spriteno = map_scr[scr_idx].fg.fg[y/16][x/16];
	if(spriteno && walls[map->maptype][spriteno]) return walls[map->maptype][spriteno];
	scr_idx = get_bonus_layer_index(scr_idx);
	if(scr_idx == MAPSCREEN_BLOCKED) return WT_NONE;
	spriteno = map_bonus_scr[scr_idx].fg[y/16][x/16];
	if(spriteno && walls[map->maptype][spriteno]) return walls[map->maptype][spriteno];
	return WT_NONE;
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

#define VSCROLL_TRESHOLD (200-74)
#define HSCROLLR_TRESHOLD (54-6)
#define HSCROLLL_TRESHOLD (192-(78+3))
static int scroll_needed() {
	struct gameobj *player = &objs[player_ids[0]];
	if((mapscrolldir == MS_UP    && player->pos.y - SCREEN_MIN_Y <  VSCROLL_TRESHOLD*SCALE) ||
	   (mapscrolldir == MS_RIGHT && player->pos.x - SCREEN_MIN_X > HSCROLLR_TRESHOLD*SCALE) ||
	   (mapscrolldir == MS_LEFT  && player->pos.x - SCREEN_MIN_X < HSCROLLL_TRESHOLD*SCALE))
		return 1;
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
static void handle_spawns(unsigned scrollstep) {
	assert(scrollstep <= 192);
	unsigned i;
	const struct enemy_spawn_screen *spawn_map = spawn_maps[current_map];
	if(!spawn_map[map_spawn_screen_index].spawns) goto done;
	for(i = 0; i < scrollstep; i++) {
		while(map_spawn_current < spawn_map[map_spawn_screen_index].num_spawns &&
		      map_spawn_line+i >= spawn_map[map_spawn_screen_index].spawns[map_spawn_current].scroll_line) {
			init_enemy(&spawn_map[map_spawn_screen_index].spawns[map_spawn_current]);
			map_spawn_current++;
		}
	}
	done:
	map_spawn_line += scrollstep;
}

static int scroll_map() {
	int ret = 0;
	int scroll_step = 1;
	if(scroll_needed()) {
		if(mapscrolldir == MS_UP) {
			mapscreen_yoff -= scroll_step;
			if(mapscreen_yoff < 0) {
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
						next_screen();
					}
					scroll_step = 0;
				} else {
					next_screen();
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
					next_screen();					
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
					next_screen();
					mapscreen_xoff -= 192;
				}
			} 
			goto handle_objs;
		}
	}
	return ret;
}

static void init_player_once(int player_no) {
	player_score[player_no] = 0;
	player_cash[player_no] = 10000;
}

static int init_player(int player_no) {
	assert(player_no == 0 || player_no == 1);
	int pid = gameobj_alloc();
	gameobj_init(pid, &VEC( SCREEN_MIN_X, SCREEN_MAX_Y - (25 * SCALE) ), &VEC( 0, 0 ), 
		     SI_PLAYERS, player_no == 0 ? ANIM_P1_MOVE_N : ANIM_P2_MOVE_N, player_no == 0 ? OBJ_P1 : OBJ_P2);
	if(pid == -1) return -1;
	player_ids[player_no] = pid;
	weapon_active[player_no] = 0;

	add_player(pid);
	return pid;
}

static vec2f *mousepos;
static int init_crosshair() {
	int id = gameobj_alloc();
	gameobj_init(id, &VEC(VMODE_W/2, VMODE_H/2), &VEC(0,0), SI_CROSSHAIR, ANIM_CROSSHAIR, OBJ_CROSSHAIR);
	if(id == -1) return -1;
	mousepos = &objs[id].pos;
	return id;
}

static int init_blood(vec2f *pos) {
	int id = gameobj_alloc();
	gameobj_init(id, pos, &VEC(0,0), SI_MISC, ANIM_BLOOD, OBJ_BLOOD);
	gameobj_init_bulletdata(id, 4);
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
	return id;
}

static int init_grenade_explosion(vec2f *pos, int from_enemy) {
	const int ticks_per_anim_frame = 4;
	const int expl_anim_frames = 11;
	vec2f grenade_center = get_sprite_center(spritemaps[SI_GRENADE_EXPLOSION]);
	vec2f mypos = vecsub(pos, &grenade_center);
	int id = gameobj_alloc();
	if(id == -1) return -1;
	gameobj_init(id, &mypos, &VEC(0,0), SI_GRENADE_EXPLOSION, ANIM_GRENADE_EXPLOSION, OBJ_GRENADE_EXPLOSION);
	gameobj_init_bulletdata(id, expl_anim_frames*ticks_per_anim_frame -1);
	audio_play_wave_resource(wavesounds[WS_GRENADE_EXPLOSION]);
	if(!from_enemy) add_explosion(id);
	else add_enemy_explosion(id);
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
	ret += init_grenade_explosion(&ax, 0) != -1;
	ret += init_grenade_explosion(&bx, 0) != -1;
	ret += init_big_explosion(&cx) != -1;
	ret += init_big_explosion(&dx) != -1;
	return ret;
}

static int init_flame(vec2f *pos, vec2f *vel, int steps) {
	int id = gameobj_alloc();
	if(id == -1) return -1;
	gameobj_init(id, pos, vel, SI_FLAME, ANIM_FLAME, OBJ_FLAME);
	gameobj_init_bulletdata(id, steps);
	return id;
}

static int init_player_flame(enum direction dir, vec2f *pos, vec2f *vel, int steps) {
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
	return init_flame(&mypos, vel, steps);
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
	add_rocket(id);
	return id;
}


static const struct enemy_route* get_enemy_current_route(int curr_step, const struct enemy_spawn *spawn) {
	int i = ENEMY_MAX_ROUTE -1;
	for(; i >= 0; i--) 
		if(spawn->route[i].shape != ES_INVALID &&
		   curr_step >= spawn->route[i].start_step)
			return &spawn->route[i];
	return 0;
}

static vec2f get_enemy_vel(int curr_step, const struct enemy_spawn *spawn) {
	const struct enemy_route *route = get_enemy_current_route(curr_step, spawn);
	return get_vel_from_direction16(route->dir, (float)route->vel/8.f);
}

static const enum animation_id enemy_animation_lut[] = { 
	[ES_SOLDIER1_DOWN] = ANIM_ENEMY_GUNNER_DOWN,
	[ES_SOLDIER1_RIGHT] = ANIM_ENEMY_GUNNER_RIGHT,
	[ES_SOLDIER1_LEFT] = ANIM_ENEMY_GUNNER_LEFT,
	[ES_SOLDIER2_DOWN] = ANIM_ENEMY_BOMBER_DOWN,
	[ES_SOLDIER2_RIGHT] = ANIM_ENEMY_BOMBER_RIGHT,
	[ES_SOLDIER2_LEFT] = ANIM_ENEMY_BOMBER_LEFT,
	[ES_JEEP] = ANIM_JEEP,
	[ES_TANK_SMALL] = ANIM_TANK_SMALL,
	[ES_TANK_BIG] = ANIM_TANK_BIG,
	[ES_TRANSPORTER] = ANIM_TRANSPORTER,
	[ES_GUNTURRET_MOVABLE_MACHINE] = ANIM_GUNTURRET_MOVABLE_MACHINE_S,
	[ES_GUNTURRET_MOVABLE_MAN] = ANIM_GUNTURRET_MOVABLE_MAN_S,
	[ES_MINE_FLAT] = ANIM_MINE_FLAT,
	[ES_MINE_CROSS] = ANIM_MINE_CROSSED,
	[ES_FLAMETURRET] = ANIM_FLAMETURRET,
	[ES_GUNTURRET_FIXED_SOUTH] = ANIM_GUNTURRET_FIXED_SOUTH,
	[ES_GUNTURRET_FIXED_NORTH] = ANIM_GUNTURRET_FIXED_NORTH,
	[ES_BUNKER_1] = ANIM_BUNKER1,
	[ES_BUNKER_2] = ANIM_BUNKER2,
	[ES_BUNKER_3] = ANIM_BUNKER3,
	[ES_BUNKER_4] = ANIM_BUNKER4,
	[ES_BUNKER_5] = ANIM_BUNKER5,
};

static int init_enemy(const struct enemy_spawn *spawn) {
	const enum objtype enemy_soldier_objtype_lut[] = {
		[0] = OBJ_ENEMY_SHOOTER,
		[1] = OBJ_ENEMY_BOMBER
	};
	const enum objtype enemy_objtype_lut[] = {
		[ES_JEEP] = OBJ_JEEP,
		[ES_TANK_SMALL] = OBJ_TANK_SMALL,
		[ES_TANK_BIG] = OBJ_TANK_BIG,
		[ES_TRANSPORTER] = OBJ_TRANSPORTER,
		[ES_GUNTURRET_MOVABLE_MACHINE] = OBJ_GUNTURRET_MOVABLE_MACHINE,
		[ES_GUNTURRET_MOVABLE_MAN] = OBJ_GUNTURRET_MOVABLE_MAN,
		[ES_MINE_FLAT] = OBJ_MINE_FLAT,
		[ES_MINE_CROSS] = OBJ_MINE_CROSSED,
		[ES_FLAMETURRET] = OBJ_FLAMETURRET,
		[ES_GUNTURRET_FIXED_SOUTH] = OBJ_GUNTURRET_FIXED_SOUTH,
		[ES_GUNTURRET_FIXED_NORTH] = OBJ_GUNTURRET_FIXED_NORTH,
		[ES_BUNKER_1] = OBJ_BUNKER1,
		[ES_BUNKER_2] = OBJ_BUNKER2,
		[ES_BUNKER_3] = OBJ_BUNKER3,
		[ES_BUNKER_4] = OBJ_BUNKER4,
		[ES_BUNKER_5] = OBJ_BUNKER5,
		[ES_BOSS] = OBJ_BOSS,
	};
	const enum animation_id boss_animation_lut[] = {
		[0] = ANIM_BOSS1,
		[1] = ANIM_BOSS2,
		[2] = ANIM_BOSS3,
		[3] = ANIM_BOSS4,
		[4] = ANIM_BOSS5,
		[5] = ANIM_BOSS6,
		[6] = ANIM_BOSS7,
		[7] = ANIM_BOSS8,
		[8] = ANIM_BOSS9,
		[9] = ANIM_BOSS10,
		[10] = ANIM_BOSS11,
		[11] = ANIM_BOSS12,
	};
	const enum sprite_index enemy_soldier_sprite_lut[] = {
		[ET_ASIAN] = SI_ENEMY_ASIAN,
		[ET_WESTERN] = SI_ENEMY_WESTERN,
	};
	const enum sprite_index enemy_sprite_lut[] = { 
		[ES_JEEP] = SI_VEHICLES_SMALL,
		[ES_TANK_SMALL] = SI_VEHICLES_MEDIUM,
		[ES_TANK_BIG] = SI_VEHICLES_BIG,
		[ES_TRANSPORTER] = SI_VEHICLES_BIG,
		[ES_BUNKER_1] = SI_BUNKERS,
		[ES_BUNKER_2] = SI_BUNKERS,
		[ES_BUNKER_3] = SI_BUNKERS,
		[ES_BUNKER_4] = SI_BUNKERS,
		[ES_BUNKER_5] = SI_BUNKERS,
		[ES_GUNTURRET_MOVABLE_MACHINE] = SI_GUNTURRET,
		[ES_GUNTURRET_MOVABLE_MAN] = SI_GUNTURRET,
		[ES_MINE_FLAT] = SI_MINES,
		[ES_MINE_CROSS] = SI_MINES,
		[ES_FLAMETURRET] = SI_MINES,
		[ES_GUNTURRET_FIXED_SOUTH] = SI_MINES,
		[ES_GUNTURRET_FIXED_NORTH] = SI_MINES,
		[ES_BOSS] = SI_BOSSES,
	};
	
	vec2f spawnpos = VEC(SCREEN_MIN_X + spawn->x*SCALE, SCREEN_MIN_Y + spawn->y*SCALE);
	int id = gameobj_alloc();
	if(id == -1) return -1;
	const struct enemy_route* route_curr = get_enemy_current_route(0, spawn);
	vec2f vel = get_enemy_vel(0, spawn);
	
	int is_soldier = route_curr->shape <= ES_SOLDIER2_RIGHT;
	int is_boss = route_curr->shape == ES_BOSS;
	enum sprite_index spriteid;
	enum objtype objid;
	enum animation_id animid;
	if(is_soldier) {
		spriteid = enemy_soldier_sprite_lut[map->enemy_type];
		objid = enemy_soldier_objtype_lut[spawn->weapon];
	} else {
		spriteid = enemy_sprite_lut[route_curr->shape];
		objid = enemy_objtype_lut[route_curr->shape];
	}
	if(is_boss) animid = boss_animation_lut[map->boss_id];
	else animid = enemy_animation_lut[route_curr->shape];
	
	gameobj_init(id, &spawnpos, &vel, spriteid, animid, objid);
	objs[id].objspecific.enemy.curr_step = 0;
	objs[id].objspecific.enemy.spawn = spawn;
	switch(objid) {
		case OBJ_BOSS:
			add_boss(id);
			break;
		case OBJ_BUNKER1: case OBJ_BUNKER2: case OBJ_BUNKER3:
		case OBJ_BUNKER4: case OBJ_BUNKER5:
			add_bunker(id);
			break;
		case OBJ_GUNTURRET_MOVABLE_MACHINE:
		case OBJ_GUNTURRET_MOVABLE_MAN:
		case OBJ_FLAMETURRET: case OBJ_GUNTURRET_FIXED_NORTH:
		case OBJ_GUNTURRET_FIXED_SOUTH:
			add_turret(id);
			break;
		case OBJ_MINE_CROSSED: case OBJ_MINE_FLAT:
			add_mine(id);
			break;
		case OBJ_JEEP: case OBJ_TRANSPORTER:
		case OBJ_TANK_BIG: case OBJ_TANK_SMALL:
			add_vehicle(id);
			break;
		default:
			add_enemy(id);
	}
	return id;
}

static void remove_enemy(int id) {
	enum objtype objid = objs[id].objtype;
	switch(objid) {
		case OBJ_JEEP: case OBJ_TRANSPORTER:
		case OBJ_TANK_BIG: case OBJ_TANK_SMALL:
			golist_remove(&go_vehicles, id);
			break;
		default:
			golist_remove(&go_enemies, id);
	}
	gameobj_free(id);
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

static enum direction16 get_direction16_from_direction(enum direction dir) {
	static const enum direction16 dir16_transl_tab[] = {
		[DIR_N] = DIR16_N, [DIR_NO] = DIR16_NO, [DIR_O] = DIR16_O, [DIR_SO] = DIR16_SO, 
		[DIR_S] = DIR16_S, [DIR_SW] = DIR16_SW, [DIR_W] = DIR16_W, [DIR_NW] = DIR16_NW,
	};
	assert(dir != DIR_INVALID);
	return dir16_transl_tab[dir];
}

static enum weapon_id get_active_weapon_id(int player_no) {
	return player_weapons[player_no][weapon_active[player_no]];
}

static const struct weapon* get_active_weapon(int player_no) {
	return &weapons[get_active_weapon_id(player_no)];
}
static enum direction16 get_shotdirection_from_enemy(int curr_step, const struct enemy_spawn *spawn) {
	const struct enemy_route* r = get_enemy_current_route(curr_step, spawn);
	switch(r->shape) {
		case ES_SOLDIER1_DOWN: case ES_SOLDIER2_DOWN:
			return DIR16_S;
		case ES_SOLDIER1_LEFT: case ES_SOLDIER2_LEFT:
			return DIR16_W;
		case ES_SOLDIER1_RIGHT: case ES_SOLDIER2_RIGHT:
			return DIR16_O;
		default:
			assert(0);
	}
}

static void enemy_fire_bullet(enum direction16 dir, int steps, enum enemy_weapon wpn, vec2f *pos) {
	vec2f vel = get_vel_from_direction16(dir, 1.75);
	int id;
	if(wpn == EW_GUN) {
		id = init_bullet(pos, &vel, steps);
		if(id != -1) add_ebullet(id);
	} else if (wpn == EW_GRENADE) {
		id = init_grenade(pos, &vel, steps);
		if(id != -1) add_enemy_grenade(id);
	} else {
		id = init_flame(pos, &vel, steps);
		if(id != -1) add_enemy_flame(id);
	}
}

static int get_crosshair_id(void) {
	assert(sblist_getsize(&go_crosshair));
	uint8_t *id = sblist_get(&go_crosshair, 0);
	return *id;
}

static void fire_bullet(int player_no) {
	int id;
	const struct weapon *pw = get_active_weapon(player_no);
	if(player_ammo[player_no][pw->ammo] == 0) return;
	vec2f from = get_gameobj_center(player_ids[player_no]);
	//get_anim_from_vel(0, objs[player].
	vec2f to = get_gameobj_center(get_crosshair_id());
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
			id = init_flash(&ffrom, dir);
			if(id != -1) add_muzzleflash(id);
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
			id = init_rocket(dir, &from, &vel, steps);
			break;
		case ST_BULLET:
			id = init_bullet(&from, &vel, steps);
			if(id != -1) add_pbullet(id);
			break;
		case ST_FLAMES:
			id = init_player_flame(dir, &from, &vel, steps);
			if(id != -1) add_flame(id);
			break;
		case ST_GRENADE:
			id = init_grenade(&from, &vel, steps);
			add_grenade(id);
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
	sblist_init(&go_crosshair, 1, 4);
	sblist_init(&go_players, 1, 4);
	sblist_init(&go_muzzleflash, 1, 4);
	sblist_init(&go_player_bullets, 1, 32);
	sblist_init(&go_flames, 1, 32);
	sblist_init(&go_enemy_bullets, 1, 32);
	sblist_init(&go_explosions, 1, 16);
	sblist_init(&go_enemy_explosions, 1, 16);
	sblist_init(&go_grenades, 1, 16);
	sblist_init(&go_enemy_grenades, 1, 16);
	sblist_init(&go_rockets, 1, 8);
	sblist_init(&go_enemies, 1, 32);
	sblist_init(&go_vehicles, 1, 4);
	sblist_init(&go_mines, 1, 4);
	sblist_init(&go_turrets, 1, 8);
	sblist_init(&go_bunkers, 1, 4);
	sblist_init(&go_boss, 1, 4);
	sblist_init(&go_blood, 1, 16);
	sblist_init(&go_enemy_flames, 1, 16);
	init_player(0);
	add_crosshair(init_crosshair());
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
	switch(objs[id].objtype) {
		case OBJ_P1:
			return ANIM_P1_DIE;
		case OBJ_P2:
			return ANIM_P2_DIE;
		case OBJ_JEEP:
			return ANIM_JEEP_DESTROYED;
		case OBJ_TANK_SMALL:
			return ANIM_TANK_SMALL_DESTROYED;
		case OBJ_TANK_BIG:
			return ANIM_TANK_BIG_DESTROYED;
		case OBJ_TRANSPORTER:
			return ANIM_TRANSPORTER_DESTROYED;
		case OBJ_ENEMY_BOMBER:
			return ANIM_ENEMY_BOMBER_DIE;
		case OBJ_ENEMY_SHOOTER:
			return ANIM_ENEMY_GUNNER_DIE;
		case OBJ_BUNKER1: case OBJ_BUNKER2: case OBJ_BUNKER3:
		case OBJ_BUNKER4: case OBJ_BUNKER5:
			return ANIM_BUNKER_DESTROYED;
		case OBJ_GUNTURRET_MOVABLE_MACHINE:
			return ANIM_GUNTURRET_MOVABLE_MACHINE_DESTROYED;
		case OBJ_GUNTURRET_MOVABLE_MAN:
			return ANIM_GUNTURRET_MOVABLE_MAN_DESTROYED;
		default:
			return ANIM_INVALID;
	}
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

static int remove_explosives(sblist *list) {
	int res = 0;
	uint8_t *item_id;
	ssize_t li;
	sblist_iter_counter2s(list, li, item_id) {
		struct gameobj *go = &objs[*item_id];
		if(go->objspecific.bullet.step_curr >= go->objspecific.bullet.step_max) {
			if(go->objtype == OBJ_GRENADE) init_grenade_explosion(&go->pos, list == &go_enemy_grenades);
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

static int remove_offscreen_objects(sblist *list) {
	int res = 0;
	uint8_t *item_id;
	ssize_t li;
	sblist_iter_counter2s(list, li, item_id) {
		assert(obj_slot_used[*item_id]);
		struct gameobj *go = &objs[*item_id];
		assert((int) go->spritemap_id < SI_MAX);
		const struct palpic *p = spritemaps[go->spritemap_id];
		assert(p->spritecount);
		int h = palpic_getspriteheight(p), w = palpic_getspritewidth(p);
		if(go->pos.x < SCREEN_MIN_X-w*SCALE || go->pos.x > SCREEN_MAX_X ||
		   go->pos.y < SCREEN_MIN_Y-h*SCALE || go->pos.y > SCREEN_MAX_Y) {
			res = 1;
			dprintf(2, "offscreen: removed gameobj %d\n", (int) *item_id);
			gameobj_free(*item_id);
			sblist_delete(list, li);
			li--;
		}
	}
	return res;
}

static int get_sprite_number(int id) {
	struct gameobj *o = &objs[id];
	return o->anim_curr == ANIM_STEP_INIT ? get_next_anim_frame(o->animid, o->anim_curr) : o->anim_curr;
}

static int is_death_anim(enum animation_id anim) {
	switch(anim) {
		case ANIM_ENEMY_BOMBER_DIE:
		case ANIM_ENEMY_GUNNER_DIE:
		case ANIM_ENEMY_BURNT:
		case ANIM_P1_DIE:
		case ANIM_P2_DIE:
		case ANIM_GUNTURRET_MOVABLE_MAN_DESTROYED:
		case ANIM_GUNTURRET_MOVABLE_MACHINE_DESTROYED:
		case ANIM_BUNKER_DESTROYED:
		case ANIM_JEEP_DESTROYED:
		case ANIM_TANK_BIG_DESTROYED:
		case ANIM_TANK_SMALL_DESTROYED:
		case ANIM_TRANSPORTER_DESTROYED:
			return 1;
		default: 
			return 0;
	}
}

static int overlap(int id1, int id2) {
	struct gameobj *o1 = &objs[id1];
	struct gameobj *o2 = &objs[id2];
	const struct palpic* p1 = spritemaps[o1->spritemap_id];
	const struct palpic* p2 = spritemaps[o2->spritemap_id];
	
	vec2f vec = velocity(&o1->pos, &o2->pos);
	float mh = o1->pos.y < o2->pos.y ? palpic_getspriteheight(p1) : palpic_getspriteheight(p2);
	float mw = o1->pos.x < o2->pos.x ? palpic_getspritewidth(p1) : palpic_getspritewidth(p2);
	mh*=SCALE, mw*=SCALE;
	return fabs(vec.x) < mw && fabs(vec.y) < mh;
}

static int masks_collide(int id1, int id2) {
	struct gameobj *a = &objs[id1];
	struct gameobj *b = &objs[id2];
	const struct palpic* pa = spritemaps[a->spritemap_id];
	const struct palpic* pb = spritemaps[b->spritemap_id];
	int ax = a->pos.x/SCALE, ay = a->pos.y/SCALE,
	    aw = palpic_getspritewidth(pa), ah = palpic_getspriteheight(pa);
	int bx = b->pos.x/SCALE, by = b->pos.y/SCALE,
	    bw = palpic_getspritewidth(pb), bh = palpic_getspriteheight(pb);
    
	/* x: normalized start position */
	int xx = MIN(ax, bx), xy = MIN(ay, by);
	/* normalize coordinates to 0 */
	ax -= xx, ay -= xy, bx -= xx, by -= xy;
	/* o: upper left point of the overlapping region */
	int ox = MAX(ax, bx), oy = MAX(ay, by);
	/* e: lower right point of the overlapping region */
	int ex = MIN(ax+aw, bx+bw), ey = MIN(ay+ah, by+bh);
	/* vector o -> e */
	int oex = ex - ox, oey = ey - oy;
	/* (s)tart and (e)nd coordinates of the overlapping regions in both rects */
	int asx = ox - ax, asy = oy - ay;
	int bsx = ox - bx, bsy = oy - by;
	int aex = asx + oex, bex = bsx + oex;
	int aey = asy + oey, bey = bsy + oey;
	assert(asx >= 0); assert(asy >= 0);
	assert(bsx >= 0); assert(bsy >= 0);
	if(!aex || !bex || !aey || !bey) return 0;
	assert(aex > 0); assert(bex > 0);
	assert(aey > 0); assert(bey > 0);
	int xa, ya, xb, yb;
	const uint8_t *da = palpic_getspritedata(pa, get_sprite_number(id1)), 
	              *db = palpic_getspritedata(pb, get_sprite_number(id2));
	assert(da); assert(db);
	for(ya = asy, yb = bsy; ya < aey && yb < bey; ya++, yb++)
		for(xa = asx, xb = bsx; xa < aex && xb < bex ; xa++, xb++)
			if(da[ya*aw+xa] && db[yb*bw+xb]) return 1;
	return 0;
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
		BS_TOUCH,
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
		} else if(bullet_list == &go_vehicles || bullet_list == &go_enemies ||
			  bullet_list == &go_boss || bullet_list == &go_mines) {
			bullet_subtybe = BS_TOUCH;
		}
		
		vec2f bullet_center = get_gameobj_center(*bullet_id);
		if(bullet_list == &go_player_bullets || bullet_list == &go_flames) {
			if(is_wall(&bullet_center) == WT_SOLID) goto remove_bullet;
		}
		
		const float bullet_radius[] = { [BS_BULLET] = 1.f, [BS_FLAME] = 6.f, 
		                                [BS_GRENADE_EXPL] = 16.f, [BS_BIG_EXPL] = 19.f, [BS_TOUCH] = 8.f, };

		size_t lj;
		uint8_t *target_id;
		sblist_iter_counter2(target_list, lj, target_id) {
			struct gameobj *target = &objs[*target_id];
			if(is_death_anim(target->animid) && target_list != &go_vehicles) continue;
			if(bullet_subtybe == BS_TOUCH && 
			   overlap(*target_id, *bullet_id) &&
			   masks_collide(*target_id, *bullet_id)) {
				dprintf(2, "hit2\n");
				if(bullet_list == &go_boss) return 2;
				goto hit;
			}
			
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
							if(target_list == &go_vehicles) {
								audio_play_wave_resource(wavesounds[WS_DROPSHOT]);
								goto remove_bullet;
							}
							player_score[0] += 50;
							player_kills[0]++;
						} else if (bullet_list == &go_rockets) {
							init_rocket_explosion(&target->pos);
							goto remove_bullet;
						} else if(bullet->objtype == OBJ_GRENADE_EXPLOSION) {
							// grenade explosion has no effect on vehicles and bunkers.
							if(target_list == &go_vehicles || target_list == &go_bunkers)
								goto next_bullet;
						} else if(bullet->objtype == OBJ_MINE_CROSSED || bullet->objtype == OBJ_MINE_FLAT) {
							init_big_explosion(&target->pos);
							goto remove_bullet;
						}
						enum animation_id death_anim = (bullet_subtybe == BS_FLAME && target_list == &go_enemies) ?
						                               ANIM_ENEMY_BURNT : get_die_anim(*target_id);
						if(death_anim == ANIM_INVALID) {
							gameobj_free(*target_id);
							sblist_delete(target_list, lj);
							lj--;
							goto next_target;
						}
						switch_anim(*target_id, death_anim);
						target->vel = VEC(0,0);
						if(target->objtype == OBJ_ENEMY_BOMBER || target->objtype == OBJ_ENEMY_SHOOTER) {
							const enum wavesound_id wid[] = { WS_SCREAM, WS_SCREAM2 };
							audio_play_wave_resource(wavesounds[wid[rand()%2]]);
							if(bullet_subtybe == BS_BULLET) {
								vec2f bloodpos = vecadd(&target->pos, &VEC(0, (2+rand()%7)*SCALE));
								/* original displays at 0,8 but i prefer a random effect */
								//vec2f bloodpos = vecadd(&target->pos, &VEC(0, 8*SCALE));
								int id = init_blood(&bloodpos);
								if(id != -1) add_blood(id);
							}
						}
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
			next_target:;
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

static void switch_enemy_shape(int objid, const struct enemy_route* r) {
	switch_anim(objid, enemy_animation_lut[r->shape]);
}

static void draw_golist(sblist *list) {
	size_t i;
	uint8_t *itemid;
	sblist_iter_counter2(list, i, itemid) {
		assert(obj_slot_used[*itemid]);
		struct gameobj *o = &objs[*itemid];
		const prgb *palette;
		switch(o->objtype) {
			case OBJ_BLOOD:
				// original blood color is bb5511 but that is hardly visible
				// palette = (prgb[]) {PRGB(0,0,0), PRGB(0xbb, 0x55, 0x11)};
				palette = (const prgb[]) {PRGB(0,0,0), PRGB(0xff, 0x0, 0x0)};
				break;
			case OBJ_ENEMY_BOMBER: case OBJ_ENEMY_SHOOTER:
				palette = map->enemy_palette;
				break;
			default:
				palette = 0;
		}
		blit_sprite(o->pos.x, o->pos.y, &video,
		            SCALE, spritemaps[o->spritemap_id],
		            get_sprite_number(*itemid),
		            palette);
	}
}

static void draw_gameobjs(void) {
	draw_golist(&go_mines);
	draw_golist(&go_turrets);
	draw_golist(&go_bunkers);
	draw_golist(&go_vehicles);
	draw_golist(&go_enemies);
	draw_golist(&go_blood);
	draw_golist(&go_enemy_bullets);
	draw_golist(&go_boss);
	draw_golist(&go_rockets);
	draw_golist(&go_players);
	draw_golist(&go_player_bullets);
	draw_golist(&go_enemy_explosions);
	draw_golist(&go_flames);
	draw_golist(&go_enemy_flames);
	draw_golist(&go_explosions);
	draw_golist(&go_grenades);
	draw_golist(&go_enemy_grenades);
	draw_golist(&go_crosshair);
	draw_golist(&go_muzzleflash);
}

static void process_soldiers(void) {
	uint8_t *itemid;
	sblist_iter(&go_enemies, itemid) {
		struct gameobj *go = &objs[*itemid];
		assert(go->objtype == OBJ_ENEMY_SHOOTER || go->objtype == OBJ_ENEMY_BOMBER);
		if (tickcounter % 4 == go->anim_frame) {
			const struct enemy_route *rc = get_enemy_current_route(go->objspecific.enemy.curr_step, go->objspecific.enemy.spawn);
			if(rc->vel) {
				go->objspecific.enemy.curr_step++;
				if(enemy_fires(&go->objspecific.enemy)) {
					vec2f from = get_gameobj_center(*itemid);
					enum direction16 dir = get_shotdirection_from_enemy(go->objspecific.enemy.curr_step, go->objspecific.enemy.spawn);
					enemy_fire_bullet(dir, 41, go->objspecific.enemy.spawn->weapon, &from);
				}
				const struct enemy_route *rn = get_enemy_current_route(go->objspecific.enemy.curr_step, go->objspecific.enemy.spawn);
				if(rn->shape != rc->shape) switch_enemy_shape(*itemid, rn);
			}
		}
		if(!is_death_anim(go->animid)) go->vel = get_enemy_vel(go->objspecific.enemy.curr_step, go->objspecific.enemy.spawn);
		else go->vel = VEC(0, 0);
	}
}

static enum animation_id get_turret_anim_from_dir(int objid, enum direction dir) {
	static const enum animation_id man_anim[] = {
		[DIR_N] = ANIM_GUNTURRET_MOVABLE_MAN_N,
		[DIR_NO] = ANIM_GUNTURRET_MOVABLE_MAN_NO,
		[DIR_O] = ANIM_GUNTURRET_MOVABLE_MAN_O,
		[DIR_SO] = ANIM_GUNTURRET_MOVABLE_MAN_SO,
		[DIR_S] = ANIM_GUNTURRET_MOVABLE_MAN_S,
		[DIR_SW] = ANIM_GUNTURRET_MOVABLE_MAN_SW,
		[DIR_W] = ANIM_GUNTURRET_MOVABLE_MAN_W,
		[DIR_NW] = ANIM_GUNTURRET_MOVABLE_MAN_NW,
	};
	static const enum animation_id mach_anim[] = {
		[DIR_N] = ANIM_GUNTURRET_MOVABLE_MACHINE_N,
		[DIR_NO] = ANIM_GUNTURRET_MOVABLE_MACHINE_NO,
		[DIR_O] = ANIM_GUNTURRET_MOVABLE_MACHINE_O,
		[DIR_SO] = ANIM_GUNTURRET_MOVABLE_MACHINE_SO,
		[DIR_S] = ANIM_GUNTURRET_MOVABLE_MACHINE_S,
		[DIR_SW] = ANIM_GUNTURRET_MOVABLE_MACHINE_SW,
		[DIR_W] = ANIM_GUNTURRET_MOVABLE_MACHINE_W,
		[DIR_NW] = ANIM_GUNTURRET_MOVABLE_MACHINE_NW,
	};
	const enum animation_id *lut = objs[objid].objtype == OBJ_GUNTURRET_MOVABLE_MAN ? man_anim : mach_anim;
	return lut[dir];
}

static int editor_mode;
static int process_turrets(sblist* list) {
	if(editor_mode) return 0;
	int res = 0;
	uint8_t *itemid;
	sblist_iter(list, itemid) {
		struct gameobj *go = &objs[*itemid];
		if(is_death_anim(go->animid)) continue;
		enum direction16 dir = DIR16_S;
		enum enemy_weapon ew = EW_GUN;
		int steps = 92;
		vec2f from;
		switch(go->objtype) {
			case OBJ_GUNTURRET_FIXED_NORTH:
				dir = DIR16_N;
			case OBJ_GUNTURRET_FIXED_SOUTH:
				from = get_gameobj_center(*itemid);
				shottest:
				if(rand()%8 == 0) {
					shot:
					enemy_fire_bullet(dir, steps, ew, &from);
					res = 1;
				}
				break;
			case OBJ_FLAMETURRET:
				ew = EW_FLAME;
				steps = 48;
				
				if(objs[player_ids[0]].pos.y <= (192-25)*SCALE/2) dir = DIR16_N;
				from = go->pos;
				from.y += (dir == DIR16_N ? -8*SCALE : 8*SCALE);
				
				/* abusing curr_step variable to save position in a burst of flames */
				if(go->objspecific.enemy.curr_step && go->objspecific.enemy.curr_step < 16)
					goto do_flame;
				else if(go->objspecific.enemy.curr_step)
					go->objspecific.enemy.curr_step = 0;
				
				if(objs[player_ids[0]].pos.x < go->pos.x-32*SCALE || objs[player_ids[0]].pos.x > go->pos.x + (16+32)*SCALE)
					break;
				if(rand()%8 == 0) {
					do_flame:
					go->objspecific.enemy.curr_step++;
					goto shot;
				}
				break;
			case OBJ_GUNTURRET_MOVABLE_MAN:
			case OBJ_GUNTURRET_MOVABLE_MACHINE: {
				from = get_gameobj_center(*itemid);
				vec2f p_center = get_gameobj_center(player_ids[0]);
				vec2f vel = velocity(&from, &p_center);
				enum direction dir8 = get_direction_from_vec(&vel);
				dir = get_direction16_from_direction(dir8);
				switch_anim(*itemid, get_turret_anim_from_dir(*itemid, dir8));
				goto shottest;
				break;
			}
			case OBJ_TANK_SMALL:
			case OBJ_BUNKER1:
			case OBJ_BUNKER2:
			case OBJ_BUNKER3:
			case OBJ_BUNKER4:
			case OBJ_BUNKER5: {
				const vec2f *bunkerpos;
				const enum direction16 *bunkerdir;
				unsigned count, sec;
				static const enum direction16 bunker5_dir[] = {
					[0] = DIR16_N, [1] = DIR16_NO, [2] = DIR16_O, [3] = DIR16_SO, 
					[4] = DIR16_S, [5] = DIR16_SW, [6] = DIR16_W, [7] = DIR16_NW,
				};
				static const enum direction16 bunker1_dir[] = {
					[0] = DIR16_NNW, [1] = DIR16_NNO, [2] = DIR16_NO, [3] = DIR16_O, 
					[4] = DIR16_SO, [5] = DIR16_SSO, [6] = DIR16_SSW, [7] = DIR16_SW,
					[8] = DIR16_W, [9] = DIR16_NW,
				};
				static const vec2f bunker5_pos[] = {
					[0] = VEC(9,-8), [1] = VEC(18,-6), [2] = VEC(26,2), [3] = VEC(22,10),
					[4] = VEC(9,16), [5] = VEC(-5,13), [6] = VEC(-7,2), [7] = VEC(-5,-6),
				};
				static const vec2f bunker2_pos[] = {
					[0] = VEC(15,-2), [1] = VEC(27,3), [2] = VEC(31,12), [3] = VEC(28,23),
					[4] = VEC(15,27), [5] = VEC(2,23), [6] = VEC(0,12), [7] = VEC(4,2),
				};
				static const vec2f bunker4_pos[] = {
					[0] = VEC(13,0), [1] = VEC(25,1), [2] = VEC(29,10), [3] = VEC(26,21),
					[4] = VEC(13,25), [5] = VEC(0,21), [6] = VEC(-2,10), [7] = VEC(2,0),
				};
				static const vec2f bunker1_pos[] = {
					[0] = VEC(6,-6), [1] = VEC(18,-6), [2] = VEC(26,2), [3] = VEC(26,12),
					[4] = VEC(26,16), [5] = VEC(20,24), [6] = VEC(6,24), [7] = VEC(0,20),
					[8] = VEC(0,12), [9] = VEC(0,2),
				};
				static const enum direction16 tank_dir[] = {
					[0] = DIR16_WSW, [1] = DIR16_OSO, [2] = DIR16_WSW, [3] = DIR16_OSO, 
					[4] = DIR16_WSW, [5] = DIR16_OSO, [6] = DIR16_SSW, [7] = DIR16_SSO,
				};
				static const vec2f tank_pos[] = {
					[0] = VEC(10,8), [1] = VEC(38,8), [2] = VEC(10,20), [3] = VEC(38,20),
					[4] = VEC(10,32), [5] = VEC(38,32), [6] = VEC(16,40), [7] = VEC(32,40),
				};
				unsigned b, dist = 28;
				switch(go->objtype) {
					case OBJ_BUNKER1:
						ew = EW_GRENADE;
						bunkerpos = bunker1_pos;
						bunkerdir = bunker1_dir;
						b = 0;
						count = 10;
						sec = 2;
						break;
					case OBJ_TANK_SMALL:
						if(tickcounter % 8) break;
						ew = EW_GUN;
						dist = 128;
						bunkerpos = tank_pos;
						bunkerdir = tank_dir;
						// FIXME: the last 2 shoots (6+7) should be fired at the same time
						goto bunker_circle_shoot;
					case OBJ_BUNKER2:
						if(tickcounter % 8) break;
						ew = EW_GUN;
						dist = 128;
						bunkerpos = bunker2_pos;
						bunkerdir = bunker5_dir;
						goto bunker_circle_shoot;
					case OBJ_BUNKER4:
						if(tickcounter % /*(fps*3.5)/8*/ 24) break;
						ew = EW_GRENADE;
						dist = 32;
						bunkerpos = bunker4_pos;
						bunkerdir = bunker5_dir;
						bunker_circle_shoot:;
						b = go->objspecific.enemy.curr_step;
						count = b+1;
						if(++go->objspecific.enemy.curr_step >= 8) go->objspecific.enemy.curr_step = 0;
						goto bunkerloop;
					case OBJ_BUNKER3:
						ew = EW_GUN;
						bunkerpos = bunker2_pos;
						bunkerdir = bunker5_dir;
						b = 0;
						count = 8;
						dist = 128;
						sec = 1;
						break;
					case OBJ_BUNKER5:
						ew = EW_FLAME;
						bunkerpos = bunker5_pos;
						bunkerdir = bunker5_dir;
						b = 0;
						count = 8;
						sec = 3;
						break;
					default:;
				}
				if(tickcounter > (uint32_t) go->objspecific.enemy.curr_step + fps*sec) {
					go->objspecific.enemy.curr_step = tickcounter;
					bunkerloop:;
					for(; b < count; b++) {
						from = go->pos;
						from.x += bunkerpos[b].x*SCALE;
						from.y += bunkerpos[b].y*SCALE;
						enemy_fire_bullet(bunkerdir[b], dist, ew, &from);
					}
					res = 1;
				}
				break;
			}
			default:;
		}
	}
	return res;
}

static int move_gameobjs(void) {
	int res = 0;
	size_t i, obj_visited;
	for(i = 0, obj_visited = 0; obj_visited < obj_count && i < OBJ_MAX; i++) {
		if(obj_slot_used[i]) {
			struct gameobj *go = &objs[i];
			obj_visited++;
			if(go->anim_curr == ANIM_STEP_INIT) res = 1;
			if(go->vel.x != 0 || go->vel.y != 0) {
				vec2f oldpos = go->pos;
				go->pos.x += go->vel.x;
				go->pos.y += go->vel.y;
				
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
				
				res = 1;
			}
			if((go->objtype == OBJ_ENEMY_BOMBER || go->objtype == OBJ_ENEMY_SHOOTER) &&
			   go->anim_curr == animations[go->animid].last &&
					  (go->animid == ANIM_ENEMY_BOMBER_DIE || 
					   go->animid == ANIM_ENEMY_GUNNER_DIE || 
					   go->animid == ANIM_ENEMY_BURNT)) {
						dprintf(2, "removed enemy from %.2f,%.2f\n", go->pos.x, go->pos.y);
						gameobj_free(i);
						golist_remove(&go_enemies, i);
						res = 1;
						continue;
				
			}
		}
	}
	return res;
}

static void game_update_caption(void) {
	char buf [128];
	snprintf(buf, 128, "objs: %d, map x,y %d/%d, index %d, xoff %d, yoff %d, spawnscreen %d, line %d", (int) obj_count, 
		 (int)mapsquare.x, (int)mapsquare.y, (int)map->screen_map[mapsquare.y][mapsquare.x], 
		 (int)mapscreen_xoff, (int)mapscreen_yoff, (int)map_spawn_screen_index, (int) map_spawn_line);
	SDL_WM_SetCaption(buf, 0);	
}
static void(*update_caption)(void) = game_update_caption;

/* returns 1 if level finished */
static int game_tick(int force_redraw) {
	int need_redraw = force_redraw;
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

	if(advance_animations()) need_redraw = 1;
	if(hit_bullets(&go_player_bullets, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_player_bullets, &go_vehicles)) need_redraw = 1;
	if(hit_bullets(&go_flames, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_enemy_flames, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_rockets, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_rockets, &go_vehicles)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_enemies)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_vehicles)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_mines)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_turrets)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_bunkers)) need_redraw = 1;
	if(hit_bullets(&go_explosions, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_enemy_explosions, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_enemy_bullets, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_enemy_flames, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_vehicles, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_enemies, &go_players)) need_redraw = 1;
	if(hit_bullets(&go_mines, &go_players)) need_redraw = 1;
	
	int ret, level_finished = 0;
	if((ret = hit_bullets(&go_boss, &go_players)) == 2) level_finished = 1;
	else if(ret == 1) need_redraw = 1;
	
	if(remove_bullets(&go_player_bullets)) need_redraw = 1;
	if(remove_bullets(&go_flames)) need_redraw = 1;
	if(remove_bullets(&go_explosions)) need_redraw = 1;
	if(remove_bullets(&go_enemy_explosions)) need_redraw = 1;
	if(remove_bullets(&go_enemy_bullets)) need_redraw = 1;
	if(remove_bullets(&go_enemy_flames)) need_redraw = 1;
	if(remove_bullets(&go_muzzleflash)) need_redraw = 1;
	if(remove_bullets(&go_blood)) need_redraw = 1;
	if(remove_explosives(&go_grenades)) need_redraw = 1;
	if(remove_explosives(&go_enemy_grenades)) need_redraw = 1;
	if(remove_explosives(&go_rockets)) need_redraw = 1;
	if(tickcounter % 2 == 0 && scroll_map()) need_redraw = 1;
	
	process_soldiers();
	if(tickcounter % 4 == 0 && process_turrets(&go_turrets)) need_redraw = 1;
	if(tickcounter % 4 == 0 && process_turrets(&go_bunkers)) need_redraw = 1;
	if(tickcounter % 4 == 0 && process_turrets(&go_vehicles)) need_redraw = 1;

	if(move_gameobjs()) need_redraw = 1;
	
	if(remove_offscreen_objects(&go_enemies)) need_redraw = 1;
	if(remove_offscreen_objects(&go_vehicles)) need_redraw = 1;
	if(remove_offscreen_objects(&go_mines)) need_redraw = 1;
	if(remove_offscreen_objects(&go_turrets)) need_redraw = 1;
	if(remove_offscreen_objects(&go_bunkers)) need_redraw = 1;
	
	long ms_used = 0;
	struct timeval timer;
	gettimestamp(&timer);
	if(need_redraw) {
		draw_map();
		draw_gameobjs();
		draw_status_bar();
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
	update_caption();
	
	return level_finished;
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

enum map_index choose_mission(uint8_t* completed);
#pragma RcB2 DEP "mission_select.c"
#include "enemytag.c"

static uint8_t mission_completed[MI_MAX];

#include <limits.h>

static void game_delay(int s) {
	/* wait for s frames while continuing to play music, 
	 * if s == -1 return as soon as music finished */
	int x = s;
	if(x == -1) x = INT_MAX;
	while(x){
		int r = audio_process();
		if(s == -1 && r == -1) return;
		SDL_Delay(1000/fps);
		x--;
		tickcounter++;
	}
}

static void finish_level(void) {
	music_play(TUNE_TITLE);
	game_delay(2*fps);
	video_darken_screen();
	video_update_region(SCREEN_MIN_X, SCREEN_MIN_Y, SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
#define STRLSZ(x) (x), sizeof(x)-1
	font_print(SCREEN_MIN_X+40*SCALE, SCREEN_MIN_Y+13*SCALE, STRLSZ("congratulations"), SCALE, PRGB(255,255,255));
	font_print(SCREEN_MIN_X+24*SCALE, SCREEN_MIN_Y+24*SCALE, STRLSZ("you have completed"), SCALE, PRGB(255,255,255));
	font_print(SCREEN_MIN_X+48*SCALE, SCREEN_MIN_Y+35*SCALE, STRLSZ("your mission"), SCALE, PRGB(255,255,255));
	video_update_region(SCREEN_MIN_X, SCREEN_MIN_Y, SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
	game_delay(-1);
	/* FIXME: for some reason there's a crack noise when switching to "empty" */
	music_play(TUNE_EMPTY);
	
	uint32_t bgbuf0[8*SCALE*((95-40)*SCALE)];
	video_save_rect(SCREEN_MIN_X+40*SCALE,SCREEN_MIN_Y+65*SCALE,(95-40)*SCALE,8*SCALE,bgbuf0);
	
	font_print(SCREEN_MIN_X+40*SCALE, SCREEN_MIN_Y+65*SCALE, STRLSZ("mission bonus"), SCALE, PRGB(255,255,255));
	
	font_print(SCREEN_MIN_X+32*SCALE, SCREEN_MIN_Y+89*SCALE, STRLSZ("1."), SCALE, PRGB(255,255,255));
	uint32_t bgbuf[8*SCALE*((159-64)*SCALE)];
	video_save_rect(SCREEN_MIN_X+64*SCALE,SCREEN_MIN_Y+89*SCALE,(159-64)*SCALE,8*SCALE,bgbuf);
	
	char buf[16];
	int dollars = player_cash[0];
	snprintf(buf, sizeof buf, "     $%.6d", dollars);
	font_print(SCREEN_MIN_X+64*SCALE, SCREEN_MIN_Y+89*SCALE, buf, 12, SCALE, PRGB(255,255,255));
	video_update_region(SCREEN_MIN_X, SCREEN_MIN_Y, SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);

	game_delay(2*fps);
	
	
	dollars += maps[current_map]->rewardk*500;
	video_restore_rect(SCREEN_MIN_X+64*SCALE,SCREEN_MIN_Y+89*SCALE,(159-64)*SCALE,8*SCALE,bgbuf);
	snprintf(buf, sizeof buf, "     $%.6d", dollars);
	font_print(SCREEN_MIN_X+64*SCALE, SCREEN_MIN_Y+89*SCALE, buf, 12, SCALE, PRGB(255,255,255));
	video_update_region(SCREEN_MIN_X, SCREEN_MIN_Y, SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
	
	
	audio_play_wave_resource(wavesounds[WS_MISSIONBONUS]);
	
	game_delay(4.2*fps);
	
	
	video_restore_rect(SCREEN_MIN_X+40*SCALE,SCREEN_MIN_Y+65*SCALE,(95-40)*SCALE,8*SCALE,bgbuf0);
	font_print(SCREEN_MIN_X+40*SCALE, SCREEN_MIN_Y+65*SCALE, STRLSZ("revenge bonus"), SCALE, PRGB(255,255,255));
	
	snprintf(buf, sizeof buf, "%.4d $%.6d", player_kills[0], dollars);
	font_print(SCREEN_MIN_X+64*SCALE, SCREEN_MIN_Y+89*SCALE, buf, 12, SCALE, PRGB(255,255,255));
	video_update_region(SCREEN_MIN_X, SCREEN_MIN_Y, SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
	game_delay(1*fps);
	tickcounter = 0;
	while(player_kills[0]) {
		dollars+=10;
		player_kills[0]--;
		video_restore_rect(SCREEN_MIN_X+64*SCALE,SCREEN_MIN_Y+89*SCALE,(159-64)*SCALE,8*SCALE,bgbuf);
		snprintf(buf, sizeof buf, "%.4d $%.6d", player_kills[0], dollars);
		font_print(SCREEN_MIN_X+64*SCALE, SCREEN_MIN_Y+89*SCALE, buf, 12, SCALE, PRGB(255,255,255));
		video_update_region(SCREEN_MIN_X, SCREEN_MIN_Y, SCREEN_MAX_X - SCREEN_MIN_X, VMODE_H);
		if(tickcounter % 4 == 0) audio_play_wave_resource(wavesounds[WS_COUNTDOWN]);
		// FIXME: when no music is played, sound does not play either... maybe add "empty song"?
		game_delay(1);
	}
	music_play(TUNE_LEVEL_FINISHED);
	game_delay(3*fps);
	
	mission_completed[current_map] = 1;
	player_cash[0] = dollars;
}

#include "weapon_shop.c"

int main() {
	video_init();
	clear_screen();
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	
	audio_init();
	init_player_once(0);
	
	mission_select:
	
	SDL_ShowCursor(1);
	
	/* background music for mission selection screen */
	music_play(TUNE_MAP);

	if((current_map = choose_mission(mission_completed)) == MI_INVALID) goto dun_goofed;
	
	player_cash[0] += maps[current_map]->rewardk*500;
	
	weapon_shop();
	
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
		//if(tickcounter>64) { player_kills[0] = 150; finish_level();}
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
							weapon_inc = -1;
							toggle_weapon:
							weapon_active[player_no] += weapon_inc;
							if(weapon_active[player_no] < 0)
								weapon_active[player_no] = weapon_count[player_no] - 1;
							else if(weapon_active[player_no] >= weapon_count[player_no])
								weapon_active[player_no] = 0;
							printf("%s\n", weapon_name(player_weapons[player_no][weapon_active[player_no]]));
							need_redraw = 1;
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_e:
							editor_mode = 1;
							enemy_tag_loop();
							editor_mode = 0;
							update_caption = game_update_caption;
							break;
						case SDLK_c: 
							clear_screen(); 
							video_update();
							need_redraw = 1; 
							break;
						case SDLK_w: case SDLK_a: case SDLK_s: case SDLK_d:
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT:
							cursors_pressed[cursor_lut[sdl_event.key.keysym.sym]] = 0;
							goto check_anim;
						case SDLK_ESCAPE:
							goto dun_goofed;
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
		if(game_tick(need_redraw)) {
			/* completed map */
			finish_level();
			goto mission_select;
		}
	}

	return 0;
};
