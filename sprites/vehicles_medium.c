#include "../palpic.h"
#define PAL_COUNT 13
#define SPRITE_COUNT 2
#define WIDTH 48
#define HEIGHT 126
#define o 0
#define STRUCT_NAME vehicles_medium

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB( 85, 125, 125), 
		PRGB(149, 149, 125), 
		PRGB(190, 190, 190), 
		PRGB(255, 255, 214), 
		PRGB(255, 214,  85), 
		PRGB( 60,  85,  85), 
		PRGB( 20,  60,  60), 
		PRGB(125,  85,  20), 
		PRGB(190, 149,  85), 
		PRGB(190, 125,  85), 
		PRGB(190,  85,  20), 
		PRGB( 60, 125,  60), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, o, o, o, o, o, o, 1, 2, 3, 4, 5, 3, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 6, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 3, 1, 3, 4, 3, 3, 2, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 2, 2, 2, 6, 1, 6, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 3, 4, 3, 2, 3, 4, 6, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 2, 2, 2, 2, 2, 6, 6, 1, 6, 1, o, o, o, o, o, o,
		 o, o, o, o, o, 1, 2, 3, 4, 4, 3, 4, 6, 1, 6, 3, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 2, 2, 2, 3, 6, 7, 7, 1, 6, 1, 8, 8, o, o, o, o,
		 o, o, o, 1, 2, 9, 9, 3, 4, 4, 3, 4, 6, 4, 6, 3, 2, 2, 1, 3, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 6, 2, 2, 3, 6, 6, 7, 1, 6, 1, 8, 8, 8, 8, o, o,
		 o, o, 1, 2, 9, 9, 9, 3, 4, 4, 3, 4, 6, 4, 6, 3, 2, 2, 1, 3, 2, 2,10,10, 2, 2, 2, 2, 2, 2, 2, 7, 2, 2, 2, 3, 6, 6, 7, 1, 6, 1, 8, 8, 8, 8, 6, o,
		 o, o, 1, 2, 9, 9, 3, 3, 4, 4, 3, 4, 6, 4, 6, 9, 2,10, 1, 3,10,10,10, 2, 2, 2, 2, 2, 2, 2, 2, 7, 2, 2, 2, 3, 6, 6, 7, 6, 6, 1, 1, 8, 8, 8, 8, o,
		 o, o, 1, 2, 9, 9, 3, 3, 4, 1, 3, 4, 6, 1, 3, 3, 2, 2, 1, 9,10,10, 2, 2, 2, 2,10, 2, 2, 2, 2, 7, 6, 2, 2, 3, 6, 7, 6, 7, 6, 1, 1, 8, 8, 8, 6, o,
		 o, o, 1, 2, 9, 3, 9, 3, 1, 6, 3, 2, 3, 4, 5, 9,10,10, 1, 9, 9, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 7, 2,10, 2, 2, 2, 6, 1, 7, 7, 1, 8, 1, 8, 8, 8, o,
		 o, o, 1, 2, 3, 9, 3, 3, 6, 6, 1, 1, 3, 4, 3,10,10,10, 8, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 2, 2, 2,10,10, 6, 6, 7, 7, 1, 1, 8, 1, 8, 6, o,
		 o, o, 1, 2, 3, 3, 2, 2, 6, 6, 3, 2, 3, 4, 9,10, 9,10,10, 2, 2, 2, 2, 2, 2, 2, 2, 2,10, 2, 2, 2,10,10,10, 2,10, 8, 1, 7, 7, 7, 1, 1, 1, 1, 8, o,
		 o, o, 1, 2, 2, 1, 1, 3, 6, 1, 3, 1, 3, 4, 9, 9,10, 3,10,10, 2,10, 2, 2, 2, 2, 2,10, 2,10,10,10,10, 3,10,10,10, 6, 8, 7, 7, 1, 7, 6, 1, 1, 6, o,
		 o, o, 1, 1, 1, 2, 3, 3, 1, 4, 3, 2, 3, 4, 9,10, 9, 8,10,10,10, 2,10, 2, 2, 2, 2, 2,10, 2,10,10,10, 8,10,10,10, 8, 8, 8, 7, 8, 1, 1, 6, 6, 6, o,
		 o, o, 6, 2, 3, 3, 3, 3, 4, 4, 3, 1, 3, 4, 9, 9,10,10,10,10,10,10, 2, 2, 2, 2, 2, 2, 2, 2, 2,10,10,10,10, 2,10, 6, 8, 8, 8, 1, 1, 1, 1, 1, 7, o,
		 o, o, 1, 2, 3, 2, 3, 3, 4, 3, 3, 2, 3, 4, 8,10, 9,10,10,10,10,10,10, 2, 2, 2, 2, 2, 2, 2,10, 2, 2,10, 2,10, 2, 6, 6, 8, 8, 8, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 4, 4, 3, 4, 6, 1, 6, 9,10,10,10,10,10,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 6, 7, 7, 1, 8, 8, 8, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 2, 3, 3, 4, 4, 3, 4, 6, 4, 6, 9,10, 3,10, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 3, 6, 6, 7, 8, 6, 8, 1, 8, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 4, 4, 3, 4, 6, 4, 6, 9,10, 8,10, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 6, 2, 3, 6, 6, 7, 1, 8, 1, 8, 1, 8, 1, 6, o,
		 o, o, 1, 2, 3, 2, 3, 3, 4, 4, 3, 4, 6, 4, 6, 3, 2,10, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 6, 6, 7, 6, 6, 8, 1, 8, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 4, 1, 3, 4, 6, 1, 3, 3, 2,10, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,10, 3, 6, 7, 6, 7, 6, 1, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 2, 3, 3, 1, 6, 3, 2, 3, 4, 5, 3, 2, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,10,10,10,10,10, 6, 8, 7, 7, 1, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 9, 3, 6, 6, 1, 1, 3, 4, 3, 3, 2, 3, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2,10, 8, 8, 9,10,10,10, 6, 8, 7, 7, 8, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 9, 3, 2, 1, 6, 6, 3, 2, 3, 4, 5, 3, 2, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,10, 2, 1, 1, 1, 7,10,10,10, 6, 8, 7, 7, 6, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 2, 1, 1, 9, 6, 1, 3, 1, 3, 4, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2,10, 2, 2, 3, 2,10, 1, 8,10, 2,10, 6, 8, 7, 7, 1, 6, 6, 1, 1, 6, o,
		 o, o, 1, 1, 1, 2, 9, 9, 1, 3, 3, 2, 3, 4, 5, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 8,10,10, 2, 6, 1, 6, 7, 1, 1, 1, 6, 6, 6, o,
		 o, o, 6, 2, 9, 9, 9, 3, 3, 4, 3, 1, 3, 4, 3, 3, 2, 2, 2, 2, 2,10, 2, 1, 2, 2, 2, 2, 2, 3, 2, 2, 1, 6, 2, 2, 1, 6, 1, 1, 6, 1, 8, 6, 1, 1, 7, o,
		 o, o, 1, 2, 9, 3, 9, 3, 4, 4, 3, 2, 3, 4, 6, 3, 2, 3, 2, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 1, 6, 2, 2, 1, 6, 6, 1, 6, 8, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 9, 9, 3, 3, 3, 4, 3, 4, 6, 1, 6, 3, 2, 6, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 2, 1, 7, 2, 3, 6, 7, 7, 1, 6, 1, 8, 6, 8, 1, 6, o,
		 o, o, 1, 2, 9, 9, 3, 9, 4, 4, 3, 4, 6, 4, 6, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 3, 2, 1, 6, 2, 3, 6, 6, 7, 1, 6, 1, 1, 8, 8, 8, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 4, 4, 3, 4, 6, 4, 6, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 3, 2, 1, 6, 2, 3, 6, 6, 7, 1, 6, 1, 1, 6, 8, 8, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 4, 4, 3, 4, 6, 4, 6, 3, 2, 2, 1, 8, 8, 8, 1, 2, 2, 2, 2, 2, 2, 4, 3, 2, 1, 6, 2, 3, 6, 6, 7, 6, 6, 1, 1, 1, 8, 8, 8, o,
		 o, o, 1, 2, 3, 3, 3, 3, 4, 1, 3, 4, 6, 1, 3, 3, 2, 1, 2,10,10, 2,10, 1, 2, 2,10, 2,10, 3, 3, 2, 1, 6, 2, 3, 6, 7, 6, 7, 6, 1, 1, 6, 1, 8, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 1, 6, 3, 2, 3, 4, 5, 3, 1, 9,10,10,10,10,10, 2, 6, 6,10,10, 2, 1, 1, 1, 1, 6, 2, 1, 2, 6, 1, 7, 7, 1, 1, 1, 8, 1, 8, o,
		 o, o, 1, 2, 9, 3, 3, 3, 6, 6, 1, 1, 3, 4, 3, 3, 1, 9, 2,10,10,10,10,10, 8, 8,10, 2,10, 6, 7, 7, 6, 2, 2, 2, 1, 6, 6, 7, 7, 1, 1, 6, 1, 1, 6, o,
		 o, o, 1, 2, 3, 9, 9, 1, 6, 6, 3, 2, 3, 4, 5, 3, 2, 8, 9, 9,10,10,10, 8,10,10,10,10,10, 2, 2, 2, 2, 2, 1, 1, 1, 6, 1, 7, 7, 6, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 9, 1, 1,10, 6, 1, 3, 1, 3, 4, 5, 3, 2,10, 8, 1, 8, 1, 8,10,10,10,10,10,10,10, 2,10, 2, 1, 2, 1, 1, 6, 1, 7, 7, 1, 6, 6, 1, 1, 6, o,
		 o, o, 1, 1, 1,10, 9, 9, 1, 4, 3, 2, 2, 3, 3,10, 2,10,10,10,10,10,10,10,10,10,10,10,10, 2,10, 2, 2, 2, 1, 1, 1, 6, 1, 6, 7, 8, 1, 1, 6, 6, 6, o,
		 o, o, 6, 2, 9, 9, 9, 9, 4, 4, 1, 1, 1, 8, 2, 3, 2, 2,10,10,10,10,10,10,10,10,10,10,10,10, 2, 2, 1, 1, 1, 6, 6, 6, 6, 1, 6, 8, 8, 8, 1, 1, 6, o,
		 o, o, 1, 2, 3, 9, 9, 9, 3, 4, 1, 2, 3, 3, 2, 1, 8, 8,10,10,10,10,10,10,10,10,10,10, 2,10, 8, 6, 6, 6, 1, 1, 1, 1, 7, 1, 6, 8, 8, 1, 8, 1, 6, o,
		 o, o, 1, 2, 9, 9, 9, 3, 3, 2, 1, 3, 6, 6, 1, 2, 3, 2, 1, 8, 6, 8,10,10,10,10,10, 8, 6, 6, 6, 1, 1, 1, 1, 6, 6, 1, 7, 6, 1, 8, 8, 8, 1, 1, 6, o,
		 o, o, 1, 9, 9, 9, 9, 9, 3, 2, 2, 3, 6, 7, 7, 7, 6, 1, 2, 3, 3, 3, 2, 6, 9,10, 6, 1, 1, 1, 1, 1, 6, 7, 7, 7, 6, 1, 6, 6, 1, 1, 8, 1, 8, 1, 6, o,
		 o, o, 1, 9, 9, 9, 9, 9, 9, 1, 3, 3, 6, 7, 7, 7, 7, 7, 7, 7, 6, 2, 3, 7, 4,10, 8, 1, 6, 7, 7, 7, 7, 7, 7, 7, 6, 1, 1, 7, 1, 8, 8, 8, 1, 1, 6, o,
		 o, o, 1, 9, 3, 9, 9, 3, 2, 1, 6, 3, 3, 1, 6, 7, 7, 7, 7, 7, 6, 2, 4, 6, 4,10, 6, 2, 6, 7, 7, 7, 7, 7, 6, 1, 1, 1, 6, 7, 6, 1, 8, 8, 8, 1, 6, o,
		 o, o, 1, 2, 9, 3, 3, 3, 1, 2, 1, 1, 1, 2, 3, 2, 1, 6, 7, 7, 6, 2, 4, 7, 3,10, 8, 2, 6, 7, 7, 6, 1, 1, 1, 1, 6, 6, 6, 6, 6, 1, 1, 8, 1, 1, 6, o,
		 o, o, 1, 2, 3, 9, 3, 2, 6, 2, 3, 3, 2, 1, 1, 1, 2, 3, 3, 4, 4, 4, 3, 7, 3,10, 6, 1, 1, 1, 1, 1, 1, 6, 6, 6, 8, 8, 1, 1, 6, 6, 1, 1, 1, 8, 6, o,
		 o, o, 1, 2, 9, 3, 3, 1, 2, 3, 4, 4, 3, 3, 2, 3, 1, 1, 1, 6, 1, 6, 1, 6, 3,10, 6, 6, 6, 6, 6, 6, 1, 2,10,10,10, 8, 8, 1, 1, 7, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 2, 6, 3, 4, 4, 3, 3, 3, 3, 2,10,10, 2,10, 1, 1, 6, 6, 8, 6, 6, 6, 1, 2, 2, 2, 2, 2,10,10, 8,10, 8, 1, 2, 6, 6, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 1, 2, 3, 4, 4, 4, 3, 3, 2, 3, 2,10,10,10,10,10,10,10, 2,10, 2, 2, 2, 2, 2, 2, 2,10, 2,10,10, 8,10, 1, 2, 1, 7, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 2, 6, 3, 4, 4, 3, 3, 3, 2, 3, 2,10, 2,10,10,10,10,10,10,10, 2, 2,10, 2, 2, 2, 2, 2, 2,10, 2,10, 8, 8, 1, 1, 2, 6, 6, 1, 1, 6, o,
		 o, o, 1, 2, 3, 1, 2, 3, 4, 4, 4, 3, 3, 3, 2, 3, 2,10,10,10,10,10,10,10, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,10,10, 8, 1, 2, 1, 7, 1, 1, 6, o,
		 o, o, 1, 2, 2, 1, 3, 4, 4, 3, 3, 3, 2, 3, 2, 2, 2,10,10,10,10,10,10,10,10,10,10, 2, 2, 2, 2, 2, 2, 2, 2,10, 2, 2, 2, 1, 1, 1, 2, 6, 6, 1, 6, o,
		 o, o, 1, 2, 1, 2, 3, 4, 3, 4, 3, 2, 3, 2, 3, 2,10, 2,10, 2,10,10,10, 2,10,10,10,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 7, 1, 6, o,
		 o, o, 1, 2, 1, 3, 2, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2,10, 2,10,10,10,10,10, 2,10, 2,10, 2, 2, 2, 2, 2, 2, 2, 6, 6, 2, 6, 6, 1, 2, 6, 6, 6, o,
		 o, o, 1, 1, 2, 3, 6, 2, 2, 1, 2, 2, 6, 1, 6, 6, 1, 6, 1, 1, 1, 1, 8, 8, 6, 6, 1, 8, 1, 1, 1, 6, 1, 6, 6, 2, 6, 2, 2, 1, 2, 2, 6, 1, 1, 7, 6, o,
		 o, o, 1, 1, 3, 4, 6, 4, 3, 1, 4, 3, 6, 2, 3, 4, 4, 4, 4, 4, 4, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 6, 4, 3, 1, 4, 3, 6, 1, 1, 6, 6, o,
		 o, o, 6, 2, 3, 4, 2, 3, 5, 2, 3, 5, 2, 3, 2, 2, 6, 2, 2, 2, 2, 2, 2, 7, o, o, 7, 7, 7, 6, 2, 2, 6, 2, 2, 2, 2, 3, 5, 2, 3, 5, 1, 1, 1, 1, 7, o,
		 o, o, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 6, o,
		 o, o, 1, 4, 3, 7, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 7, 4, 3, 1, o,
		 o, o, 1,10,11, 7, 6, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 7,10,11, 1, o,
		 o, o, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 6, 1, 1, 6, 1, 1, 1, 6, 1, 1, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, o,
		 o, o, o, 6, 7, 7, 7, 7, 7, 7, 7, o, o, o, o, o, o, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, o, o, o, o, o, o, 7, 7, 7, 7, 7, 7, 7, 6, o, o,
		 o, o, o, o, 6, 7, 6, 7, 6, 7, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 7, 6, 7, 6, 7, 6, o, o, o,
		 o, o, o, o, 6, 7, 6, 7, 6, 7, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 7, 6, 7, 6, 7, 6, o, o, o,
		/* sprite #001 */
		 o, o, o, o, o, o, o, o, o, o, 1, 2, 3, 4, 5, 3, 1, 2, 1, 2, 1, 2, 1, 2, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 3, 1, 3, 4, 3, 3, 2, 2, 2, 2, 2, 2, 6, 2, 2, 2, 1, 2, 1, 2, 1, 6, 6, 6, o, o, o, o, o, o, o, 6, 6, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 2, 3, 2, 3, 4, 6, 3, 2, 7, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 6, 2, 6, 6, 6, 6, 6, 2, 1, 2, 6, 7, 6, 6, 6, o, o, o, o, o,
		 o, o, o, o, o, 1, 1, 7, 1, 3, 3, 4, 6, 1, 6, 3, 2, 7, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 7, 6, 6, 2, 2, 2, 6, 1, 6, 7, 6, 6, o, o, o, o, o,
		 o, o, o, 1, 2, 2, 7, 6, 2, 4, 3, 4, 6, 2, 2, 3, 7, 7, 1, 3, 2,10, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 6, 6, 2, 2, 2, 6, 6, 1, 6, 1, 6, o, o, o, o, 2,
		 o, o, 1, 2, 9, 2, 6, 1, 3, 4, 3, 4, 6, 2, 6, 3, 7, 7, 7, 1, 2, 2,10,10, 2, 2, 2, 2, 2, 2, 2, 7, 6, 2, 2, 3, 6, 7, 7, 1, 6, 1, 8, 8, o, o, 2, 2,
		 o, o, 1, 2, 9, 2, 6, 3, 4, 4, 3, 4, 2, 2, 1, 7, 7, 7, 7, 1, 1,10,10, 2, 2, 2, 2, 2, 2, 2, 2, 7, 6, 2, 2, 3, 6, 6, 7, 1, 7, 1, 8, 8, 8, 8, 2, 3,
		 o, o, 1, 2, 9, 9, 2, 3, 4, 1, 3, 2, 2, 1, 6, 7, 7, 7,12, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 6, 2, 2, 3, 6, 6, 7, 1, 6, 1, 8, 8, 8, 8, 2, 3,
		 o, o, 1, 2, 9, 3, 9, 3, 1, 6, 2, 2, 1, 6, 7, 7,12,12,12, 1, 1, 2, 2, 2, 2, 2,10, 2, 2, 2, 2, 7, 6, 2, 2, 3, 6, 6, 7, 6, 7, 1, 1, 8, 8, 2, 3, 3,
		 2, 2, 1, 2, 3, 9, 3, 3, 6, 2, 2, 1, 6, 6,12,12,12,12,12, 1, 2, 2, 1, 1, 1, 1, 2, 3, 2, 3, 2, 7, 2,10, 2, 3, 6, 7, 6, 7, 6, 1, 1, 6, 2, 3, 3, 2,
		 3, 3, 2, 6, 3, 3, 2, 2, 2, 2, 1, 6, 6,12,12,12, 7, 7, 7, 1, 2, 1, 1, 6, 7, 7, 7, 6, 7, 6, 7, 6, 2, 2, 2, 2, 2, 6, 1, 7, 7, 1, 6, 6, 6, 2, 2, o,
		 o, 2, 3, 2, 6, 1, 1, 2, 2, 1, 6, 6,12,12, 7, 6, 7, 7, 7, 7, 2, 1, 6, 6, 6, 7, 7, 7, 7, 2, 2, 2,10,10, 2,10,10, 6, 6, 7, 7, 6, 6, 7, 7, 2, 2, o,
		 o, 2, 2, 2, 6, 6, 6, 6, 6, 7,12,12,12, 7, 6, 6, 7, 7, 7, 7, 2, 6, 6, 6,10,11,11, 7, 7, 7,10,10,10, 3,10, 2,10, 8, 7, 7, 7, 7, 7, 7, 7, 2, 8, o,
		 o, o, 2, 2, 6, 6, 7, 7, 7, 7, 7, 7, 6, 6, 6, 7, 7,10, 7, 7, 7, 6, 6,10, 9, 9, 6,11, 7, 7, 7, 7,10, 8,10,10, 7, 7, 7, 6, 7, 7, 7, 7, 1, 1, 6, o,
		 o, o, 6, 2, 6, 7, 7, 7, 7, 6, 6, 6, 6, 6, 7, 7, 7, 7,10,10, 7, 6, 6,10, 6, 9,10,10, 7, 7, 7, 7, 7, 7, 7, 6, 7, 6, 6, 7, 7, 8, 1, 1, 6, 6, 6, o,
		 o, o, 6, 2, 7, 6, 6, 6, 6, 6, 3, 4, 6, 1, 6, 6, 7, 7,10,10,10, 7, 6, 8,10,10, 7, 8, 8, 7,12,12,12, 7, 7, 7, 6, 7, 6, 6, 8, 1, 1, 1, 1, 1, 7, o,
		 o, o, 1, 6, 7, 2, 3, 3, 4, 4, 3, 4, 6, 2, 6, 6, 6, 7,10, 2,10, 2, 7, 7, 8, 8,10,12,12,12,11,12,11,12,12,12,12,12,12, 7, 7, 8, 1, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 4, 4, 4, 3, 3, 4, 6, 1, 6, 7, 7, 7,10, 1, 2, 7, 7, 7, 7,12,12,12,10,10,11,11,11,12, 6, 6, 6,12,12, 9,10, 7, 8, 1, 1, 1, 6, o,
		 o, o, 1, 2, 3, 4, 4, 3, 3, 1, 3, 2, 6, 6, 7,12, 6, 6, 2,10, 2, 7, 7, 7,12,12,12,11,10,11,11, 6,11,12, 7, 6, 7, 7, 7,10,10, 7, 7, 8, 1, 1, 6, o,
		 o, o, 1, 2, 3, 3, 3, 3, 1, 1, 1, 6, 6,12,12, 6, 6,10, 2, 2, 1, 6, 6, 6,12,11,11,12,11,11,11, 7, 6, 6, 1, 2, 6, 6, 7, 7, 7, 7, 7, 7, 7, 1, 6, o,
		 o, 1, 1, 2, 1, 1, 1, 1, 7, 7, 6, 7,12, 6, 6, 6, 2, 2,10, 2, 1, 7, 6,12,12,12, 7,12,12,11, 7, 6, 6, 1, 2, 3, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 6, o,
		 o, 1, 1, 2, 7, 1, 1, 1, 7, 7, 7,12,12,12,12, 7, 7, 7, 2, 1, 1, 7, 7,12, 6, 6, 6, 7, 7, 7, 6, 6,10,10,10, 3, 6, 7, 6, 7, 7, 7, 6, 6, 7, 7, 6, o,
		 o, 1, 2, 2, 7, 7, 7, 7, 7, 7, 7, 7,12, 4, 5, 3, 2, 6, 1, 1, 7, 7, 7,12, 7, 6, 7, 6, 6, 6,10, 2, 2, 9,10,10,10, 6, 8, 7, 7, 6, 6, 6, 1, 1, 6, o,
		 1, 2, 2, 3, 2, 6, 7, 7, 7, 1, 3, 1, 3, 4, 3, 3, 2, 1, 6, 6, 7, 7,12,12, 7, 7, 6, 6, 6, 2, 2, 2, 2, 2,10,10,10, 6, 8, 7, 7, 6, 6, 1, 2, 2, 6, o,
		 1, 2, 3, 3, 1, 2, 6, 6, 6, 3, 3, 2, 3, 4, 5, 3, 1, 6, 6, 7, 7, 7, 7, 7, 7, 6, 6, 1, 1, 1, 2, 2, 2, 2,10,10,10, 6, 8, 7, 7, 6, 6, 1, 2, 2, 2, o,
		 1, 3, 3, 2, 9, 6, 6, 2, 3, 4, 3, 1, 1, 1, 1, 1, 1, 6, 6, 7, 7,10,10, 7, 7, 6, 6, 1, 2, 2, 1, 2, 2, 2,10, 2,10, 6, 8, 7, 7, 6, 6, 6, 1, 2, 2, o,
		 1, 3, 3, 2, 6, 1, 2, 3, 4, 4, 3, 2, 1, 1, 1, 6, 6, 6,12, 7, 7,10,10, 7, 6, 2, 2, 3, 3, 2, 2, 1, 2, 2,10,10, 2, 6, 1, 6, 7, 7, 1, 7, 6, 2, 2, o,
		 6, 1, 2, 6, 7, 2, 3, 3, 3, 4, 3, 1, 1, 1, 6, 6, 6,12,12,12, 7,10, 7, 6, 2, 2, 2, 2, 3, 4, 2, 2, 1, 2, 2, 2, 1, 6, 1, 1, 6, 7, 6, 6, 7, 1, 2, 1,
		 6, 1, 6, 7, 2, 9, 3, 9, 4, 2, 1, 1, 6, 6, 6, 6, 7, 7,12,11,11, 6, 7, 2, 2, 2, 2, 2, 3, 3, 3, 2, 1, 2, 2, 2, 1, 6, 6, 1, 6, 8, 7, 6, 7, 1, 2, 1,
		 6, 1, 6, 1, 3, 3, 3, 3, 2, 2, 1, 6, 6, 7, 7, 7, 6, 7,12,10,11,11, 6, 2, 2,11,11, 2, 2, 4, 3, 2, 1, 6, 2, 3, 6, 7, 7, 1, 6, 1, 8, 6, 6, 7, 6, 1,
		 6, 6, 6, 2, 3, 2, 3, 2, 2, 1, 6, 7, 7, 7, 6, 7, 6, 6, 7,11,11, 7, 2, 2, 7, 7,11,11, 2, 4, 3, 2, 1, 6, 2, 3, 6, 6, 7, 1, 6, 1, 1, 8, 8, 6, 7, 1,
		 6, 6, 1, 2, 3, 3, 2, 2, 1,12,12, 7, 7, 6, 7, 6,11, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,11, 2, 4, 3, 2, 1, 6, 2, 3, 6, 6, 7, 1, 6, 1, 1, 6, 8, 6, 6, o,
		 o, o, 1, 2, 3, 2, 2, 1, 7,12,12,12, 6, 6,12,11,12, 6,11, 7, 7, 7, 7, 7, 6, 7, 7, 2,10, 3, 3, 2, 1, 6, 2, 3, 6, 6, 7, 6, 6, 1, 1, 1, 8, 8, 6, o,
		 o, o, 1, 2, 9, 1, 7, 7, 7,12,12,12,12,12,11,11,11, 6, 7, 7, 7, 7, 7, 6, 1, 7, 7, 7, 2, 1, 1, 1, 1, 6, 2, 3, 6, 7, 6, 7, 6, 1, 1, 6, 1, 8, 6, o,
		 o, o, 1, 2, 2, 7, 7, 7, 7, 6, 8,12,12,12,12,12,11,12, 7, 7, 7, 7, 6, 1, 7, 7, 7, 7, 1, 6, 7, 7, 6, 2, 2, 1, 2, 6, 1, 7, 7, 1, 1, 1, 8, 1, 8, o,
		 o, o, 1, 2, 7, 7, 7,10, 3, 3, 8, 8,12,12,12,12,12,11, 7, 7, 7, 7, 6, 1, 7, 7, 6, 6, 6, 2, 2, 2, 2, 2, 2, 2, 1, 6, 6, 7, 7, 1, 1, 6, 1, 1, 6, o,
		 o, o, 1, 7, 6, 3, 3, 3, 3, 1,10,10,10, 8, 1,12,12, 6,12, 7, 7, 6, 1, 7, 7, 6, 6, 1, 1, 6,10,10, 2, 1, 1, 1, 1, 6, 1, 7, 7, 6, 1, 1, 1, 1, 6, o,
		 o, o, 6, 3, 4, 4, 3, 9, 4, 1,10,10, 8, 1, 7, 7, 6, 1,12,12,10,10, 7, 6, 7, 6, 6, 1, 1, 6, 6, 2, 2, 2, 1, 1, 6, 1, 7, 7, 7, 7, 6, 6, 1, 1, 6, o,
		 o, o, 3, 4, 4, 3, 1, 1, 3, 1, 8,10, 1, 1, 1, 1, 7, 7, 1,12,10,10, 7, 6, 7, 6, 1, 1, 1, 6, 6, 6, 2, 2, 1, 1, 6, 1, 1, 6, 7, 7, 1, 1, 6, 6, 6, 2,
		 o, 3, 4, 4, 9, 1, 1, 6, 6, 2, 7, 1, 2, 2, 3, 2, 2, 7, 7, o, 7,10, 7, 7, 7, 6, 1, 6, 6,10, 2, 2, 1, 1, 1, 6, 6, 6, 7, 1, 7, 7, 7, 8, 1, 1, 6, 3,
		 3, 3, 3, 3, 1, 6, 6, 6, 3, 2, 1, 1, 1, 2, 3, 3, 2, 2, 8, 7, 7, 7, 7, 7,11, 7, 6, 6,10,10, 8, 6, 6, 6, 1, 1, 1, 1, 7, 1, 6,11, 7, 1, 8, 1, 2, 3,
		 3, 3, 3, 1, 6, 6, 9, 9, 9, 1, 1, 2, 3, 8, 2, 3,10, 2,10, 9, 7, 7, 7,11,11, 7, 1,10,10,10, 6, 1, 1, 1, 1, 6, 6, 1, 6, 6, 1,11,11,12, 1, 1, 3, 3,
		 o, o, 1, 1, 1, 9, 9, 3, 2, 2, 3, 3, 6, 3, 2, 3, 2,10,10, 1, 1, 7,11,10,11,11, 1,10, 8, 6, 1, 1, 1, 6, 7, 7, 7, 6, 1, 1, 1, 1,12,11, 8, 2, 3, 2,
		 o, o, 1, 1, 9, 3, 3, 3, 1, 3, 3, 6, 7, 1, 2, 8, 8,10,10, 1, 1,11,12,10,11,12, 7, 6, 1, 1, 7, 7, 7, 7, 7, 7, 7, 6, 1, 6, 1, 8, 7,12, 7, 2, 2, o,
		 o, o, 6, 2, 3, 9, 3, 2, 1, 3, 3, 7, 7, 7, 2, 3, 8,10,10,10, 1,12,11,11,11,11, 7, 8, 1, 6, 7, 7, 7, 7, 1, 6, 1, 1, 6, 6, 6, 1, 7,12,12, 2, 2, o,
		 o, o, 6, 1, 9, 3, 3, 3, 3, 1, 3, 1, 7, 7, 6, 1, 2, 1,10,10, 1,12,12, 6,11,11, 7, 6, 2, 6, 7, 7, 6, 1, 6, 1, 1, 6, 8, 1, 6, 1, 1, 7,12,12, 6, o,
		 o, 1, 6, 6, 2, 3, 2, 4, 3, 2, 2, 3, 6, 7, 7, 7, 2, 3, 6, 8, 7,12,12,12,12,11, 7,10, 8, 2, 1, 1, 1, 1, 1, 2, 6, 6,10, 8, 8, 6, 1, 7,12,12, 6, o,
		 o, 1, 2, 6, 1, 2, 4, 3, 4, 3, 1, 1, 2, 1, 7, 7, 7, 7, 3, 8, 7,12, 6, 6, 6,12, 7, 6, 6, 1, 6, 6, 6, 6, 2, 2,10,10, 8, 1, 1, 7, 6, 1, 7,12,12, o,
		 o, 2, 2, 6, 6, 2, 4, 4, 3, 3, 2, 3, 2, 2, 6, 7, 7, 6, 2, 1, 7, 6, 6, 8, 8, 6,12, 7, 6, 6, 1, 1, 2, 2,10,10, 8,10, 8, 1, 2, 6, 7, 1, 1,12,12, o,
		 1, 1, 2, 6, 2, 1, 2, 3, 1, 1, 1, 3, 1, 3, 3, 7, 6, 6, 1, 7,12, 8,10, 8, 8, 8, 6,12, 7, 6, 2, 2, 1, 2, 2,10,10, 8,10, 1, 2, 1, 6, 7, 1,12,10, o,
		 o, 1, 6, 2, 2, 1, 3, 4, 4, 6, 6, 1,10, 1, 1, 4, 4, 2, 6, 7,12,10, 8, 8, 8, 8, 6,12, 7, 1, 1, 2, 2, 2,10, 2,10, 8, 8, 2, 2, 2, 1, 6, 7,12, 9,10,
		 o, o, 1, 2, 1, 2, 3, 4, 3, 4, 3, 6, 6, 2,10, 1, 6, 6, 6, 7, 7,10, 8, 8, 8, 8,11,12,12, 7, 1, 1, 3, 3, 2, 2, 2,10,10, 8, 1, 2, 1, 6, 7, 1,10,10,
		 o, o, 1, 2, 1, 3, 2, 1, 1, 2, 1, 1, 7, 6, 6, 1, 6, 7, 7, 7, 7, 8, 8, 8, 8, 7,11,11,12, 7, 7, 1, 2, 3, 2,10, 2, 2, 2, 2, 1, 1, 1, 1, 6, 6, 6, o,
		 o, o, 1, 1, 2, 3, 6, 2, 2, 2, 1, 1, 2, 7, 7, 6, 7, 7, 2, 2, 2, 7, 8, 8, 7, 7, 7,12,11,12, 7, 2, 2, 2, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 6, 7, 6, o,
		 o, o, 1, 1, 3, 4, 6, 4, 3, 1, 2, 2, 6, 2, 3, 4, 3, 3, 3, 4, 2,11, 7, 7,10,10, 1, 7,11,12, 1, 6, 1, 6, 2, 3, 2, 6, 6, 2, 6, 6, 1, 1, 6, 6, 6, o,
		 o, o, 6, 2, 3, 4, 2, 3, 5, 1, 4, 3, 6, 3, 2, 2, 6, 2, 2, 2, 2, 2,11,10,10, 1, 1, 7,12,12, 3, 3, 3, 3, 6, 2, 6, 2, 2, 1, 2, 2, 6, 1, 1, 6, 6, o,
		 o, o, 6, 2, 2, 2, 2, 2, 2, 2, 3, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6,11, o, 7, 7,11,12, 2, 2, 6, 2, 3, 2, 6, 4, 3, 1, 4, 3, 6, 1, 1, 6, 6, o,
		 o, o, 1, 4, 3, 7, 6, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1,11, 2, 2, 2,12,12, 2, 2, 2, 2, 2, 2, 2, 3, 5, 2, 3, 5, 1, 1, 1, 1, 7, o,
		 o, o, 1,10,11, 7, 6, 6, 1, 6, 1, 6, 1, 6, 1, 1, 1, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6,12,12, 6, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 6, o,
		 o, o, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 6, 7, 6, 1, 1, 6, 1, 1, 6, 6,10,12,12, 7, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 7, 4, 3, 1, o,
		 o, o, o, 6, 7, 7, 7, 7, 7, 7, 7, o, o, 1, 6, 6, 6, 6, 7, 7, 7, 7, 7, 6, 6, 6, 6, 9, 9, 6, 7, 6, 6, 6, 6, 1, 6, 1, 6, 1, 6, 1, 6, 7,10,11, 1, o,
		 o, o, o, o, 6, 7, 6, 7, 6, 7, o, 6, 6, 6, 6, o, o, o, o, o, o, o, o, o, o, 7, 7, 9,10, 7, 7, 7, o, o, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, o,
		 o, o, o, o, o, 7, 7, 6, 7, 6, 7, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

