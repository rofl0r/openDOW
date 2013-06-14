#include "palpic.h"
#include "sdl_rgb.h"

#if 0
static sdl_rgb_t convert_prgb(prgb col) {
	sdl_rgb_t ret;
	ret.colors.r = col.colors.r;
	ret.colors.g = col.colors.g;
	ret.colors.b = col.colors.b;
	ret.colors.a = 0;
	return ret;
}
#else
/* warning: this macro is to get reasonable performance in -O0 mode
 * it only work as long as the sdl ARGB and the prgb RGBA type remain unchanged */
#define convert_prgb(x) ((sdl_rgb_t){ .asInt  = x .val >> 8 } )
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
	else if(x_pos < 0) x_tl_off = -x_pos;
	else if(x_pos + sprite_width * scale >= video->width) {
		x_br_off = x_pos + sprite_width * scale - video->width;
		int odd = 0;
		if(x_br_off%scale)odd=1;
		x_br_off=x_br_off/scale+odd;
	}
	if(y_pos >= (int)video->height) return;
	else if(y_pos < 0) y_tl_off = -y_pos;
	else if(y_pos + sprite_height * scale >= video->height) {
		y_br_off = y_pos + sprite_height * scale - video->height;
		int odd = 0;
		if(y_br_off%scale)odd=1;
		y_br_off=y_br_off/scale+odd;
	}
	
	unsigned lineoffset = (y_pos + y_tl_off) * (video->pitch / 4);
	unsigned pixel_start = y_tl_off * sprite_width + x_tl_off;
	static const sdl_rgb_t mask_colors_transp[2] = {
		[0] = (SRGB_BLACK),
		[1] = (SRGB_WHITE),
	};
	static const sdl_rgb_t mask_colors_non_transp[2] = {
		[0] = (SRGB_BLACK),
		[1] = (SRGB_BLACK),
	};
	const sdl_rgb_t *mask_colors = (pic->flags & PPF_TRANSPARENT ? mask_colors_transp : mask_colors_non_transp);
	for (y = y_tl_off; y < sprite_height - y_br_off; y++) {
		for(scale_y = 0; scale_y < scale; scale_y++) {
			sdl_rgb_t *ptr = &((sdl_rgb_t *) video->mem)[lineoffset + x_pos + x_tl_off];
			const uint8_t *p = &bitmap[pixel_start];
			for (x = x_tl_off; x < sprite_width - x_br_off; x++) {
				prgb col = palette[*p++];
				uint32_t mask = mask_colors[(col.val == palette[0].val)].asInt;
				for(scale_x = 0; scale_x < scale; scale_x++) {
					ptr[0].asInt &= mask;
					ptr[0].asInt |= convert_prgb(col).asInt;
					ptr++;
				}
			}
			lineoffset += video->pitch / 4;
		}
		pixel_start += sprite_width;
	}
}