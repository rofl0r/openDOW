#include "../palpic.h"
#define PAL_COUNT 12
#define SPRITE_COUNT 6
#define WIDTH 64
#define HEIGHT 192
#define o 0
#define STRUCT_NAME bg_forest

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, 0, 0 },
	{
		PRGB( 85, 125, 125), 
		PRGB(190, 190, 190), 
		PRGB(149, 149, 125), 
		PRGB( 60,  85,  85), 
		PRGB(255, 255, 214), 
		PRGB( 20,  60,  60), 
		PRGB( 60, 125,  60), 
		PRGB( 60, 190,  85), 
		PRGB( 20,  85,  60), 
		PRGB(125,  85,  20), 
		PRGB(190, 125,  85), 
		PRGB(190, 149,  85), 
		
	},
	{
		/* sprite #000 */
		 o, 1, 2, 2, 2, 2, o, o, 2, 2, 2, o, 3, o, 4, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, o, 2, 2, 2, 2, o, 1, 2, 2, 2, 2, o, o, 2, 2, 2, o, 3, o, 4, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, o, 2, 2, 2, 2,
		 o, 1, 2, 2, 2, o, o, 1, 2, 2, 2, 2, 2, 3, 4, 1, 2, 2, 2, o, 3, 2, 1, 2, 2, 2, o, o, o, 2, 2, 2, o, 1, 2, 2, 2, o, o, 1, 2, 2, 2, 2, 2, 3, 4, 1, 2, 2, 2, o, 3, 2, 1, 2, 2, 2, o, o, o, 2, 2, 2,
		 3, o, 1, 2, 2, o, 2, 4, 2, 2, 2, 2, 2, 3, o, 4, 1, 2, o, o, 3, o, 2, 2, 2, o, 3, 3, 3, o, o, o, 3, o, 1, 2, 2, o, 2, 4, 2, 2, 2, 2, 2, 3, o, 4, 1, 2, o, o, 3, o, 2, 2, 2, o, 3, 3, 3, o, o, o,
		 2, 3, o, o, 3, 3, 2, 4, 1, 2, 2, 2, 2, o, o, o, o, o, 2, 2, 2, 3, o, o, o, 2, 2, 2, o, 3, o, 2, 2, 3, o, o, 3, 3, 2, 4, 1, 2, 2, 2, 2, o, o, o, o, o, 2, 2, 2, 3, o, o, o, 2, 2, 2, o, 3, o, 2,
		 2, 2, 3, o, 2, 2, 3, 2, 1, 1, 2, 2, 2, 3, o, 3, 3, 5, 1, 2, 2, 2, 3, o, 1, 2, 2, 2, 2, 3, 1, 2, 2, 2, 3, o, 2, 2, 3, 2, 1, 1, 2, 2, 2, 3, o, 3, 3, 5, 1, 2, 2, 2, 3, o, 1, 2, 2, 2, 2, 3, 1, 2,
		 2, 2, 3, 1, 2, 2, 2, 3, 2, 1, 2, 2, o, o, 3, o, 2, o, 1, 2, 2, 2, 3, o, 1, 2, 2, 2, 2, o, 1, 2, 2, 2, 3, 1, 2, 2, 2, 3, 2, 1, 2, 2, o, o, 3, o, 2, o, 1, 2, 2, 2, 3, o, 1, 2, 2, 2, 2, o, 1, 2,
		 2, 2, 3, 1, 2, 2, 2, 3, o, o, 3, 5, o, o, 2, 2, 2, 2, 5, 1, 2, 3, o, 3, 2, 1, 2, 2, 2, 3, 3, 1, 2, 2, 3, 1, 2, 2, 2, 3, o, o, 3, 5, o, o, 2, 2, 2, 2, 5, 1, 2, 3, o, 3, 2, 1, 2, 2, 2, 3, 3, 1,
		 3, 3, o, o, 1, 2, 2, o, 2, 2, 2, o, 5, o, 1, 2, 2, 2, o, 3, o, 2, 2, 2, 3, 2, 2, 2, 2, o, o, 3, 3, 3, o, o, 1, 2, 2, o, 2, 2, 2, o, 5, o, 1, 2, 2, 2, o, 3, o, 2, 2, 2, 3, 2, 2, 2, 2, o, o, 3,
		 2, 3, o, o, o, o, o, 2, 2, 2, 2, 2, o, 3, 4, 1, 2, 2, o, 3, 1, 2, 2, 2, 2, 3, 2, 2, o, o, 2, 2, 2, 3, o, o, o, o, o, 2, 2, 2, 2, 2, o, 3, 4, 1, 2, 2, o, 3, 1, 2, 2, 2, 2, 3, 2, 2, o, o, 2, 2,
		 2, 2, 3, o, 2, o, 3, 2, 2, 2, 2, 2, 2, 3, o, 1, 1, 2, 3, 2, 1, 2, 2, 2, 2, o, 3, o, 2, 2, 2, 2, 2, 2, 3, o, 2, o, 3, 2, 2, 2, 2, 2, 2, 3, o, 1, 1, 2, 3, 2, 1, 2, 2, 2, 2, o, 3, o, 2, 2, 2, 2,
		 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, o, o, o, o, o, 2, 4, 2, 2, 2, 2, o, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 3, o, o, o, o, o, 2, 4, 2, 2, 2, 2, o, 3, 2, 2, 2, 2, 2,
		 2, 2, 3, 1, 2, 2, 2, o, 2, 2, 2, 2, 2, o, o, 2, 3, 3, o, o, 2, 1, 2, 2, 2, 3, o, 1, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, o, 2, 2, 2, 2, 2, o, o, 2, 3, 3, o, o, 2, 1, 2, 2, 2, 3, o, 1, 2, 2, 2, 2,
		 2, 2, o, 1, 2, 2, 2, 2, o, 2, 2, 2, o, o, 2, 2, 2, o, 3, o, o, 3, 3, 3, 5, o, o, 2, 1, 2, 2, 2, 2, 2, o, 1, 2, 2, 2, 2, o, 2, 2, 2, o, o, 2, 2, 2, o, 3, o, o, 3, 3, 3, 5, o, o, 2, 1, 2, 2, 2,
		 2, o, 3, o, 1, 2, 2, o, o, 3, 3, 3, o, o, 1, 2, 2, 2, 3, o, 2, 2, 2, o, 3, 5, o, 3, o, 1, 1, 1, 2, o, 3, o, 1, 2, 2, o, o, 3, 3, 3, o, o, 1, 2, 2, 2, 3, o, 2, 2, 2, o, 3, 5, o, 3, o, 1, 1, 1,
		 o, 3, o, o, 3, 3, 3, o, o, 2, 2, 2, 3, o, 1, 2, 2, 2, o, 2, 2, 2, 2, 2, o, 5, o, o, 3, 3, 5, 5, o, 3, o, o, 3, 3, 3, o, o, 2, 2, 2, 3, o, 1, 2, 2, 2, o, 2, 2, 2, 2, 2, o, 5, o, o, 3, 3, 5, 5,
		 3, o, o, 2, 2, 2, o, 3, 1, 2, 2, 2, 2, 3, o, 1, 2, 2, o, 2, 1, 2, 2, 2, 2, 3, o, 2, 2, 2, 2, o, 3, o, o, 2, 2, 2, o, 3, 1, 2, 2, 2, 2, 3, o, 1, 2, 2, o, 2, 1, 2, 2, 2, 2, 3, o, 2, 2, 2, 2, o,
		 2, 3, 2, 2, 2, 2, 2, o, 4, 2, 2, 2, 2, 3, o, o, 3, 3, o, 2, 1, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, o, 4, 2, 2, 2, 2, 3, o, o, 3, 3, o, 2, 1, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2,
		 2, 3, 1, 2, 2, 2, 2, o, 4, 1, 2, 2, 2, o, o, 2, 2, o, 3, o, 2, 1, 2, 2, 2, o, 1, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, o, 4, 1, 2, 2, 2, o, o, 2, 2, o, 3, o, 2, 1, 2, 2, 2, o, 1, 2, 2, 2, 2, 2,
		 2, o, 1, 2, 2, 2, 2, 2, o, 4, 2, 2, o, o, 2, 2, 2, 2, o, 3, o, 2, 1, 1, o, o, 4, 1, 2, 2, 2, 2, 2, o, 1, 2, 2, 2, 2, 2, o, 4, 2, 2, o, o, 2, 2, 2, 2, o, 3, o, 2, 1, 1, o, o, 4, 1, 2, 2, 2, 2,
		 2, 2, o, 1, 2, 2, 2, o, o, 3, 5, 5, 3, o, 1, 2, 2, 2, o, 3, o, o, o, 3, 3, o, 2, 4, 2, 2, 2, 2, 2, 2, o, 1, 2, 2, 2, o, o, 3, 5, 5, 3, o, 1, 2, 2, 2, o, 3, o, o, o, 3, 3, o, 2, 4, 2, 2, 2, 2,
		 2, o, o, o, 2, 2, o, o, 2, 2, 2, o, 3, 3, 1, 2, 2, 2, 2, 3, o, 2, 2, 2, 2, 3, o, 2, 1, 2, 2, 2, 2, o, o, o, 2, 2, o, o, 2, 2, 2, o, 3, 3, 1, 2, 2, 2, 2, 3, o, 2, 2, 2, 2, 3, o, 2, 1, 2, 2, 2,
		 o, 2, 2, o, 3, 3, o, 1, 2, 2, 2, 2, o, 3, 2, 1, 2, 2, 2, o, 2, 2, 2, 2, 2, 2, 3, o, o, 2, 2, o, o, 2, 2, o, 3, 3, o, 1, 2, 2, 2, 2, o, 3, 2, 1, 2, 2, 2, o, 2, 2, 2, 2, 2, 2, 3, o, o, 2, 2, o,
		 1, 2, 2, 2, 2, o, 3, 1, 2, 2, 2, 2, 2, 3, o, 2, 1, 2, o, o, 1, 2, 2, 2, 2, 2, o, 3, o, o, o, 2, 1, 2, 2, 2, 2, o, 3, 1, 2, 2, 2, 2, 2, 3, o, 2, 1, 2, o, o, 1, 2, 2, 2, 2, 2, o, 3, o, o, o, 2,
		 4, 2, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, 3, 3, o, 3, 5, 3, o, 1, 2, 2, 2, 2, 2, o, 3, o, 3, 3, o, 4, 2, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, 3, 3, o, 3, 5, 3, o, 1, 2, 2, 2, 2, 2, o, 3, o, 3, 3, o,
		 4, 1, 2, 2, 2, 2, 3, o, 2, 1, 1, 1, o, 5, o, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, o, o, 2, 2, 2, 3, 4, 1, 2, 2, 2, 2, 3, o, 2, 1, 1, 1, o, 5, o, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, o, o, 2, 2, 2, 3,
		 o, 4, 1, 2, 2, o, 3, o, o, 2, 2, o, 5, o, 2, 2, 2, 2, 2, o, 3, 2, 1, 1, 1, o, o, 2, 2, 2, 2, o, o, 4, 1, 2, 2, o, 3, o, o, 2, 2, o, 5, o, 2, 2, 2, 2, 2, o, 3, 2, 1, 1, 1, o, o, 2, 2, 2, 2, o,
		 2, o, 2, 2, o, o, o, o, 2, o, 3, 3, o, 4, 2, 2, 2, 2, 2, 2, 5, o, o, 2, o, o, 2, 1, 2, 2, 2, 2, 2, o, 2, 2, o, o, o, o, 2, o, 3, 3, o, 4, 2, 2, 2, 2, 2, 2, 5, o, o, 2, o, o, 2, 1, 2, 2, 2, 2,
		 2, o, o, 3, 3, 3, o, 2, 2, 2, 2, o, 3, 4, 1, 2, 2, 2, 2, 2, 3, o, 3, 5, 5, o, 2, 1, 2, 2, 2, 2, 2, o, o, 3, 3, 3, o, 2, 2, 2, 2, o, 3, 4, 1, 2, 2, 2, 2, 2, 3, o, 3, 5, 5, o, 2, 1, 2, 2, 2, 2,
		 o, o, 2, 2, 2, o, 3, 1, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, o, o, 2, 2, 2, 2, 5, o, 2, 1, 2, 2, 2, o, o, 2, 2, 2, o, 3, 1, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, o, o, 2, 2, 2, 2, 5, o, 2, 1, 2, 2, 2,
		 o, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, o, o, o, 2, 1, 2, 2, o, o, 2, 2, 2, 2, 2, 2, 3, o, 2, 2, 2, o, o, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, o, o, o, 2, 1, 2, 2, o, o, 2, 2, 2, 2, 2, 2, 3, o, 2, 2, 2, o,
		 o, 1, 2, 2, 2, 2, o, 2, 2, 2, 2, o, o, 2, o, o, 3, 3, 3, o, 1, 2, 2, 2, 2, 2, 2, o, o, o, o, o, o, 1, 2, 2, 2, 2, o, 2, 2, 2, 2, o, o, 2, o, o, 3, 3, 3, o, 1, 2, 2, 2, 2, 2, 2, o, o, o, o, o,
		 o, 1, 2, 2, 2, 2, 2, o, o, 3, 3, o, 1, 2, 2, 2, 2, 2, o, 3, 4, 2, 2, 2, 2, 2, 2, 3, o, 2, 2, 2, o, 1, 2, 2, 2, 2, 2, o, o, 3, 3, o, 1, 2, 2, 2, 2, 2, o, 3, 4, 2, 2, 2, 2, 2, 2, 3, o, 2, 2, 2,
		/* sprite #001 */
		 6, 6, 6, 2, 6, 6, 7, 6, 3, 6, 6, 2, 6, 6, 8, 6, 6, 2, 6, 6, 7, 6, 3, 6, 6, 6, 7, 6, 6, 3, 6, 8, 6, 6, 6, 2, 6, 6, 7, 6, 3, 6, 6, 2, 6, 6, 8, 6, 6, 2, 6, 6, 7, 6, 3, 6, 6, 6, 7, 6, 6, 3, 6, 8,
		 7, 6, 3, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, o, 6, 6, 6, 6, 7, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 7, 6, 3, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, o, 6, 6, 6, 6, 7, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6,
		 6, 6, 2, 6, 8, 6, 6, 6, 2, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 8, 6, 6, 6, 2, 6, 8, 6, 6, 6, 2, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 8, 6,
		 o, 6, 6, 6, 8, 3, 6, 8, 6, 8, 6, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 2, 6, 6, 6, 8, 6, 8, 6, 6, 6, 8, o, 6, 6, 6, 8, 3, 6, 8, 6, 8, 6, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 2, 6, 6, 6, 8, 6, 8, 6, 6, 6, 8,
		 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 6, 2, 1, 6, 8, 6, 7, 6, 6, 6, 7, 6, 6, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 6, 2, 1, 6, 8, 6, 7, 6, 6, 6, 7, 6, 6, 8, 8, 6, 6, 6, 6, 6, 6, 6,
		 7, 6, 7, 8, 6, 7, 6, 3, 6, 6, 3, 6, 6, 2, 2, 6, 6, 3, 6, 6, 6, 6, 8, 8, 6, 6, 3, 6, 8, 8, 6, 6, 7, 6, 7, 8, 6, 7, 6, 3, 6, 6, 3, 6, 6, 2, 2, 6, 6, 3, 6, 6, 6, 6, 8, 8, 6, 6, 3, 6, 8, 8, 6, 6,
		 6, 8, 6, 8, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 8, 8, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 8, 6, 8, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 8, 8, 6, 6, 6, 6, 8, 6, 6, 6, 6,
		 6, 6, 8, 6, 7, 6, 6, 3, 6, 6, 8, 6, 6, 3, 6, 6, 6, 3, 6, 6, o, 8, 7, 6, 6, 3, 6, 8, 6, 6, 6, 7, 6, 6, 8, 6, 7, 6, 6, 3, 6, 6, 8, 6, 6, 3, 6, 6, 6, 3, 6, 6, o, 8, 7, 6, 6, 3, 6, 8, 6, 6, 6, 7,
		 6, 3, 8, 6, 6, 3, 6, 6, 6, 8, 6, 8, 6, 6, 6, 6, 8, 6, 6, 7, 6, 8, 6, 6, 8, 6, 8, 6, 6, 6, 3, 6, 6, 3, 8, 6, 6, 3, 6, 6, 6, 8, 6, 8, 6, 6, 6, 6, 8, 6, 6, 7, 6, 8, 6, 6, 8, 6, 8, 6, 6, 6, 3, 6,
		 6, 6, 8, 2, 6, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, o, 2, 6, 6, 6, 8, 8, 3, 6, 6, 6, 6, 6, 3, o, 6, 6, 6, 6, 8, 2, 6, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, o, 2, 6, 6, 6, 8, 8, 3, 6, 6, 6, 6, 6, 3, o, 6, 6,
		 6, 7, 6, 6, 6, 3, 6, 7, 6, 6, 6, 6, 7, 6, 7, 6, 6, 7, 6, 6, 2, 8, 6, 6, 6, 8, 6, 7, 6, 6, 6, 6, 6, 7, 6, 6, 6, 3, 6, 7, 6, 6, 6, 6, 7, 6, 7, 6, 6, 7, 6, 6, 2, 8, 6, 6, 6, 8, 6, 7, 6, 6, 6, 6,
		 8, 6, 8, 6, 7, 6, 6, 6, 8, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 6, 6, 3, 6, 6, 3, 6, 3, 6, 8, 6, 8, 6, 7, 6, 6, 6, 8, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8, 6, 6, 3, 6, 6, 3, 6, 3, 6,
		 6, 8, 6, 6, 6, 7, 6, 8, 6, 6, 6, 7, o, 6, 6, 7, 6, 3, 6, 8, 6, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 7, 6, 8, 6, 6, 6, 7, 6, 8, 6, 6, 6, 7, o, 6, 6, 7, 6, 3, 6, 8, 6, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 7,
		 6, 6, 6, 8, 6, 8, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 7, 6, 6, 6, 8, 8, 6, 6, 6, 8, 6, 6, o, 6, 6, 6, 8, 6, 8, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 7, 6, 6, 6, 8, 8, 6, 6, 6, 8, 6, 6, o,
		 6, o, 6, 6, 8, 8, 7, o, 6, 6, 8, 6, 7, 6, 3, 6, 6, 6, 8, 6, o, 6, 6, 7, 8, 7, 6, 3, 6, 6, 7, 6, 6, o, 6, 6, 8, 8, 7, o, 6, 6, 8, 6, 7, 6, 3, 6, 6, 6, 8, 6, o, 6, 6, 7, 8, 7, 6, 3, 6, 6, 7, 6,
		 6, 6, 6, 6, 8, 8, 6, 6, 6, 6, 6, 7, 6, 2, 6, 8, 6, 8, 6, 8, 6, 8, 6, 6, 8, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 8, 8, 6, 6, 6, 6, 6, 7, 6, 2, 6, 8, 6, 8, 6, 8, 6, 8, 6, 6, 8, 6, 6, 2, 6, 6, 6, 6,
		 6, 6, 6, 8, 8, 8, 6, 6, 6, 8, 6, 6, 6, 8, 1, 6, o, 6, 6, 8, 6, 6, 6, 6, 8, o, 6, 6, 7, 6, 3, 6, 6, 6, 6, 8, 8, 8, 6, 6, 6, 8, 6, 6, 6, 8, 1, 6, o, 6, 6, 8, 6, 6, 6, 6, 8, o, 6, 6, 7, 6, 3, 6,
		 8, 6, 8, 8, 6, o, 6, 6, 7, 6, 7, 6, 3, 6, 6, 1, 6, 6, 6, 8, 8, 6, 6, 6, 7, 6, 6, 6, 8, 6, 2, 6, 8, 6, 8, 8, 6, o, 6, 6, 7, 6, 7, 6, 3, 6, 6, 1, 6, 6, 6, 8, 8, 6, 6, 6, 7, 6, 6, 6, 8, 6, 2, 6,
		 6, 7, 8, 6, 6, 6, 8, 6, 6, 6, 6, 6, 2, 6, 6, 1, 6, 6, 6, 6, 3, 8, 6, 3, 6, 6, 6, 6, 6, 2, 6, 6, 6, 7, 8, 6, 6, 6, 8, 6, 6, 6, 6, 6, 2, 6, 6, 1, 6, 6, 6, 6, 3, 8, 6, 3, 6, 6, 6, 6, 6, 2, 6, 6,
		 6, 8, 6, 6, 6, 6, 6, 6, 8, 7, o, 6, 6, 8, 6, 7, 2, 8, 6, 2, 6, 8, o, 6, 6, 6, 7, 6, 2, 1, 7, 6, 6, 8, 6, 6, 6, 6, 6, 6, 8, 7, o, 6, 6, 8, 6, 7, 2, 8, 6, 2, 6, 8, o, 6, 6, 6, 7, 6, 2, 1, 7, 6,
		 o, 6, 6, 6, 8, 6, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 2, 6, 7, 6, 3, 6, 8, 6, 6, 7, 6, 6, 1, o, 6, 6, o, 6, 6, 6, 8, 6, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 2, 6, 7, 6, 3, 6, 8, 6, 6, 7, 6, 6, 1, o, 6, 6,
		 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 7, 6, 7, 6, 8, 6, 2, 2, 6, 6, 6, 7, 8, 6, 6, 6, 6, 2, 2, 6, 6, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 7, 6, 7, 6, 8, 6, 2, 2, 6, 6, 6, 7, 8, 6, 6, 6, 6, 2, 2, 6, 6, 6,
		 7, 6, 7, 6, 8, 6, 6, 6, 3, 6, 6, 7, 6, o, 8, 6, 6, 6, 8, 6, 6, 6, 8, 7, 6, 6, 3, 2, 6, 6, 6, 7, 7, 6, 7, 6, 8, 6, 6, 6, 3, 6, 6, 7, 6, o, 8, 6, 6, 6, 8, 6, 6, 6, 8, 7, 6, 6, 3, 2, 6, 6, 6, 7,
		 6, 7, 6, 3, 8, 6, 6, 7, 6, 8, 6, 6, 6, 8, 8, 2, 8, 6, 6, 6, 3, 6, 8, 6, 8, 6, 6, 6, 6, 7, 6, 6, 6, 7, 6, 3, 8, 6, 6, 7, 6, 8, 6, 6, 6, 8, 8, 2, 8, 6, 6, 6, 3, 6, 8, 6, 8, 6, 6, 6, 6, 7, 6, 6,
		 6, 6, 6, 6, 8, 3, 6, 6, 8, 6, 6, 3, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 6, 8, 6, 8, 6, 7, 6, 6, 7, 6, 6, 6, 6, 6, 8, 3, 6, 6, 8, 6, 6, 3, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 6, 8, 6, 8, 6, 7, 6, 6, 7, 6,
		 2, 6, 6, 6, 8, 6, 7, 6, 6, 6, 6, 6, 8, 2, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 7, 8, o, 6, 7, 6, 6, 2, 6, 6, 6, 8, 6, 7, 6, 6, 6, 6, 6, 8, 2, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 7, 8, o, 6, 7, 6, 6,
		 6, 2, 6, 3, 6, 3, 6, 6, 3, 6, 6, 7, 8, 6, 6, 6, o, 6, 8, 6, 7, 6, 3, 6, 7, 6, 8, 6, 6, 6, 6, 6, 6, 2, 6, 3, 6, 3, 6, 6, 3, 6, 6, 7, 8, 6, 6, 6, o, 6, 8, 6, 7, 6, 3, 6, 7, 6, 8, 6, 6, 6, 6, 6,
		 6, 2, 7, 6, 2, 6, 6, 6, 6, 6, 8, 6, 8, 6, 7, 6, 6, 6, 6, 8, 6, 8, 6, 6, 6, 7, 6, 8, 2, 3, 6, 7, 6, 2, 7, 6, 2, 6, 6, 6, 6, 6, 8, 6, 8, 6, 7, 6, 6, 6, 6, 8, 6, 8, 6, 6, 6, 7, 6, 8, 2, 3, 6, 7,
		 6, 8, 2, 6, 6, 7, 6, 8, 6, 6, 6, 8, 8, 6, 6, 6, 6, 8, 6, 6, 6, 2, 6, 6, o, 6, 6, 8, 6, 6, 8, 6, 6, 8, 2, 6, 6, 7, 6, 8, 6, 6, 6, 8, 8, 6, 6, 6, 6, 8, 6, 6, 6, 2, 6, 6, o, 6, 6, 8, 6, 6, 8, 6,
		 6, 6, 2, 6, 7, 6, 2, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 6, 7, 6, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 6, 6, 2, 6, 7, 6, 2, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6, 6, 7, 6, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 6,
		 6, 6, 2, 6, 6, 6, 6, 6, 7, 6, 6, o, 6, 6, 6, 7, 6, 6, 7, 6, 3, 6, 3, 6, 6, 7, 6, 3, 6, 7, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 7, 6, 6, o, 6, 6, 6, 7, 6, 6, 7, 6, 3, 6, 3, 6, 6, 7, 6, 3, 6, 7, 6, 6,
		 7, 6, 6, 6, 7, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, o, 6, 7, 6, 6, 6, 7, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, o, 6,
		/* sprite #002 */
		 1, 6, 6, 6, 6, 6, 8, 6, 1, 6, 7, 6, 3, 6, 6, 9, 6, 1, 6, 6, 6, 6, 6, 6, 6, 1, 6, 7, 6, 3, 6, 6, 1, 6, 6, 6, 6, 6, 8, 6, 1, 6, 7, 6, 3, 6, 6, 9, 6, 1, 6, 6, 6, 6, 6, 6, 6, 1, 6, 7, 6, 3, 6, 6,
		 7, 6, 3, 6, 6, 6, 8, 8, 6, 6, 6, 7, 6, 6, 9, 2, 6, 6, 3, 6, 6, 6, 7, 6, 6, 9, 6, 6, 6, 1, 6, 6, 7, 6, 3, 6, 6, 6, 8, 8, 6, 6, 6, 7, 6, 6, 9, 2, 6, 6, 3, 6, 6, 6, 7, 6, 6, 9, 6, 6, 6, 1, 6, 6,
		 2, 6, 6, 6, 6, 6, 2, 8, 7, 6, 6, 6, 6, 9, 9, 7, 6, 6, o, 3, 3, 6, 6, 7, 6, 6, 9, 1, 6, 7, 6, 6, 2, 6, 6, 6, 6, 6, 2, 8, 7, 6, 6, 6, 6, 9, 9, 7, 6, 6, o, 3, 3, 6, 6, 7, 6, 6, 9, 1, 6, 7, 6, 6,
		 9, 6, 2, 6, 8, 6, 6, 6, 8, 6, 6, 7, 6, 9, 6, 6, 7, 6, 6, 6, 3, 3, 6, 6, 6, 9, 6, 6, 7, 6, 7, 6, 9, 6, 2, 6, 8, 6, 6, 6, 8, 6, 6, 7, 6, 9, 6, 6, 7, 6, 6, 6, 3, 3, 6, 6, 6, 9, 6, 6, 7, 6, 7, 6,
		 9, 7, 6, 6, 9, 6, 6, 6, 8, 6, 6, 6, 9, 6, 8, 6, 6, 6, 8, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 8, 6, 9, 7, 6, 6, 9, 6, 6, 6, 8, 6, 6, 6, 9, 6, 8, 6, 6, 6, 8, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 8, 6,
		 7, 6, 6, 9, 6, 9, 3, 6, 6, 7, 6, 2, 6, 6, 6, 6, 6, 8, 6, 8, 6, 3, 6, 6, 6, 6, 6, 8, 6, 6, 6, 8, 7, 6, 6, 9, 6, 9, 3, 6, 6, 7, 6, 2, 6, 6, 6, 6, 6, 8, 6, 8, 6, 3, 6, 6, 6, 6, 6, 8, 6, 6, 6, 8,
		 6, 6, 6, 6, 2, 6, 6, 9, 6, 6, 3, 8, 3, 6, 6, 3, 6, 6, 2, 2, 7, 6, 6, o, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 9, 6, 6, 3, 8, 3, 6, 6, 3, 6, 6, 2, 2, 7, 6, 6, o, 7, 6, 6, 6, 6, 6, 6, 6,
		 6, 6, 7, 2, 1, 6, 2, 6, 6, 6, 8, 8, 6, 7, 6, 6, 6, 2, 1, 8, 6, 6, 6, 6, 9, 9, 9, 6, 6, 2, 6, 6, 6, 6, 7, 2, 1, 6, 2, 6, 6, 6, 8, 8, 6, 7, 6, 6, 6, 2, 1, 8, 6, 6, 6, 6, 9, 9, 9, 6, 6, 2, 6, 6,
		 6, 6, 6, 1, 6, 6, 7, 6, 6, 6, 8, o, 3, 6, 6, 8, 6, 1, 3, 6, 6, 7, 6, 9, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 1, 6, 6, 7, 6, 6, 6, 8, o, 3, 6, 6, 8, 6, 1, 3, 6, 6, 7, 6, 9, 6, 6, 6, 6, 2, 6, 6, 6,
		 6, 6, 7, 2, 2, 6, 6, 7, 6, 6, 8, 6, 6, 6, 7, 6, 2, 6, 6, 6, o, 6, 9, 6, 6, 3, 6, 2, 6, 6, 6, 7, 6, 6, 7, 2, 2, 6, 6, 7, 6, 6, 8, 6, 6, 6, 7, 6, 2, 6, 6, 6, o, 6, 9, 6, 6, 3, 6, 2, 6, 6, 6, 7,
		 o, 3, 2, 6, 8, 6, 6, 3, 6, 8, 6, 6, 6, 6, 6, 2, 6, 6, 7, 6, 6, 6, 9, 6, 8, 6, 7, 2, 6, 6, 3, 6, o, 3, 2, 6, 8, 6, 6, 3, 6, 8, 6, 6, 6, 6, 6, 2, 6, 6, 7, 6, 6, 6, 9, 6, 8, 6, 7, 2, 6, 6, 3, 6,
		 9, 6, 6, 7, 6, 8, 6, 6, 6, 8, 7, 6, 7, 6, 6, 2, 6, 7, 6, 7, 6, 6, 9, 6, 6, 8, 2, 6, 3, o, 6, 6, 9, 6, 6, 7, 6, 8, 6, 6, 6, 8, 7, 6, 7, 6, 6, 2, 6, 7, 6, 7, 6, 6, 9, 6, 6, 8, 2, 6, 3, o, 6, 6,
		 6, 6, 8, 8, 8, 6, 6, 7, 6, 8, 8, 7, 6, 6, 3, 2, 6, 6, 6, 6, 2, 8, 6, 9, 6, 6, 2, 7, 6, 6, 6, 6, 6, 6, 8, 8, 8, 6, 6, 7, 6, 8, 8, 7, 6, 6, 3, 2, 6, 6, 6, 6, 2, 8, 6, 9, 6, 6, 2, 7, 6, 6, 6, 6,
		 6, 8, 8, 6, 6, 6, 7, 3, 3, 3, 8, 8, 6, 6, 6, 2, 7, o, 6, 6, 6, 6, 7, 6, 6, 3, 2, 9, 3, 6, 3, 6, 6, 8, 8, 6, 6, 6, 7, 3, 3, 3, 8, 8, 6, 6, 6, 2, 7, o, 6, 6, 6, 6, 7, 6, 6, 3, 2, 9, 3, 6, 3, 6,
		 7, 8, 6, 3, 6, 6, 6, 3, 6, 6, 6, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 8, 6, 8, 6, 6, 9, 6, 6, 2, 6, 7, 7, 8, 6, 3, 6, 6, 6, 3, 6, 6, 6, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 8, 6, 8, 6, 6, 9, 6, 6, 2, 6, 7,
		 9, 8, 6, o, 6, 6, 3, 6, 6, 7, 6, 6, 8, 6, 6, 7, 6, 7, 6, 3, 6, 6, 8, 6, 6, 6, 9, 6, 7, 6, 6, 6, 9, 8, 6, o, 6, 6, 3, 6, 6, 7, 6, 6, 8, 6, 6, 7, 6, 7, 6, 3, 6, 6, 8, 6, 6, 6, 9, 6, 7, 6, 6, 6,
		 8, 7, 6, 6, 6, 8, 3, 6, 2, 6, 6, 7, 6, 8, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 7, 9, 6, 2, 6, 7, 6, 6, 8, 7, 6, 6, 6, 8, 3, 6, 2, 6, 6, 7, 6, 8, 6, 6, 7, 6, 6, 6, 8, 6, 6, 6, 7, 9, 6, 2, 6, 7, 6, 6,
		 8, 6, 6, 8, 6, 6, 3, 6, 3, 6, 6, 9, 6, 8, 7, 6, 6, 8, 6, 7, 6, 6, o, 6, 6, 9, 6, 6, 2, 9, 6, 9, 8, 6, 6, 8, 6, 6, 3, 6, 3, 6, 6, 9, 6, 8, 7, 6, 6, 8, 6, 7, 6, 6, o, 6, 6, 9, 6, 6, 2, 9, 6, 9,
		 8, 6, 8, 6, 8, 3, 6, 9, 6, 8, 6, 6, 9, 6, 6, 2, 8, 6, 7, 6, 2, 6, 6, 7, 9, 6, 6, 8, 2, 2, 9, 6, 8, 6, 8, 6, 8, 3, 6, 9, 6, 8, 6, 6, 9, 6, 6, 2, 8, 6, 7, 6, 2, 6, 6, 7, 9, 6, 6, 8, 2, 2, 9, 6,
		 8, 6, 6, 7, 2, 6, 6, 6, 7, 6, 6, 7, 6, 3, 6, 8, 6, 6, 6, 7, 6, 8, 6, 6, 9, 8, 6, 6, 6, 2, 6, 2, 8, 6, 6, 7, 2, 6, 6, 6, 7, 6, 6, 7, 6, 3, 6, 8, 6, 6, 6, 7, 6, 8, 6, 6, 9, 8, 6, 6, 6, 2, 6, 2,
		 6, 6, 6, 1, 8, 2, 2, 6, 6, 6, 6, 6, 6, 6, 8, 6, 7, 2, 2, 6, 6, 6, 6, 6, 9, 6, 8, 6, 7, 2, 6, 6, 6, 6, 6, 1, 8, 2, 2, 6, 6, 6, 6, 6, 6, 6, 8, 6, 7, 2, 2, 6, 6, 6, 6, 6, 9, 6, 8, 6, 7, 2, 6, 6,
		 8, 6, 2, 3, 6, 6, 6, 6, 6, 7, 6, 6, 6, 7, 8, 8, 6, 2, 6, 3, 6, 6, 3, 6, 6, 7, 6, 6, 6, 2, 6, 6, 8, 6, 2, 3, 6, 6, 6, 6, 6, 7, 6, 6, 6, 7, 8, 8, 6, 2, 6, 3, 6, 6, 3, 6, 6, 7, 6, 6, 6, 2, 6, 6,
		 6, 8, 1, 6, 6, 6, 9, 7, 6, 6, 8, 8, 6, 8, o, 6, 2, 6, 6, 6, 7, 2, 6, 6, 6, 6, 8, 2, 6, 6, 2, 7, 6, 8, 1, 6, 6, 6, 9, 7, 6, 6, 8, 8, 6, 8, o, 6, 2, 6, 6, 6, 7, 2, 6, 6, 6, 6, 8, 2, 6, 6, 2, 7,
		 3, 6, 2, 7, 6, 9, 7, 6, 6, 6, 8, 6, 9, 8, 9, 6, 1, 6, o, 3, 6, 6, 1, 6, 6, 3, 6, 6, 6, 3, 2, 6, 3, 6, 2, 7, 6, 9, 7, 6, 6, 6, 8, 6, 9, 8, 9, 6, 1, 6, o, 3, 6, 6, 1, 6, 6, 3, 6, 6, 6, 3, 2, 6,
		 6, 6, 2, 6, 9, 6, 6, 2, 6, o, 8, 6, 6, 8, 6, 2, 6, 3, 6, 6, 6, 7, 6, 1, 6, 6, 6, 6, 7, 6, 2, 3, 6, 6, 2, 6, 9, 6, 6, 2, 6, o, 8, 6, 6, 8, 6, 2, 6, 3, 6, 6, 6, 7, 6, 1, 6, 6, 6, 6, 7, 6, 2, 3,
		 6, 2, 6, 6, 9, 6, 6, 6, 2, 8, 6, 9, 6, 8, 7, 2, 7, 6, 6, 9, 6, 6, 3, 6, 2, 8, 6, o, 6, 2, 9, 6, 6, 2, 6, 6, 9, 6, 6, 6, 2, 8, 6, 9, 6, 8, 7, 2, 7, 6, 6, 9, 6, 6, 3, 6, 2, 8, 6, o, 6, 2, 9, 6,
		 6, 7, o, 6, 9, 9, 7, 6, 6, 8, 6, 6, 6, 7, 6, 2, 6, 9, 6, 7, 6, 6, 6, 6, 1, 6, 8, 6, 6, 2, 6, 6, 6, 7, o, 6, 9, 9, 7, 6, 6, 8, 6, 6, 6, 7, 6, 2, 6, 9, 6, 7, 6, 6, 6, 6, 1, 6, 8, 6, 6, 2, 6, 6,
		 6, 6, 6, 9, 9, 6, 9, 6, 6, 8, 8, 6, 2, 6, 6, 2, 9, 6, 7, 6, 6, 3, 6, 6, 6, 2, 6, 8, 8, 6, 6, 2, 6, 6, 6, 9, 9, 6, 9, 6, 6, 8, 8, 6, 2, 6, 6, 2, 9, 6, 7, 6, 6, 3, 6, 6, 6, 2, 6, 8, 8, 6, 6, 2,
		 7, 6, 7, 6, 3, 6, 6, 6, 3, 8, 6, 6, 6, 6, 2, 6, 6, 9, 6, 6, 6, 6, 9, 7, o, 2, 6, 7, 8, 3, 6, 6, 7, 6, 7, 6, 3, 6, 6, 6, 3, 8, 6, 6, 6, 6, 2, 6, 6, 9, 6, 6, 6, 6, 9, 7, o, 2, 6, 7, 8, 3, 6, 6,
		 6, 7, 6, 6, 6, 6, 6, 7, 6, 8, 6, 9, 3, 6, 7, 6, 8, 6, 6, 6, 8, 9, 6, 6, 6, 6, 2, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 6, 7, 6, 8, 6, 9, 3, 6, 7, 6, 8, 6, 6, 6, 8, 9, 6, 6, 6, 6, 2, 6, 6, 8, 6, 6,
		 7, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 6, 2, 6, 8, 6, 6, 8, 6, o, 6, 9, 7, 6, 7, 6, 3, 6, 6, 8, 6, 8, 7, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 6, 2, 6, 8, 6, 6, 8, 6, o, 6, 9, 7, 6, 7, 6, 3, 6, 6, 8, 6, 8,
		 6, 6, 7, 6, 6, 2, 6, 7, 6, 6, 2, 6, 6, 6, 9, 6, 6, 6, 7, 6, 6, 9, 6, 7, 6, 6, 6, 8, 6, 6, o, 6, 6, 6, 7, 6, 6, 2, 6, 7, 6, 6, 2, 6, 6, 6, 9, 6, 6, 6, 7, 6, 6, 9, 6, 7, 6, 6, 6, 8, 6, 6, o, 6,
		/* sprite #003 */
		 7, 6, o, 6, 2, 6, 1, 6, 6, 6, 6, 7, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 9, 6, 6, 6, 3, 6, 6, 7, 6, o, 6, 2, 6, 1, 6, 6, 6, 6, 7, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 9, 6, 6, 6, 3, 6, 6,
		 6, o, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 6, 9, 6, 6, 6, 2, 6, 6, 7, 6, 2, 6, 6, 7, 6, 6, 6, o, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 6, 9, 6, 6, 6, 2, 6, 6, 7, 6, 2, 6, 6, 7, 6, 6,
		 8, 6, 7, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 8, 6, 6, 8, 6, 2, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 6, 7, 8, 6, 7, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 8, 6, 6, 8, 6, 2, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 6, 7,
		 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 8, 6, 6, 6, 8, 6, 7, 6, 3, 9, 6, 6, 6, 7, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 8, 6, 6, 6, 8, 6, 7, 6, 3, 9, 6, 6, 6, 7, 6, 6, 6, 6, 6, 7, 6,
		 6, 6, 3, 6, 7, 6, 6, o, 7, 6, 6, 6, 6, 6, 9, 6, 6, 2, 6, 6, 6, 6, 6, 3, 6, 6, 6, 3, 6, 7, 6, 7, 6, 6, 3, 6, 7, 6, 6, o, 7, 6, 6, 6, 6, 6, 9, 6, 6, 2, 6, 6, 6, 6, 6, 3, 6, 6, 6, 3, 6, 7, 6, 7,
		 2, 6, 6, 9, 6, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, 9, 6, 6, 6, 2, 6, 8, 6, 6, 6, 9, 6, 2, 6, 6, 6, 6, 2, 6, 6, 9, 6, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, 9, 6, 6, 6, 2, 6, 8, 6, 6, 6, 9, 6, 2, 6, 6, 6, 6,
		 6, 6, 7, 6, 6, 7, 6, 7, 6, 6, 6, 6, 7, 6, 9, 6, 6, 6, 7, 6, 6, 6, 2, 6, 6, 7, 9, 6, 6, o, 7, 6, 6, 6, 7, 6, 6, 7, 6, 7, 6, 6, 6, 6, 7, 6, 9, 6, 6, 6, 7, 6, 6, 6, 2, 6, 6, 7, 9, 6, 6, o, 7, 6,
		 6, 9, 6, 6, o, 6, 7, 6, 6, 3, 6, 6, 9, 6, 6, 7, 6, 7, 6, 6, 9, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9, 6, 6, o, 6, 7, 6, 6, 3, 6, 6, 9, 6, 6, 7, 6, 7, 6, 6, 9, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6,
		 3, 6, 6, 7, 6, 6, 6, 6, 8, 6, 7, 6, 6, 6, 3, 6, 6, 6, 9, 6, 6, 6, o, 6, 2, 6, 6, 7, 6, 7, 6, 6, 3, 6, 6, 7, 6, 6, 6, 6, 8, 6, 7, 6, 6, 6, 3, 6, 6, 6, 9, 6, 6, 6, o, 6, 2, 6, 6, 7, 6, 7, 6, 6,
		 6, 6, 3, 6, 6, 6, 3, 6, 6, 8, 6, 6, 3, o, 6, 6, 6, 9, 6, 9, 6, 7, 6, 6, 6, 7, o, 6, 7, 6, 6, 3, 6, 6, 3, 6, 6, 6, 3, 6, 6, 8, 6, 6, 3, o, 6, 6, 6, 9, 6, 9, 6, 7, 6, 6, 6, 7, o, 6, 7, 6, 6, 3,
		 7, 6, 6, 6, 2, 8, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, o, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 6, 8, 6, 7, 6, 6, 6, 2, 8, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, o, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 6, 6, 8, 6,
		 6, 6, 3, 6, 6, 6, 7, 6, 6, 3, 6, 6, 3, 6, 3, 6, 8, 6, 7, 6, 6, 6, 7, 6, 6, 6, 6, 6, 3, 6, 6, 8, 6, 6, 3, 6, 6, 6, 7, 6, 6, 3, 6, 6, 3, 6, 3, 6, 8, 6, 7, 6, 6, 6, 7, 6, 6, 6, 6, 6, 3, 6, 6, 8,
		 6, 6, 6, 7, 6, 2, 6, 8, 6, 6, 6, 6, 6, 2, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 8, 6, 6, 6, 6, 6, 6, 6, 7, 6, 2, 6, 8, 6, 6, 6, 6, 6, 2, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 8, 6, 6, 6, 6,
		 2, 6, 7, 6, 6, 6, 2, 6, 6, 6, 8, 6, 7, 6, 6, 6, 6, 6, 3, 6, 7, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 3, 2, 6, 7, 6, 6, 6, 2, 6, 6, 6, 8, 6, 7, 6, 6, 6, 6, 6, 3, 6, 7, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 3,
		 6, 9, 6, 6, 8, 6, 6, 2, 7, 6, 6, 2, 6, 7, 6, 6, 2, 6, 6, 9, 6, 6, 8, 6, 9, 6, 6, 8, 6, 8, 6, 6, 6, 9, 6, 6, 8, 6, 6, 2, 7, 6, 6, 2, 6, 7, 6, 6, 2, 6, 6, 9, 6, 6, 8, 6, 9, 6, 6, 8, 6, 8, 6, 6,
		 9, 6, 9, 6, 6, 6, 7, 6, 2, o, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 9, 6, 6, 3, 6, 7, 6, 6, 8, 6, 6, 6, 9, 6, 9, 6, 6, 6, 7, 6, 2, o, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 9, 6, 6, 3, 6, 7, 6, 6, 8, 6, 6, 6,
		 6, 6, 7, 6, 2, 6, 6, 7, 2, 6, 6, 8, 6, 6, 6, 7, 6, 6, 9, 6, 7, 6, 6, 2, 6, 6, 8, 6, 6, 6, 7, 6, 6, 6, 7, 6, 2, 6, 6, 7, 2, 6, 6, 8, 6, 6, 6, 7, 6, 6, 9, 6, 7, 6, 6, 2, 6, 6, 8, 6, 6, 6, 7, 6,
		 6, 6, 6, 7, 6, 8, 6, 6, 6, 8, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 6, 7, 6, 6, o, 6, 6, o, 6, 6, 9, 6, 6, 6, 7, 6, 8, 6, 6, 6, 8, 6, 6, 3, 6, 7, 6, 7, 6, 6, o, 6, 6, 7, 6, 6, o, 6, 6, o, 6, 6, 9,
		 7, 6, 2, 6, 6, 6, 6, 6, 8, 6, 8, 6, 2, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 2, 2, 6, 6, 3, 6, 6, 7, 7, 6, 2, 6, 6, 6, 6, 6, 8, 6, 8, 6, 2, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 2, 2, 6, 6, 3, 6, 6, 7,
		 6, 3, 6, 3, 6, 6, 3, 6, 6, 7, 6, 6, 6, 6, o, 7, 6, 6, 6, 6, 9, 6, 6, 7, 6, 2, 6, 6, 6, 6, 7, 6, 6, 3, 6, 3, 6, 6, 3, 6, 6, 7, 6, 6, 6, 6, o, 7, 6, 6, 6, 6, 9, 6, 6, 7, 6, 2, 6, 6, 6, 6, 7, 6,
		 6, 6, 6, 6, 7, 6, 6, 6, 9, 6, 8, 2, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, o, 6, 7, 6, 2, 3, 6, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 6, 9, 6, 8, 2, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, o, 6, 7, 6, 2, 3, 6, 6, 6, 6,
		 6, 6, o, 3, 6, 6, 8, 6, 6, 3, 6, 6, 7, 6, 7, 6, 6, 6, 6, 7, 6, 7, 6, 6, 6, 6, 2, 6, 7, 6, 6, 9, 6, 6, o, 3, 6, 6, 8, 6, 6, 3, 6, 6, 7, 6, 7, 6, 6, 6, 6, 7, 6, 7, 6, 6, 6, 6, 2, 6, 7, 6, 6, 9,
		 6, 3, 6, 6, 6, 7, 6, 8, 6, 6, 6, 6, 6, 7, 6, 6, 3, 6, 6, 6, 6, 6, 6, 6, 3, 6, 6, 2, 6, 6, 3, o, 6, 3, 6, 6, 6, 7, 6, 8, 6, 6, 6, 6, 6, 7, 6, 6, 3, 6, 6, 6, 6, 6, 6, 6, 3, 6, 6, 2, 6, 6, 3, o,
		 7, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, o, 6, 6, 6, 8, 6, 7, 6, 6, 6, 3, 6, 6, 7, 6, 6, 2, 6, 7, 6, 6, 7, 6, 6, 6, 6, 6, 3, 6, 6, 7, 6, o, 6, 6, 6, 8, 6, 7, 6, 6, 6, 3, 6, 6, 7, 6, 6, 2, 6, 7, 6, 6,
		 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 7, 6, 6, 3, 6, 6, 8, 6, 6, 3, o, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 7, 6, 6, 3, 6, 6, 8, 6, 6, 3, o, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6,
		 6, 6, 7, 6, 6, 3, 6, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 7, 6, 6, 6, 6, 7, 6, 6, 3, 6, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 7, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 7, 6, 6,
		 6, 6, 6, 6, 6, 6, 6, 7, 2, 6, 6, 7, 6, 7, 6, 6, 3, 6, 6, 3, 6, 3, 6, 6, 9, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 2, 6, 6, 7, 6, 7, 6, 6, 3, 6, 6, 3, 6, 3, 6, 6, 9, 6, 6, 2, 6, 6, 6, 6,
		 8, 6, 6, 6, 8, 6, 6, 6, 6, 2, 2, 6, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 7, 6, 6, 3, 9, 6, 9, 6, 6, 7, 8, 6, 6, 6, 8, 6, 6, 6, 6, 2, 2, 6, 8, 6, 8, 6, 6, 6, 6, 6, 2, 6, 7, 6, 6, 3, 9, 6, 9, 6, 6, 7,
		 6, 8, 6, o, 6, 6, 7, 6, 7, 2, 2, 6, 6, 8, 6, 6, 6, 8, 6, 7, 6, 6, 6, 7, 6, 6, 6, 9, 6, 6, 7, 6, 6, 8, 6, o, 6, 6, 7, 6, 7, 2, 2, 6, 6, 8, 6, 6, 6, 8, 6, 7, 6, 6, 6, 7, 6, 6, 6, 9, 6, 6, 7, 6,
		 6, 7, 6, 7, 6, 6, 9, 6, 6, 6, 2, 8, 6, 6, 6, 7, 6, 6, 2, 6, 7, 6, 6, 6, 6, 6, 6, 8, 6, 2, 6, 6, 6, 7, 6, 7, 6, 6, 9, 6, 6, 6, 2, 8, 6, 6, 6, 7, 6, 6, 2, 6, 7, 6, 6, 6, 6, 6, 6, 8, 6, 2, 6, 6,
		 6, 6, 7, 6, 1, 9, 6, 6, 7, 6, 6, 2, 6, o, 6, 6, 7, 6, 6, 6, 6, 6, 8, 7, 6, 2, 6, 6, 6, 6, 6, 2, 6, 6, 7, 6, 1, 9, 6, 6, 7, 6, 6, 2, 6, o, 6, 6, 7, 6, 6, 6, 6, 6, 8, 7, 6, 2, 6, 6, 6, 6, 6, 2,
		 6, 6, 1, 6, 6, 6, 9, 6, 6, 7, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 7, 6, 6, 8, 6, 6, 6, 6, 6, 3, 6, 7, 6, 6, 1, 6, 6, 6, 9, 6, 6, 7, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 7, 6, 6, 8, 6, 6, 6, 6, 6, 3, 6, 7,
		/* sprite #004 */
		 5, 5, 8, 8, 6, 6, 2, 6, 5, 5, 6, 6, 8, 6, 6, 8, 6, 6, 8, 8, 8, 5, 8, 5, 5, 8, 6, 6, 2, 5, 6, 6, 5, 5, 8, 8, 6, 6, 6, 6, 5, 5, 6, 6, 8, 6, 6, 8, 6, 6, 8, 8, 8, 5, 8, 5, 5, 8, 6, 6, 2, 5, 6, 6,
		 2, 8, 8, 5, 5, 5, 6, 2, 2, 6, 6, 9, 8, 8, 2, 6, 8, 6, 6, 8, 8, 6, 6, 6, 6, 8, 8, 9, 2, 6, 5, 8, 6, 8, 5, 6, 6, 8, 5, 6, 2, 5, 5, 8, 5, 6, 8, 8, 5, 6, 6, 8, 6, 5, 6, 6, 6, 6, 6, 2, 6, 2, 8, 2,
		 6, 8, 6, 6, 6, 6, 5, 9, 6, 2, 9, 6, 6, 8, 6, 2, 6, 8, 6, 8, 6, 6, 2, 2, 6, 6, 8, 5, 6, 2, 6, 5, 8, 6, 6, 8, 6, 6, 5, 6, 2, 8, 8, 5, 5, 8, 6, 8, 8, 5, 5, 8, 8, 6, 8, 5, 8, 8, 8, 6, 6, 6, 6, 6,
		 8, 5, 5, 5, 9, 6, 2, 5, 9, 6, 6, 5, 5, 9, 8, 2, 6, 5, 6, 6, 2, 2, 6, 6, 9, 6, 6, 8, 9, 6, 6, 5, 5, 8, 6, 6, 6, 6, 6, 2, 6, 5, 8, 8, 9, 5, 6, 6, 8, 8, 5, 8, 6, 8, 5, 6, 5, 5, 6, 6, 6, 6, 8, 8,
		 8, 8, 5, 8, 5, 6, 6, 2, 6, 6, 5, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 9, 6, 6, 9, 6, 6, 8, 5, 6, 6, 5, 5, 6, 8, 6, 6, 2, 6, 8, 8, 6, 8, 8, 9, 5, 6, 6, 8, 8, 6, 6, 5, 9, 5, 8, 8, 6, 5, 5, 6, 2, 6,
		 6, 8, 8, 6, 6, 5, 9, 6, 6, 6, 6, 6, 6, 6, 5, 8, 6, 6, 6, 6, 8, 8, 6, 6, 8, 5, 8, 8, 6, 8, 5, 9, 6, 8, 2, 6, 8, 8, 6, 8, 8, 5, 6, 6, 8, 8, 9, 9, 6, 6, 8, 9, 9, 9, 8, 8, 6, 6, 5, 6, 9, 6, 2, 6,
		 8, 6, 6, 6, 6, 6, 5, 6, 2, 6, 8, 5, 8, 8, 6, 6, 9, 8, 5, 5, 6, 6, 8, 6, 6, 5, 5, 8, 6, 8, 9, 5, 5, 5, 2, 6, 8, 6, 6, 8, 5, 9, 8, 6, 6, 8, 8, 6, 2, 6, 6, 9, 8, 6, 6, 6, 8, 5, 5, 9, 8, 2, 2, 5,
		 5, 5, 5, 8, 8, 6, 6, 6, 9, 6, 6, 6, 5, 8, 6, 9, 8, 5, 6, 6, 9, 8, 8, 8, 6, 6, 5, 8, 5, 6, 9, 9, 5, 8, 6, 2, 8, 8, 8, 8, 5, 5, 6, 8, 6, 6, 6, 9, 6, 2, 9, 6, 6, 6, 6, 8, 8, 6, 5, 8, 6, 2, 6, 5,
		 6, 6, 8, 5, 5, 9, 6, 9, 8, 8, 8, 6, 6, 5, 8, 5, 6, 6, 6, 8, 8, 5, 8, 5, 8, 6, 5, 8, 8, 6, 8, 9, 9, 8, 6, 2, 8, 8, 8, 5, 9, 6, 8, 6, 8, 6, 6, 2, 6, 2, 6, 6, 6, 8, 5, 8, 5, 5, 9, 9, 6, 6, 8, 8,
		 6, 8, 6, 6, 6, 5, 6, 6, 5, 5, 8, 8, 6, 6, 5, 6, 6, 6, 9, 8, 5, 8, 5, 8, 5, 5, 6, 5, 5, 6, 6, 8, 8, 8, 6, 6, 8, 8, 6, 9, 6, 6, 5, 8, 6, 6, 6, 6, 2, 6, 2, 5, 8, 5, 8, 5, 9, 9, 6, 6, 6, 8, 8, 6,
		 8, 5, 8, 8, 8, 6, 6, 2, 5, 6, 6, 5, 8, 8, 6, 2, 6, 8, 8, 5, 5, 6, 6, 6, 8, 8, 8, 8, 8, 6, 6, 8, 8, 6, 6, 8, 8, 6, 2, 6, 6, 9, 8, 6, 6, 5, 8, 6, 6, 2, 2, 9, 5, 6, 6, 6, 8, 8, 8, 8, 8, 6, 6, 6,
		 6, 8, 5, 5, 8, 8, 6, 2, 6, 6, 9, 5, 6, 8, 8, 6, 2, 8, 5, 6, 2, 2, 6, 6, 6, 8, 6, 8, 8, 8, 6, 6, 9, 6, 6, 9, 6, 2, 6, 8, 9, 5, 5, 8, 5, 8, 8, 6, 2, 6, 6, 9, 9, 5, 6, 6, 6, 6, 2, 2, 2, 6, 6, 6,
		 6, 8, 6, 6, 6, 6, 6, 6, 2, 6, 5, 8, 8, 6, 8, 8, 2, 6, 6, 2, 6, 8, 8, 6, 6, 6, 6, 6, 6, 6, 2, 2, 6, 9, 6, 6, 6, 6, 8, 5, 8, 5, 8, 8, 8, 8, 6, 6, 5, 5, 5, 6, 6, 9, 5, 5, 9, 5, 5, 9, 9, 6, 2, 8,
		 8, 6, 6, 8, 8, 9, 8, 6, 6, 6, 6, 5, 8, 8, 6, 8, 6, 6, 6, 8, 8, 8, 9, 9, 6, 6, 6, 2, 2, 2, 6, 2, 2, 6, 9, 6, 8, 8, 8, 8, 5, 8, 9, 8, 6, 9, 9, 5, 8, 5, 8, 5, 6, 6, 6, 6, 5, 8, 9, 9, 2, 2, 6, 5,
		 5, 6, 8, 8, 9, 6, 9, 8, 8, 6, 6, 9, 5, 8, 8, 8, 8, 6, 6, 8, 8, 6, 9, 5, 8, 5, 8, 8, 8, 8, 6, 2, 6, 8, 6, 6, 9, 6, 6, 8, 8, 9, 8, 6, 6, 6, 9, 8, 8, 8, 8, 8, 8, 8, 6, 5, 8, 9, 9, 2, 6, 6, 8, 8,
		 8, 5, 8, 5, 6, 6, 5, 9, 9, 6, 9, 6, 6, 6, 2, 2, 2, 6, 8, 8, 6, 6, 5, 8, 5, 5, 5, 8, 8, 6, 2, 6, 6, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 8, 5, 9, 6, 6, 5, 8, 8, 8,
		 5, 8, 5, 6, 6, 8, 5, 8, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 8, 8, 6, 6, 2, 6, 6, 6, 6, 8, 8, 9, 8, 5, 8, 5, 6, 6, 8, 8, 6, 2, 2, 2, 6, 6, 6, 9, 6, 9, 9, 5, 6, 6, 5, 8, 5, 8, 8,
		 5, 6, 6, 2, 9, 9, 8, 5, 6, 8, 8, 8, 8, 8, 8, 8, 9, 6, 6, 6, 8, 9, 8, 8, 6, 6, 6, 6, 6, 8, 6, 2, 9, 6, 6, 8, 8, 5, 8, 5, 9, 6, 8, 8, 6, 6, 8, 8, 8, 8, 5, 9, 6, 6, 8, 8, 9, 6, 9, 8, 8, 6, 5, 8,
		 6, 2, 2, 9, 9, 8, 5, 6, 6, 6, 6, 5, 8, 5, 8, 5, 9, 9, 6, 8, 9, 8, 5, 8, 8, 9, 8, 6, 9, 8, 6, 6, 8, 2, 6, 6, 8, 6, 6, 9, 9, 8, 8, 8, 6, 6, 6, 8, 6, 8, 8, 5, 6, 6, 6, 6, 8, 9, 8, 8, 6, 6, 5, 8,
		 2, 6, 9, 9, 8, 5, 8, 5, 5, 9, 6, 6, 5, 5, 5, 6, 6, 8, 8, 8, 8, 5, 8, 5, 8, 6, 6, 6, 8, 8, 6, 9, 8, 6, 6, 6, 6, 6, 8, 8, 8, 8, 6, 2, 2, 6, 6, 8, 8, 6, 8, 8, 5, 6, 2, 6, 6, 6, 6, 6, 6, 6, 5, 5,
		 6, 6, 2, 2, 2, 6, 6, 6, 6, 5, 9, 9, 6, 6, 2, 6, 8, 8, 5, 5, 5, 8, 5, 8, 6, 2, 6, 9, 8, 8, 9, 8, 6, 8, 8, 8, 8, 8, 8, 6, 2, 2, 2, 6, 9, 8, 6, 6, 8, 8, 6, 5, 5, 6, 6, 2, 6, 8, 8, 5, 9, 6, 6, 5,
		 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 5, 9, 2, 2, 6, 6, 8, 5, 6, 6, 5, 5, 6, 2, 2, 6, 8, 8, 6, 8, 8, 8, 6, 6, 8, 8, 8, 8, 6, 6, 6, 6, 9, 5, 8, 8, 6, 2, 6, 8, 8, 5, 6, 6, 5, 2, 6, 6, 8, 8, 8, 5, 6, 6,
		 6, 9, 6, 6, 6, 9, 9, 8, 8, 5, 8, 5, 2, 6, 2, 6, 6, 6, 6, 5, 5, 6, 2, 9, 6, 8, 8, 6, 6, 8, 8, 8, 6, 6, 5, 5, 6, 9, 9, 5, 5, 8, 5, 8, 8, 6, 2, 6, 5, 6, 6, 8, 8, 5, 5, 6, 6, 8, 6, 6, 8, 8, 5, 6,
		 8, 6, 2, 9, 9, 8, 8, 5, 5, 8, 6, 6, 6, 2, 6, 2, 6, 6, 8, 6, 5, 6, 9, 5, 8, 8, 8, 6, 2, 8, 9, 9, 8, 6, 8, 5, 5, 8, 5, 5, 8, 5, 8, 8, 6, 6, 6, 5, 8, 9, 6, 6, 8, 8, 8, 5, 6, 8, 5, 8, 8, 8, 8, 8,
		 6, 2, 6, 8, 8, 6, 5, 8, 6, 6, 6, 6, 9, 2, 6, 9, 6, 6, 6, 8, 6, 5, 5, 8, 8, 8, 9, 6, 2, 8, 5, 9, 9, 6, 8, 8, 9, 8, 8, 8, 8, 8, 8, 6, 6, 5, 8, 8, 6, 5, 9, 6, 6, 6, 9, 6, 6, 6, 8, 5, 8, 5, 8, 6,
		 6, 6, 8, 9, 8, 5, 8, 6, 6, 6, 8, 9, 6, 6, 2, 6, 8, 8, 6, 6, 8, 5, 5, 8, 9, 6, 8, 6, 6, 5, 5, 8, 9, 8, 6, 6, 8, 9, 8, 8, 8, 6, 6, 5, 5, 8, 6, 2, 6, 8, 8, 5, 9, 6, 2, 6, 5, 6, 6, 6, 6, 8, 6, 2,
		 8, 6, 9, 6, 5, 6, 6, 8, 8, 9, 9, 9, 8, 6, 6, 9, 9, 8, 8, 6, 6, 5, 8, 9, 6, 9, 8, 6, 6, 8, 5, 5, 8, 8, 6, 6, 6, 9, 8, 8, 8, 8, 8, 6, 2, 2, 6, 8, 5, 6, 6, 6, 6, 6, 6, 6, 9, 5, 6, 6, 5, 6, 6, 8,
		 6, 6, 5, 5, 6, 8, 8, 5, 8, 5, 6, 6, 8, 8, 6, 6, 5, 9, 8, 8, 6, 8, 8, 6, 2, 6, 6, 8, 6, 8, 5, 8, 5, 8, 8, 6, 2, 2, 2, 6, 6, 8, 6, 2, 2, 6, 8, 6, 6, 6, 6, 6, 9, 6, 6, 2, 6, 6, 5, 5, 5, 8, 8, 5,
		 6, 8, 6, 6, 6, 8, 5, 6, 8, 8, 6, 8, 5, 5, 8, 6, 6, 5, 9, 8, 8, 5, 6, 2, 6, 2, 6, 6, 6, 8, 8, 5, 8, 6, 8, 8, 6, 6, 6, 8, 8, 5, 6, 6, 6, 8, 9, 5, 5, 9, 9, 9, 6, 6, 5, 9, 2, 6, 9, 5, 6, 5, 5, 8,
		 6, 6, 2, 6, 8, 8, 8, 8, 6, 6, 8, 8, 5, 5, 8, 8, 6, 8, 5, 5, 8, 8, 6, 2, 8, 2, 6, 8, 6, 6, 8, 5, 6, 6, 8, 6, 8, 8, 5, 5, 5, 6, 6, 8, 6, 5, 8, 5, 8, 8, 6, 6, 5, 2, 6, 5, 9, 6, 6, 6, 6, 5, 8, 6,
		 6, 2, 6, 8, 6, 6, 6, 6, 6, 5, 6, 8, 6, 6, 5, 8, 8, 6, 5, 8, 5, 5, 6, 6, 8, 6, 2, 6, 6, 2, 6, 5, 6, 8, 5, 6, 6, 8, 5, 6, 6, 6, 5, 8, 6, 6, 5, 8, 8, 5, 8, 8, 6, 2, 6, 2, 6, 5, 5, 5, 5, 8, 6, 8,
		 8, 6, 6, 6, 6, 8, 8, 5, 5, 8, 5, 6, 8, 6, 6, 5, 8, 6, 5, 5, 8, 8, 6, 8, 8, 8, 6, 6, 6, 2, 6, 8, 8, 5, 8, 6, 6, 8, 6, 6, 8, 5, 8, 5, 8, 6, 6, 5, 8, 8, 5, 6, 2, 5, 5, 6, 2, 6, 6, 5, 8, 8, 5, 5,
		/* sprite #005 */
		 9, 9, 3, 9,10, 9, 3, 9,11, 9, 3, 9, 3, 3,11, 9, 6, 9, 9, 9, 3, 3, o,11, 9, 6, 3, 9, 9, 3,10,11, 9, 9, 3, 9,10, 9, 3, 9,11, 9, 3, 9, 3, 3,11, 9, 6, 9, 9, 9, 3, 3, o,11, 9, 6, 3, 9, 9, 3,10,11,
		 9, 9, 6, 9, 9, 9, 3,10,10, 9, 3,10, 3, 3,11, 9, 3, 9,10, 9, 3, 3, 9, 1, 9, 2, 9, 9, 9, 3, 9,10, 9, 9, 6, 9, 9, 9, 3,10,10, 9, 3,10, 3, 3,11, 9, 3, 9,10, 9, 3, 3, 9, 1, 9, 2, 9, 9, 9, 3, 9,10,
		 9, 3, 2, 3,10, 9, 3,11, 9, 3, 3,11, 9, 9,11, 9, 3, 3, 9, 9, 3, 9, 9,11, 9, 6, 9, 6, 9, 3, 3, 9, 9, 3, 2, 3,10, 9, 3,11, 9, 3, 3,11, 9, 9,11, 9, 3, 3, 9, 9, 3, 9, 9,11, 9, 6, 9, 6, 9, 3, 3, 9,
		 6, 9, 2, 3, 9, 9, 9, 1, 9, o, 3,11, 9, 9,10, o, 9, 6, 9, 3, 9, 9,10,10, 9, 3, 3, 9, 9, 6, 9, 9, 6, 9, 2, 3, 9, 9, 9, 1, 9, o, 3,11, 9, 9,10, o, 9, 6, 9, 3, 9, 9,10,10, 9, 3, 3, 9, 9, 6, 9, 9,
		 6, 9, 6, o, 9, 9, 9,11, 9, o, 3,11, 9, 3,10, o, 9, 6, 9, 3, 3, 9,11,10, 9, 3, 3, 6,10, 3, 3, 9, 6, 9, 6, o, 9, 9, 9,11, 9, o, 3,11, 9, 3,10, o, 9, 6, 9, 3, 3, 9,11,10, 9, 3, 3, 6,10, 3, 3, 9,
		 2, 6, 3, o,10, 9, 9,10, 9, 3, 9,10, 9, 3, 9,10, 9, 6, 3, 9, 3, 9,10, 9, 3, 3, 9, 2, 9, 6, 3, 9, 2, 6, 3, o,10, 9, 9,10, 9, 3, 9,10, 9, 3, 9,10, 9, 6, 3, 9, 3, 9,10, 9, 3, 3, 9, 2, 9, 6, 3, 9,
		 9, 2, 3, o, 9, 9, 3, 9, 9, 6, 3, 9, 9, 6, 9,10, o, 3, 3, 9, 9, 3, 9, 9, 3, 9, 6, 2, 3, 2, 3, 9, 9, 2, 3, o, 9, 9, 3, 9, 9, 6, 3, 9, 9, 6, 9,10, o, 3, 3, 9, 9, 3, 9, 9, 3, 9, 6, 2, 3, 2, 3, 9,
		 9, 2, 3, 9,10, 9, 3, 9,10, 3, 3,10, 9, 3, 9,10, o, 3, 9, 6, 9, 3,10, 9, 3, 9, 2,10, 3, 2, 3, 9, 9, 2, 3, 9,10, 9, 3, 9,10, 3, 3,10, 9, 3, 9,10, o, 3, 9, 6, 9, 3,10, 9, 3, 9, 2,10, 3, 2, 3, 9,
		 9, 6, 3, 9, 9, 9, o, 9,10, 9, 6, 9, 9, 6, 3, 9,10, 3, 3, 9, 6, 9,10,11, 9, 3, 6,10, 3, 6, 3, 9, 9, 6, 3, 9, 9, 9, o, 9,10, 9, 6, 9, 9, 6, 3, 9,10, 3, 3, 9, 6, 9,10,11, 9, 3, 6,10, 3, 6, 3, 9,
		10, 9, o,10, 9, 3, o, 9, 9, 9, 2, 3, 9, 2, 3, 9,11, 9, 3, 9, 9, 9, 9, 1, 9, 3, 9,10, 3, 8, 3, 9,10, 9, o,10, 9, 3, o, 9, 9, 9, 2, 3, 9, 2, 3, 9,11, 9, 3, 9, 9, 9, 9, 1, 9, 3, 9,10, 3, 8, 3, 9,
		11, 9, o, 9,10, 3, o, 3,11, 3, 2, 3, 9, 6, 2, 9,11, 9, 9, 9, 3, 9, o, 1, 9, 3, 9, 9, 3, 6, 3, 9,11, 9, o, 9,10, 3, o, 3,11, 3, 2, 3, 9, 6, 2, 9,11, 9, 9, 9, 3, 9, o, 1, 9, 3, 9, 9, 3, 6, 3, 9,
		11, 9, 3, 9,11, 9, 3, 3, 1, 3, 6, 9, 9, 3, 2, 9, o,10, 9, 9, 6, 9, o,11, 9, 3, 9,10, 3, 8, 9,10,11, 9, 3, 9,11, 9, 3, 3, 1, 3, 6, 9, 9, 3, 2, 9, o,10, 9, 9, 6, 9, o,11, 9, 3, 9,10, 3, 8, 9,10,
		10, 9, 9, 9,11, 9, 3, 9, 1, 9, 3, 3, 9, 9, 6, 3, 9,11, 9, 9, 6, 9,10,10, 3, 9, 9,11, 9, 8, 9,11,10, 9, 9, 9,11, 9, 3, 9, 1, 9, 3, 3, 9, 9, 6, 3, 9,11, 9, 9, 6, 9,10,10, 3, 9, 9,11, 9, 8, 9,11,
		 9, 9, 9, o,11, 9, 3,10,11, 3, 6, 9,10, 9, 3, 3, 9,10, 9, 3, 3, 9,10, o, 3, 9,10,11, 3, 3, 9,10, 9, 9, 9, o,11, 9, 3,10,11, 3, 6, 9,10, 9, 3, 3, 9,10, 9, 3, 3, 9,10, o, 3, 9,10,11, 3, 3, 9,10,
		 6,10, 9,10,10, 9, 3, 9,10, 3, 3, 9, 9, 6, 3, 6, 9, o, 9, 3, 9, 9,10, 9, 9, 9,11, 9, 3, 9,10, 9, 6,10, 9,10,10, 9, 3, 9,10, 3, 3, 9, 9, 6, 3, 6, 9, o, 9, 3, 9, 9,10, 9, 9, 9,11, 9, 3, 9,10, 9,
		 9,11, 9,10, o, 9, 3, 3, 9, 3, 3, 9,10, 6, 6, 3, 9, 9, 3, 9, 3, 9, 9, 9, 9,10, 9, 9, 3, 9, 9, 9, 9,11, 9,10, o, 9, 3, 3, 9, 3, 3, 9,10, 6, 6, 3, 9, 9, 3, 9, 3, 9, 9, 9, 9,10, 9, 9, 3, 9, 9, 9,
		 9, 9, 9, 9,11, 9, 9, 3, o, 3, 9, 9,10, 9, 2, 3, 3, 9, 9, 9,10, 9, 9, 3, 9,10, 9, 3, 3, 9, 9, 3, 9, 9, 9, 9,11, 9, 9, 3, o, 3, 9, 9,10, 9, 2, 3, 3, 9, 9, 9,10, 9, 9, 3, 9,10, 9, 3, 3, 9, 9, 3,
		10, 9, 3, 9,10,10, 9, 3, o, 3, 9,10,11,10, 6, 3, 3, 9, o, 9,10, 9, 3, o, 9,11, 9, 3, 6, 3, 9, 9,10, 9, 3, 9,10,10, 9, 3, o, 3, 9,10,11,10, 6, 3, 3, 9, o, 9,10, 9, 3, o, 9,11, 9, 3, 6, 3, 9, 9,
		10, 9, 6, 3, o,11, 9, 9, 8, 9, 9,11,10,11, 9, 9, 3, 9,10, 3, 9,10, 3, o, 9,11,10, 9, 3, 3, 3, 9,10, 9, 6, 3, o,11, 9, 9, 8, 9, 9,11,10,11, 9, 9, 3, 9,10, 3, 9,10, 3, o, 9,11,10, 9, 3, 3, 3, 9,
		11,10, 3, 6, 9,10,10, 3, 8, 9, o,10, 3,10, o, 9, 3,10, o, 9, 9,10, 3, 3, 3,10,11, 9, 9, 6, 3,10,11,10, 3, 6, 9,10,10, 3, 8, 9, o,10, 3,10, o, 9, 3,10, o, 9, 9,10, 3, 3, 3,10,11, 9, 9, 6, 3,10,
		 o,10, 9, 6, 3, o,11, 3, 3, 3,10, o, 3, 9,10, 9, 9,11, o, 3, 3, 9, 9, 6, 3, 9, 1, 9, 3, 6, 9,10, o,10, 9, 6, 3, o,11, 3, 3, 3,10, o, 3, 9,10, 9, 9,11, o, 3, 3, 9, 9, 6, 3, 9, 1, 9, 3, 6, 9,10,
		 9,11, 9, 6, 3, 9,11, 9, 3, 3,10, 9, 9, 3,10,10, 9,11, 9, 3, 8, 9,10, 6, 3, 9,11, 9, 3, 3, 3,10, 9,11, 9, 6, 3, 9,11, 9, 3, 3,10, 9, 9, 3,10,10, 9,11, 9, 3, 8, 9,10, 6, 3, 9,11, 9, 3, 3, 3,10,
		 9,11, 9, 6, 6, 9,11, 9, 6, 3, 9, 9, 9, 6, o,11, 9,10, 3, 6, 3, 9,10, 3, 6, 3,10,10, 9, 2, 3, 9, 9,11, 9, 6, 6, 9,11, 9, 6, 3, 9, 9, 9, 6, o,11, 9,10, 3, 6, 3, 9,10, 3, 6, 3,10,10, 9, 2, 3, 9,
		 o,11, 3, 6, 3, o,11, 9, 3, 3,10, 9, 3, 6, o, 1, 9,10, 3, 2, 3, 3,10, 9, 3, 3, o,11, 9, 2, 3, 9, o,11, 3, 6, 3, o,11, 9, 3, 3,10, 9, 3, 6, o, 1, 9,10, 3, 2, 3, 3,10, 9, 3, 3, o,11, 9, 2, 3, 9,
		10,10, 3, 3, 9,10,10, 9, 6, 3,11, 9, 6, 3, 9, 1, 9, 9, 9, 2, 6, 3,10, 9, 6, 3, 9,10, 9, 6, 3, o,10,10, 3, 3, 9,10,10, 9, 6, 3,11, 9, 6, 3, 9, 1, 9, 9, 9, 2, 6, 3,10, 9, 6, 3, 9,10, 9, 6, 3, o,
		11, 9, 3, 6, 6,10, o, 9, 6, 9, 1, 9, 6, 9, 9,11, 9, 9, 9, 6, 3, 9, 9, 3, 2, 3, 9, 9, 9, o, 3, o,11, 9, 3, 6, 6,10, o, 9, 6, 9, 1, 9, 6, 9, 9,11, 9, 9, 9, 6, 3, 9, 9, 3, 2, 3, 9, 9, 9, o, 3, o,
		11, 3, 6, 3, 6,10, 9, 3, 6, 9,11, 9, 2, 9,10,10, 9,10, 3, 3, 9,10, 9, 3, 2, 6, 9,10, 9, o, 3,10,11, 3, 6, 3, 6,10, 9, 3, 6, 9,11, 9, 2, 9,10,10, 9,10, 3, 3, 9,10, 9, 3, 2, 6, 9,10, 9, o, 3,10,
		10, 3, 6, 2, 6,10, 9, 3, 3, 9,10, 9, 2, 3,10, 9, 9, 9, 3, 6, 9,10, 9, 3, 6, 3, 3, o, 9, 3, 9,10,10, 3, 6, 2, 6,10, 9, 3, 3, 9,10, 9, 2, 3,10, 9, 9, 9, 3, 6, 9,10, 9, 3, 6, 3, 3, o, 9, 3, 9,10,
		 9, 3, 2, 6, 9,10, 9, 6, 3,10, 9, 9, 2, 3,11, 9, 9,10, 9, 3, 9,10, o, 9, 3, 6, 3, 9, 6, 3, 9,11, 9, 3, 2, 6, 9,10, 9, 6, 3,10, 9, 9, 2, 3,11, 9, 9,10, 9, 3, 9,10, o, 9, 3, 6, 3, 9, 6, 3, 9,11,
		 9, 3, 6, 6, 9, 9, 3, 6, 9,11, 9, 9, 6, 3,11, 3, 3,10, 9, 3, 9,10,10, 9, 6, 2, 3,10, 6, 9,10, 1, 9, 3, 6, 6, 9, 9, 3, 6, 9,11, 9, 9, 6, 3,11, 3, 3,10, 9, 3, 9,10,10, 9, 6, 2, 3,10, 6, 9,10, 1,
		 9, 3, 3, 9,10, 9, 3, 3,10,10, 9, 9, 6, 9,11, 3, 6, 9,10, 3, 3, 9,10,10, 3, 2, 3, 9, 9, 3,10, 1, 9, 3, 3, 9,10, 9, 3, 3,10,10, 9, 9, 6, 9,11, 3, 6, 9,10, 3, 3, 9,10,10, 3, 2, 3, 9, 9, 3,10, 1,
		 9, 9, 3, 9, 9, 9, 6, 9,11, 9, 3,10, 3, 3,11, 9, 6, 3,10, 9, 3, 3, o,10, 9, 6, 3, 6, 9, 9, 9, 1, 9, 9, 3, 9, 9, 9, 6, 9,11, 9, 3,10, 3, 3,11, 9, 6, 3,10, 9, 3, 3, o,10, 9, 6, 3, 6, 9, 9, 9, 1,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

