#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 2
#define WIDTH 6
#define HEIGHT 16
#define o 0
#define STRUCT_NAME grenade

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(187, 153,  85), 
		PRGB(119,  85,  17), 
		PRGB( 17,  51,  51), 
		PRGB( 51,  85,  85), 
		PRGB(187, 119,  85), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, o, o,
		 o, o, 1, 1, o, o,
		 o, 2, 3, 1, 4, o,
		 o, 5, 4, 1, 4, o,
		 o, 4, 2, 4, 4, o,
		 o, o, 4, 4, o, o,
		 o, o, o, o, o, o,
		 o, o, o, o, o, o,
		/* sprite #001 */
		 o, o, 1, 1, o, o,
		 o, 4, 3, 1, 1, o,
		 3, 2, 4, 3, 1, 3,
		 4, 1, 4, 3, 1, 4,
		 4, 5, 2, 4, 1, 4,
		 3, 2, 5, 4, 4, 3,
		 o, 4, 2, 2, 4, o,
		 o, o, 3, 3, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

