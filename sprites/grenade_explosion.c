#include "../palpic.h"
#define PAL_COUNT 6
#define SPRITE_COUNT 11
#define WIDTH 32
#define HEIGHT 242
#define o 0
#define STRUCT_NAME grenade_explosion

static const struct {
	struct palpic header;
	prgb palette[PAL_COUNT];
	uint8_t data[WIDTH * HEIGHT];
} STRUCT_NAME = { 
	{ {'p', 'P', 'i', 'C', }, 1, PAL_COUNT, SPRITE_COUNT, WIDTH, HEIGHT, PPF_TRANSPARENT, 0 },
	{
		PRGB(  0,   0,   0), 
		PRGB(187,  85,  17), 
		PRGB(153, 153, 119), 
		PRGB(255, 221,  85), 
		PRGB(187, 187, 187), 
		PRGB( 85, 119, 119), 
		
	},
	{
		/* sprite #000 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, 1, 1, o, o, 1, o, o, o, o, o, 1, 1, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 2, 1, 1, o, o, o, 1, 1, 1, o, o, o, o, o, 1, 1, 1, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, o, 1, o, o, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 1, 3, 3, 1, 1, 3, 1, 1, o, 1, 1, 2, 1, o, o, 1, 1, o, o, o,
		 o, o, o, o, o, 1, o, o, o, o, o, o, 1, 2, 3, 3, 2, 3, 2, 1, 2, 3, 3, 1, o, 1, 1, 1, 1, o, o, o,
		 o, o, o, o, o, o, 1, 1, 1, 1, 1, o, 1, 1, 2, 3, 3, 3, 2, 3, 3, 3, 1, 1, 1, 3, 2, 1, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, 4, 3, 4, 1, 1, 1, 2, 3, 3, 3, 3, 4, 2, 1, 2, 3, 3, 3, 1, o, o, o, o, o,
		 o, o, o, o, 1, o, o, 1, 1, 2, 3, 3, 3, 2, 2, 2, 4, 3, 4, 3, 2, 3, 3, 3, 2, 1, 1, 1, o, o, o, o,
		 o, o, o, o, o, o, 1, o, o, 1, 4, 3, 3, 3, 3, 3, 3, 4, 3, 3, 4, 4, 3, 3, 3, 3, 3, 2, 1, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 1, 3, 3, 3, 2, 1, 3, 3, 4, 3, 3, 3, 3, 3, 2, 1, 1, 1, 1, 1, 1, o,
		 o, o, o, o, o, 1, 1, 1, 2, 2, 3, 3, 2, 1, 1, 3, 4, 3, 3, 4, 3, 3, 3, 3, 1, o, o, o, o, o, o, o,
		 o, 1, o, 1, 1, 1, 1, 1, 1, 3, 2, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 2, 1, 3, 1, o, 1, 1, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 1, o, 1, 3, 3, 1, 3, 4, 3, 3, 3, 1, 1, 2, 3, 1, o, o, o, 1, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, o, 1, 3, 3, 2, 1, 3, 3, 2, 1, 3, 1, o, 1, 1, 1, 1, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 1, o, o, 1, 3, 2, 1, 1, 3, 3, 2, 1, 2, 3, 1, o, 1, o, 1, 1, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, o, o, 1, 3, 2, 1, 1, 1, 3, 2, 1, o, 1, 3, 1, o, o, o, o, 1, 1, o, o, o,
		 o, o, o, o, o, 1, 1, o, o, 1, 2, 1, 1, 1, o, 1, 3, 1, 1, o, 1, 2, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, 1, 2, 1, o, 1, o, 1, 1, o, o, o, o, o, o, 1, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, o, o, o, 1, o, 1, 1, o, o, 1, o, 1, 2, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, 1, 1, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, 1, o, o, o, o, o, o, 1, o, o, o, o, o, o, o, o,
		/* sprite #001 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o, o, 1, 1, 1, 1, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 2, 3, 4, 2, 1, 1, 2, 3, 3, 2, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 1, 4, 3, 3, 4, 1, 2, 3, 3, 3, 3, 3, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 1, 1, 2, 3, 3, 1, 3, 1, 2, 3, 3, 4, 2, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, o, o, 1, 1, 4, 4, 1, 1, 1, 1, 2, 4, 3, 2, 1, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 2, 4, 3, 3, 4, 2, 1, 2, 1, 1, 1, 1, 2, 1, 1, o, 1, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 2, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 3, 3, 3, 3, 2, 1, 1, 2, 1, 4, 3, 2, 1, 2, 1, o, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 3, 2, 1, 1, 4, 3, 1, 1, 2, 3, 3, 2, 1, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, 1, 1, 1, 1, 1, 4, 3, 3, 2, 1, 1, 2, 3, 3, 3, 1, 1, o, 1, o, o, o, o, o,
		 o, o, o, o, o, 1, 3, 1, 1, o, o, 1, 3, 3, 3, 4, 1, 1, 1, 1, 2, 3, 3, 2, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, 1, 1, o, o, o, o, 1, 1, 3, 4, 2, 1, 1, o, 1, 1, 1, 1, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 1, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #002 */
		 o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 3, 1, o, o, o, 1, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, o, 1, 1, 1, 1, 1, o, o, 1, 1, 1, 4, 2, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 2, 3, 4, 1, 1, 1, 1, 2, 3, 3, 3, 1, o, o, o, o, o, 1, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 2, 3, 3, 3, 4, 2, 1, 2, 3, 3, 3, 2, 1, o, 1, 1, 1, o, 1, 1, o, o,
		 o, o, o, o, o, o, 1, 1, o, 1, 1, 4, 3, 3, 3, 4, 1, 3, 3, 2, 1, 1, 2, 1, 2, 3, 4, 1, o, o, o, o,
		 o, o, o, o, o, 1, 1, 1, 1, o, 1, 1, 1, 2, 3, 4, 1, 3, 1, 1, 2, 4, 3, 3, 3, 3, 2, 1, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 1, 1, 1, 1, 1, 1, 2, 3, 2, 1, 2, 1, 4, 3, 3, 3, 2, 1, 1, 1, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 2, 2, 1, 2, 3, 3, 3, 2, 1, 1, 2, 1, 2, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 4, 3, 3, 4, 1, 2, 3, 2, 2, 1, 2, 1, 1, 1, o, o, 1, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 1, 2, 3, 3, 4, 2, 1, 1, 2, 1, 4, 3, 4, 4, 1, 1, o, 1, 1, 1, 1, o, o, o,
		 o, o, o, o, o, o, o, 1, 4, 3, 3, 4, 1, 1, 2, 3, 2, 1, 2, 3, 3, 3, 2, 1, 1, o, o, 1, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, 3, 4, 2, 1, 1, 2, 3, 3, 1, 2, 1, 2, 3, 3, 3, 4, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 2, 1, 1, 1, 1, 4, 3, 3, 4, 1, 1, 1, 2, 2, 3, 3, 3, 4, 1, o, o, 1, o, o, o,
		 o, o, o, 1, 1, o, o, 1, 1, o, 1, 2, 3, 3, 3, 2, 1, 1, o, 1, 1, 2, 4, 3, 3, 1, 1, o, o, o, o, o,
		 o, o, 1, 3, 3, 1, o, o, o, o, 1, 4, 3, 4, 2, 1, 1, o, o, o, 1, 1, 1, 2, 4, 4, 1, o, o, o, o, o,
		 o, o, 1, 3, 1, o, o, o, o, o, 1, 1, 1, 1, 1, 1, o, o, o, o, o, o, 1, 1, 1, 1, 1, o, o, o, o, o,
		 o, o, o, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 3, 1, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		/* sprite #003 */
		 o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, o, o, 1, 1, o, o, o, o, o, o, o, o, 1, 3, 2, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 3, 1, 1, o, o, o, o, 1, 1, 3, 3, 3, 1, o, o, o, o, o, 1, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, 2, 3, 1, 1, o, o, o, 1, 3, 2, 1, 1, o, o, o, 1, 1, o, o, 1, o,
		 o, o, o, o, o, 1, o, o, o, o, 1, 1, 3, 3, 1, 1, o, 1, 2, 1, 1, 1, o, o, o, 1, 2, 3, 1, o, o, o,
		 o, o, o, o, 1, 1, 1, 1, o, o, 1, 1, 1, 2, 1, 1, o, 1, 1, 1, 1, o, o, 1, 1, 3, 3, 4, 1, o, o, o,
		 o, o, o, o, o, o, 1, 1, 5, o, o, o, 1, 1, 1, 1, o, 1, o, o, o, o, 1, 1, 2, 3, 4, 1, 1, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 2, o, 5, 1, 5, 1, 2, 1, 2, 4, 2, 1, 1, o, o, o, o,
		 o, o, o, o, o, 1, o, o, o, 1, 1, 1, o, 5, o, o, 5, 5, o, 1, o, 1, 1, 1, 1, 1, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, 1, 2, 1, 1, 1, o, 1, 5, 5, 2, 5, o, o, o, o, 5, o, o, 5, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, 3, 3, 1, 1, 1, 5, o, 5, o, 5, o, 1, 5, o, 1, o, o, 5, 1, 1, 1, 1, o, o,
		 o, o, o, o, o, 1, 1, 3, 3, 1, 1, o, o, o, 1, 1, o, 1, o, 1, 1, 1, o, o, o, o, o, o, 1, 1, o, o,
		 o, o, o, o, o, 1, 1, 2, 1, 1, o, o, 1, 1, 1, 2, 1, o, 5, 1, 1, 2, 1, 1, o, o, 1, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, o, o, o, 1, 1, 2, 3, 1, 1, o, o, 1, 1, 1, 3, 2, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 1, 2, 3, 3, 4, 1, o, 1, 1, o, 1, 1, 3, 3, 3, 2, 1, o, o, o, o, o,
		 o, o, o, o, o, o, 5, o, o, 1, 1, 3, 3, 2, 1, o, 1, 1, 1, o, 1, 1, 2, 3, 3, 3, 1, 1, o, o, o, o,
		 o, o, 1, 1, o, 5, 5, o, o, 1, 1, 1, 1, 1, 1, o, 1, 3, 1, 1, o, 1, 1, 2, 3, 2, 1, 1, o, o, o, o,
		 o, 1, 3, 3, 1, o, o, o, o, o, 1, 1, 1, 1, o, o, 1, 2, 3, 1, o, o, 1, 1, 1, 1, 1, 1, o, o, o, o,
		 o, o, 1, 1, 1, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, 1, 1, 1, 1, 5, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1,
		/* sprite #004 */
		 o, o, o, o, o, o, 1, o, o, 1, 1, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 3, 3, 1, o, o, o, o, o, o, o, o, 1, 2, 3, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 2, 3, 1, 1, 1, o, o, o, o, o, 1, 1, 3, 2, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, 1, o, o, o, o, 1, 1, 3, 1, 1, 5, o, o, o, 5, 1, 1, 1, 1, o, o, o, o, 1, 1, 1, o, o,
		 o, o, o, 1, 1, 1, o, o, o, o, 1, 1, 1, o, 1, 5, o, o, o, 1, 1, 1, 5, o, o, o, 1, 2, 3, 2, 1, o,
		 o, o, o, o, o, 1, o, 5, o, o, 5, o, 1, 1, 1, o, o, 5, o, o, 5, 5, 5, o, o, 1, 1, 1, 2, 3, 1, o,
		 o, o, o, o, o, o, o, o, 5, o, o, 5, o, o, o, 1, 5, 2, 5, o, o, 5, o, o, o, 1, 1, 1, 1, 1, 1, o,
		 o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, 5, 5, 5, 5, 5, 5, 5, 5, o, o, 1, 5, o, 1, 1, 1, o, o,
		 o, o, o, 1, o, o, o, o, o, o, 5, o, 5, 5, 2, 5, 5, 2, 2, 5, 5, o, o, 1, 1, 1, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, o, 1, o, o, 5, 5, 2, 5, 5, o, o, o, o, o, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, 1, 1, o, 1, 1, o, 5, 5, 5, 2, 5, 5, 5, 5, o, o, 1, o, o, o, o, 5, 5, 1, o, o,
		 o, o, o, o, 1, 1, 2, 1, 1, o, o, o, 5, o, 5, 5, 5, 5, o, 5, o, 5, o, o, o, o, o, o, o, 1, 1, o,
		 o, o, o, 1, 2, 3, 3, 1, 1, 5, o, 5, o, 1, o, 5, 5, o, 5, 1, 5, 1, 1, 1, 5, 5, o, o, o, o, o, o,
		 o, o, o, 1, 3, 3, 1, 1, 5, 5, o, o, 1, 2, 1, 5, o, 1, o, 5, 5, 1, 3, 1, 5, 5, 5, o, 1, o, o, o,
		 o, o, o, o, 1, 1, o, 5, o, o, 1, 1, 1, o, 1, o, 5, o, 5, o, 5, 1, 1, o, o, 1, 1, 5, o, o, o, o,
		 o, o, o, o, o, 5, o, o, o, 1, 1, 2, 1, 1, o, o, o, 5, 5, o, 5, o, o, 1, 1, 1, 1, 1, o, o, o, o,
		 o, o, o, o, 5, o, 5, o, 1, 1, 2, 3, 1, 1, 5, o, o, o, 1, o, o, o, 1, 1, 1, 1, 3, 1, 1, o, o, o,
		 o, o, 1, 1, o, 5, o, o, 1, 3, 3, 1, 1, 5, 5, o, o, 1, 1, 1, o, o, 1, 1, 1, 2, 3, 3, 1, o, o, o,
		 o, 1, 1, 1, o, o, o, o, o, 1, 2, 3, 1, o, o, o, 1, 3, 2, 1, o, o, o, o, 1, 1, 2, 3, 1, 1, o, o,
		 o, o, 1, o, o, o, o, o, o, o, 1, 1, o, o, o, o, o, 1, 1, o, o, o, o, o, o, 1, 1, 1, 1, 1, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1,
		/* sprite #005 */
		 o, o, o, o, o, o, 1, o, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 1, 3, 2, 1, o, o, o, o, o, o, o, o, o, 1, 1, 3, 1, 1, o, o, o, o, o, o,
		 o, o, 1, 1, o, o, o, o, o, 1, 1, 1, 5, o, o, o, o, o, o, o, 1, 1, 1, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, 1, o, o, o, o, o, 5, 5, 1, 5, 1, o, o, o, o, o, o, o, 5, 1, o, o, o, o, o, o, 1, 1, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 1, o, o, o, 5, 5, 5, 5, 5, o, o, o, o, o, o, o, 1, 2, 3, 1,
		 o, o, o, o, o, o, o, o, 5, o, o, o, o, 5, o, 5, 5, 5, 5, 5, o, 5, 5, o, o, o, 5, 1, 2, 1, 2, 1,
		 o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, 5, 5, 2, 5, 2, 5, 5, 5, 2, 5, 5, 5, o, 1, 1, 1, 1, o,
		 o, o, o, o, o, o, o, o, o, o, o, 5, 5, 2, 2, 5, 5, 2, 2, 2, 2, 2, 5, 5, 5, o, 1, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 2, 2, 5, 2, 5, 2, 5, 2, 5, 5, 5, o, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, 5, 2, 5, 2, 2, 2, 2, 2, 5, 5, 5, 5, o, 5, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, 1, o, o, 5, 5, 5, 5, 5, 2, 5, 2, 2, 5, o, o, 5, o, 5, o, 5, 5, o, o, o, o,
		 o, o, o, o, 1, o, 5, 5, 5, o, o, o, 5, 5, 2, 5, 5, 5, 2, 2, 5, o, 1, o, o, o, o, 5, 5, o, o, 1,
		 o, o, o, 1, 1, 1, 1, 5, 5, 5, o, 5, o, 5, 5, 5, 5, 5, 5, 5, 5, 5, o, o, o, o, o, o, o, o, o, o,
		 o, o, 1, 3, 1, 1, 1, 5, o, o, o, o, o, 5, 5, 5, o, o, o, 5, 5, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 1, 1, 1, 1, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, 1, 1, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 1, 1, o, 5, o, o, o, o, o, o, o, o, 1, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 5, 1, 5, o, o, o, o, o, o, o, o, o, o, 5, 5, 5, 5, o, o, o, o,
		 o, o, o, o, 5, o, o, o, 1, 1, 1, o, 5, 5, o, o, o, o, 5, o, o, o, o, o, o, 1, 1, 5, o, o, o, o,
		 o, 1, o, 5, o, o, o, 1, 2, 3, 1, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o,
		 o, 1, 1, o, o, o, o, 1, 3, 3, 3, 1, o, o, o, o, o, o, 1, o, o, o, o, o, o, o, 1, 1, 3, 1, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, 1, 2, 1, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, o, o,
		/* sprite #006 */
		 o, o, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o,
		 o, 1, o, o, o, o, o, o, 1, 1, 1, 5, o, o, o, o, o, o, o, o, o, o, 1, 1, 1, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, o, 5, 5, o, o, o, o, o, o, o, o, o, 5, 1, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, 5, 5, o, 5, o, o, 5, 5, o, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, 2, 2, 5, 5, o, o, o, 5, o, o, o, 5, o, 1, 1, 1,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, 5, 2, 5, 2, 5, o, 5, 5, 5, 5, o, o, o, 1, 1, 1, 1,
		 o, o, o, o, o, o, o, o, o, 5, o, 5, 5, 5, 5, 5, 5, 2, 2, 5, 5, 5, 2, 5, 5, 5, 5, 1, o, 1, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 2, 5, 2, o, 5, 2, 5, 2, 5, 2, 2, 2, 5, 5, o, o, 5, o, o, o,
		 o, o, o, o, o, o, o, 5, o, 5, 5, 5, 2, 2, 5, 5, o, 5, o, 5, 2, 2, 5, 5, 5, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, 2, 2, 5, 2, 2, 5, 5, o, 5, 2, 5, 5, 5, 5, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 5, 2, 5, 2, 2, 5, 5, 5, 5, 2, 2, 5, 5, 5, o, o, o, o, o, 5, 5, o, o, o,
		 o, o, o, o, o, o, o, 5, 2, 5, 5, 5, 5, 5, 5, 2, 5, 5, 2, 2, 5, 5, 5, o, 5, o, o, o, o, 5, 5, o,
		 o, o, o, o, 1, 5, 5, o, o, o, 5, 5, 5, 5, 2, 2, 2, 5, 5, 2, 2, 2, 5, 5, o, o, o, o, o, o, o, o,
		 o, o, 1, 1, o, 1, o, o, o, o, o, o, 5, 5, 2, 5, 5, 5, 5, 5, 5, 2, 2, 5, 5, o, o, o, o, o, o, o,
		 o, 1, 1, 1, 1, o, o, o, o, o, 5, o, o, 5, 5, 5, 5, 5, o, o, 5, 5, 5, 2, o, o, o, o, o, o, o, o,
		 o, o, 1, 1, o, o, o, o, o, o, o, o, 5, o, o, 5, 5, o, o, o, o, 5, o, 5, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, 5, o, 5, 5, o, o, o, o, o, o, 5, 1, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 1, o, o, o, o, o, 5, 5, o, o, o, o, o, o, o, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, 5, o, 5, o, o, o, o,
		 o, 5, o, o, o, o, o, o, 1, 1, 1, 1, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, 5, 1, 1, o, o, o,
		 1, o, o, o, o, o, o, 1, 3, 2, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, 1, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, 1, o, o, o, o, o, o, o, 1, o, o, o, o, o, o, o, o, o, o, 1, 1, o,
		/* sprite #007 */
		 o, o, o, o, o, o, o, o, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, o, 5, o, o, o, 5, 5, 5, 5, o, o, o, o, o, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, 2, 2, 5, 5, 5, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, 5, o, o, o, o, 5, 5, 5, 5, 2, 5, 5, o, o, 5, 5, o, 5, o, o, o, o, 1, 1,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, 2, 5, 2, 2, 5, 5, 5, o, 5, 5, 5, 5, o, o, 5, o, 1,
		 o, o, o, o, o, o, o, o, o, 5, 5, 5, 5, 5, o, 5, 2, 2, 5, 5, o, 5, 5, 5, 2, 2, 5, o, o, 5, 5, o,
		 o, o, o, o, o, o, o, o, 5, 5, 5, 2, 5, 2, 5, o, 5, 2, 5, o, 5, 5, 2, 5, 5, 2, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, o, 5, o, 2, 5, 5, 2, 5, 5, 5, o, 5, 5, o, 5, 2, 5, 2, 2, 5, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, 5, 5, 5, 2, 2, 5, 2, 2, 2, 5, o, o, o, o, 5, 2, 5, 5, 5, 5, 5, o, o, o, o, o,
		 o, o, o, o, o, o, 5, 5, 2, 5, 2, 2, 5, 5, 5, o, 5, 5, 5, o, 5, 5, 5, 5, o, 5, o, o, o, o, o, o,
		 o, o, o, 5, o, o, o, 5, 5, 5, 5, 5, o, 5, o, 5, 5, 2, 5, o, 5, o, 5, 5, o, o, o, 5, o, o, o, o,
		 o, o, 5, o, 5, 5, o, o, o, 5, o, 5, 5, 5, 5, 2, 2, 5, 5, o, 2, 2, 5, o, 5, o, o, o, o, o, 5, o,
		 o, o, o, 5, o, o, o, o, 5, o, o, 5, 5, 5, 2, 5, 2, 5, o, 5, 2, 5, 2, 5, 5, 5, o, o, o, o, o, o,
		 o, o, o, 5, o, o, o, o, o, o, o, 5, 5, 2, 2, 2, 5, 5, 5, 2, 5, 2, 5, 5, 2, 5, o, o, o, o, o, o,
		 o, 1, 1, o, o, o, o, o, o, o, o, o, 5, 5, 5, 5, o, 5, o, 5, 5, 5, 5, 2, 5, 5, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, 5, o, 5, o, o, o, 5, 5, 2, 5, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, 5, 5, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, 5, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, o,
		 o, o, o, o, o, o, o, 1, 1, o, o, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o, o,
		 o, o, o, o, o, o, o, o, 1, 1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 1, o,
		/* sprite #008 */
		 o, o, o, o, o, o, o, o, 5, 5, o, o, o, o, o, o, 5, 5, 5, o, o, o, o, o, o, o, o, o, 5, o, o, o,
		 o, o, o, o, o, o, o, 5, o, 5, 5, o, o, o, 5, 5, 2, 5, o, 5, o, o, o, o, o, 5, o, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, 5, o, 5, o, o, 5, o, 5, 5, 2, 5, 5, o, 5, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, 2, 5, 5, 5, o, o, 5, 5, o, 5, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, 5, 5, o, o, o, 5, o, 5, 5, 5, 5, o, o, 5, o, o, 5, 5, 2, 5, 5, o, o, 5,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, 5, o, 5, o, 5, o, o, 5, 2, 5, 5, 5, 5, o, o, 5, o,
		 o, o, o, o, o, o, o, o, 5, 5, o, o, 5, o, o, 5, 5, 5, 5, 5, o, 5, o, 5, 2, 2, 5, o, 5, o, o, o,
		 o, o, o, o, o, o, o, 5, o, 5, 5, 5, o, 5, 5, o, 5, 5, 5, o, 5, o, 5, 5, 5, o, 5, 5, o, o, o, o,
		 o, o, o, o, o, 5, 5, 5, 5, 2, 5, 5, 5, 5, 5, 5, 5, 2, 5, 5, o, o, o, 5, o, 5, o, 5, o, o, o, o,
		 o, o, o, o, o, o, 5, 2, 5, 5, 2, 5, 5, o, 5, o, 5, 5, o, 5, 5, o, 5, o, 5, 5, 5, o, o, o, o, o,
		 o, o, o, o, o, 5, 5, 2, 2, 5, 5, 5, o, 5, 5, o, 5, 2, 2, 5, 5, 5, 5, o, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, 5, 5, 5, 5, o, 5, 5, 5, o, 5, 5, 2, 5, o, 5, 5, o, 5, o, o, o, o, o, o, o, o,
		 o, 5, o, o, o, o, 5, 5, 5, 5, 5, 5, o, 5, 5, 5, 5, 5, o, o, 5, 5, 5, 5, 5, o, o, o, o, o, o, o,
		 o, o, 5, o, o, o, o, o, o, 5, o, o, o, 5, o, 5, o, 5, 5, o, o, 5, o, 5, 5, 5, o, o, o, o, o, o,
		 o, 5, o, o, o, o, o, o, o, o, o, 5, 5, 2, 2, 5, 5, o, o, 5, o, 5, 5, 2, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, 5, o, o, o, o, o, 5, 5, 2, 5, 5, 5, 5, 5, o, 5, 5, 5, 2, 5, 2, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, o, 5, 2, 2, 5, 5, o, o, o, 5, o, 5, 2, 5, o, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 5, o, 5, 5, 5, o, o, o, o, 5, 5, 2, 2, 5, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 5, 5, 5, o, o, o, o, o, o, o, 5, 5, o, 5, 5, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, 5, o, o, 5, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, o, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o,
		/* sprite #009 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, 2, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, 5, o, o, o, o, o, o, o, o, 5, o, 5, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, 5, 5, o, 5, o, o, o, o, 5, o, 5, 5, o, 5, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, o, o, o, o, 5, 5, 2, 5, o, 5, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, 5, o, o, o, o, 5, o, o, o, o, 5, 5, 5, o, 5, 5, o, o,
		 o, o, o, o, o, o, o, 5, 5, o, o, o, o, o, o, 5, 5, o, o, o, 5, o, o, o, o, 5, o, 5, 5, o, 5, o,
		 o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, 5, 5, o, o, 5, o, o, 5, o, o, 5, o, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, o, 5, o, 5, o, 5, 5, 5, o, 5, 5, 5, 5, 5, o, o, 5, o, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, 5, 5, o, 5, o, o, 5, o, o, 5, 5, 5, o, 5, 5, 5, o, 5, o, 5, 5, 5, 5, o, o, o, o,
		 o, o, o, o, 5, 2, 5, 5, 5, 5, 5, o, o, 5, o, o, o, 5, o, 5, o, o, 5, 5, o, o, o, o, o, o, o, o,
		 o, o, o, 5, o, 5, o, 5, o, 5, 5, o, 5, o, 5, 5, o, o, 5, 5, 5, 5, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, 5, 5, 5, o, 5, 5, o, 5, 5, 5, o, 5, o, 5, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, 5, o, o, o, 5, o, o, o, o, o, 5, 5, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, 5, o, 5, o, 5, 5, o, 5, 5, 5, o, o, o, o, o, o, o,
		 o, o, o, o, 5, o, o, o, o, o, o, 5, o, 5, 5, o, o, o, o, o, o, 5, o, 5, o, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 5, o, 5, o, o, o, o, o, o, o, 5, 5, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, 5, 5, o, 5, 5, 5, o, o, o, o, o, 5, 5, 5, 5, o, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 2, 5, o, 5, o, o, o, o, o, o, 5, 5, o, 5, 5, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 5, 5, o, o, o, o, o, o, o, o, o, 5, 2, 5, 5, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, 5, o, 5, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o,
		/* sprite #010 */
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, o, o, o, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, 5, 5, o, o, o, o, o, o, o, o, o, o, o, 5, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, 5, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, 5, o, o, o, o, 5, o, o, 5, 5, 5, 5, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, 5, o, o, 5, o, 5, o, o, o,
		 o, o, o, o, o, o, o, 5, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, o, 5, o,
		 o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, 5, o, 5, o, o, o, o, o, o, o, o, 5, o, 5, o, o, o,
		 o, o, o, o, 5, o, 5, o, o, o, o, o, 5, o, 5, o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, o, 5, o,
		 o, o, o, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, 5, 5, o, o, o, o, o,
		 o, o, 5, o, o, 5, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o,
		 o, o, o, 5, 5, o, 5, o, o, o, o, o, 5, o, o, o, o, o, o, o, 5, 5, o, o, o, o, o, o, o, o, o, o,
		 o, o, o, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, 5, o, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, 5, 5, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, 5, o, o, 5, o, o, o, o, 5, o, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, 5, o, o, o, 5, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, 5, o, o, o, o, o, o, o, o, o, 5, o, 5, o, 5, o, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, 5, o, o, o, o, o, o, o, 5, 5, 5, o, 5, o, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, o, 5, 5, 5, o, 5, o, o, o, o, o, o, o, 5, o, 5, 5, 5, o, o, o,
		 o, o, o, o, o, o, o, o, o, o, 5, 5, 5, o, 5, o, o, o, o, o, o, o, o, o, o, o, o, 5, o, 5, o, o,
		 o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o,
		
	},
};

#undef o
#undef PAL_COUNT
#undef SPRITE_COUNT
#undef WIDTH
#undef HEIGHT
#undef STRUCT_NAME

