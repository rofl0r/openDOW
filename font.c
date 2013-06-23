#include "palpic.h"
#include "sprites/font.c"
#include "SDL/SDL.h"
#include <stddef.h>

#define STRSWITCH_LETTERS_UC 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': \
			     case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': \
			     case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z'

#define STRSWITCH_LETTERS_LC 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': \
			     case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': \
			     case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z'

#define STRSWITCH_LETTERS STRSWITCH_LETTERS_UC: case STRSWITCH_LETTERS_LC

#define STRSWITCH_NUMBERS '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9'


extern SDL_Surface *surface;
extern struct vo_desc video;

static int chartofontindex(int c) {
	switch(c) {
		case STRSWITCH_NUMBERS:
			return c - '0' + 16;
		case STRSWITCH_LETTERS_UC:
			return c - 'A' + 33;
		case STRSWITCH_LETTERS_LC:
			return c - 'a' + 33;
		case '!' : return 1;
		case '$' : return 4;
		case '\'': return 7;
		case ',' : return 12;
		case '.' : return 14;
		case '\?': return 31;
		default:
			return 0;
	}
}

void font_print(int x, int y, const char *str, size_t len, unsigned scale, prgb color) {
	size_t i;
	prgb col[2] = {PRGB(0,0,0), color };
	for(i = 0; i < len; i++, x+=8*scale)
		blit_sprite(x,y, &video, scale, &font.header, chartofontindex(str[i]), col);
}
