#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 2
#define WIDTH 59
#define HEIGHT 26
#define o 0
#define STRUCT_NAME ws_viewexit

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB( 51, 187,  85), 
		PRGB( 17,  85,  51), 
		PRGB( 51, 119,  51), 
		PRGB(187, 187, 187), 
		PRGB(255, 255, 221), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, 1, 1, 1, 1, 2, o, o, o, o, o, o, 3, 1, o, 3, 1, 1, 1, 1, 3, 2, o, 3, 1, 1, 1, 3, o, 1, 1, 1, 1, 1, o, 1, 1, 1, 1, 2, o, o, o, o, 1, 2, o, o, o, o, 3, 1, o, o, o, o,
		 o, o, o, o, 2, 4, 1, 1, 3, o, o, o, o, o, o, 1, 3, o, o, 4, 1, 1, 3, o, o, o, o, 4, 1, 1, 3, o, o, 2, 3, 1, 1, o, 2, 4, 1, 1, 3, o, o, o, 2, 1, 3, o, o, o, o, 1, 3, o, o, o, o,
		 o, o, o, o, o, 4, 1, 1, 1, 2, o, o, o, o, 2, 1, 2, o, o, 5, 1, 1, 3, o, o, o, o, 5, 1, 1, 2, o, o, o, o, 3, 1, o, o, 1, 4, 1, 1, 2, o, o, 3, 1, 1, 2, o, o, 2, 1, 2, o, o, o, o,
		 o, o, o, o, o, 3, 4, 1, 1, 3, o, o, o, o, 3, 1, o, o, o, 5, 1, 1, 3, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, o, 3, 5, 1, 1, 3, o, o, 1, 1, 1, 3, o, o, 3, 1, o, o, o, o, o,
		 o, o, o, o, o, 2, 5, 1, 1, 1, o, o, o, o, 1, 3, o, o, o, 5, 1, 1, 3, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, o, 2, 4, 1, 1, 3, o, o, 4, 1, 1, 3, o, o, 1, 3, o, o, o, o, o,
		 o, 3, 1, 3, o, o, 1, 4, 1, 1, 2, o, o, 2, 1, 2, o, o, o, 5, 1, 1, 3, o, o, o, o, 5, 1, 1, 2, o, o, 3, 1, o, o, o, o, o, 1, 4, 1, 1, 2, o, 4, 1, 1, 1, 2, 2, 1, 2, o, 3, 1, 3, o,
		 3, 1, 1, 1, 3, o, 3, 5, 1, 1, 3, o, o, 3, 1, o, o, o, o, 5, 1, 1, 3, o, o, o, o, 5, 1, 1, 2, o, 1, 4, 1, o, o, o, o, o, 3, 5, 1, 1, 3, o, 3, 4, 1, 1, 3, o, 1, o, 3, 1, 1, 1, 3,
		 1, 4, 1, 1, 1, o, 2, 4, 1, 1, 1, o, o, 1, 3, o, o, o, o, 4, 1, 1, 3, o, o, o, o, 5, 1, 1, 2, o, o, 3, 1, o, o, o, o, o, 2, 4, 1, 1, 3, o, 2, 4, 1, 1, 3, o, 2, o, 1, 4, 1, 1, 1,
		 3, 5, 4, 1, 3, o, o, 1, 4, 1, 1, 2, 2, 1, 2, o, o, o, o, 4, 1, 1, 3, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, 1, 4, 1, 1, 2, o, 1, 4, 1, 1, 2, o, o, 3, 5, 4, 1, 3,
		 o, 3, 1, 3, o, o, o, 3, 5, 1, 1, 3, o, 1, o, o, o, o, o, 4, 1, 1, 3, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, 3, 4, 1, 1, 3, o, 3, 4, 1, 1, 3, o, o, o, 3, 1, 3, o,
		 o, o, o, o, o, o, o, 2, 4, 1, 1, 1, o, 3, o, o, o, o, o, 4, 1, 1, 3, o, o, o, o, 4, 1, 1, 2, o, o, o, o, 3, 1, o, o, o, o, 2, 1, 4, 1, 2, o, 2, 4, 1, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 3, 4, 1, 1, 2, o, o, o, o, o, o, 4, 1, 1, 3, o, o, o, o, 4, 1, 1, 3, o, o, 2, 3, 1, 1, o, o, o, o, o, 3, 4, 1, o, o, o, 3, 4, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 4, 1, 1, 1, o, o, o, o, o, 3, 1, 1, 1, 1, 3, 2, o, 3, 1, 1, 1, 3, o, 1, 1, 1, 1, 1, o, o, o, o, o, 2, 4, 3, o, o, o, 2, 4, 3, o, o, o, o, o, o, o, o,
		/* sprite #001 */
		 o, o, o, o, o, 3, 1, 1, 1, 3, o, 1, 1, 1, 1, 1, o, o, 1, 1, 1, 1, 3, o, o, 3, 1, 1, 1, 2, o, 1, 1, 1, 1, 1, 3, 2, o, 1, 1, 1, o, 4, 1, 1, 3, o, 1, 1, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 4, 1, 1, 3, o, o, 2, 3, 1, 1, o, o, 2, 4, 1, 1, 1, 2, o, o, 3, 4, o, o, o, o, 4, 1, 1, 3, o, o, o, 4, 1, 1, o, 4, 1, 1, 2, o, 4, 1, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, 3, 1, o, o, o, 2, 4, 1, 1, 3, o, o, 1, o, o, o, o, o, 5, 1, 1, 3, o, o, o, 5, 1, o, o, 5, 1, 1, 2, o, o, 4, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, 3, 5, 1, 1, 2, o, o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, 4, 2, o, o, 5, 1, 1, 2, o, o, 2, 1, o, o, o, o, o, o, o, o,
		 o, 3, 1, 3, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, 2, 4, 1, 1, 3, o, o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, 1, o, o, o, 5, 1, 1, 2, o, o, o, 1, o, o, 3, 1, 3, o, o, o,
		 3, 1, 1, 1, 3, o, 5, 1, 1, 2, o, o, 3, 1, o, o, o, o, o, o, o, 3, 5, 1, 1, 2, o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, 3, 1, 1, 1, 3, o, o,
		 1, 4, 1, 1, 1, o, 5, 1, 1, 2, o, 1, 4, 1, o, o, o, o, o, o, o, 2, 4, 1, 1, 3, o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, 1, 4, 1, 1, 1, o, o,
		 3, 5, 4, 1, 3, o, 4, 1, 1, 2, o, o, 3, 1, o, o, o, o, o, o, o, o, 3, 4, 1, 1, 2, o, o, o, o, o, 5, 1, 1, 2, o, o, o, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, 3, 5, 4, 1, 3, o, o,
		 o, 3, 1, 3, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, 2, 4, 1, 1, 3, o, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, 3, 1, 3, o, o, o,
		 o, o, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, 2, 1, o, 3, 4, 1, 1, 2, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 4, 1, 1, 2, o, o, o, o, 3, 1, o, o, o, o, 4, 3, o, 2, 4, 1, 1, 3, o, o, o, o, 4, 1, 1, 2, o, o, o, o, o, o, o, 4, 1, 1, 3, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 4, 1, 1, 3, o, o, 2, 3, 1, 1, o, o, o, 4, 1, o, o, o, 3, 4, 1, 1, 2, o, o, o, 4, 1, 1, 3, o, o, o, o, o, o, o, 4, 1, 1, 3, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, 3, 1, 1, 1, 3, o, 1, 1, 1, 1, 1, o, 2, 1, 1, 1, 3, o, o, 2, 4, 1, 1, 1, 2, o, 3, 1, 1, 1, 1, 3, 2, o, o, o, o, 3, 1, 1, 1, 1, 3, o, o, o, o, o, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

