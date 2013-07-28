#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 4
#define WIDTH 1
#define HEIGHT 16
#define o 0
#define STRUCT_NAME ws_vbar1

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(255, 221,  85), 
		PRGB(255, 255, 221), 
		PRGB(119,  85,  17), 
		PRGB(187, 119,  85), 
		PRGB(187, 153,  85), 
		
	},
	{
		/* sprite #000 */
		 o,
		 1,
		 2,
		 1,
		/* sprite #001 */
		 3,
		 4,
		 5,
		 1,
		/* sprite #002 */
		 1,
		 5,
		 4,
		 3,
		/* sprite #003 */
		 2,
		 2,
		 2,
		 2,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

