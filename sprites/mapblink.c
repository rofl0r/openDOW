#include "../palpic.h"
#define PAL_COUNT 2
#define SPRITE_COUNT 7
#define WIDTH 5
#define HEIGHT 35
#define o 0
#define STRUCT_NAME mapblink

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(255, 255, 255), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		/* sprite #001 */
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, 1, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		/* sprite #002 */
		 o, o, o, o, o,
		 o, o, 1, o, o,
		 o, 1, 1, 1, o,
		 o, o, 1, o, o,
		 o, o, o, o, o,
		/* sprite #003 */
		 o, 1, 1, 1, o,
		 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1,
		 1, 1, 1, 1, 1,
		 o, 1, 1, 1, o,
		/* sprite #004 */
		 o, o, o, o, o,
		 o, o, 1, o, o,
		 o, 1, 1, 1, o,
		 o, o, 1, o, o,
		 o, o, o, o, o,
		/* sprite #005 */
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, 1, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		/* sprite #006 */
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		 o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

