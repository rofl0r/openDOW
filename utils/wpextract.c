#include <leptonica/allheaders.h>
//RcB: LINK "-llept"
#include <stdio.h>
#include <assert.h>

void copy_rect(int x, int y, int w, int h, void* inbuf, unsigned in_pitch, void* outbuf) {
	uint32_t*ptr = (uint32_t*) inbuf;
	uint32_t*out = (uint32_t*) outbuf;
	int ix, iy;
	for(iy = y; iy < y+h; iy++) for (ix = x; ix < x+w; ix++) {
		*out++ = ptr[iy*in_pitch + ix];
	}
}

int main(int argc, char**argv) {
	if(argc != 3) {
		dprintf(2, "%s in.png out.png\n", argv[0]);
		return 1;
	}
	const char *in = argv[1];
	const char *out = argv[2];
	struct Pix* pin = pixRead(in);
	struct Pix* pin32 = pixConvertTo32(pin);
	struct Pix* pout = pixCreate(59, 16*30, 32);
	
	int xo = 0, yo = 0, i;
	uint32_t *od = (void*) pout->data;
	for(i = 0; i < 30; i++) {
		int xi = 3 + (i % 5) * 64;
		int yi = 5 + (i / 5) * 23;
		copy_rect(xi, yi, 59, 16, (void*) pin32->data, pin32->w, od);
		od += 16*59;
	}
	pixWritePng(out, pout, 0);
	return 0;
}
