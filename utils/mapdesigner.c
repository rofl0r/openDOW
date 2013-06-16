#include "../map.h"
#include "../palpic.h"
#include <assert.h>

#include <SDL/SDL.h>
//RcB: LINK "-lSDL"
#include "../sdl_rgb.h"
#include "../vec2f.h"

#include "../sprites/bg_urban.c"
#include "../sprites/bg_forest.c"
#include "../sprites/bg_desert.c"
#include "../sprites/map_urban.c"
#include "../sprites/map_forest.c"
#include "../sprites/map_desert.c"

#define SCALE 2
#define BORDER_W 4
#define BORDER_H 4

#define STARTX (BORDER_W*SCALE)
#define STARTY (BORDER_H*SCALE)
#define ENDX (STARTX+192*SCALE)
#define ENDY (STARTY+192*SCALE)

#define BRUSH_STARTX (STARTX + 192*SCALE + BORDER_W*SCALE)
#define BRUSH_STARTY (STARTY)
#define BRUSH_ENDX (BRUSH_STARTX + 64*SCALE)
#define BRUSH_ENDY (BRUSH_STARTY + 32*6*SCALE)

#define BRUSHFG_STARTX (BRUSH_STARTX + 64*SCALE + BORDER_W*SCALE)
#define BRUSHFG_STARTY (BRUSH_STARTY)
#define BRUSHFG_ENDX (BRUSHFG_STARTX + 14*16*SCALE)
#define BRUSHFG_ENDY (BRUSHFG_STARTY + 15*16*SCALE)

#define VMODE_W (BRUSHFG_ENDX + BORDER_W*SCALE)
#define VMODE_H (BRUSHFG_ENDY + BORDER_H*SCALE)

struct map map;
struct map_screen mapscreen;
SDL_Surface *surface;
struct vo_desc video;

static void init_video() {
	SDL_Init(SDL_INIT_VIDEO);
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_RESIZABLE | SDL_HWPALETTE);
	video.mem = surface->pixels;
	video.pitch = surface->pitch;
	video.width = VMODE_W;
	video.height = VMODE_H;
}

const struct palpic *fg_sprites;
const struct palpic *bg_sprites;
int fullscreen_active;
int grid_enabled;

void paint_map() {
	int bg_x, bg_y, x, y;
	int w, h;
	w = palpic_getspritewidth(bg_sprites);
	h = palpic_getspriteheight(bg_sprites);
	for(y= 0, bg_y = 0; bg_y < 192/h; bg_y++, y+=h*SCALE)
		for(x = 0, bg_x = 0; bg_x < 192/w; bg_x++, x+=w*SCALE) {
			blit_sprite(STARTX + x, STARTY + y, &video, SCALE, bg_sprites, mapscreen.bg[bg_y][bg_x], 0);
		}
		
	w = palpic_getspritewidth(fg_sprites);
	h = palpic_getspriteheight(fg_sprites);
	for(y= 0, bg_y = 0; bg_y < 192/h; bg_y++, y+=h*SCALE)
		for(x = 0, bg_x = 0; bg_x < 192/w; bg_x++, x+=w*SCALE) {
			blit_sprite(STARTX + x,STARTY + y, &video, SCALE, fg_sprites, mapscreen.fg[bg_y][bg_x], 0);
		}
}

void paint_brushes() {
	int bg_x, bg_y, x, y;
	int w, h, c;
	w = palpic_getspritewidth(bg_sprites);
	h = palpic_getspriteheight(bg_sprites);
	c = palpic_getspritecount(bg_sprites);
	for(y = 0, bg_y = 0; y < c; y++, bg_y += h*SCALE)
		blit_sprite(BRUSH_STARTX, BRUSH_STARTY + bg_y,
			    &video, 
			    SCALE, bg_sprites, y, 0);
		
	w = palpic_getspritewidth(fg_sprites);
	h = palpic_getspriteheight(fg_sprites);
	c = palpic_getspritecount(fg_sprites);
		
	for(y= 0; y < c/14; y++)
		for(x = 0, x = 0; x < 14; x++) {
			blit_sprite(BRUSHFG_STARTX + x*w*SCALE, BRUSHFG_STARTY + y*h*SCALE,
				    &video, 
				    SCALE, fg_sprites, y*14+x, 0);
		}

}

static void draw_grid(int x_pos, int y_pos, int w, int h, int x_count, int y_count, sdl_rgb_t hcol, sdl_rgb_t vcol) {
	int x,y;
	sdl_rgb_t *pix = (sdl_rgb_t*) surface->pixels;
	unsigned pitch = surface->pitch / 4;
	/* horizontal */
	for(y = 0; y <= y_count * h * SCALE; y += h*SCALE) for(x = 0; x <= w * x_count * SCALE; x++) 
		pix[(y_pos + y) * pitch + x + x_pos] = hcol;
	/*vertical*/
	for(y = 0; y <= y_count * h * SCALE; y++) for(x = 0; x <= w * x_count * SCALE; x += w*SCALE) 
		pix[(y_pos + y) * pitch + x + x_pos] = vcol;
}

