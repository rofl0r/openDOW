/* when using gfxrip and an uncompressed amiga save state,
 * we find at offset 401408 the map background tiles, followed
 * by other map sprites in 16x16, ST mode, 4bitplanes.
 * the first 16 tiles are background data.
 * to recreate the 64x64 bg tile, 4 lines of each bg sprite
 * are put horizontally into the output tile. */
#include "../palpic.h"
#include "leptonica/allheaders.h"
#include <string.h>
//RcB: LINK "-llept"

#include "../temp.c"
#define sprite temp
#define sprites_per_pic 8
#define bgs 6

int main() {
	const struct palpic* f = & sprite .header;
	size_t seq;
	PIX* o = pixCreate(64, 32*bgs, 32);
	prgb* bufptr = (prgb*) o->data;

	for(seq = 0; seq < bgs * sprites_per_pic; seq += sprites_per_pic) {
		prgb* palette = palpic_getpalette(f);
		
		size_t i;
		for(i = seq; i < seq + sprites_per_pic; i++) {
			int x, y;
			const uint8_t *source = palpic_getspritedata(f, i);
			for(y = 0; y < palpic_getspriteheight(f); y++) {
				for(x = 0; x < palpic_getspritewidth(f); x++) {
					*bufptr++ = palette[*source++];
				}
			}
		}
	}
	pixWritePng("test.png", o, 0.0);
	pixDestroy(&o);
	
	return 0;
}
