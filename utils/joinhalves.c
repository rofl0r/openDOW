#include "../palpic.h"
#include "leptonica/allheaders.h"
#include <string.h>
//RcB: LINK "-llept"

#include "../temp.c"
#define sprite temp
#define parts 2

int main() {
	const struct palpic* f = & sprite .header;
	struct vo_desc video;
	video.height = palpic_getspritecount(f) * palpic_getspriteheight(f)/parts;
	video.width = f->width*parts;
	PIX* o = pixCreate(video.width, video.height, 32);
	video.mem = o->data;
	video.pitch = video.width * 4;
	prgb* bufptr = (prgb*) o->data;
	size_t i;
	for(i = 0; i < f->spritecount; i++) {
		int odd = i%parts;
		int x = f->width * odd, y = palpic_getspriteheight(f)*(i/parts);
		blit_sprite(x, y, &video, 1, f, i, 0);
	}
	pixWritePng("test.png", o, 0.0);
	return 0;
}