static void paint_grids() {
#define VIOLET SRGB(255,0,255)
#define WHITE SRGB(255,255,255)
#define BLUE SRGB(0,0,255)
#define BLACK SRGB(0,0,0)
	draw_grid(STARTX, STARTY, 16, 16, 12, 12, BLACK, BLACK);
	draw_grid(STARTX, STARTY, 64, 32, 3, 6, WHITE, WHITE);
	draw_grid(BRUSH_STARTX, BRUSH_STARTY, 64, 32, 1, palpic_getspritecount(bg_sprites), BLUE, WHITE);
	draw_grid(BRUSHFG_STARTX, BRUSHFG_STARTY, 16, 16, 14, palpic_getspritecount(fg_sprites)/14, VIOLET, WHITE);
}

enum cursor_type { CT_NONE = 0, CT_BG, CT_FG };
struct cursor {
	enum cursor_type ct;
	vec2f pos;
	uint8_t spriteno;
} cursor;
#define mousepos cursor.pos

static void paint_cursor() {
	if(cursor.ct == CT_NONE) return;
	const struct palpic *p = cursor.ct == CT_BG ? bg_sprites : fg_sprites;
	
	if(cursor.pos.x + palpic_getspritewidth(p)*SCALE >= VMODE_W ||
	   cursor.pos.y + palpic_getspriteheight(p)*SCALE >= VMODE_H) return;
	
	blit_sprite(cursor.pos.x, cursor.pos.y, 
		    &video, SCALE,
		    p, cursor.spriteno, 0);
	draw_grid(cursor.pos.x, cursor.pos.y, palpic_getspritewidth(p), palpic_getspriteheight(p), 1, 1, WHITE, WHITE);
}

static void update_screen() {
	SDL_UpdateRect(surface, 0, 0, VMODE_W, VMODE_H);
}

static void clear() {
	uint_fast16_t x, w = VMODE_W;
	uint_fast16_t y, h = VMODE_H;
	sdl_rgb_t *pix, *ptr = pix = (sdl_rgb_t*) surface->pixels;
	uint_fast32_t pitch = surface->pitch / 4, inc = pitch - VMODE_W;
	for(y=0;y<h;y++) {
		for(x=0;x<w;x++) *ptr++ = SRGB(0,0,0);
		ptr+=inc;
	}
}

void redraw() {
	clear();
	paint_map();
	paint_brushes();
	paint_grids();
	paint_cursor();
	update_screen();
}
void tick(int force) { redraw(); SDL_Delay(20);}

typedef struct {
	vec2f topleft;
	vec2f bottomright;
} rect;

#define point_in_rect(POINT_PTR, RECT_PTR) ((POINT_PTR)->x >= (RECT_PTR)->topleft.x && \
					    (POINT_PTR)->x <= (RECT_PTR)->bottomright.x && \
					    (POINT_PTR)->y >= (RECT_PTR)->topleft.y && \
					    (POINT_PTR)->y <= (RECT_PTR)->bottomright.y )

#ifndef IN_KDEVELOP_PARSER
#define RECT(A,B,C,D) { {A, B}, {C, D}}
static rect map_rect = RECT(STARTX,STARTY,ENDX,ENDY);
static rect brushbg_rect = RECT(BRUSH_STARTX,BRUSH_STARTY, BRUSH_ENDX, BRUSH_ENDY);
static rect brushfg_rect = RECT(BRUSHFG_STARTX,BRUSHFG_STARTY, BRUSHFG_ENDX, BRUSHFG_ENDY);
#endif

vec2f get_tile(rect* area, int w, int h, vec2f* pos) {
	vec2f ret;
	ret.x = (pos->x - area->topleft.x) / w;
	ret.y = (pos->y - area->topleft.y) / h;
	return ret;
}

static void disable_sdl_cursor() {
	if(cursor.ct == CT_NONE)
		SDL_ShowCursor(0);
}

static void fill() {
	vec2f tile = get_tile(&brushbg_rect, 64*SCALE, 32*SCALE, &cursor.pos);
	int x,y;
	for(y = 0; y < 6; y++) for(x=0; x < 3; x++) mapscreen.bg[y][x] = tile.y;
}

static void set_bg() {
	vec2f tile = get_tile(&brushbg_rect, 64*SCALE, 32*SCALE, &cursor.pos);
	disable_sdl_cursor();
	cursor.ct = CT_BG;
	cursor.spriteno = tile.y;
}

