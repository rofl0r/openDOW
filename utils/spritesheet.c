#include <leptonica/allheaders.h>
//RcB: LINK "-llept"
#include <stdio.h>
#include <assert.h>

int main(int argc, char**argv) {

	if(argc < 4) {
		dprintf(2, "spritesheet outfilename pic1 pic2 ...\n");
		return 1;
	}
	int startarg = 1;
	const char *out = argv[startarg++];
	struct Pix* pout = 0;
	int oy;
	const int pixcount = argc - startarg;
	while(startarg < argc) {
		const char *a = argv[startarg++];
		struct Pix* pa = pixRead(a);
		struct Pix* pa32 = pixConvertTo32(pa);
		
		if(pout == 0) {
			pout = pixCreate(pa32->w, pa32->h * pixcount, 32);
			oy = 0;
		} else {
			assert(pa32->w == pout->w && pa32->h == pout->h / pixcount);
		}
		int x, y;
		for(y = 0; y < pa32->h; y++, oy++)
			for(x = 0; x < pa32->w; x++)
				((uint32_t*)pout->data)[oy * pa32->w + x] = ((uint32_t*)pa32->data)[y * pa32->w + x];
		
		pixDestroy(&pa);
		pixDestroy(&pa32);
	}
	pixWritePng(out, pout, 0);
	return 0;
	
}
