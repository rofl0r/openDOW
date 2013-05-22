#include "palpic.h"
#define PAL_COUNT 3
#define SPRITE_COUNT 3
#define WIDTH 2
#define HEIGHT 6
#define STRUCT_NAME bullet

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, 0, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(254, 254, 254), 
		PRGB(255, 148,  21), 
		
	},
	{
		/* sprite #000 */
		 0, 0,
		 0, 0,
		/* sprite #001 */
		 1, 1,
		 1, 1,
		/* sprite #002 */
		 2, 2,
		 2, 2,
		
	},
};

#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

