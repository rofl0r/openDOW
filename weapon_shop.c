#include "video.h"
#include "palpic.h"
#include "spritemaps.h"
#include "maps.h"
#include "font.h"
#include "audio.h"
#include "music.h"
#include "SDL/SDL.h"

#define GRID_START_X (0*SCALE)
#define GRID_START_Y (SCREEN_MIN_Y + 16*SCALE)

static struct { int x, y; } ws_cursor;

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
	blit_sprite(GRID_START_X+3*SCALE, GRID_START_Y+121*SCALE, &video, SCALE, spritemaps[SI_WS_VIEWEXIT], 0, 0);
	blit_sprite(GRID_START_X+259*SCALE, GRID_START_Y+121*SCALE, &video, SCALE, spritemaps[SI_WS_VIEWEXIT], 1, 0);
}

static void draw_ws_weapons() {
	unsigned img = 0;
	unsigned y,yy,x,xx;
	for(yy= 0, y = GRID_START_Y+5*SCALE; yy < 6; y+=23*SCALE, yy++) {
		for(xx = 0, x = GRID_START_X+3*SCALE; xx < 5; x+=64*SCALE, xx++) {
			if(yy == 5 && (xx == 0 || xx == 4)) continue;
			const struct palpic* p;
			if(img == 8) img++; /* m16 with launcher not implemented */
			if(img > 19) p = spritemaps[SI_WEAPONS];
			else p = spritemaps[SI_WEAPONS];
			blit_sprite(x, y, &video, SCALE, p, img > 19 ? img - 20 : img , 0);
			img++;
		}
	}
}

static void draw_ws_stuff() {
	clear_screen();
	draw_ws_grid();
	draw_ws_text_sprites();
	draw_ws_weapons();
	video_update();
}

static void shop_tick(void) {
	draw_ws_stuff();
	if (audio_process() == -1) music_restart();
	SDL_Delay(20);
}

static void weapon_shop(void) {
	int x=0, y=0;
	SDL_Event sdl_event;
	while(1) {
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					ws_cursor.x = sdl_event.motion.x;
					ws_cursor.y = sdl_event.motion.y;
					break;
				case SDL_MOUSEBUTTONDOWN:
					dprintf(2, "click on %d,%d\n", ws_cursor.x/SCALE-x, ws_cursor.y/SCALE-y);
					//if((ret = cursor_on_map(x, y, completed)) != MI_INVALID) goto dun_goofed;
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
