#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 2
#define WIDTH 10
#define HEIGHT 6
#define o 0
#define STRUCT_NAME ws_hbar10

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, 0, 0 },
	{
		PRGB(187, 153,  85), 
		PRGB(187, 119,  85), 
		PRGB(119,  85,  17), 
		PRGB( 17,  51,  51), 
		PRGB(255, 221,  85), 
		PRGB(255, 255, 221), 
		
	},
	{
		/* sprite #000 */
		 o, o, 1, 1, 2, 2, 3, 3, 3, 4,
		 5, 5, 4, o, o, 1, 1, 2, 2, o,
		 o, o, 1, 1, 2, 2, 3, 3, 3, 2,
		/* sprite #001 */
		 4, 3, 3, 3, 2, 2, 1, 1, o, o,
		 o, 2, 2, 1, 1, o, o, 4, 5, 5,
		 2, 3, 3, 3, 2, 2, 1, 1, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

