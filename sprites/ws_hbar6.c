#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 2
#define WIDTH 6
#define HEIGHT 6
#define o 0
#define STRUCT_NAME ws_hbar6

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, 0, 0 },
	{
		PRGB( 17,  51,  51), 
		PRGB(119,  85,  17), 
		PRGB(187, 119,  85), 
		PRGB(187, 153,  85), 
		PRGB(255, 221,  85), 
		PRGB(255, 255, 221), 
		
	},
	{
		/* sprite #000 */
		 o, 1, 1, 2, 3, 3,
		 2, 3, 4, 5, 5, 5,
		 o, 1, 1, 2, 3, 3,
		/* sprite #001 */
		 3, 3, 2, 1, 1, o,
		 5, 5, 5, 4, 3, 2,
		 3, 3, 2, 1, 1, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

