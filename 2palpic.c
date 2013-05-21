#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "palpic.h"
#include <leptonica/allheaders.h>
#define assert(x) if(!(x)) __asm__("int3");

//RcB: LINK "-llept"
/* leptonica:
enum {
    COLOR_RED = 0,
    COLOR_GREEN = 1,
    COLOR_BLUE = 2,
    L_ALPHA_CHANNEL = 3
};

static const l_int32  L_RED_SHIFT =
       8 * (sizeof(l_uint32) - 1 - COLOR_RED);           //24
static const l_int32  L_GREEN_SHIFT =
       8 * (sizeof(l_uint32) - 1 - COLOR_GREEN);         //16
static const l_int32  L_BLUE_SHIFT =
       8 * (sizeof(l_uint32) - 1 - COLOR_BLUE);          //8
static const l_int32  L_ALPHA_SHIFT =
       8 * (sizeof(l_uint32) - 1 - L_ALPHA_CHANNEL);     //0

composeRGBPixel(l_int32    rval, l_int32    gval,  l_int32    bval,  l_uint32  *ppixel)
{
    *ppixel = (rval << L_RED_SHIFT) | (gval << L_GREEN_SHIFT) | (bval << L_BLUE_SHIFT);
    return 0;
} */

static unsigned get_sprite_start(unsigned sprite_nr, unsigned row_nr, unsigned sprite_w, unsigned sprites_per_row) {
	unsigned row_off = (row_nr * sprite_w * sprites_per_row);
	return row_off + (sprite_nr * sprite_w);
}

