#include "../palpic.h"
#define PAL_COUNT 4
#define SPRITE_COUNT 8
#define WIDTH 8
#define HEIGHT 64
#define STRUCT_NAME flash

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB( 187,  85, 17), 
		PRGB( 255, 221, 85), 
		PRGB(153, 153, 119), 
		
	},
	{
		/* sprite #000 */
		 0, 1, 1, 1, 1, 1, 0, 0,
		 1, 2, 2, 2, 2, 3, 1, 1,
		 0, 1, 1, 1, 1, 1, 1, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		/* sprite #001 */
		 0, 0, 0, 0, 0, 1, 0, 0,
		 0, 0, 0, 1, 1, 1, 0, 0,
		 0, 0, 1, 3, 1, 0, 0, 0,
		 0, 1, 2, 2, 1, 0, 0, 0,
		 1, 2, 2, 1, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		/* sprite #002 */
		 0, 1, 0, 0, 0, 0, 0, 0,
		 0, 1, 1, 0, 0, 0, 0, 0,
		 1, 3, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 0, 1, 0, 0, 0, 0, 0, 0,
		/* sprite #003 */
		 1, 1, 0, 0, 0, 0, 0, 0,
		 0, 1, 1, 1, 0, 0, 0, 0,
		 0, 1, 3, 2, 1, 0, 0, 0,
		 0, 0, 1, 2, 2, 1, 0, 0,
		 0, 0, 0, 1, 2, 2, 0, 0,
		 0, 0, 0, 0, 1, 1, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		/* sprite #004 */
		 0, 1, 1, 1, 1, 1, 1, 0,
		 1, 1, 3, 2, 2, 2, 2, 1,
		 0, 0, 1, 1, 1, 1, 1, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		/* sprite #005 */
		 0, 0, 0, 1, 2, 1, 0, 0,
		 0, 0, 1, 2, 2, 1, 0, 0,
		 0, 1, 2, 2, 1, 0, 0, 0,
		 0, 1, 3, 1, 0, 0, 0, 0,
		 1, 1, 1, 0, 0, 0, 0, 0,
		 1, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		/* sprite #006 */
		 0, 1, 0, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 1, 0, 0, 0, 0, 0,
		 1, 3, 1, 0, 0, 0, 0, 0,
		 1, 1, 0, 0, 0, 0, 0, 0,
		 0, 1, 0, 0, 0, 0, 0, 0,
		/* sprite #007 */
		 1, 1, 0, 0, 0, 0, 0, 0,
		 2, 2, 1, 0, 0, 0, 0, 0,
		 1, 2, 2, 1, 0, 0, 0, 0,
		 0, 1, 2, 3, 1, 0, 0, 0,
		 0, 0, 1, 1, 1, 0, 0, 0,
		 0, 0, 0, 0, 1, 1, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		
	},
};

#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

