#include "../palpic.h"
#define PAL_COUNT 7
#define SPRITE_COUNT 1
#define WIDTH 7
#define HEIGHT 7
#define o 0
#define STRUCT_NAME ws_bolt

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(255, 255, 221), 
		PRGB(187, 153,  85), 
		PRGB(187, 119,  85), 
		PRGB(255, 221,  85), 
		PRGB(119,  85,  17), 
		PRGB( 17,  51,  51), 
		
	},
	{
		/* sprite #000 */
		 o, 1, 2, 3, 2, 4, o,
		 1, 2, 3, 5, 3, 2, 4,
		 2, 3, 5, 6, 5, 3, 2,
		 3, 5, 6, o, 6, 5, 3,
		 3, 3, 5, 6, 5, 3, 2,
		 5, 3, 3, 5, 3, 2, 5,
		 o, 5, 3, 3, 3, 5, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

