#include "../palpic.h"
#include "leptonica/allheaders.h"
#include <string.h>
#pragma RcB2 LINK "-llept -lpng -ljpeg -ltiff -lgif -lz"

struct palpic *palpic_from_file(const char *fn) {
	FILE *fi = fopen(fn, "r");
	if(!fi) return 0;
	fseek(fi,  0, SEEK_END);
	off_t len = ftello(fi);
	fseek(fi,  0, SEEK_SET);
	struct palpic* f = malloc(len);
	if(f) fread(f, 1, len, fi);
	fclose(fi);
	if(f) palpic_hostformat(f);
	return f;
}

void palpic_to_png(const struct palpic *f, const char *fn) {
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
	pixWritePng(fn, o, 0.0);
	pixDestroy(&o);
}


#ifdef BUILT_IN
#include "../temp.c"
#define sprite temp

int main() {
	const struct palpic* f = & sprite .header;
	palpic_to_png(f, "test.png");
	return 0;
}

#else

int main(int argc, char **argv) {
	while(*(++argv)) {
		struct palpic *f = palpic_from_file(*argv);
		if(!f) {
			perror("fopen");
			dprintf(2, "%s\n", *argv);
			continue;
		}
		char buf[1024];
		snprintf(buf, sizeof buf, "%s.png", *argv);
		palpic_to_png(f, buf);
		free(f);
	}
	return 0;
}

#endif
