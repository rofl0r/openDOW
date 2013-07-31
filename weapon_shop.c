#include "video.h"
#include "palpic.h"
#include "spritemaps.h"
#include "maps.h"
#include "font.h"
#include "audio.h"
#include "music.h"
#include "SDL/SDL.h"
#include "weapon.h"

#define GRID_START_X (0*SCALE)
#define GRID_START_Y (SCREEN_MIN_Y + 16*SCALE)

static struct { int x, y; } ws_cursor;

/* returns -1 if not on any clickable item, 0 - 29 otherwise */
static int ws_cursor_on(void) {
	if(ws_cursor.x < GRID_START_X+3*SCALE || ws_cursor.y < GRID_START_Y + 5*SCALE) return -1;
	int rx = (ws_cursor.x - (GRID_START_X+3*SCALE)) / (64*SCALE);
	int ry = (ws_cursor.y - (GRID_START_Y+5*SCALE)) / (23*SCALE);
	if(rx > 4 || ry > 5) return -1;
	return ry * 5 + rx;
}

static void draw_ws_grid() {
	unsigned i,y,x;
	for(i = 0, y= GRID_START_Y; i < 9; i++, y+=23*SCALE) {
		if(i == 7) y+=21*SCALE;
		else if(i == 8) y-=8*SCALE;
		blit_sprite(GRID_START_X, y, &video, SCALE, spritemaps[SI_WS_HBAR6], 0, 0);
		blit_sprite(GRID_START_X+(6+308)*SCALE, y, &video, SCALE, spritemaps[SI_WS_HBAR6], 1, 0);
	}
#define X (GRID_START_X+6*SCALE)
	for(i = 0, y= GRID_START_Y-1*SCALE; i < 9; i++, y+=23*SCALE) {
		if(i == 7) y+=21*SCALE;
		else if(i == 8) y-=8*SCALE;
		for(x=X; x<X+308*SCALE;x+=SCALE)
			blit_sprite(x, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 0, 0);
	}
#undef X
	for(i = 0, y= GRID_START_Y+3*SCALE; i < 8; i++, y+=23*SCALE) {
		if(i == 7) y+=21*SCALE;
		blit_sprite(GRID_START_X+1*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 1, 0);
		blit_sprite(GRID_START_X+(1+317)*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 1, 0);
	}
	for(i = 0, y= GRID_START_Y+19*SCALE; i < 8; i++, y+=23*SCALE) {
		if(i == 6) y+=21*SCALE;
		else if(i == 7) y-=8*SCALE;
		blit_sprite(GRID_START_X+1*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 2, 0);
		blit_sprite(GRID_START_X+(1+317)*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 2, 0);
	}
	for(i = 0, y= GRID_START_Y+7*SCALE; i < 8; i++, y+=23*SCALE) {
		if(i == 7) y+=21*SCALE;
		blit_sprite(GRID_START_X+1*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
		blit_sprite(GRID_START_X+(1+317)*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
	}
	for(i = 0, y= GRID_START_Y+11*SCALE; i < 7; i++, y+=23*SCALE) {
		blit_sprite(GRID_START_X+1*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
		blit_sprite(GRID_START_X+(1+317)*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
	}
	for(i = 0, y= GRID_START_Y+15*SCALE; i < 7; i++, y+=23*SCALE) {
		blit_sprite(GRID_START_X+1*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
		blit_sprite(GRID_START_X+(1+317)*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
	}
	for(i = 0, y= GRID_START_Y+(138+3+4+3*4)*SCALE; i < 6; i++, y+=4*SCALE) {
		if(i == 5) y-=3*SCALE;
		blit_sprite(GRID_START_X+1*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
		blit_sprite(GRID_START_X+(1+317)*SCALE, y, &video, SCALE, spritemaps[SI_WS_VBAR1], 3, 0);
	}
	for(i = 0, y= GRID_START_Y+21*SCALE; i < 5; i++, y+=23*SCALE) {
		for(x=GRID_START_X+61*SCALE; x<260*SCALE;x+=64*SCALE)
			blit_sprite(x, y, &video, SCALE, spritemaps[SI_WS_BOLT], 0, 0);
	}
	for(i = 0, y= GRID_START_Y+23*SCALE; i < 5; i++, y+=23*SCALE) {
		for(x=GRID_START_X+51*SCALE; x<260*SCALE;x+=64*SCALE)
			blit_sprite(x, y, &video, SCALE, spritemaps[SI_WS_HBAR10], 0, 0);
	}
	for(i = 0, y= GRID_START_Y+23*SCALE; i < 5; i++, y+=23*SCALE) {
		for(x=GRID_START_X+68*SCALE; x<280*SCALE;x+=64*SCALE)
			blit_sprite(x, y, &video, SCALE, spritemaps[SI_WS_HBAR10], 1, 0);
	}
	
	for(x = GRID_START_X+63*SCALE; x<GRID_START_X+280*SCALE; x+=64*SCALE) {
		blit_sprite(x, GRID_START_Y+3*SCALE, &video, SCALE, spritemaps[SI_WS_VBAR3], 2, 0);
	}
	for(x = GRID_START_X+63*SCALE; x<GRID_START_X+280*SCALE; x+=64*SCALE) {
		blit_sprite(x, GRID_START_Y+128*SCALE, &video, SCALE, spritemaps[SI_WS_VBAR3], 3, 0);
	}
	for(i = 0, y = GRID_START_Y+13*SCALE; i < 5; i++, y+=23*SCALE) {
		for(x = GRID_START_X+63*SCALE; x<GRID_START_X+280*SCALE; x+=64*SCALE) {
			blit_sprite(x, y, &video, SCALE, spritemaps[SI_WS_VBAR3], 1, 0);
		}
	}
	for(i = 0, y = GRID_START_Y+26*SCALE; i < 5; i++, y+=23*SCALE) {
		for(x = GRID_START_X+63*SCALE; x<GRID_START_X+280*SCALE; x+=64*SCALE) {
			blit_sprite(x, y, &video, SCALE, spritemaps[SI_WS_VBAR3], 0, 0);
		}
	}
}

static void draw_ws_text_sprites() {
	blit_sprite(GRID_START_X+31*SCALE, GRID_START_Y+186*SCALE, &video, SCALE, spritemaps[SI_WS_COSTCREDIT], 0, 0);
	blit_sprite(GRID_START_X+150*SCALE, GRID_START_Y+186*SCALE, &video, SCALE, spritemaps[SI_WS_COSTCREDIT], 1, 0);
}

static void draw_ws_weapons() {
	unsigned img = 0;
	const struct palpic* p = spritemaps[SI_WEAPONSHOP];
	unsigned y,yy,x,xx;
	for(yy= 0, y = GRID_START_Y+5*SCALE; yy < 6; y+=23*SCALE, yy++) {
		for(xx = 0, x = GRID_START_X+3*SCALE; xx < 5; x+=64*SCALE, xx++) {
			blit_sprite(x, y, &video, SCALE, p, img, 0);
			img++;
		}
	}
}

static void print_ws_info(unsigned line, const char* text) {
	font_print(GRID_START_X+16*SCALE, GRID_START_Y+144*SCALE+line*9*SCALE,
	           text, strlen(text), SCALE, PRGB(0x00,0x88,0xee));
}

static void print_ws_num(unsigned num, int x) {
	char buf[8];
	snprintf(buf, sizeof buf, "%.6u", num);
	font_print(GRID_START_X+x*SCALE, GRID_START_Y+187*SCALE,
	           buf, 6, SCALE, PRGB(0xff,0xdd,0x55));
}

static void print_ws_cost(unsigned cost) {
	print_ws_num(cost, 88);
}

static void print_ws_credit(unsigned credit) {
	print_ws_num(credit, 224);
}

static const enum weapon_id wp_lut[] = {
	[0] = WP_COLT45,
	[1] = WP_BROWNING,
	[2] = WP_SA80,
	[3] = WP_MP5,
	[4] = WP_UZI,
	[5] = WP_STEYR,
	[6] = WP_AK47,
	[7] = WP_M16A2,
	//[0] = WP_M203,
	[8] = WP_RPK,
	[9] = WP_L7A2,
	[10] = WP_HK21,
	[11] = WP_M60,
	[12] = WP_MG42,
	[13] = WP_M134,
	[14] = WP_RPG7,
	[15] = WP_LAW,
	[16] = WP_MAW,
	[17] = WP_ABC,
};
static const enum ammo_id ammo_lut[] = {
	[0] = AMMO_GRENADE,
	[1] = AMMO_556,
	[2] = AMMO_762,
	[3] = AMMO_45ACP,
	[4] = AMMO_9MMPARABELLUM,
	[5] = AMMO_10MM,
	[6] = AMMO_ROCKET83MM,
	// 7 : view button
	[8] = AMMO_ROCKET40MM,
	[9] = AMMO_K200GRENADE40MM,
	[10] = AMMO_GAS
};

static enum ammo_id ws_ammo_from_index(int index) {
	assert(index < 30 && index >= 0);
	if((unsigned) index < ARRAY_SIZE(wp_lut) ||
	   index == ARRAY_SIZE(wp_lut) + 7 ||
	   (unsigned) index >= ARRAY_SIZE(wp_lut) + ARRAY_SIZE(ammo_lut)) return AMMO_INVALID;
	return ammo_lut[index - ARRAY_SIZE(wp_lut)];
}

static enum weapon_id ws_weapon_from_index(int index) {
	assert(index < 30 && index >= 0);
	if((unsigned) index >= ARRAY_SIZE(wp_lut)) return WP_INVALID;
	return wp_lut[index];
}

static void draw_ws_weapon_info(int index) {
	enum ammo_id a = ws_ammo_from_index(index);
	enum weapon_id w = ws_weapon_from_index(index);
	const char* name; unsigned cost;
	if(a != AMMO_INVALID) {
		cost = ammunition[a].price;
		name = ammo_name(a);
	} else if (w != WP_INVALID) {
		cost = weapons[w].price;
		name = weapon_name(w);
	} else 
		return;
	
	print_ws_info(0, name);
	print_ws_cost(cost);
}

static void draw_ws_stuff() {
	clear_screen();
	draw_ws_grid();
	draw_ws_text_sprites();
	draw_ws_weapons();
	int wp_index = ws_cursor_on();
	if(wp_index != -1) draw_ws_weapon_info(wp_index);
	print_ws_credit(player_cash[0]);
	video_update();
}

static void shop_tick(void) {
	draw_ws_stuff();
	if (audio_process() == -1) music_restart();
	SDL_Delay(20);
}

/* returns 1 if successful */
static int purchase_weapon(enum weapon_id w) {
	int cost = weapons[w].price;
	int playerno = 0, i;
	if(cost > player_cash[playerno]) return 0;
	for(i = 0; i < weapon_count[playerno]; i++)
		if(player_weapons[playerno][i] == w) return 0;
	player_cash[playerno] -= cost;
	player_weapons[playerno][weapon_count[playerno]++] = w;
	return 1;
}

static int purchase_ammo(enum ammo_id a) {
	int cost = ammunition[a].price;
	int playerno = 0;
	if(cost > player_cash[playerno]) return 0;
	player_cash[playerno] -= cost;
	player_ammo[playerno][a] += ammunition[a].rounds;
	if(a == AMMO_GRENADE) purchase_weapon(WP_GRENADES);
	return 1;
}

static void print_ws_stats() {
	int playerno = 0, i;
	const char* str;

	font_print(28*SCALE,32*SCALE,"WEAPONS",7,SCALE,PRGB(0xff,0xff,0xbb));
	for(i = 0; i < weapon_count[playerno]; i++) {
		enum weapon_id w = player_weapons[playerno][i];
		str = weapon_name(w);
		font_print(28*SCALE, 47*SCALE+i*9*SCALE, str, strlen(str), SCALE, PRGB(0xdd,0x33,0x11));
	}
	
	font_print(172*SCALE,32*SCALE,"AMMUNITION ROUNDS",17,SCALE,PRGB(0xff,0xff,0xbb));
	
	for(i = 0; i < AMMO_MAX; i++) {
		str = ammo_name((enum ammo_id) i);
		font_print(180*SCALE,47*SCALE+i*9*SCALE,str,strlen(str),SCALE,PRGB(0x11,0xbb,0x55));
		font_print(246*SCALE,47*SCALE+i*9*SCALE,":",1,SCALE,PRGB(0x11,0xbb,0x55));
		char buf[8];
		snprintf(buf, sizeof buf, "%.5d", (int) player_ammo[playerno][i]);
		font_print(260*SCALE,47*SCALE+i*9*SCALE,buf,5,SCALE,PRGB(0x11,0x77,0xff));
	}
}

static void show_weapons() {
	clear_screen();
	print_ws_stats();
	video_update();
	SDL_ShowCursor(0);

	while(1) {
		SDL_Event sdl_event;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_QUIT:
				case SDL_MOUSEBUTTONDOWN:
					goto dun;
				default:;
			}
		}
		if (audio_process() == -1) music_restart();
		SDL_Delay(20);
	}
	dun:
	SDL_ShowCursor(1);
}

/* returns 1 if exit was clicked, otherwise 0 */
static int process_ws_click(void) {
	int wp_index = ws_cursor_on();
	int player_no = 0;
	if(wp_index < 0 || wp_index >= 30) return 0;
	if(wp_index == 29) {
		if(weapon_count[player_no]) return 1;
		else goto fail; /* player must purchase at least one weapon */
	}
	if(wp_index == 25) {
		show_weapons();
		return 0;
	}
	
	enum ammo_id a = ws_ammo_from_index(wp_index);
	enum weapon_id w = ws_weapon_from_index(wp_index);
	int success;
	
	if(a != AMMO_INVALID) {
		success = purchase_ammo(a);
	} else if (w != WP_INVALID) {
		success = purchase_weapon(w);
	} else {
		return 0;
	}
	
	if(success) {
		audio_play_wave_resource(wavesounds[WS_SUCCESS]);
	} else {
		fail:;
		audio_play_wave_resource(wavesounds[WS_FAIL]);
	}
	
	return 0;
}

static void weapon_shop(void) {
	SDL_Event sdl_event;
	while(1) {
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					ws_cursor.x = sdl_event.motion.x;
					ws_cursor.y = sdl_event.motion.y;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(process_ws_click()) goto dun_goofed;
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
		shop_tick();
	}
	dun_goofed:
	clear_screen();
	video_update();
}
