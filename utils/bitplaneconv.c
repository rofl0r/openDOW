#include "../palpic.h"
#include "../temp.c"
#include "leptonica/allheaders.h"
#include <string.h>
//RcB: LINK "-llept"

#define BITPLANES 4
#define sprite temp

int main() {
	const prgb color_tab[] = {
		PRGB(0, 0, 0),
		PRGB(0xff, 0xdd, 0x55), //yellow
		PRGB(0xbb, 0xbb, 0xbb), // light gray
		PRGB(0x11, 0x33, 0x33), // dark gray
		PRGB(0x22, 0x22, 0x22), // dummy2
		PRGB(0x33, 0x33, 0x33), // dummy3
		PRGB(0xbb, 0x55, 0x11), // orange
		PRGB(0x66, 0x66, 0x66), // dummy6
		PRGB(0xff, 0xff, 0xdd), // white
		PRGB(0x11, 0x11, 0x11), // dummy1
		PRGB(0xbb, 0x77, 0x55), // light orange
		PRGB(0x77, 0x55, 0x11), // brown,
		PRGB(0x44, 0x44, 0x44), // dummy4
		PRGB(0x55, 0x55, 0x55), // dummy5
		PRGB(0x77, 0x77, 0x77), // dummy7
		PRGB(0xbb, 0x99, 0x55), // light brown
	};
	const struct palpic* f = &sprite.header;
	PIX* o = pixCreate(f->width, f->height / BITPLANES, 32);
	int w = palpic_getspritewidth(f);
	int h = palpic_getspriteheight(f);
	size_t i = 0;
	uint8_t plane[h][w];
	prgb* bufptr = (prgb*) o->data;
	for(i = 0; i+(BITPLANES-1) < f->spritecount; i+=BITPLANES) {
		memset(plane, 0, sizeof plane);
		int x;
		int y;
		size_t j;
		for(j = 0; j < BITPLANES; j++) {
			const uint8_t *source = palpic_getspritedata(f, i + j);
			for(y = 0; y < h; y++) {
				for(x = 0; x < w; x++) {
					if(*source) plane[y][x] |= 1 << j;
					source++;
				}
			}
		}
		for(j = 0; j < sizeof plane; j++) {
			*bufptr++ = color_tab[((uint8_t*)plane)[j]];
		}
	}
	pixWritePng("test.png", o, 0.0);
	return 0;
}
