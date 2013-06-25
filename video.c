#include "video.h"
#include <stdbool.h>
#include <stdlib.h>
//RcB: LINK "-lGL"
#include <SDL/SDL_opengl.h>
SDL_Surface *surface;
bool fullscreen_active;
struct vo_desc video;
static float gw, gh;

static void gl_init_viewport() {
	glViewport (0, 0, VMODE_W, VMODE_H);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

static GLuint texid;
static void gl_init_texture(GLuint *t) {
	glGenTextures(1, t);
	glBindTexture(GL_TEXTURE_2D, *t);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, VMODE_W, VMODE_H, 0, GL_RGBA, GL_UNSIGNED_BYTE, video.mem);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void video_init(void) {
	SDL_Init(SDL_INIT_VIDEO);
	//SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	//SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	//SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	//SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 0 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	surface = SDL_SetVideoMode(VMODE_W, VMODE_H, 32, SDL_OPENGL);
	//surface = SDL_CreateRGBSurface(0, VMODE_W, VMODE_H, 32, 0, 0, 0, 0);
	video.mem = malloc(VMODE_W * VMODE_H * 4);//surface->pixels;
	video.pitch = VMODE_W * 4;//surface->pitch;
	video.width = VMODE_W;
	video.height = VMODE_H;
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);

	// disable unneeded features
	glDisable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	
	glEnable(GL_TEXTURE_2D);
	texid = 0; gl_init_texture(&texid);
	gw = VMODE_W;
	gh = VMODE_H;
	dprintf(2, "%s\n", glGetString(GL_RENDERER));
	fullscreen_active = 0;
}

void video_cleanup(void) {
	if(fullscreen_active) SDL_WM_ToggleFullScreen(surface);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void video_update_region(int x, int y, int w, int h) {
	//SDL_UpdateRect(surface, x, y, w, h);
	video_update();
}

void video_update(void) {
	//glEnable(GL_TEXTURE_2D);
	//glClear(GL_COLOR_BUFFER_BIT);
	glDeleteTextures(1, &texid);
	gl_init_texture(&texid);
	glBindTexture(GL_TEXTURE_2D, texid);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex2i(-1,1);
	glTexCoord2f(1,0); glVertex2i(1,1);
	glTexCoord2f(1,1); glVertex2i(1,-1);
	glTexCoord2f(0,1); glVertex2i(-1, -1);
	glEnd();
	glFinish();
	SDL_GL_SwapBuffers();
	//SDL_Flip(surface);
	//SDL_UpdateRect(surface, 0, 0, video.width, video.height);
}

#include "sdl_rgb.h"
void clear_screen(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	sdl_rgb_t *ptr = video.mem;
	unsigned pitch = video.pitch/4;
	unsigned x, y;
	for(y = 0; y < VMODE_H; y++) for (x = 0; x < VMODE_W; x++)
		ptr[y*pitch + x] = SRGB_BLACK;
	*/
}

void toggle_fullscreen(void) {
	fullscreen_active = !fullscreen_active;
	SDL_WM_ToggleFullScreen(surface);
	SDL_Delay(1);
	clear_screen();
	video_update();
	SDL_Delay(1);
}
