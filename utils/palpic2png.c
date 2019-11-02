#include "../palpic.h"
#include "leptonica/allheaders.h"
#include <string.h>
#pragma RcB2 LINK "-llept -lpng -ljpeg -ltiff -lgif -lz"

#include "../temp.c"
#define sprite temp

int main() {
	const struct palpic* f = & sprite .header;
	PIX* o = pixCreate(f->width, f->height, 32);
	prgb* palette = palpic_getpalette(f);
	prgb* bufptr = (prgb*) o->data;
	size_t i;
	for(i = 0; i < f->spritecount; i++) {
		int x, y;
		const uint8_t *source = palpic_getspritedata(f, i);
		for(y = 0; y < palpic_getspriteheight(f); y++) {
			for(x = 0; x < palpic_getspritewidth(f); x++) {
				*bufptr++ = palette[*source++];
			}
		}
	}
	pixWritePng("test.png", o, 0.0);
	return 0;
}
