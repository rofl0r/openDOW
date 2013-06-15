#include "../palpic.h"
#include "leptonica/allheaders.h"
#include <string.h>
//RcB: LINK "-llept"

#include "../vehicles_scrambled.c"
#define sprite vehicles_scrambled
#define scramble_factor 3

int main() {
	const struct palpic* f = & sprite .header;
	PIX* o = pixCreate(f->width*scramble_factor, palpic_getspritecount(f) * palpic_getspriteheight(f)/scramble_factor, 32);
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
