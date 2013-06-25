#include "palpic.h"


#if defined(PALPIC_SDL) && !defined(PALPIC_OPENGL)
#include "sdl_rgb.h"
typedef sdl_rgb_t output_rgb_t;
#define output_rgb_as_int asInt
#define RGB_WHITE SRGB(0xFF,0xFF,0xFF)
#define RGB_BLACK SRGB(0x00,0x00,0x00)
#else
typedef prgb output_rgb_t;
#define output_rgb_as_int val
#define RGB_WHITE PRGB(0xFF,0xFF,0xFF)
#define RGB_BLACK PRGB(0x00,0x00,0x00)
#endif

#if 0
static output_rgb_t convert_prgb(prgb col) {
	output_rgb_t ret;
	ret.colors.r = col.colors.r;
	ret.colors.g = col.colors.g;
	ret.colors.b = col.colors.b;
	ret.colors.a = col.colors.a;
	return ret;
}
#else

#if defined(PALPIC_SDL) && !defined(PALPIC_OPENGL)
/* warning: this macro is to get reasonable performance in -O0 mode
 * it only work as long as the sdl ARGB and the prgb RGBA type remain unchanged
 * since the alpha value is unused in SDL 2D, we can safely zero it. */
#define convert_prgb(x) ((output_rgb_t){ .output_rgb_as_int  = x .val >> 8 } )
#else
#define convert_prgb(x) ((output_rgb_t){ .output_rgb_as_int  = x .val } )
#endif

#endif
void blit_sprite(int x_pos, int y_pos, struct vo_desc *video, 
	         unsigned scale, const struct palpic* pic, uint16_t spritenum, const prgb *palette) {
	unsigned sprite_width = palpic_getspritewidth(pic);
	unsigned sprite_height = palpic_getspriteheight(pic);
	if(!palette) palette = palpic_getpalette(pic);
	const uint8_t *bitmap = palpic_getspritedata(pic, spritenum);
	unsigned int scale_y, scale_x, y, x;
	int x_tl_off = 0, y_tl_off = 0;
	int x_br_off = 0, y_br_off = 0;
	if(x_pos >= (int)video->width) return;
	else if(x_pos < 0) x_tl_off = -x_pos/scale + !!(x_pos%scale);
	else if(x_pos + sprite_width * scale >= video->width) {
		x_br_off = x_pos + sprite_width * scale - video->width;
		x_br_off=x_br_off/scale+!!(x_br_off%scale);
	}
	if(y_pos >= (int)video->height) return;
	else if(y_pos < 0) y_tl_off = -y_pos/scale + !!(y_pos%scale);
	else if(y_pos + sprite_height * scale >= video->height) {
		y_br_off = y_pos + sprite_height * scale - video->height;
		y_br_off=y_br_off/scale+!!(y_br_off%scale);
	}
	
	unsigned lineoffset = (y_pos + y_tl_off*scale) * (video->pitch / 4);
	unsigned pixel_start = y_tl_off * sprite_width + x_tl_off;
	static const output_rgb_t mask_colors_transp[2] = {
		[0] = (RGB_BLACK),
		[1] = (RGB_WHITE),
	};
	static const output_rgb_t mask_colors_non_transp[2] = {
		[0] = (RGB_BLACK),
		[1] = (RGB_BLACK),
	};
	const output_rgb_t *mask_colors = (pic->flags & PPF_TRANSPARENT ? mask_colors_transp : mask_colors_non_transp);
	for (y = y_tl_off; y < sprite_height - y_br_off; y++) {
		for(scale_y = 0; scale_y < scale; scale_y++) {
			output_rgb_t *ptr = &((output_rgb_t *) video->mem)[lineoffset + x_pos + x_tl_off];
			const uint8_t *p = &bitmap[pixel_start];
			for (x = x_tl_off; x < sprite_width - x_br_off; x++) {
				prgb col = palette[*p++];
				uint32_t mask = mask_colors[(col.val == RGB_BLACK.output_rgb_as_int)].output_rgb_as_int;
				for(scale_x = 0; scale_x < scale; scale_x++) {
					ptr[0].output_rgb_as_int &= mask;
					ptr[0].output_rgb_as_int |= convert_prgb(col).output_rgb_as_int;
					ptr++;
				}
			}
			lineoffset += video->pitch / 4;
		}
		pixel_start += sprite_width;
	}
}