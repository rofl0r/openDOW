#include <leptonica/allheaders.h>
//RcB: LINK "-llept"
#include <stdio.h>
#include <assert.h>

int main(int argc, char**argv) {

	if(argc != 4) {
		dprintf(2, "scaledown factor in out\n");
		return 1;
	}
	int scale = atoi(argv[1]);
	const char *in = argv[2];
	const char *out = argv[3];
	struct Pix* pin = pixRead(in);
	assert(pin->w % scale == 0 && pin->h % scale == 0);
	struct Pix* pin32 = pixConvertTo32(pin);
	struct Pix* pout = pixCreate(pin32->w / scale, pin32->h / scale, 32);
	int xi, xo, yi, yo;
	for(yo = 0, yi = 0; yi < pin->h; yi+=scale, yo++)
		for(xo = 0, xi = 0; xi < pin->w; xi+=scale, xo++)
			((uint32_t*)pout->data)[yo * pout->w + xo] = ((uint32_t*)pin->data)[yi * pin->w + xi];
	pixWritePng(out, pout, 0);
	return 0;
}
