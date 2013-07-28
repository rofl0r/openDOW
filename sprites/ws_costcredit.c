#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 2
#define WIDTH 70
#define HEIGHT 20
#define o 0
#define STRUCT_NAME ws_costcredit

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB( 51,  85,  85), 
		PRGB( 85, 119, 119), 
		PRGB( 17,  51,  51), 
		PRGB(153, 153, 119), 
		PRGB(187, 187, 187), 
		
	},
	{
		/* sprite #000 */
		 o, o, 1, 2, 2, o, 2, 3, 2, o, o, o, 2, 2, 2, o, 2, 2, 2, o, o, o, o, 1, 2, 2, 2, o, 2, 3, 2, o, 2, 2, o, 2, 2, 2, 2, o, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, 2, 2, 2, o, o, o, 2, 2, o, o, 2, 2, 2, 3, o, 3, 2, 2, 2, o, o, 1, 2, 2, 2, o, o, o, 2, 2, o, 2, 1, o, 4, 2, 2, 2, o, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 1, 4, 2, 2, o, o, o, o, 2, o, 1, 4, 2, 2, o, o, o, 4, 2, 2, 1, o, 2, 4, 2, 2, o, o, o, o, 2, o, 2, 3, o, 5, 2, 2, 2, o, 3, 2, o, o, o, o, o, o, o, o, o, o, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 4, 2, 2, 2, o, o, o, o, o, o, 4, 2, 2, 2, o, o, o, 5, 2, 2, 2, o, 1, 5, 2, 2, 2, o, o, o, o, o, 2, o, o, 5, 2, 2, 2, o, o, 2, o, o, o, 4, 2, 2, 2, 1, 1, 3, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 5, 2, 2, 2, o, o, o, o, o, o, 5, 2, 2, 2, o, o, o, 5, 2, 2, 2, o, o, 2, 5, 2, 2, 2, 1, o, o, o, o, o, o, 5, 2, 2, 2, o, o, o, o, o, 4, 2, 2, 2, 2, 2, 2, 2, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 5, 2, 2, 2, o, o, o, o, o, o, 5, 2, 2, 2, o, o, o, 5, 2, 2, 2, o, o, o, 1, 4, 2, 2, 2, 2, o, o, o, o, o, 5, 2, 2, 2, o, o, o, o, o, 4, 3, 1, 1, 2, 2, 2, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 4, 2, 2, 2, o, o, o, o, o, o, 4, 2, 2, 2, o, o, o, 5, 2, 2, 2, o, o, o, o, o, 4, 2, 2, 2, 1, o, o, o, o, 4, 2, 2, 2, o, o, o, o, o, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 1, 2, 2, 2, o, o, o, o, o, o, 1, 4, 2, 2, o, o, o, 4, 2, 2, 1, o, 2, o, o, o, o, 4, 2, 2, 2, o, o, o, o, 4, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, 2, 2, 2, o, o, o, o, 2, o, o, 2, 2, 2, 3, o, 3, 2, 2, 2, o, o, 2, 2, o, o, o, 4, 2, 2, 1, o, o, o, o, 4, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 1, 2, 2, o, 2, 2, o, o, o, o, 2, 2, 2, o, 2, 2, 2, o, o, o, 2, 3, 2, o, 2, 2, 2, 1, o, o, o, o, o, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #001 */
		 o, o, 1, 2, 2, o, 2, 3, 2, o, 2, 2, 2, 2, o, 2, 2, 1, o, o, o, 2, 2, 2, 2, o, 1, 2, 2, 2, 2, o, 2, 2, 2, 2, o, 2, 2, 1, o, o, 2, 2, 2, 2, 2, 2, o, 2, 2, o, 2, 2, 2, 2, o, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, 2, 2, 2, o, o, o, 2, 2, o, 4, 2, 2, 2, o, o, 4, 2, 2, o, o, 4, 2, 2, 2, o, o, o, 1, 2, 2, o, 4, 2, 2, 2, o, o, 2, 2, 2, o, o, 4, 2, 2, 2, o, o, 2, 1, o, 4, 2, 2, 2, o, 1, 2, o, o, o, o, o, o, o, o, o, o, o,
		 1, 4, 2, 2, o, o, o, o, 2, o, 5, 2, 2, 2, o, o, 5, 2, 2, 1, o, 5, 2, 2, 2, o, o, o, o, o, o, o, 5, 2, 2, 2, o, o, 4, 2, 2, 1, o, 5, 2, 2, 2, o, o, 2, 3, o, 5, 2, 2, 2, o, 3, 2, o, o, o, o, o, o, o, o, o, o, 1,
		 4, 2, 2, 2, o, o, o, o, o, o, 5, 2, 2, 2, o, o, 5, 2, 2, 2, o, 5, 2, 2, 2, o, o, o, o, o, o, o, 5, 2, 2, 2, o, o, 5, 2, 2, 2, o, 5, 2, 2, 2, o, o, 2, o, o, 5, 2, 2, 2, o, o, 2, o, o, o, 4, 2, 2, 2, 1, 1, 3, 2,
		 5, 2, 2, 2, o, o, o, o, o, o, 5, 2, 2, 2, o, o, 4, 2, 2, 1, o, 5, 2, 2, 2, o, 2, 2, 2, o, o, o, 5, 2, 2, 2, o, o, 5, 2, 2, 2, o, 5, 2, 2, 2, o, o, o, o, o, 5, 2, 2, 2, o, o, o, o, o, 4, 2, 2, 2, 2, 2, 2, 2, 1,
		 5, 2, 2, 2, o, o, o, o, o, o, 5, 2, 2, 2, o, 2, 2, 2, 1, o, o, 5, 2, 2, 2, o, o, 1, 2, o, o, o, 5, 2, 2, 2, o, o, 5, 2, 2, 2, o, 5, 2, 2, 2, o, o, o, o, o, 5, 2, 2, 2, o, o, o, o, o, 4, 3, 1, 1, 2, 2, 2, 1, o,
		 4, 2, 2, 2, o, o, o, o, o, o, 5, 2, 2, 2, o, o, 4, 2, 2, 1, o, 5, 2, 2, 2, o, o, o, o, o, o, o, 5, 2, 2, 2, o, o, 5, 2, 2, 2, o, 5, 2, 2, 2, o, o, o, o, o, 4, 2, 2, 2, o, o, o, o, o, 1, o, o, o, o, o, o, o, o,
		 1, 2, 2, 2, o, o, o, o, o, o, 4, 2, 2, 2, o, o, 4, 2, 2, 2, o, 4, 2, 2, 2, o, o, o, o, o, o, o, 4, 2, 2, 2, o, o, 4, 2, 2, 1, o, 5, 2, 2, 2, o, o, o, o, o, 4, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, 2, 2, 2, o, o, o, o, 2, o, 4, 2, 2, 2, o, o, 2, 2, 2, 2, o, 4, 2, 2, 2, o, o, o, 1, 2, 2, o, 4, 2, 2, 2, o, o, 2, 2, 2, o, o, 4, 2, 2, 2, o, o, o, o, o, 4, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 1, 2, 2, o, 2, 2, o, o, 2, 2, 2, 2, o, o, 1, 2, 2, 2, o, 4, 2, 2, 2, o, 1, 2, 2, 2, 2, o, 2, 2, 2, 2, o, 2, 2, 1, o, o, 2, 2, 2, 2, 2, 2, o, o, o, o, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