#define STRSZ(lit) lit, sizeof(lit) - 1
#define LIT_SIZE(lit) ( sizeof(lit) - 1)
int main(int argc, char** argv) {
	int w, h;
	struct palpic pp = palpic_empty;
	prgb pal[256];
	
	struct Pix* infile;
	struct Pix* pix32;

	unsigned startarg = 1;
	for(; startarg < (unsigned) argc; startarg++)
		if(memcmp(argv[startarg], STRSZ("-sprite="))) break;
	if(startarg == argc) {
		printf("syntax: %s -sprite=WxH infile outfile\n"
		       "where WxH denotes the dimensions of a single picture in the spritesheet\n", argv[0]);
		return 1;
	}
	char *in_filename = argv[startarg];
	char *out_filename = argv[startarg + 1];
	char* cp;
	unsigned sprite_w, sprite_h;
	unsigned sprite_count;
	int to_c = (cp = strrchr(out_filename, '.')) && cp == out_filename + strlen(out_filename) - 2 && cp[1] == 'c';
	char struct_name[256];
	if(to_c) {
		size_t l = snprintf(struct_name, sizeof struct_name, "%s", out_filename);
		struct_name[l-2] = 0;
	}
	
	
	infile = pixRead(in_filename);

	pixGetDimensions(infile, &w, &h, NULL);
	
	if(startarg > 1) {
		char* str_w = argv[startarg -1] + LIT_SIZE("-sprite=");
		char* str_h = strchr(str_w, 'x');
		*(str_h++) = 0;
		sprite_w = atoi(str_w);
		sprite_h = atoi(str_h);
		sprite_count = (h * w) / (sprite_h * sprite_w);
		unsigned rest = (h * w) % (sprite_h * sprite_w);
		if(rest) {
			printf("error: the picture dimensions are no multiple of the sprite dimensions!\n");
			return 1;
		}
		if(w % sprite_w) {
			printf("error: the picture width is no multiple of the sprite width!\n");
			return 1;
		}
	} else {
		// no sprite support
		sprite_w = w;
		sprite_h = h;
		sprite_count = 1;
	}
	
	unsigned sprites_per_row = w / sprite_w;
	
	pp.height = sprite_h * sprite_count;
	pp.width = sprite_w;
	
	pix32 = pixConvertTo32(infile);
	prgb* bufptr = (prgb*) pix32->data;
	
	unsigned x, y = 0, p;
	for(y = 0; y < (unsigned) h; y++) {
		for(x = 0; x < (unsigned) w; x++) {
			for(p = 0; p < pp.palcount; p++)
				if(pal[p].val == bufptr->val)
					goto next_x;
			pal[pp.palcount++] = *bufptr;
			next_x:
			bufptr++;
		}
	}
	
	FILE* outfile = fopen(out_filename, "w");

	
	unsigned sprite;
	if(!to_c) {
		palpic_fileformat(&pp);
		fwrite(&pp, sizeof(pp), 1, outfile);
		fwrite(pal, sizeof(prgb) * pp.palcount, 1, outfile);
		
		for(sprite = 0; sprite < sprite_count; sprite++) {
			for(y = 0; y < sprite_h; y++) {
				unsigned sprite_start_y = get_sprite_start(sprite, y, sprite_w, sprites_per_row);
				bufptr = &((prgb*) pix32->data)[sprite_start_y];
				
				for(x = 0; x < sprite_w; x++) {
					for(p = 0; p < pp.palcount; p++)
						if(pal[p].val == bufptr->val) {
							uint8_t val = p;
							fwrite(&val, sizeof(val), 1, outfile);
							goto success;
						}
					fprintf(stderr, "bug: could not find color in palette\n");
					return 1;
					success:
					bufptr++;
				}
			}
		}
	} else {
		char buf[1024];
		snprintf(buf, sizeof(buf), 
			 "#include \"palpic.h\"\n"
			 "#define PAL_COUNT %d\n"
			 "#define PIXEL_COUNT %d\n"
			 "#define SPRITE_COUNT %d\n"
			 "#define WIDTH %d\n"
			 "#define HEIGHT %d\n"
			 "#define SPRITE_WIDTH %d\n"
			 "#define SPRITE_HEIGHT %d\n"
			 
			 "#define STRUCT_NAME %s\n\n"
			 "static const struct {\n"
			 "\tstruct palpic header;\n"
			 "\tprgb palette[PAL_COUNT];\n"
			 "\tuint8_t data[PIXEL_COUNT];\n"
			 "} STRUCT_NAME = { \n"
			 "\t{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, 0, 0, WIDTH, HEIGHT, 0 },\n"
			 "\t{\n\t\t",
			 (int) pp.palcount,
			 (int) pp.width * pp.height, 
			 (int) sprite_count, 
			 (int) pp.width, 
			 (int) pp.height,
			 (int) sprite_w,
			 (int) sprite_h,
			 struct_name
		);
		fwrite(buf, strlen(buf), 1, outfile);
		
		for(p = 0; p < pp.palcount; p++) {
			snprintf(buf, sizeof(buf), "PRGB(%3u, %3u, %3u), ", (unsigned) pal[p].colors.r,(unsigned) pal[p].colors.g, (unsigned) pal[p].colors.b);
			fwrite(buf, strlen(buf), 1, outfile);
			//if(p % 8 == 7) 
				fwrite(STRSZ("\n\t\t"), 1, outfile);
		}
		
		snprintf(buf, sizeof(buf), "\n\t},\n\t{\n\t\t");
		fwrite(buf, strlen(buf), 1, outfile);
		unsigned counter = 0;
		unsigned values_per_line = sprite_w;
		const char *value_format = pp.palcount > 99 ? "%3u," : "%2u,";
		for(sprite = 0; sprite < sprite_count; sprite++) {
			for(y = 0; y < sprite_h; y++) {
				unsigned sprite_start_y = get_sprite_start(sprite, y, sprite_w, sprites_per_row);
				assert(sprite_start_y + sprite_w <= h * w);
				bufptr = &((prgb*) pix32->data)[sprite_start_y];
				
				for(x = 0; x < sprite_w; x++) {
					for(p = 0; p < pp.palcount; p++) {
						if(pal[p].val == bufptr->val) {
							snprintf(buf, sizeof(buf), value_format, (unsigned) p);
							fwrite(buf, strlen(buf), 1, outfile);
							if(counter % values_per_line == values_per_line - 1) 
								fwrite(STRSZ("\n\t\t"), 1, outfile);
							goto success2;
						}
					}
					fprintf(stderr, "bug: could not find color in palette\n");
					return 1;
					success2:
					bufptr++;
					counter++;
				}
			}
		}

		fwrite(STRSZ("\n\t},\n"), 1, outfile);

		snprintf(buf, sizeof(buf), 
			 "};\n\n"
			 "#undef PAL_COUNT\n"
			 "#undef PIXEL_COUNT\n"
			 "#undef WIDTH\n"
			 "#undef HEIGHT\n"
			 "#undef STRUCT_NAME\n\n");
		fwrite(buf, strlen(buf), 1, outfile);
		
	}
	fclose(outfile);
	pixDestroy(&pix32);
	pixDestroy(&infile);
	return 0;
}
