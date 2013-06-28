#include "../palpic.h"
#define PAL_COUNT 14
#define SPRITE_COUNT 18
#define WIDTH 16
#define HEIGHT 288
#define o 0
#define STRUCT_NAME gunturret

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(255, 255, 214), 
		PRGB( 85, 125, 125), 
		PRGB( 60, 125,  60), 
		PRGB( 60, 190,  85), 
		PRGB(190, 190, 190), 
		PRGB(149, 149, 125), 
		PRGB( 20,  85,  60), 
		PRGB( 60,  85,  85), 
		PRGB( 20,  60,  60), 
		PRGB(190, 125,  85), 
		PRGB( 85, 125, 149), 
		PRGB(125,  85,  20), 
		PRGB(190,  85,  20), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 1, 2, 8, o, o, o, o, o, o,
		 o, o, o, o, o, 8, 8, 5, 2, 9, 8, o, o, o, o, o,
		 o, o, o, o, 8, 2, 8, 5, 2, 9, 2, 8, o, o, o, o,
		 o, o, o, o, 6, 2, 8, 5, 2, 9, 2, 2, o, o, o, o,
		 o, o, o, o, 6, 9, 8, 5, 2, 9, 9, 2, o, o, o, o,
		 o, o, o, o, 8, 6, 8, 5, 2, 9, 2, 8, o, o, o, o,
		 o, o, o, o, 9, 8, 8, 2, 8, 9, 8, 9, o, o, o, o,
		 o, o, o, o, o, 9, 8, 5, 2, 9, 9, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 2, 8, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 2, 2, 8, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #001 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 8, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 8, 1, 8, o,
		 o, o, o, o, o, o, o, o, o, o, 8, 8, 1, 8, o, o,
		 o, o, o, o, o, o, 8, 8, 8, 8, 2, 1, 8, o, o, o,
		 o, o, o, o, o, 8, 2, 2, 8, 2, 5, 2, 9, o, o, o,
		 o, o, o, o, 8, 2, 9, 8, 2, 5, 2, 9, o, o, o, o,
		 o, o, o, o, 6, 2, 8, 2, 5, 2, 9, 2, o, o, o, o,
		 o, o, o, o, 6, 8, 2, 5, 2, 9, 2, 2, o, o, o, o,
		 o, o, o, o, 8, 2, 8, 2, 9, 9, 2, 8, o, o, o, o,
		 o, o, o, 9, 2, 5, 2, 9, 6, 2, 8, 9, o, o, o, o,
		 o, o, o, 2, 8, 2, 9, 8, 8, 8, 9, o, o, o, o, o,
		 o, o, o, o, 2, 9, 9, 9, 9, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #002 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 8, 8, 8, o, o, o, o, o, o,
		 o, o, o, o, o, 8, 2, 9, 2, 2, 8, o, o, o, o, o,
		 o, o, 8, 9, 9, 9, 9, 9, 9, 9, 9, 8, o, o, o, o,
		 o, o, 2, 8, 2, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		 o, o, 2, 2, 5, 2, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1,
		 o, o, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, o, o, o, o,
		 o, o, o, o, 9, 8, 6, 9, 2, 2, 8, 9, o, o, o, o,
		 o, o, o, o, o, 9, 8, 8, 8, 8, 9, o, o, o, o, o,
		 o, o, o, o, o, o, 9, 9, 9, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #003 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, 2, 9, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, 2, 8, 2, 9, 8, 8, 8, o, o, o, o, o, o,
		 o, o, o, 8, 2, 5, 2, 9, 2, 2, 8, o, o, o, o, o,
		 o, o, o, o, 8, 2, 8, 2, 9, 9, 2, 8, o, o, o, o,
		 o, o, o, o, 6, 8, 2, 5, 2, 9, 2, 2, o, o, o, o,
		 o, o, o, o, 6, 2, 8, 2, 5, 2, 9, 2, o, o, o, o,
		 o, o, o, o, 8, 6, 9, 8, 2, 5, 2, 8, o, o, o, o,
		 o, o, o, o, 9, 8, 6, 2, 8, 2, 5, 2, 8, o, o, o,
		 o, o, o, o, o, 9, 8, 8, 8, 8, 2, 1, 8, o, o, o,
		 o, o, o, o, o, o, 9, 9, 9, 9, 8, 8, 1, 8, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 8, 1, 8, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 8, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #004 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 2, 2, 8, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 2, 8, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 5, 2, 9, o, o, o, o, o, o,
		 o, o, o, o, o, 8, 8, 2, 8, 9, 8, o, o, o, o, o,
		 o, o, o, o, 8, 2, 8, 5, 2, 9, 2, 8, o, o, o, o,
		 o, o, o, o, 6, 9, 8, 5, 2, 9, 9, 2, o, o, o, o,
		 o, o, o, o, 6, 2, 8, 5, 2, 9, 2, 2, o, o, o, o,
		 o, o, o, o, 8, 6, 8, 5, 2, 9, 2, 8, o, o, o, o,
		 o, o, o, o, 9, 8, 8, 5, 2, 9, 8, 9, o, o, o, o,
		 o, o, o, o, o, 9, 8, 1, 2, 8, 9, o, o, o, o, o,
		 o, o, o, o, o, o, 9, 1, 2, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 2, o, o, o, o, o, o, o,
		/* sprite #005 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 8, 2, o, o, o, o,
		 o, o, o, o, o, o, 8, 8, 8, 8, 2, 8, 2, o, o, o,
		 o, o, o, o, o, 8, 2, 2, 8, 2, 5, 2, 9, o, o, o,
		 o, o, o, o, 8, 2, 9, 8, 2, 8, 2, 9, o, o, o, o,
		 o, o, o, o, 6, 2, 8, 2, 5, 2, 9, 2, o, o, o, o,
		 o, o, o, o, 6, 8, 2, 5, 2, 9, 2, 2, o, o, o, o,
		 o, o, o, o, 8, 2, 5, 2, 9, 9, 2, 8, o, o, o, o,
		 o, o, o, 8, 2, 5, 2, 9, 2, 2, 8, 9, o, o, o, o,
		 o, o, o, 8, 1, 2, 9, 8, 8, 8, 9, o, o, o, o, o,
		 o, o, 8, 1, 8, 9, 9, 9, 9, 9, o, o, o, o, o, o,
		 o, 8, 1, 8, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 8, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #006 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 8, 8, 8, o, o, o, o, o, o,
		 o, o, o, o, o, 8, 2, 2, 9, 2, 8, o, o, o, o, o,
		 o, o, o, o, 8, 9, 9, 9, 9, 9, 9, 9, 9, 8, o, o,
		 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 2, 8, 2, o, o,
		 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 2, 5, 2, 2, o, o,
		 o, o, o, o, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, o, o,
		 o, o, o, o, 9, 8, 6, 2, 9, 2, 8, 9, o, o, o, o,
		 o, o, o, o, o, 9, 8, 8, 8, 8, 9, o, o, o, o, o,
		 o, o, o, o, o, o, 9, 9, 9, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #007 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 8, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, 8, 1, 8, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 8, 1, 8, 9, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, 8, 1, 2, 9, 2, 2, 8, o, o, o, o, o, o,
		 o, o, o, 8, 2, 5, 2, 9, 2, 2, 8, o, o, o, o, o,
		 o, o, o, o, 8, 2, 5, 2, 9, 9, 2, 8, o, o, o, o,
		 o, o, o, o, 6, 8, 2, 5, 2, 9, 2, 2, o, o, o, o,
		 o, o, o, o, 6, 2, 8, 2, 5, 2, 9, 2, o, o, o, o,
		 o, o, o, o, 8, 6, 9, 8, 2, 8, 2, 9, o, o, o, o,
		 o, o, o, o, 9, 8, 6, 2, 8, 2, 5, 2, 9, o, o, o,
		 o, o, o, o, o, 9, 8, 8, 8, 8, 2, 8, 2, o, o, o,
		 o, o, o, o, o, o, 9, 9, 9, 9, 9, 2, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #008 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 8, 8, 8, 8, 2, o, o, o, o, o,
		 o, o, o, o, o, 8, 2, 2, 5, 2, 5, 2, 9, o, o, o,
		 o, o, o, o, 8, 2, 8, 8, 5, 5, 2, 9, o, o, o, o,
		 o, o, o, o, 6, 8, 6, 5, 5, 2, 9, 2, o, o, o, o,
		 o, o, o, o, 6, 8, 6, 5, 1, 1, 5, 2, o, o, o, o,
		 o, o, o, o, 8, 2, 6, 2, 2, 2, 1, 5, o, o, o, o,
		 o, o, o, 9, 2, 6, 2, 2, 6, 2, 8, 9, o, o, o, o,
		 o, o, o, o, 8, 2, 9, 8, 8, 8, 9, o, o, o, o, o,
		 o, o, o, o, o, 9, 9, 9, 9, 9, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #009 */
		 o, o, o, o, o, 3, 4, 3, 1, 3, 3, o, o, o, o, o,
		 o, o, o, 4, 3, 8, 9, 8, 1, 8, 8, 3, 3, o, o, o,
		 o, o, 4, 8, 8, 9, 9,10, 1, 9, 9, 8, 8, 3, o, o,
		 o, 4, 8, 8, 9, 9, 8, 2, 6, 6, 9, 9, 8, 8, 4, o,
		 4, 3, 9, 9, 9, 8, 2, 6, 5, 6, 6, 9, 9, 9, 7, 4,
		 5, 9, 9, 9, 8, 8, 6, 5, 5, 6, 6, 8, 9, 9, 9, 4,
		 1, 9, 9, 9, 8,11, 6, 1, 5, 6, 6, 8, 9, 9, 9, 4,
		 5, 7, 9, 9, 8, 2, 6, 5, 6, 6, 6, 8, 8, 9, 7, 3,
		 3, 5, 3, 9, 8, 2, 8, 6, 6, 6, 8,11, 8, 9, 3, 7,
		 3, 4, 5, 3, 8,11,11, 8, 9, 9,11, 8, 8, 3, 7, 7,
		 3, 4, 5, 5, 3, 7,11,11,11,11, 8, 7, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #010 */
		 o, o, o, o, o, 3, 4, 3, 4, 3, 3, o, o, o, o, 5,
		 o, o, o, 4, 3, 8, 9, 8, 9, 8, 8, 3, 3, o, 5, 1,
		 o, o, 4, 8, 8, 9, 9, 9, 9, 9,11,11,10, 5, 1, 2,
		 o, 4, 8, 8, 9, 9, 2, 6, 6, 6,11,10, 5,10, 2, o,
		 4, 3, 9, 9, 9, 2, 6, 5, 6, 6, 6, 5,10,10, 7, 4,
		 5, 9, 9, 9, 9, 2, 1, 5, 6, 6, 2, 9, 8,11, 9, 4,
		 1, 9, 9, 9, 8, 2, 5, 6, 6, 6,10, 9,11, 8, 9, 4,
		 5, 7, 9, 9, 8,11, 6, 6, 6, 6,11, 8, 2, 8, 7, 3,
		 3, 5, 3, 9, 8,11, 8, 6, 6, 8,11, 2, 8, 9, 3, 7,
		 3, 4, 5, 3, 9,11,11, 8, 8,11,11, 8, 9, 3, 7, 7,
		 3, 4, 5, 5, 3, 7,11,11,11,11, 8, 7, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #011 */
		 o, o, o, o, o, 3, 6, 6, 6, 3, 3, o, o, o, o, o,
		 o, o, o, 4, 3, 6, 5, 5, 6, 6, 8, 3, 3, o, o, o,
		 o, o, 4, 8, 2, 5, 1, 5, 6, 6, 9, 8, 8, 3, o, o,
		 o, 4, 8, 8, 2, 5, 5, 6, 6, 2, 8, 9, 8, 8, 4, o,
		 4, 3, 9, 9, 2, 6, 6, 6, 2,10,11, 8, 9, 9, 7, 4,
		 5, 9, 9, 9, 2, 6, 2, 2, 9,10,11, 1, 1, 1, 1, 1,
		 1, 9, 9, 9, 8, 2,10,10,10, 8, 9, 5,10,10, 5, 5,
		 5, 7, 9, 9, 8,11,11, 9, 9, 9, 8,11,11, 9, 7, 3,
		 3, 5, 3, 9, 8, 8,11,11,11,11, 2, 8, 9, 9, 3, 7,
		 3, 4, 5, 3, 9, 8, 8,11,11, 2, 8, 8, 9, 3, 7, 7,
		 3, 4, 5, 5, 3, 7, 8, 7, 8, 7, 8, 9, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #012 */
		 o, o, o, o, o, 3, 6, 6, 6, 6, 3, o, o, o, o, o,
		 o, o, o, 4, 3, 6, 5, 5, 6, 6, 6, 3, 3, o, o, o,
		 o, o, 4, 8, 8, 5, 1, 5, 6, 6, 6, 8, 8, 3, o, o,
		 o, 4, 8, 8, 9, 5, 6, 6, 6, 6,12, 9, 8, 8, 4, o,
		 4, 3, 9, 9, 9, 6, 6, 6, 6,12, 9,11, 8, 9, 7, 4,
		 5, 9, 9, 9, 9, 9,12,10, 9,10,10,11,11, 8, 9, 4,
		 1, 9, 9, 9, 9,11,11,10,10,10, 8, 5,10,11, 9, 3,
		 5, 7, 9, 9, 9,11,11, 9, 9, 8,10,10, 1, 5, 7, 3,
		 3, 5, 3, 9, 8,11,11,11,11, 2,11,10, 2, 1, 5, 7,
		 3, 4, 5, 3, 9, 8,11, 2, 2, 8, 8, 9, 7, 2, 1, 5,
		 3, 4, 5, 5, 3, 7, 9, 7, 9, 7, 9, 7, 3, 7, 2, 1,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, 2,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #013 */
		 o, o, o, o, o, 3, 7, 6, 6, 6, 3, o, o, o, o, o,
		 o, o, o, 4, 3, 8, 6, 5, 6, 6, 6, 3, 3, o, o, o,
		 o, o, 4, 8, 8, 9, 5, 1, 6, 6, 6, 8, 8, 3, o, o,
		 o, 4, 8, 8, 9, 9, 6, 5, 5, 6, 6, 9, 8, 8, 4, o,
		 4, 3, 9, 9, 9, 8, 2, 6, 6, 6, 8, 9, 9, 9, 7, 4,
		 5, 9, 9, 9, 8,11,10, 9,10, 9,10,11, 9, 9, 9, 4,
		 1, 9, 9, 9,11,11, 8,10,10,10,11,11, 8, 9, 9, 4,
		 5, 7, 9, 9, 2,11,11, 8, 9, 9,11,11, 8, 9, 7, 3,
		 3, 5, 3, 9,11, 8,11,11,11,11, 8, 2, 8, 9, 3, 7,
		 3, 4, 5, 3, 9,11, 8, 1,11, 8, 2, 8, 8, 3, 7, 7,
		 3, 4, 5, 5, 3, 9,10, 1,10, 7, 8, 7, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6,10, 1,10, 8, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 1, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 1, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 5, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #014 */
		 o, o, o, o, o, 3, 7, 6, 6, 6, 3, o, o, o, o, o,
		 o, o, o, 4, 3, 8, 6, 1, 5, 6, 6, 3, 3, o, o, o,
		 o, o, 4, 8, 8, 9, 5, 5, 6, 6, 6, 8, 8, 3, o, o,
		 o, 4, 8, 8, 9, 9,12, 6, 6, 6, 6, 9, 8, 8, 4, o,
		 4, 3, 9, 9, 9,11, 9,12, 2, 2, 8, 8, 9, 9, 7, 4,
		 5, 9, 9, 9,11,11,10,10, 9,10,12,11, 9, 9, 9, 4,
		 1, 9, 9,11,10, 5, 8,10,10,10,11,11, 8, 9, 9, 4,
		 5, 7, 9, 5, 1,10,10, 8, 9, 9, 2,11, 8, 9, 7, 3,
		 3, 5, 5, 1, 2,10,11,11,11, 2,11,11, 8, 9, 3, 7,
		 3, 5, 1, 2, 9, 8, 8, 8, 8,11,11, 8, 9, 3, 7, 7,
		 5, 1, 2, 5, 3, 9, 8, 7, 9, 7, 8, 7, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #015 */
		 o, o, o, o, o, 3, 4, 3, 2, 2, 2, o, o, o, o, o,
		 o, o, o, 4, 3, 8, 9, 2, 6, 6, 6, 2, 3, o, o, o,
		 o, o, 4, 8, 8, 9, 9, 6, 5, 5, 6, 6, 2, 3, o, o,
		 o, 4, 8, 8, 9, 9, 8, 2, 1, 5, 6, 6, 2, 8, 4, o,
		 4, 3, 9, 9, 9, 8,11,10, 5, 6, 6, 6, 2, 9, 7, 4,
		 1, 1, 1, 1, 1, 1,11,10, 9, 2, 2, 6, 2, 9, 9, 4,
		 5, 5, 5,10,10, 5, 9, 8,10,10,10, 2, 8, 9, 9, 4,
		 5, 7, 9, 9,11,11, 8, 9, 9, 9,11,11, 8, 9, 7, 3,
		 3, 5, 3, 9, 8, 9,11, 2, 2,11,11, 8, 8, 9, 3, 7,
		 3, 4, 5, 3, 9, 8, 9, 9, 8,11, 8, 8, 9, 3, 7, 7,
		 3, 4, 5, 5, 3, 9, 8, 7, 8, 7, 8, 7, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #016 */
		 1, 5, o, o, o, 3, 4, 3, 4, 3, 3, o, o, o, o, o,
		 2, 1, 5, o, 3, 8, 9, 8, 9, 8, 8, 3, 3, o, o, o,
		 o, 2, 1, 5,10,11,11, 9, 9, 9, 9, 8, 8, 3, o, o,
		 o, 4, 2,10, 5,10,11, 6, 6, 6, 2, 9, 8, 8, 4, o,
		 4, 3, 7,10,10, 5, 6, 5, 5, 6, 6, 2, 9, 9, 7, 4,
		 5, 9, 9,11, 8, 9, 2, 1, 5, 6, 6, 2, 9, 9, 9, 4,
		 1, 9, 9, 8,11, 9,10, 5, 6, 6, 6, 2, 8, 9, 9, 4,
		 5, 7, 9, 8, 2, 8, 9, 6, 6, 6, 6,11, 8, 9, 7, 3,
		 3, 5, 3, 9, 8, 2,11, 8, 6, 6, 8,11, 8, 9, 3, 7,
		 3, 4, 5, 3, 9, 8,11,11, 8, 8,11,11, 9, 3, 7, 7,
		 3, 4, 5, 5, 3, 7, 8,11,11,11,11, 7, 3, 7, 9, 7,
		 o, 4, 5, 1, 4, 6, 5, 5, 5, 5, 4, 3,12, 7, 7, o,
		 o, 6, 5, 1, 4, 2, 3, 3, 3,12, 3,12, 7, 7, 8, o,
		 o, o, 4, 5, 4, 2, 8, 8, 8, 8,12,12,12, 8, o, o,
		 o, o, o, 6, 4, 2,12, 3, 3,12, 3,12, 7, o, o, o,
		 o, o, o, o, o, 3, 3,12,12, 3,12, o, o, o, o, o,
		/* sprite #017 */
		 o, o, o, o, o, o, o, 3, o, o, o, o, o, o, o, o,
		 o, 3, o, o, o, o, 3, 4, o, o, o, o, o, 3, o, o,
		 o, 2, 6, 6, 6, 3, 4, 3, o, o, 3, 7, 3, o, o, o,
		 2, 6, 5, 5, 6, 6, 4, o, 3, 4, 4, 3, o, o, o, o,
		 6, 1, 5, 6, 6,10,12, 9, 4, 3, 7, 3, 7, o, o, o,
		 6, 5, 6, 6, 9,10,12, 3, 3, 7, 3, 9, 7, 9, o, o,
		 4, 6, 6,10,10,10,10,12,11,11, 9, 7, 9, 3, o, o,
		 3, 6,10, 9,10,12,10, 9,11,13, 3, 4, 5, 4, 3, o,
		 3, 4, 7, 3,10,10, 9,11,13,11, 9, 7, 7, 3, 4, o,
		 8, 3, 3, 4, 9, 9,11,13,13,13,11, 9, 9, o, 3, o,
		 9, 4, 3,12,11,11, 3, 3,13,13, 3, 4, 3, 3, o, o,
		 3, 3,13,13, 3, 4, 3, 7,13,11, 9, 9, 9, 3, 3, o,
		 o, o,13,13, 4, 6, 3, 7, 3,11, 9, 8, 8, 9, o, o,
		 o, 9, 9, 3, 3, 7, 7, 9, 4,12, 3, 9, 8, 8, o, o,
		 9, 9, o, 3, 7, 9, 3,12, 7,12, 3, o, o, 8, o, o,
		 o, o, o, o, o, o, o, o, 3, 7, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME
