#include "enemy.h"
#include "gameobj.h"
#include <unistd.h>
static struct enemy_spawn tag_enemy;
static int tag_enemy_current_route;
static int tag_enemy_id;

static void reset_tag_enemy() {
	memset(&tag_enemy, 0, sizeof(tag_enemy));
	tag_enemy.route[0].shape = ES_SOLDIER1_DOWN;
}

static void update_tag_enemy() {
	remove_enemy(tag_enemy_id);
	tag_enemy_id = init_enemy(&tag_enemy);
}

static void dup_route() {
	int i;
	for(i = tag_enemy_current_route + 1; i < ENEMY_MAX_ROUTE; i++)
		tag_enemy.route[i] = tag_enemy.route[tag_enemy_current_route];
}

static void toggle_shape(int shapedir) {
	int s = tag_enemy.route[tag_enemy_current_route].shape;
	s += shapedir;
	if(s < ES_FIRST) s = ES_MAX - 1;
	else if(s >= ES_MAX) s = ES_FIRST;
	tag_enemy.route[tag_enemy_current_route].shape = s;
	dup_route();
	update_tag_enemy();
}

static void toggle_vel(int veldir) {
	int v = tag_enemy.route[tag_enemy_current_route].vel;
	v+=veldir;
	if(v<0) v = 0;
	else if(v > 255) v = 255;
	tag_enemy.route[tag_enemy_current_route].vel = v;
	dup_route();
	update_tag_enemy();
}

static void toggle_route(int dir) {
	int newroute = tag_enemy_current_route + dir;
	if(newroute >= ENEMY_MAX_ROUTE) newroute = 0;
	else if(newroute < 0) newroute = ENEMY_MAX_ROUTE -1;
	tag_enemy_current_route = newroute;
}

static void insert_steps(void) {
	tag_enemy.route[tag_enemy_current_route].start_step = objs[tag_enemy_id].objspecific.enemy.curr_step;
	dup_route();
}

static int paused;
static void tag_update_caption(void) {
	char buf [128];
	snprintf(buf, 128, "%s tag mode: x %d, y %d, route: %d, vel: %d, step: %d", 
		 paused ? "XXXX PAUSED XXXX" : "",
		 (int) tag_enemy.x, (int) tag_enemy.y,
		 (int) tag_enemy_current_route,
	         (int) tag_enemy.route[tag_enemy_current_route].vel,
	         (int) objs[tag_enemy_id].objspecific.enemy.curr_step
		);
	SDL_WM_SetCaption(buf, 0);
}

static void print_dirbuf(char* dirbuf) {
	char buf [128];
	snprintf(buf, 128, "enter dir16: %s", dirbuf);
	SDL_WM_SetCaption(buf, 0);
}

static void do_pause() {
	static int save_vel[ENEMY_MAX_ROUTE];
	int i;
	if(!paused) {
		for(i = 0; i < ENEMY_MAX_ROUTE; i++) save_vel[i] = tag_enemy.route[i].vel;
		for(i = 0; i < ENEMY_MAX_ROUTE; i++) tag_enemy.route[i].vel = 0; 
	} else {
		for(i = 0; i < ENEMY_MAX_ROUTE; i++) tag_enemy.route[i].vel = save_vel[i]; 
	}
	paused = !paused;
}

static void enter_direction() {
	char dirbuf[4] = {0};
	char* p = dirbuf;
	while(1) {
		SDL_Event sdl_event;
		while (SDL_PollEvent(&sdl_event)) {
			if(sdl_event.type == SDL_KEYUP) switch(sdl_event.key.keysym.sym) {
				#define check(dir) if(p+dir < dirbuf || p+dir>=dirbuf+4) break;
				case SDLK_w: check(1); *p++ = 'w'; break;
				case SDLK_s: check(1); *p++ = 's'; break;
				case SDLK_o: check(1); *p++ = 'o'; break;
				case SDLK_n: check(1); *p++ = 'n'; break;
				case SDLK_BACKSPACE: check(-1); *--p = 0; break;
				#undef check
				case SDLK_RETURN: goto end_loop;
				default: ;
			}
			print_dirbuf(dirbuf);
		}
		print_dirbuf(dirbuf);
		SDL_Delay(5);
	}
	end_loop:;
	enum direction16 dir;
	if(0);
	else if (!strcmp(dirbuf,"o")) dir= DIR16_O;
	else if (!strcmp(dirbuf,"ono")) dir= DIR16_ONO;
	else if (!strcmp(dirbuf,"no")) dir= DIR16_NO;
	else if (!strcmp(dirbuf,"nno")) dir= DIR16_NNO;
	else if (!strcmp(dirbuf,"n")) dir= DIR16_N;
	else if (!strcmp(dirbuf,"nnw")) dir= DIR16_NNW;
	else if (!strcmp(dirbuf,"nw")) dir= DIR16_NW;
	else if (!strcmp(dirbuf,"wnw")) dir= DIR16_WNW;
	else if (!strcmp(dirbuf,"w")) dir= DIR16_W;
	else if (!strcmp(dirbuf,"wsw")) dir= DIR16_WSW;
	else if (!strcmp(dirbuf,"sw")) dir= DIR16_SW;
	else if (!strcmp(dirbuf,"ssw")) dir= DIR16_SSW;
	else if (!strcmp(dirbuf,"s")) dir= DIR16_S;
	else if (!strcmp(dirbuf,"sso")) dir= DIR16_SSO;
	else if (!strcmp(dirbuf,"so")) dir= DIR16_SO;
	else if (!strcmp(dirbuf,"oso")) dir= DIR16_OSO;
	else dir = DIR16_INVALID;
	if(dir != DIR16_INVALID) tag_enemy.route[tag_enemy_current_route].dir = dir;
	dup_route();
	update_tag_enemy();
}

static void enemy_tag_loop() {
	update_caption = tag_update_caption;
	tag_enemy_current_route = 0;
	reset_tag_enemy();
	tag_enemy_id = init_enemy(&tag_enemy);
	
	SDL_Event sdl_event;
	while(1) {
		if(!obj_slot_used[tag_enemy_id])
			tag_enemy_id = init_enemy(&tag_enemy);
		unsigned need_redraw = 1;
		while (SDL_PollEvent(&sdl_event)) {
			need_redraw = 0;
			int dir = -1;
			switch (sdl_event.type) {
				case SDL_KEYUP:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_e: return;
						case SDLK_d: enter_direction(); break;
						case SDLK_i: insert_steps(); break;
						case SDLK_p: do_pause(); break;
						case SDLK_KP_PLUS:
							dir = 1;
						case SDLK_KP_MINUS:
							if((sdl_event.key.keysym.mod & KMOD_RSHIFT) ||
							   (sdl_event.key.keysym.mod & KMOD_LSHIFT))
								toggle_shape(dir);
							else
							if((sdl_event.key.keysym.mod & KMOD_RALT) ||
							   (sdl_event.key.keysym.mod & KMOD_LALT))
								toggle_route(dir);
							else
								toggle_vel(dir);
							break;
						default: break;
					}
				case SDL_KEYDOWN:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_RIGHT: dir = 1;
						case SDLK_LEFT:
							if((sdl_event.key.keysym.mod & KMOD_RSHIFT) ||
							   (sdl_event.key.keysym.mod & KMOD_LSHIFT)) dir *= 4;
							tag_enemy.x += dir;
							update_tag_enemy();
							break;
						case SDLK_DOWN:
							dir = 1;
						case SDLK_UP:
							if((sdl_event.key.keysym.mod & KMOD_RSHIFT) ||
							   (sdl_event.key.keysym.mod & KMOD_LSHIFT)) dir *= 4;
							tag_enemy.y += dir;
							update_tag_enemy();
							break;
						default: ;
					}
				break;
				default: ;
			}
		}
		game_tick(need_redraw);
	}
}