#include "../palpic.h"
#define PAL_COUNT 4
#define SPRITE_COUNT 8
#define WIDTH 10
#define HEIGHT 80
#define o 0
#define STRUCT_NAME rocket

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB( 85, 119, 119), 
		PRGB(153, 153, 119), 
		PRGB(187, 187, 187), 
		
	},
	{
		/* sprite #000 */
		 o, 1, o, o, o, o, o, o, o, o,
		 1, 1, 1, o, o, o, o, o, o, o,
		 1, 1, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		 2, 3, 1, o, o, o, o, o, o, o,
		/* sprite #001 */
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 3, 2, o, o, o, o, o, o, o,
		 1, 1, 1, o, o, o, o, o, o, o,
		 1, 1, 1, o, o, o, o, o, o, o,
		 o, 1, o, o, o, o, o, o, o, o,
		/* sprite #002 */
		 2, 2, 2, 2, 2, 2, 2, 1, 1, o,
		 3, 3, 3, 3, 3, 3, 3, 1, 1, 1,
		 1, 1, 1, 1, 1, 1, 1, 1, 1, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		/* sprite #003 */
		 o, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		 1, 1, 1, 3, 3, 3, 3, 3, 3, 3,
		 o, 1, 1, 2, 2, 2, 2, 2, 2, 2,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		/* sprite #004 */
		 o, o, o, o, o, o, 1, 1, o, o,
		 o, o, o, o, o, 1, 1, 1, o, o,
		 o, o, o, o, 1, 3, 2, 1, o, o,
		 o, o, o, 1, 3, 2, 1, o, o, o,
		 o, o, 1, 3, 2, 1, o, o, o, o,
		 o, 1, 3, 2, 1, o, o, o, o, o,
		 1, 3, 2, 1, o, o, o, o, o, o,
		 o, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		/* sprite #005 */
		 o, 1, o, o, o, o, o, o, o, o,
		 1, 3, 1, o, o, o, o, o, o, o,
		 1, 2, 3, 1, o, o, o, o, o, o,
		 o, 1, 2, 3, 1, o, o, o, o, o,
		 o, o, 1, 2, 3, 1, o, o, o, o,
		 o, o, o, 1, 2, 3, 1, o, o, o,
		 o, o, o, o, 1, 2, 1, 1, o, o,
		 o, o, o, o, o, 1, 1, 1, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		/* sprite #006 */
		 o, o, o, o, o, 1, 1, o, o, o,
		 o, o, o, o, 1, 2, 3, 1, o, o,
		 o, o, o, 1, 2, 3, 1, o, o, o,
		 o, o, 1, 2, 3, 1, o, o, o, o,
		 o, 1, 2, 3, 1, o, o, o, o, o,
		 1, 2, 3, 1, o, o, o, o, o, o,
		 1, 1, 1, o, o, o, o, o, o, o,
		 1, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		/* sprite #007 */
		 1, 1, 1, o, o, o, o, o, o, o,
		 1, 1, 2, 1, o, o, o, o, o, o,
		 o, 1, 3, 2, 1, o, o, o, o, o,
		 o, o, 1, 3, 2, 1, o, o, o, o,
		 o, o, o, 1, 3, 2, 1, o, o, o,
		 o, o, o, o, 1, 3, 2, 1, o, o,
		 o, o, o, o, o, 1, 3, 1, o, o,
		 o, o, o, o, o, o, 1, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

