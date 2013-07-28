#include "../palpic.h"
#define PAL_COUNT 7
#define SPRITE_COUNT 4
#define WIDTH 3
#define HEIGHT 40
#define o 0
#define STRUCT_NAME ws_vbar3

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(119,  85,  17), 
		PRGB(187, 153,  85), 
		PRGB( 17,  51,  51), 
		PRGB(255, 221,  85), 
		PRGB(187, 119,  85), 
		PRGB(255, 255, 221), 
		
	},
	{
		/* sprite #000 */
		 o, o, o,
		 o, o, o,
		 1, 2, 1,
		 3, 1, 3,
		 1, 4, 1,
		 5, 6, 5,
		 2, 6, 2,
		 2, 6, 2,
		 4, 6, 2,
		 4, 6, 2,
		/* sprite #001 */
		 4, 6, 2,
		 4, 6, 2,
		 2, 6, 2,
		 2, 6, 2,
		 5, 6, 5,
		 1, 4, 1,
		 1, 6, 1,
		 6, 2, 4,
		 o, o, o,
		 o, o, o,
		/* sprite #002 */
		 3, 2, 3,
		 3, 2, 3,
		 1, 4, 1,
		 1, 6, 1,
		 5, 6, 5,
		 5, 6, 5,
		 2, 6, 2,
		 2, 6, 2,
		 4, 6, 2,
		 4, 6, 2,
		/* sprite #003 */
		 4, 6, 2,
		 4, 6, 2,
		 2, 6, 2,
		 2, 6, 2,
		 5, 6, 5,
		 5, 6, 5,
		 1, 6, 1,
		 1, 4, 1,
		 3, 2, 3,
		 3, 2, 3,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