static void set_fg() {
	vec2f tile = get_tile(&brushfg_rect, 16*SCALE, 16*SCALE, &cursor.pos);
	disable_sdl_cursor();
	cursor.ct = CT_FG;
	cursor.spriteno = (int)tile.y * 14 + (int)tile.x;
}

static void set_map_bg() {
	vec2f tile = get_tile(&map_rect, 64*SCALE, 32*SCALE, &cursor.pos);
	mapscreen.bg[(int)tile.y][(int)tile.x] = cursor.spriteno;
}

static void set_map_fg() {
	vec2f tile = get_tile(&map_rect, 16*SCALE, 16*SCALE, &cursor.pos);
	mapscreen.fg[(int)tile.y][(int)tile.x] = cursor.spriteno;
}

static void process_click(int isleft) {
	if(point_in_rect(&cursor.pos, &map_rect)) {
		if(!isleft) return;
		if(cursor.ct == CT_BG) set_map_bg();
		else if(cursor.ct == CT_FG) set_map_fg();
	} else if (point_in_rect(&cursor.pos, &brushbg_rect)) {
		if(isleft) set_bg();
		else fill();
	} else if (point_in_rect(&cursor.pos, &brushfg_rect)) {
		if(isleft) set_fg();
	}
}

#include <stdio.h>
void print_map() {
	int i;
	printf("A\n");
	for(i = 0; i < sizeof(mapscreen.bg); i++)
		printf(i % 3 == 2 ? "%d,\n" : "%d,", (int)((unsigned char*)(mapscreen.bg))[i]);
	printf("B\n");
	for(i = 0; i < sizeof(mapscreen.fg); i++)
		printf(i % 12 == 11 ? "%3d,\n" : "%3d,", (int)((unsigned char*)(mapscreen.fg))[i]);
	printf("\n");
}

int main(int argc, char**argv) {
	memset(&map, 0, sizeof(struct map));
	memset(&mapscreen, 0, sizeof(struct map_screen));
	assert(argc == 2);
	if(!strcmp(argv[1], "urban"))
		map.maptype = MT_URBAN;
	else if(!strcmp(argv[1], "desert"))
		map.maptype = MT_DESERT;
	else if(!strcmp(argv[1], "forest"))
		map.maptype = MT_FOREST;
	else assert(0);
	const struct palpic* map_fg_lut[] = {
		[MT_URBAN] = &map_urban.header,
		[MT_DESERT] = &map_desert.header,
		[MT_FOREST] = &map_forest.header,
	};
	const struct palpic* map_bg_lut[] = {
		[MT_URBAN] = &bg_urban.header,
		[MT_DESERT] = &bg_desert.header,
		[MT_FOREST] = &bg_forest.header,
	};
	fg_sprites = map_fg_lut[map.maptype];
	bg_sprites = map_bg_lut[map.maptype];
	
	init_video();
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_EnableKeyRepeat(100, 20);
	tick(1);
	while(1) {
		SDL_Event sdl_event;
		unsigned need_redraw = 0;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_MOUSEMOTION:
					mousepos.x = sdl_event.motion.x;
					mousepos.y = sdl_event.motion.y;
					break;
				case SDL_MOUSEBUTTONDOWN:
					mousepos.x = sdl_event.button.x;
					mousepos.y = sdl_event.button.y;
					need_redraw = 1;
					process_click(sdl_event.button.button == SDL_BUTTON_LEFT);
					break;
				case SDL_MOUSEBUTTONUP:
					mousepos.x = sdl_event.button.x;
					mousepos.y = sdl_event.button.y;
					break;
				case SDL_QUIT:
					dun_goofed:
					// restore desktop video mode correctly...
					if(fullscreen_active)
						SDL_WM_ToggleFullScreen(surface);
					print_map();
					return 0;
				case SDL_KEYDOWN:
					switch(sdl_event.key.keysym.sym) {
						case SDLK_g:
							grid_enabled = !grid_enabled;
							need_redraw = 1;
							break;
						case SDLK_ESCAPE:
							goto dun_goofed;
						case SDLK_w: case SDLK_a: case SDLK_s: case SDLK_d:
						case SDLK_UP:
						case SDLK_DOWN:
						case SDLK_RIGHT:
						case SDLK_LEFT: 
						case SDLK_RETURN:
							if((sdl_event.key.keysym.mod & KMOD_LALT) ||
							   (sdl_event.key.keysym.mod & KMOD_RALT)) {
								SDL_WM_ToggleFullScreen(surface);
								fullscreen_active = !fullscreen_active;
							} else {
							}
							break;
						case SDLK_KP_PLUS:
							break;
						case SDLK_KP_MINUS:
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
						default:
							break;
					}
				default:
					break;
			}
		}
		tick(need_redraw);
	}
}