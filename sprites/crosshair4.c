#include "../palpic.h"
#define PAL_COUNT 2
#define SPRITE_COUNT 1
#define WIDTH 9
#define HEIGHT 9
#define STRUCT_NAME crosshair4

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(255, 148,  21), 
		
	},
	{
		/* sprite #000 */
		 0, 0, 0, 1, 0, 1, 0, 0, 0,
		 0, 0, 0, 1, 0, 1, 0, 0, 0,
		 0, 0, 1, 0, 0, 0, 1, 0, 0,
		 1, 1, 0, 0, 0, 0, 0, 1, 1,
		 0, 0, 0, 0, 1, 0, 0, 0, 0,
		 1, 1, 0, 0, 0, 0, 0, 1, 1,
		 0, 0, 1, 0, 0, 0, 1, 0, 0,
		 0, 0, 0, 1, 0, 1, 0, 0, 0,
		 0, 0, 0, 1, 0, 1, 0, 0, 0,
		
	},
};

#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

