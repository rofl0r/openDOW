#include <leptonica/allheaders.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#pragma RcB2 LINK "-llept"

__attribute__((noreturn)) void syntax(void) {
	dprintf(2, "imgdiff [-dim=x,y,w,h] file1 file2 outfile.png\n"
		   "if dim is passed, only the coordinates contents are written out.\n"
	);
	exit(1);
}

int main(int argc, char** argv) {
	if(argc != 5 && argc != 4) syntax();
	int startarg = 1;
	int x=INT_MAX,y=INT_MAX,xmax=INT_MIN,ymax=INT_MIN,w=-1,h=-1;
	if(strncmp(argv[1], "-dim=", 5) == 0) {
		sscanf(argv[1]+5, "%d,%d,%d,%d", &x, &y, &w, &h);
		startarg++;
	}
	const char* pic1 = argv[startarg++];
	const char* pic2 = argv[startarg++];
	const char* out = argv[startarg++];
	struct Pix* p1 = pixRead(pic1);
	struct Pix* p2 = pixRead(pic2);
	if(p1->h != p2->h || p1->w != p2->w) {
		dprintf(2, "error: both pics need same dimensions!");
		exit(1);
	}
	struct Pix* p1b = pixConvertTo32(p1);
	struct Pix* p2b = pixConvertTo32(p2);
	int X, Y, W = p1->w, H = p1->h;
	if(x == INT_MAX) {
		for(Y = 0; Y < H; Y++) {
			for(X = 0; X < W; X++) {
				if(((uint32_t*)p1b->data)[Y * W + X] != ((uint32_t*)p2b->data)[Y * W + X]) {
					if(X < x) x = X;
					if(X > xmax) xmax = X;
					if(Y < y) y = Y;
					if(Y > ymax) ymax = Y;
				}
			}
		}
		++xmax; ++ymax;
		w = xmax - x;
		h = ymax - y;
	}
	struct Pix* po = pixCreate(w,h,32);
	int ox, oy;
	for(oy = 0, Y = y; Y < y + h; oy++, Y++) for(ox = 0, X = x; X < x + w; ox++, X++) {
		if(((uint32_t*)p1b->data)[Y * W + X] != ((uint32_t*)p2b->data)[Y * W + X])
			((uint32_t*)po->data)[oy * w + ox] = ((uint32_t*)p2b->data)[Y * W + X];
		else 
			((uint32_t*)po->data)[oy * w + ox] = 0;
	}
	pixWritePng(out, po, 0);
	dprintf(1, "wrote pixels x,y,w,h: %d,%d,%d,%d to %s\n", x,y,w,h,out);
	return 0;
	
}

