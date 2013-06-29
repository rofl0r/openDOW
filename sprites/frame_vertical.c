#include "../palpic.h"
#define PAL_COUNT 4
#define SPRITE_COUNT 2
#define WIDTH 2
#define HEIGHT 64
#define o 0
#define STRUCT_NAME frame_vertical

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, 0, 0 },
	{
		PRGB(153,  85,  51), 
		PRGB(221, 187,   0), 
		PRGB(187, 119,  85), 
		PRGB(255, 255, 221), 
		
	},
	{
		/* sprite #000 */
		 o, 1,
		 2, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 1, o,
		 3, o,
		 1, o,
		 3, o,
		 3, o,
		 3, o,
		 3, o,
		 3, o,
		 3, o,
		 3, o,
		 1, o,
		 3, o,
		 1, o,
		 2, o,
		 o, 1,
		/* sprite #001 */
		 1, o,
		 o, 2,
		 o, 1,
		 o, 3,
		 o, 1,
		 o, 3,
		 o, 3,
		 o, 3,
		 o, 3,
		 o, 3,
		 o, 3,
		 o, 3,
		 o, 1,
		 o, 3,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 1,
		 o, 2,
		 1, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

