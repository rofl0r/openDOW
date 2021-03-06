#include "../palpic.h"
#define PAL_COUNT 9
#define SPRITE_COUNT 5
#define WIDTH 48
#define HEIGHT 200
#define o 0
#define STRUCT_NAME bigexpl

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(187,  85,  17), 
		PRGB(119,  85,  17), 
		PRGB(187, 119,  85), 
		PRGB(187, 153,  85), 
		PRGB(255, 221,  85), 
		PRGB(255, 255, 221), 
		PRGB(187, 187, 187), 
		PRGB( 17,  17,  17), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 2, o, 3, 1, 3, 4, 3, 3, 2, 2, 1, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 3, 1, 4, 4, 5, 6, 5, 3, 3, 1, 3, 3, 3, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 5, 5, 6, 5, 4, 4, 5, 6, 6, 5, 3, 4, 4, 4, 4, 3, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 3, 4, 5, 6, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 5, 5, 4, 3, 3, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 4, 5, 5, 6, 6, 6, 5, 4, 3, 3, 5, 5, 5, 6, 6, 4, 4, 3, 1, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 5, 4, 4, 5, 6, 5, 5, 4, 5, 4, 3, 3, 5, 6, 5, 6, 5, 4, 3, 3, 1, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 1, 5, 5, 5, 5, 5, 5, 6, 5, 5, 6, 6, 6, 5, 3, 5, 3, 3, 5, 5, 4, 5, 3, 3, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 1, 5, 5, 3, 3, 5, 5, 4, 4, 3, 3, 5, 6, 5, 5, 3, 5, 5, 3, 3, 5, 5, 6, 5, 3, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 2, 5, 3, 3, 3, 5, 5, 4, 1, 3, 3, 3, 5, 6, 5, 3, 3, 5, 5, 5, 3, 3, 5, 5, 6, 3, 1, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 2, 3, 3, 3, 5, 6, 6, 6, 1, 3, 5, 5, 5, 5, 5, 3, 3, 3, 5, 6, 6, 5, 3, 7, 5, 5, 5, 3, 3, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 3, 3, 5, 3, 6, 6, 5, 5, 3, 5, 5, 6, 6, 6, 5, 3, 5, 5, 3, 5, 6, 5, 5, 3, 3, 5, 5, 5, 3, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 3, 5, 3, 7, 6, 6, 6, 5, 3, 3, 5, 6, 6, 5, 5, 5, 6, 5, 3, 3, 5, 5, 3, 3, 1, 3, 5, 3, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 5, 3, 5, 6, 5, 5, 5, 5, 3, 3, 7, 6, 5, 5, 6, 6, 4, 4, 5, 5, 6, 6, 5, 4, 1, 3, 3, 3, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 3, 5, 5, 5, 5, 3, 5, 6, 6, 6, 5, 5, 6, 6, 6, 5, 6, 5, 4, 4, 5, 5, 6, 6, 5, 1, 3, 3, 4, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 3, 5, 6, 6, 5, 3, 5, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 5, 5, 5, 5, 5, 6, 6, 5, 3, 3, 5, 4, 4, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 3, 5, 6, 5, 5, 3, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 4, 5, 6, 5, 5, 3, 5, 5, 4, 4, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 5, 6, 6, 5, 5, 3, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 7, 4, 5, 5, 5, 5, 5, 5, 3, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 3, 5, 5, 4, 3, 5, 5, 6, 3, 5, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 4, 4, 5, 4, 3, 5, 5, 3, 4, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 3, 5, 5, 4, 3, 7, 6, 5, 5, 3, 5, 5, 6, 5, 6, 6, 5, 6, 6, 6, 5, 4, 6, 5, 5, 4, 3, 5, 4, 3, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 5, 5, 4, 3, 5, 6, 6, 5, 1, 5, 5, 6, 6, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 6, 5, 1, 1, 5, 5, 3, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 3, 5, 5, 3, 4, 5, 6, 6, 1, 3, 5, 5, 6, 6, 6, 6, 5, 5, 6, 4, 5, 6, 6, 5, 4, 1, 1, 5, 4, 3, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 3, 5, 5, 5, 3, 4, 6, 5, 5, 1, 3, 7, 6, 6, 6, 6, 6, 4, 4, 1, 5, 5, 5, 5, 4, 1, 3, 5, 4, 3, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 3, 3, 5, 3, 5, 3, 3, 5, 5, 5, 3, 3, 5, 6, 6, 6, 6, 3, 1, 5, 5, 3, 4, 3, 3, 3, 5, 3, 4, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 1, o, 3, 5, 6, 5, 5, 6, 6, 5, 5, 5, 5, 5, 6, 5, 5, 5, 5, 5, 5, 4, 5, 5, 6, 5, 5, 3, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 3, 6, 6, 5, 3, 6, 6, 6, 5, 4, 5, 5, 5, 3, 5, 5, 5, 5, 5, 5, 5, 6, 6, 5, 3, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 5, 6, 6, 5, 3, 5, 6, 6, 6, 3, 3, 3, 3, 3, 5, 5, 6, 5, 5, 5, 6, 6, 5, 5, 3, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 4, 4, 5, 6, 6, 5, 3, 5, 5, 5, 5, 4, 4, 5, 5, 6, 6, 6, 5, 3, 3, 5, 5, 3, 3, 1, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 3, 5, 5, 6, 6, 5, 3, 3, 3, 5, 5, 5, 5, 4, 5, 6, 6, 6, 5, 4, 1, 1, 3, 1, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 1, 3, 3, 5, 5, 4, 4, 5, 5, 6, 6, 5, 5, 4, 6, 6, 6, 6, 5, 4, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 3, 3, 3, 3, 5, 6, 6, 6, 6, 5, 1, 5, 5, 5, 5, 5, 3, 3, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 3, 3, 5, 5, 5, 5, 1, 3, 3, 5, 5, 3, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 3, 3, 3, 3, o, o, o, 3, 3, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #001 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 2, 2, 1, 1, 3, 3, 4, 3, 3, 2, 2, 2, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 3, 3, 3, 1, 3, 3, 4, 4, 6, 5, 3, 3, 3, 1, 3, 3, 3, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 3, 4, 5, 6, 5, 5, 4, 4, 5, 6, 6, 5, 3, 3, 4, 4, 4, 4, 3, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 3, 3, 4, 5, 6, 6, 6, 5, 5, 1, 5, 5, 5, 5, 4, 4, 4, 5, 5, 4, 3, 3, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 3, 5, 5, 6, 6, 6, 5, 5, 4, 5, 5, 5, 5, 4, 4, 5, 6, 5, 5, 3, 3, 3, 1, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 1, 1, 3, 5, 5, 6, 6, 6, 5, 5, 4, 3, 3, 4, 5, 5, 6, 6, 6, 4, 4, 3, 3, 1, 1, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 2, 1, 3, 4, 4, 1, 4, 5, 6, 5, 5, 4, 4, 5, 4, 1, 3, 4, 5, 6, 5, 6, 5, 4, 4, 3, 3, 1, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 1, 3, 4, 5, 5, 5, 5, 5, 6, 5, 5, 6, 6, 6, 6, 5, 1, 3, 6, 3, 3, 5, 5, 4, 5, 5, 3, 3, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 3, 5, 5, 4, 4, 4, 4, 5, 3, 1, 1, 3, 3, 5, 6, 5, 5, 1, 3, 1, 1, 3, 3, 5, 5, 6, 6, 5, 3, o, 2, 2, o, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 1, 2, 4, 4, 5, 3, 1, 1, 3, 5, 3, 1, 3, 5, 5, 5, 5, 6, 5, 3, 1, 1, 4, 4, 3, 1, 4, 5, 6, 6, 6, 3, 1, 1, 2, 2, o, o, o, o, o,
		 o, o, o, o, o, 2, 2, 1, 2, 4, 4, 3, 1, 3, 5, 5, 3, 1, 5, 5, 6, 6, 5, 5, 6, 5, 3, 3, 3, 5, 6, 5, 3, 1, 3, 5, 5, 6, 3, 3, 3, 1, o, 2, o, o, o, o,
		 o, o, o, o, o, 2, 1, 2, 3, 3, 3, 1, 3, 5, 6, 6, 3, 1, 5, 6, 6, 6, 5, 5, 5, 3, 3, 1, 4, 5, 6, 6, 5, 3, 3, 7, 5, 6, 5, 3, 3, 3, 1, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 3, 3, 4, 4, 3, 5, 6, 5, 5, 5, 3, 5, 5, 6, 6, 6, 6, 5, 3, 4, 5, 5, 3, 5, 6, 5, 5, 3, 1, 3, 5, 5, 5, 5, 3, 1, o, o, o, o, o,
		 o, o, o, o, o, 2, 2, 3, 4, 4, 5, 4, 6, 6, 6, 5, 5, 3, 5, 5, 6, 6, 6, 5, 5, 5, 6, 5, 5, 3, 3, 5, 5, 3, 1, 1, 1, 3, 5, 3, 3, 1, o, o, o, o, o, o,
		 o, o, o, o, o, 2, o, 1, 4, 5, 5, 4, 6, 5, 5, 6, 5, 5, 3, 5, 7, 6, 6, 5, 5, 6, 6, 5, 4, 1, 5, 5, 3, 4, 5, 5, 4, 1, 3, 3, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, 2, 1, 3, 4, 5, 5, 4, 5, 3, 5, 6, 6, 6, 5, 5, 5, 6, 6, 6, 6, 5, 6, 6, 5, 4, 4, 5, 5, 5, 6, 6, 5, 1, 3, 3, 1, 4, 1, o, o, o, o, o,
		 o, o, o, o, 2, 2, 1, 3, 4, 5, 5, 5, 4, 1, 5, 6, 6, 6, 5, 5, 5, 6, 6, 6, 6, 5, 6, 6, 6, 4, 5, 5, 5, 6, 6, 6, 5, 1, 5, 3, 3, 3, 3, 1, o, o, o, o,
		 o, o, o, 2, 2, 2, 1, 3, 5, 6, 6, 6, 4, 1, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 6, 5, 5, 5, 5, 5, 6, 6, 6, 5, 3, 3, 5, 5, 4, 3, 1, o, o, o, o,
		 o, o, o, 2, 2, o, 1, 3, 5, 6, 6, 5, 5, 3, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 4, 5, 6, 6, 5, 5, 3, 5, 6, 5, 4, 3, 1, o, o, o, o,
		 o, o, o, o, 2, o, 1, 1, 5, 6, 6, 6, 5, 5, 3, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 6, 6, 7, 4, 5, 5, 5, 5, 5, 5, 5, 4, 3, 1, 2, o, o, o, o,
		 o, o, o, o, o, o, o, 3, 5, 5, 5, 4, 3, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 4, 4, 5, 5, 4, 3, 5, 4, 3, 3, 3, 2, 2, o, o, o, o,
		 o, o, o, o, o, o, 3, 5, 5, 4, 4, 3, 5, 6, 5, 5, 4, 5, 6, 6, 6, 5, 5, 6, 6, 5, 6, 6, 6, 6, 5, 4, 6, 5, 6, 5, 4, 3, 5, 4, 3, 3, 2, o, o, o, o, o,
		 o, o, o, o, o, o, 3, 4, 5, 4, 1, 3, 5, 6, 5, 5, 3, 3, 5, 5, 5, 5, 5, 6, 6, 5, 6, 6, 6, 6, 5, 4, 6, 6, 6, 5, 4, 3, 5, 4, 4, 3, o, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 4, 5, 4, 1, 3, 5, 6, 6, 3, 1, 1, 4, 5, 6, 5, 6, 6, 6, 5, 5, 6, 6, 6, 6, 5, 6, 6, 6, 6, 5, 1, 1, 5, 4, 1, 1, o, o, o, o, o,
		 o, o, o, o, o, 2, 1, 3, 5, 5, 1, 1, 4, 5, 6, 6, 1, 1, 3, 5, 5, 6, 6, 6, 6, 1, 5, 6, 6, 6, 6, 5, 5, 6, 5, 5, 3, 1, 1, 5, 5, 4, 1, 2, o, o, o, o,
		 o, o, o, o, o, 2, 1, 3, 4, 5, 3, 1, 1, 4, 6, 5, 3, 1, 1, 3, 7, 6, 6, 6, 6, 3, 5, 5, 6, 6, 5, 4, 5, 5, 4, 3, 1, 1, 3, 5, 4, 4, 3, 2, o, o, o, o,
		 o, o, o, o, o, 2, 1, 3, 3, 5, 5, 3, 3, 3, 3, 5, 4, 3, 4, 3, 3, 5, 6, 6, 6, 3, 1, 5, 5, 5, 4, 1, 5, 4, 1, 1, 1, 3, 4, 3, 3, 4, 1, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 1, 2, 4, 3, 5, 6, 5, 4, 6, 5, 4, 4, 4, 5, 5, 5, 6, 6, 5, 1, 5, 5, 4, 1, 5, 4, 4, 4, 5, 4, 3, 4, 3, 3, 1, 2, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 1, 2, 3, 4, 5, 6, 5, 5, 6, 6, 5, 5, 4, 3, 5, 5, 5, 6, 5, 5, 4, 3, 3, 4, 5, 4, 5, 5, 6, 5, 4, 3, 1, 1, 1, 2, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 2, 4, 3, 6, 6, 5, 3, 6, 6, 6, 6, 5, 1, 3, 4, 5, 3, 3, 5, 5, 6, 6, 5, 5, 5, 5, 5, 6, 6, 5, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 4, 5, 6, 6, 5, 3, 5, 5, 6, 6, 6, 3, 1, 1, 3, 1, 3, 5, 5, 6, 6, 5, 5, 5, 6, 6, 6, 5, 3, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 4, 4, 5, 5, 6, 6, 5, 3, 3, 5, 5, 5, 4, 4, 1, 1, 4, 5, 5, 5, 5, 6, 5, 3, 3, 5, 5, 5, 3, 3, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 3, 3, 5, 5, 6, 6, 5, 5, 3, 3, 3, 5, 5, 5, 5, 5, 4, 5, 6, 6, 6, 6, 5, 4, 1, 1, 3, 3, 1, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 3, 3, 4, 5, 5, 4, 4, 1, 3, 4, 6, 6, 6, 5, 5, 4, 6, 6, 6, 6, 6, 5, 4, 4, 1, 1, 1, 1, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 3, 3, 4, 3, 1, 1, 1, 4, 5, 6, 6, 6, 5, 5, 4, 6, 6, 6, 6, 6, 5, 4, 4, 1, 1, 1, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 1, 1, 1, 2, 1, 3, 4, 5, 6, 6, 6, 4, 1, 5, 5, 5, 5, 5, 5, 3, 3, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 3, 4, 5, 5, 4, 1, 2, 1, 1, 5, 5, 3, 3, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 1, 3, 3, o, o, 2, 2, 1, 1, 1, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #002 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 2, 2, o, o, o, o, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 3, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 1, 1, 1, 4, 4, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, o, 3, 3, 3, 3, 4, 1, 3, 3, 3, 4, 3, 3, 1, 4, 4, 4, 5, 4, 3, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 1, 4, 5, 6, 5, 5, 3, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 1, 3, 4, 5, 6, 4, 5, 4, 4, 4, 3, 4, 4, 5, 6, 6, 6, 4, 1, 1, 1, 1, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 2, 2, 1, 1, 4, 5, 6, 5, 4, 4, 4, 3, 1, 3, 4, 5, 5, 5, 5, 5, 1, 4, 3, 1, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 2, 3, 4, 4, 1, 5, 5, 5, 1, 1, 1, 6, 3, 3, 3, 3, 6, 3, 3, 5, 5, 3, 3, 3, 3, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 4, 5, 4, 1, 1, 1, 2, 1, 1, 3, 1, 5, 3, 3, 1, 3, 1, 1, 3, 1, 4, 5, 3, 3, 3, o, 2, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 2, 1, 1, 4, 3, 1, 1, 2, 2, 1, 1, 3, 3, 3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 4, 5, 6, 5, 3, 1, 1, 2, 2, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 2, 1, 2, 4, 1, 1, 1, 1, 1, 2, 1, 3, 3, 3, 4, 4, 3, 5, 1, 1, 3, 1, 1, 1, 2, 1, 3, 5, 6, 3, 3, 3, 1, o, 2, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 4, 4, 6, 5, 5, 3, 1, 1, 4, 1, 3, 3, 2, 1, 3, 5, 5, 4, 3, 3, 3, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 3, 4, 1, 1, 1, 3, 3, 1, 3, 3, 4, 5, 6, 6, 6, 3, 1, 4, 4, 3, 4, 3, 3, 1, 1, 3, 5, 5, 4, 3, 3, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 1, 1, 4, 3, 3, 1, 3, 3, 4, 1, 1, 3, 5, 6, 5, 6, 5, 5, 5, 5, 4, 3, 3, 4, 3, 1, 1, 1, 3, 4, 3, 3, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 1, 1, 4, 3, 3, 1, 3, 4, 4, 3, 1, 1, 5, 5, 6, 6, 5, 5, 5, 4, 4, 1, 4, 4, 3, 4, 1, 1, 1, 1, 1, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 1, 1, 1, 3, 4, 1, 3, 4, 5, 5, 5, 1, 5, 5, 6, 6, 5, 5, 5, 5, 5, 4, 1, 1, 3, 3, 3, 1, 1, 3, 1, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 2, 1, 3, 3, 1, 5, 5, 1, 5, 5, 6, 6, 5, 5, 5, 5, 6, 5, 5, 6, 6, 6, 3, 3, 1, 1, 5, 3, 1, 1, 3, 3, 3, 1, 1, 1, o, o, o, o, o,
		 o, o, o, o, o, 2, 2, o, 1, 3, 3, 5, 6, 5, 5, 1, 1, 5, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6, 6, 6, 5, 3, 1, 5, 3, 1, 3, 4, 3, 3, 3, 1, 1, o, o, o, o, o,
		 o, o, o, o, o, o, 2, o, 1, 1, 3, 6, 5, 1, 1, 1, 5, 5, 1, 5, 5, 5, 6, 6, 5, 6, 5, 5, 5, 5, 3, 3, 1, 1, 3, 5, 4, 4, 3, 3, 3, 1, 2, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 3, 4, 5, 5, 1, 1, 3, 5, 1, 1, 3, 3, 5, 6, 5, 6, 6, 5, 5, 3, 3, 3, 3, 1, 1, 5, 3, 5, 1, 1, 3, 1, 1, 2, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 3, 3, 5, 4, 1, 1, 3, 3, 5, 1, 3, 3, 4, 5, 5, 5, 6, 5, 6, 6, 6, 1, 1, 1, 1, 5, 5, 4, 1, 4, 1, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 3, 3, 5, 4, 1, 3, 3, 5, 5, 1, 3, 3, 4, 4, 3, 6, 6, 5, 6, 5, 1, 4, 1, 1, 1, 6, 4, 4, 1, 2, 4, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 2, 2, 1, 5, 4, 1, 3, 5, 6, 3, 1, 1, 3, 3, 3, 3, 6, 6, 5, 5, 6, 6, 4, 4, 1, 6, 6, 4, 3, 2, 2, 4, 3, 1, 2, o, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 2, 1, 1, 3, 5, 1, 1, 3, 6, 3, 1, 1, 3, 3, 3, 3, 5, 5, 1, 5, 6, 6, 4, 1, 1, 5, 4, 3, 1, 2, 1, 4, 3, 1, 2, 2, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 2, 1, 1, 3, 4, 3, 1, 1, 5, 3, 3, 1, 1, 3, 4, 5, 5, 4, 3, 1, 5, 4, 1, 1, 1, 1, 1, 1, 2, 1, 1, 4, 3, 4, 1, 2, o, o, o, o, o,
		 o, o, o, o, o, o, 2, 2, 1, 1, 3, 3, 3, 3, 3, 1, 5, 4, 3, 4, 1, 3, 4, 4, 4, 3, 1, 1, 1, 4, 1, 1, 3, 1, 1, 1, 3, 4, 3, 3, 4, 1, 2, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 2, 1, 1, 4, 3, 4, 5, 1, 5, 5, 4, 4, 1, 3, 4, 4, 3, 3, 1, 1, 1, 1, 1, 3, 4, 4, 4, 4, 1, 4, 3, 3, 1, 2, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 1, 1, 1, 1, 1, 5, 1, 1, 6, 5, 5, 1, 2, 3, 3, 3, 1, 1, 4, 3, 3, 4, 3, 3, 5, 4, 3, 1, 1, 1, 1, 1, 2, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 4, 6, 2, 1, 5, 6, 6, 5, 1, 2, 2, 1, 1, 5, 6, 5, 5, 5, 4, 3, 4, 4, 3, 3, 1, o, 2, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 1, 3, 3, 6, 1, 2, 1, 5, 6, 1, 3, 1, 2, 1, 1, 3, 6, 6, 6, 5, 1, 1, 3, 3, 3, 3, 2, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 1, 1, 3, 3, 4, 5, 2, 2, 1, 1, 1, 4, 4, 1, 1, 3, 3, 5, 5, 6, 4, 3, 1, 1, 3, 3, 1, 2, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 3, 3, 3, 3, 1, 2, 1, 3, 5, 5, 5, 5, 4, 3, 3, 4, 4, 3, 3, 4, 1, 1, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 1, 3, 3, 4, 4, 1, 3, 4, 5, 5, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, o, 1, 1, 1, 2, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #003 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, o, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, o, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 2, o, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 3, 3, 3, 1, 2, 2, 2, 2, 1, 1, 2, 1, 3, 1, 1, o, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 1, 1, 1, 2, 1, 3, 3, 2, 1, 1, 1, 4, 4, 4, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 3, 1, 1, 3, 1, 1, 4, 4, 4, 3, 3, 3, 1, 2, 2, 1, 3, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 1, 3, 3, 3, 3, 4, 4, 1, 2, 1, 1, 4, 3, 3, 2, 2, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 1, 1, 3, 4, 4, 5, 5, 4, 3, 1, 2, 2, 2, 4, 4, 4, 2, 4, 3, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 3, 4, 1, 4, 4, 4, 1, 1, 4, 4, 3, 3, 3, 2, 2, 4, 4, 3, 3, 1, 1, o, 2, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 3, 3, 4, 1, 2, 2, 1, 1, 3, 1, 4, 3, 3, 1, 1, 2, 3, 1, 4, 3, 3, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 2, 1, 2, 1, 4, 3, 2, 2, 2, 1, 1, 3, 1, 1, 3, 4, 3, 1, 1, 1, 2, 1, 4, 5, 4, 3, 1, 1, 2, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 3, 1, 2, 2, 1, 1, 1, 1, 2, 2, 2, 3, 5, 3, 3, 1, 3, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 1, 1, 3, 4, 1, 2, 1, 3, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 3, 4, 1, 1, 2, 2, 3, 4, 1, 2, 3, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 2, 1, 4, 3, 1, 1, 3, 4, 1, 1, 3, 3, 4, 4, 3, 3, 3, 3, 1, 3, 4, 3, 1, 2, 1, 4, 1, 2, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 1, 1, 4, 3, 1, 3, 4, 4, 3, 1, 1, 4, 5, 4, 4, 4, 3, 3, 1, 4, 4, 3, 1, 2, 1, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 3, 1, 3, 4, 4, 5, 4, 1, 5, 5, 5, 4, 4, 4, 3, 3, 2, 1, 3, 3, 1, 1, 3, 1, 1, 2, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 2, 2, o, 1, 1, 3, 3, 4, 4, 1, 1, 4, 5, 4, 4, 5, 5, 4, 4, 4, 3, 3, 2, 2, 1, 4, 1, 1, 4, 3, 3, 2, 2, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, o, 2, 1, 3, 4, 1, 1, 1, 4, 4, 4, 4, 4, 5, 5, 4, 5, 4, 3, 3, 1, 2, 1, 1, 3, 4, 4, 3, 3, 3, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 4, 3, 1, 2, 3, 4, 1, 1, 4, 4, 5, 4, 5, 5, 4, 3, 3, 1, 2, 1, 1, 4, 3, 1, 1, 3, 1, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 4, 1, 2, 3, 4, 1, 1, 3, 4, 4, 4, 5, 3, 3, 3, 1, 1, 2, 1, 4, 5, 4, 4, 1, 1, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 1, 4, 3, 2, 2, 3, 1, 1, 3, 4, 1, 3, 3, 3, 1, 1, 4, 1, 1, 4, 5, 4, 4, 1, 4, 1, 1, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 4, 3, 1, 2, 2, 1, 1, 1, 3, 1, 1, 1, 1, 1, 4, 4, 4, 1, 3, 3, 3, 3, 2, 4, 3, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 4, 4, 3, 1, 4, 1, 1, 1, 1, 1, 1, 2, 2, 4, 3, 1, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 2, 2, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3, 4, 2, 4, 4, 4, 3, 1, 1, 4, 1, 1, 3, 1, 2, 2, 4, 3, 1, 4, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 2, 2, 1, 2, 4, 4, 3, 3, 3, 1, 1, 4, 1, 2, 2, 1, 1, 1, 1, 1, 1, 3, 4, 4, 1, 1, 1, 1, 1, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 1, 2, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 4, 3, 4, 3, 3, 3, 4, 3, 1, 1, 2, 1, 2, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 2, 2, 1, 1, 1, 3, 4, 4, 1, 1, 4, 1, 1, 4, 4, 4, 3, 4, 3, 4, 5, 3, 1, o, 2, 2, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 3, 1, 1, 1, 1, 3, 4, 4, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 3, 3, 3, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 3, 1, 3, 3, 1, 1, 1, 4, 5, 5, 4, 4, 1, 1, 4, 3, 1, 1, 1, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 3, 1, 1, 4, 1, 3, 3, 4, 4, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 1, 3, 3, 1, 1, 1, 2, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 2, 1, 2, 1, 3, 1, 1, 2, 2, 2, 1, 1, 1, 1, 2, 1, 2, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, o, 2, 2, o, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, o, 2, 2, 2, o, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #004 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 8, 2, 8, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 8, 2, 1, 2, 1, 2, 2, 2, 2, 8, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 3, 1, 2, 2, 8, 2, 1, 2, 2, 2, o, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 3, 1, 1, 2, 1, 3, 2, 1, 2, 1, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 1, 2, 1, 3, 3, 1, 2, 1, 1, 2, 8, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 2, 2, 1, 3, 3, 1, 1, 1, 2, 8, 1, 1, 2, 2, o, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 8, 2, 2, 3, 1, 3, 3, 1, 1, 3, 3, 1, 2, 2, 3, 1, 8, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 8, 2, 1, 3, 3, 3, 1, 2, 1, 1, 2, 3, 2, 8, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 1, 2, 1, 1, 1, 8, 1, 1, 2, 1, 8, 1, 1, 1, 3, 3, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 2, 3, 4, 1, 2, 3, 1, 3, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 1, 2, 1, 3, 3, 1, 1, 3, 3, 3, 1, 2, 1, 4, 1, 2, 1, 2, 8, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 3, 1, 2, 1, 3, 1, 3, 3, 4, 4, 1, 1, 2, 1, 3, 1, 2, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 3, 3, 1, 1, 3, 4, 1, 3, 4, 4, 3, 3, 1, 1, 2, 1, 3, 1, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 3, 1, 3, 3, 1, 3, 1, 4, 3, 3, 1, 3, 1, 8, 1, 3, 3, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 3, 3, 1, 1, 3, 2, 3, 1, 1, 3, 1, 3, 3, 3, 2, 3, 3, 1, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 3, 1, 2, 2, 8, 2, 3, 1, 1, 1, 2, 3, 8, 1, 1, 1, 1, 3, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 3, 3, 1, 1, 2, 1, 1, 3, 3, 1, 2, 1, 2, 1, 2, 3, 3, 2, 1, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 8, 1, 1, 3, 3, 2, 3, 2, 2, 1, 1, 2, 8, 2, 1, 3, 1, 2, 2, 1, 2, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 2, 1, 2, 1, 1, 1, 1, 8, 2, 8, 2, 1, 3, 3, 3, 1, 8, 2, 2, o, 2, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 8, 1, 2, 1, 2, 2, 1, 1, 2, 1, 1, 3, 3, 3, 1, 2, 2, o, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 1, 2, 1, 3, 3, 3, 3, 1, 2, 1, 1, 1, 8, 2, 1, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 1, 1, 3, 3, 3, 3, 2, 3, 1, 2, 1, 8, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 1, 2, 2, 2, 3, 1, 3, 2, 2, 8, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, o, 2, 2, 2, 2, 1, 1, 2, 2, o, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 2, 2, 2, 2, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

