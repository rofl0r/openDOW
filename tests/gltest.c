#pragma RcB2 LINK "-lGL"
#pragma RcB2 LINK "-lSDL"
#include <SDL/SDL_opengl.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdint.h>
typedef union {
	struct colors {
		uint8_t r,g,b,a;
	} colors;
	uint32_t val;
} rgba_t;
#define RGB(R,G,B) ((rgba_t) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0xff})

#define VMODE_W 320
#define VMODE_H 240
#define PIC_W 17
#define PIC_H 17

static rgba_t pic[PIC_H][PIC_W];
GLuint texid;

void fill() {
	int x,y;
#define COL1 RGB(0x0, 0xff, 0)
#define COL2 RGB(0xff, 0xff, 0xff)
	for(y=0; y<PIC_H; y++) for(x=0;x<PIC_W;x++)
		if(y == 4 || x == 4) pic[y][x] = COL2;
		else pic[y][x] = COL1;
}
void draw_shit() {
	glBindTexture(GL_TEXTURE_2D, texid);
	glBegin(GL_QUADS);
#if 0
	glTexCoord2f(0,0); glVertex2i(-1,-1);
	glTexCoord2f(1,0); glVertex2i( 1,-1);
	glTexCoord2f(1,1); glVertex2i( 1, 1);
	glTexCoord2f(0,1); glVertex2i(-1, 1);
#else
	glTexCoord2f(0,0); glVertex2i(-1,1);
	glTexCoord2f(1,0); glVertex2i(1,1);
	glTexCoord2f(1,1); glVertex2i(1,-1);
	glTexCoord2f(0,1); glVertex2i(-1, -1);

#endif
	glEnd();
	SDL_GL_SwapBuffers();
}
void video_init(void) {
	fill();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_OPENGL);
	glViewport(0, 0, PIC_W, PIC_H);
	glMatrixMode(GL_PROJECTION);                       // Select The Projection Matrix
	glLoadIdentity();                          // Reset The Projection Matrix	
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texid);
	glBindTexture(GL_TEXTURE_2D, texid);
	int mode = GL_RGBA;
	glTexImage2D(GL_TEXTURE_2D, 0, mode, PIC_W, PIC_H, 0, mode, GL_UNSIGNED_BYTE, pic);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	dprintf(2, "%s\n", glGetString(GL_RENDERER));
}
int main() {
	video_init();
	
	SDL_Event sdl_event;
	while(1) {
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
				case SDL_QUIT:
					goto dun;
			}
		}
		draw_shit();
		SDL_Delay(20);
	}
	dun:
	SDL_Quit();
}
