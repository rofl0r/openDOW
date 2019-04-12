#include <leptonica/allheaders.h>
#pragma RcB2 LINK "-llept"
#include <stdio.h>
#include <assert.h>

int main(int argc, char**argv) {

	if(argc != 4) {
		dprintf(2, "imgcombine filea fileb out\n");
		return 1;
	}
	const char *a = argv[1];
	const char *b = argv[2];
	const char *out = argv[3];
	struct Pix* pa = pixRead(a);
	struct Pix* pb = pixRead(b);
	assert(pa->w == pb->w && pa->h == pb->h);
	struct Pix* pa32 = pixConvertTo32(pa);
	struct Pix* pb32 = pixConvertTo32(pb);
	struct Pix* pout = pixCreate(pa32->w, pb32->h, 32);
	int x, y;
	for(y = 0; y < pa->h; y++)
		for(x = 0; x < pa->w; x++)
			if(((uint32_t*)pa->data)[y * pa->w + x] == 0)
				((uint32_t*)pout->data)[y * pa->w + x] = ((uint32_t*)pb->data)[y * pa->w + x];
			else 
				((uint32_t*)pout->data)[y * pa->w + x] = ((uint32_t*)pa->data)[y * pa->w + x];
	pixWritePng(out, pout, 0);
	return 0;
}
