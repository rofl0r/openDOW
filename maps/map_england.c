#include "../map.h"

#define SCREEN_COUNT 23
#define BONUS_COUNT 16

const struct {
	struct map header;
	struct map_screen screens[SCREEN_COUNT];
	mapscreen_index bonus_index[BONUS_COUNT];
	struct map_fglayer bonus_screens[BONUS_COUNT];
} map_england = {
	.header = {
		.maptype = MT_FOREST,
		.mission_text = {
			" my young son has been kidnapped",
			"by a band of ruthless terrorists!",
			"i will pay you $10000 if you can",
			"safeguard his return.",
			"",
		},
		.rewardk = 10,
		.client_face = 1,
		.mini_pic = 0,
		.worldmap_coords = VEC(125,18),
		.bonuslayer_count = BONUS_COUNT,
		.enemy_type = ET_WESTERN,
		.enemy_palette = {
			PRGB(  0,   0,   0), 
			PRGB( 51,  85,  85), 
			PRGB( 51, 119,  51), 
			PRGB(119,  85,  17), 
			PRGB(187, 153,  85), 
			PRGB(187, 119,  85), 
			PRGB(0x55,0x77,0x77), 
			PRGB( 17,  51,  51), 
		},
		.screen_map = {
			#define X MAPSCREEN_BLOCKED
			[ 0] = { X, X, X, X, X, X, X },
			[ 1] = { X, X, X, X, X, X, X },
			[ 2] = { X,22, X, X, X, X, X },
			[ 3] = { X,21, X, X, X, X, X },
			[ 4] = { X,20, X, X, X, X, X },
			[ 5] = { X,19, X, X, X, X, X },
			[ 6] = { X,18, X, X, X, X, X },
			[ 7] = { X,17, X, X, X, X, X },
			[ 8] = { X, 0, 0, 0, 0, 0, X },
			[ 9] = { X, 0, 0, 0, 0,16, X },
			[10] = { X, X, X, X, X,15, X },
			[11] = { X, X, X, X, X,14, X },
			[12] = { X, X, X, X, X,13, X },
			[13] = { X, X, X, X, X,12, X },
			[14] = { X,11,11,11,11,11, X },
			[15] = { X,10,11,11,11,11, X },
			[16] = { X, 9, X, X, X, X, X },
			[17] = { X, 8, X, X, X, X, X },
			[18] = { X, 7, X, X, X, X, X },
			[19] = { X, 6, X, X, X, X, X },
			[20] = { X, 0, 0, 0, 0, 0, X },
			[21] = { X, 0, 0, 0, 0, 5, X },
			[22] = { X, X, X, X, X, 4, X },
			[23] = { X, X, X, X, X, 3, X },
			[24] = { X, X, X, X, X, 2, X },
			[25] = { X, X, X, X, X, 1, X },
			[26] = { X, X, X, X, X, 0, X },
			[27] = { X, X, X, X, X, 0, X },
			#undef X
		},
	},
	.screens = {
		[0] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[1] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{ 45, 45, 45, 45,  0,  0,  0,171, 45, 45, 45, 45,},
				{  0,  0,  0,181,  0,  0,  0,  0,  0,  0,  0,171,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{165,165,165,165,165,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,166,166,166,166,166,166,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[2] = {
			.bg = {{
				{0,0,0,},
				{2,2,2,},
				{2,2,1,},
				{0,0,1,},
				{0,0,3,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,172,  0,171,  0,  0,204,},
				{170,169,169,169,170,169,169,170,169,169,170,169,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 56, 56, 56, 56, 56, 56,  0,  0,  0,  0,  0,  0,},
				{ 56, 56, 56, 56, 56, 56,  0,  0,  0,  0,  0,  0,},
				{ 56, 56, 56, 56, 56, 56,185,185,185,185,185,185,},
				{ 57, 57, 57, 57, 57, 57,128,128,  0,  0,  0,  0,},
				{ 25,  1, 25,  1, 25, 28,128,128,  0,  0,  0,144,},
				{  1,  1,  1,  1,  1,128,128,128,  0,151,  0,  0,},
				{  1,  1,  1,  1,  1,128,128,128,  0,  0,  0,  0,},
				{128,128,128,128,128,128,128,128,174,175,175,174,},
				{  0,  0,  0,  0,152,  0,  0,  0,  0,171,  0,  0,},
			}},
		},
		[3] = {
			.bg = {{
				{0,0,0,},
				{4,0,4,},
				{4,0,4,},
				{4,0,4,},
				{4,0,4,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,180,  0,  0,  0,  0,152,  0,  0,  0,  0,},
				{ 45, 45, 45, 45,  0,  0,171,  0, 45, 45, 45, 45,},
				{177,177,177,177,  0,  0,  0,  0,177,177,177,177,},
				{ 58,  0,  0,178,  0,171,  0,152,178,117,184,117,},
				{ 58, 58,  0,178,  0,  0,  0,  0,178,116,199,116,},
				{  3, 58,  0,178,151,  0,  0,  0,178,117,  0,117,},
				{ 82,  8,  0,178,  0,  0,  0,171,178,116,  0,116,},
				{  3,  8,  0,178,  0,  0,  0,  0,178,117,183,117,},
				{ 21,  8,  0,178,  0,171,  0,  0,178,116,192,116,},
				{  0,  0,  0,178,  0,  0,  0,  0,178,117,199,117,},
				{175,175,175,178,  0,  0,171,  0,178,176,176,176,},
				{  0,171,  0,  0,151,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[4] = {
			.bg = {{
				{0,0,0,},
				{0,1,2,},
				{0,1,2,},
				{0,2,1,},
				{0,1,1,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,171,  0,},
				{  0,  0,  0,  0,169,169,168,168,169,168,169,168,},
				{  0,  0,  0,200,  0,193,  0,  0,  0,  0,  0,  0,},
				{204,  0,  0,200,193,  0,177,177,177,177,177,177,},
				{  0,  0,  0,200,  0,  0,177,177,177,177,177,177,},
				{  0,  0,171,200,192,  0,  0,205,  0,  0,183,  0,},
				{  0,  0,  0,200,  0, 84, 85,  0,  0,  0,  0,179,},
				{  0,  0,  0,200,  0, 86, 91,  0,192,  0,  0,  0,},
				{  0,181,  0,200,  0,  0,  0,  0,  0,205,  0,  0,},
				{  0,  0,  0,200,  0,  0,180,  0,  0,  0,  0,184,},
				{  0,  0,  0,206,175,176,175,176,175,176,175,175,},
				{  0,  0,  0,171,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[5] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,194,194,194,194,194,194,194,194,},
				{  0,  0,171,  0,194,194,194,194,194,194,194,194,},
				{  0,  0,  0,  0,194,194,194,194,194,194,194,194,},
				{  0,  0,  0,171,194,194,194,194,194,194,194,194,},
				{108,  0,  0,  0,194,194,194,194,194,194,194,194,},
				{  0,171,  0,  0,195,195,195,195,195,195,195,195,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,171,  0,},
				{  0,  0,171,  0,183,  0,  0,172,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,171,},
				{  0,204,  0,173,  0,172,182,  0,  0,  0,  0,  0,},
			}},
		},
		[6] = {
			.bg = {{
				{2,2,1,},
				{0,2,2,},
				{0,2,2,},
				{0,2,2,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{ 36, 36, 36, 36, 36, 36, 15,  0,  0,  0,  0,  0,},
				{ 59, 59, 59, 59, 35, 59, 10,201,  0,145,  0,  0,},
				{ 59, 81, 59, 81, 59, 59, 10,  0,  0,  0,  0,  0,},
				{ 59, 59, 59, 59, 59, 59,185,185,185,185,185,185,},
				{ 59, 81, 59, 81, 59, 59, 10,144,  0,  0,  0,  0,},
				{ 59, 59, 59, 59, 35, 59, 10,145,  0,199,  0,  0,},
				{ 37, 37, 37, 37, 37, 37,  7,  0,  0,  0,  0,192,},
				{  3,  3, 34,  3,  3,  3,  8,  0,  0,  0,  0,  0,},
				{  3, 24,  3, 24,  3, 24,175,174,175,175,174,175,},
				{ 23,  3, 23,  3, 23,  3,  8,  0,201,  0,171,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[7] = {
			.bg = {{
				{2,2,1,},
				{1,3,2,},
				{2,3,1,},
				{2,3,2,},
				{1,2,2,},
				{2,3,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,206,  0,  0,  0,  0,159,},
				{  0,  0,  0, 77, 80,  0,  0, 79, 78,  0,181,156,},
				{  0,  0,  0, 75,108,  0,149,106, 76,  0,145,  0,},
				{  0,  0,  0, 75, 74,  0,145, 74, 76,  0,  0,  0,},
				{  0,201,  0, 75,148,199,  0,148, 76,  0,  0,  0,},
				{  0,  0,  0, 75,  0,152,  0,  0, 76,145,  0,  0,},
				{145,  0,  0, 75,  0,150,192,  0, 76,  0,  0,  0,},
				{  0,  0,  0, 79, 45, 45, 45, 45, 80,  0,  0,  0,},
				{160,  0,145,  0,  0,  0,199,  0,  0,  0,184,  0,},
				{158,  0,  0,204,  0,  0,  0,  0,  0,  0,  0,  0,},
				{158, 63, 74, 62, 63,  0,  0,145,  0,  0, 62, 63,},
				{158, 65,148, 64, 65, 63,  0,  0,  0,  0, 64, 65,},
			}},
		},
		[8] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{1,2,2,},
				{2,2,1,},
			}},
			.fg = {{
				{194,194,194,  0,199,  0,  0,  0,  0,159,167,167,},
				{194,194,194,  0,  0,  0,  0,206,  0,159,167,167,},
				{195,195,195,  0,  0,  0,  0,  0,  0,156,157,157,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,192,  0,  0,204,  0,172,  0,  0,  0,181,  0,},
				{  0,172,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{171,  0,  0,172,  0,173,192,194,194,194,  0,171,},
				{169,170,168,169,170,169,170,194,194,194,169,170,},
				{  0,181,  0,  0,  0,  0,  0,194,194,194,  0,  0,},
				{  0,  0,  0,149,  0,  0,  0,195,195,195,  0,  0,},
				{196,  0,  0,  0,  0,  0,  0,  0,145,  0,  0,146,},
				{  0,  0,145,  0,199,  0,  0,  0,  0,  0,  0,155,},
			}},
		},
		[9] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{172,  0,  0,  0,  0,  0,  0,199,  0,203,202,202,},
				{  0,  0,108,  0,  0,192,  0,  0,  0,  0,202,202,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,203,203,},
				{193,  0,  0,149,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,181,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,192,  0,  0,  0,  0,},
				{  0,  0,  0,206,  0,  0,  0,  0,  0,  0,  0,  0,},
				{194,194,194,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{194,194,194,194,194,194,194,  0,  0,  0,  0,206,},
				{194,194,194,194,194,194,194,  0,  0,  0,  0,  0,},
				{194,194,194,195,195,195,195,  0,  0,155,162,162,},
			}},
		},
		[10] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,201,  0,  0,},
				{198,198,198,198,198,198,198,198,198,198,198,198,},
				{197,197,197,197,197,197,197,197,197,197,197,197,},
				{  0,  0,  0,  0,  0,  0,181,  0,  0,  0,  0,  0,},
				{  0,  0,  0,108,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,199,  0,  0,  0,  0,  0,149,},
				{155,160,  0,  0,  0,  0,  0,192,  0,  0,  0,155,},
				{156,161,  0,  0,192,  0,  0,  0,  0,  0,  0,159,},
				{  0,  0,199,  0,  0,  0,  0,  0,  0,  0,  0,156,},
				{174,174,175,174,175,174,174,175,202,202,202,202,},
				{  0,172,  0,  0,171,  0,172,  0,137,202,202,202,},
			}},
		},
		[11] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[12] = {
			.bg = {{
				{1,1,1,},
				{0,0,0,},
				{1,1,1,},
				{1,1,1,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{148,  0,  0,  0,  0,182,  0,  0,  0,183,192,148,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{174,176,174,175,175,175,174,176,175,175,175,174,},
				{169,170,170,169,170,170,186,170,169,170,169,169,},
				{  0,  0,191,  0,  0,199,186,154,  0,  0,  0,155,},
				{154,  0,  0,  0,  0,  0,186,  0,  0,183,  0,156,},
				{  2,  2,  2, 14, 15,  0,186, 18, 19,  2,  2,  2,},
				{  2,  2,  2,  6,  7,192,189,185, 12,  2,  2,  2,},
				{  1, 82,  1, 82,  8,  0,  0, 13, 82,  1, 82,  1,},
				{  1,  1,  1,  1,  8,  0,  0, 13,  1,  1,  1,  1,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[13] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{  0,171,  0,  0,173,  0,  0,171,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,171,  0,},
				{  0,  0,  0,  0,  0,171,  0,  0,  0,  0,  0,181,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{  0,  0,  0,  0,  0,  0,  0,  0,180,  0,  0,184,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,199,  0,},
				{  0,199,  0,  0,181,  0,  0,  0,  0,  0,  0,  0,},
				{ 74,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 74,},
				{148,  0,  0,  0,  0,  0,  0,  0,  0,171,  0,148,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,199,  0,  0,  0,  0,  0,180,  0,  0,  0,  0,},
				{ 74,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 74,},
			}},
		},
		[14] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{0,0,0,},
			}},
			.fg = {{
				{ 62, 63, 62, 63,  0, 62, 63,  0,  0,  0,  0,  0,},
				{ 64, 65, 64, 65, 63, 64, 65,  0,  0,  0,  0,  0,},
				{  0, 44,  0, 64, 65,183,  0,  0,  0,  0,  0,  0,},
				{  0, 84, 85,  0,  0,  0,  0,  0,180,  0,  0,  0,},
				{ 63, 89, 90,  0,154,  0,  0,  0,  0,113,113,113,},
				{ 65, 86, 87,  0,  0,  0,155,160,  0,  0,  0,  0,},
				{160,  0,  0,  0,  0,  0,156,161,  0,  0,  0,  0,},
				{161,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,155,},
				{113,113,113,  0,  0,  0,  0,  0,179,  0,  0,159,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,156,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{  0,  0,  0,171,  0,  0,  0,  0,173,  0,  0,  0,},
			}},
		},
		[15] = {
			.bg = {{
				{1,1,2,},
				{2,1,1,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{160,154,  0,  0,  0,  0,  0,  0,  0,  0,  0,156,},
				{158,  0,  0,180,  0,  0,  0,  0,  0,206,  0,  0,},
				{161,  0,  0,  0,  0,113,113,113,113,  0,  0,155,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,156,},
				{174,174,175,175,174,174,174,175,174,174,174,175,},
				{154,  0,171,172,173,  0,173,  0,  0,171,  0,  0,},
				{  0,172,  0,172,  0,  0,  0, 45, 45, 45, 45, 45,},
				{193,  0,  0,155,162,160,  0,  0,  0,  0,  0,155,},
				{  0,  0,  0,159,167,158,  0,  0,192,  0,  0,159,},
				{  0,180,  0,156,157,161,  0,  0,  0,  0,  0,159,},
				{  0,193,  0,  0,  0,  0,  0,  0,  0,  0,181,156,},
				{  0,  0,  0,  0,  0,  0,182,  0,  0,  0,  0, 47,},
			}},
		},
		[16] = {
			.bg = {{
				{0,0,0,},
				{2,1,1,},
				{1,1,1,},
				{1,0,1,},
				{1,1,1,},
				{1,1,2,},
			}},
			.fg = {{
				{  0,171,  0,  0,173,  0,  0,  0,  0,171,  0,181,},
				{169,169,168,169,170,169,168,168,170,168,168,170,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,155,},
				{177,177,177,177,177,209,209,209,209,177,178,159,},
				{185,185,185,185,194, 57, 57, 57, 57,194,178,156,},
				{177,177,177,177,194,194,208,208,194,194,178,177,},
				{160,  0,  0,178,194,194,208,208,194,194,185,185,},
				{161,  0,  0,178,195,195,195,195,195,195,178,177,},
				{  0,  0,  0,178,177,177,177,177,177,177,178,  0,},
				{185,185,185,185,185,185,185,185,185,185,185,185,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,206,},
				{104,105,104,105,  0,181,  0,  0,  0,  0,  0,155,},
			}},
		},
		[17] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,194,194,194,194,194,},
				{  0,  0,  0,  0,  0,193,191,194,194,194,194,194,},
				{194,194,194,194,194,194,194,194,194,194,194,194,},
				{194,194,194,194,194,194,194,194,194,194,194,194,},
				{195,195,195,195,195,195,195,194,194,194,194,194,},
				{  0,  0,  0,  0,  0,  0,171,194,194,194,194,194,},
				{  0,  0,  0,146,  0,  0,  0,195,195,195,195,195,},
				{  0,  0,  0,  0,191,  0,  0,  0,  0,  0,  0,149,},
				{151,  0,  0,  0,  0,193,171,  0,  0,  0,192,  0,},
				{191,  0,  0,  0,  0,150,  0,191,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[18] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,180,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,153,  0,  0, 31, 35, 31, 31,},
				{  0,171,  0,  0,  0,181,  0, 77, 31, 31, 31, 31,},
				{  0,  0,  0,149,  0,  0,153, 75, 31, 31, 31, 31,},
				{193,  0,  0,  0,  0,193,  0, 75, 54,208,208,208,},
				{  0,  0,171,  0,  0,  0,  0, 75, 54,208,208,208,},
				{  0,  0,  0,181,  0,  0,  0, 79, 45, 45, 45, 45,},
				{193,  0,  0,  0,  0,  0,  0,  0,  0,  0,149,  0,},
				{  0,171,  0,  0,  0,  0,  0,191,  0,  0,  0,193,},
				{  0,  0,150,  0,  0,  0,  0,  0,  0,182,  0,  0,},
				{171,  0,  0,152,  0,  0,  0,193,  0,  0,  0,  0,},
				{  0,183,  0,171,  0,  0,  0,  0,  0,152,  0,193,},
			}},
		},
		[19] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{ 45, 45,  0,150,  0,  0,  0,  0,  0,  0, 45, 45,},
				{198,198,198,198,198,198,198,198,198,198,198,198,},
				{197,197,197,197,197,197,197,197,197,197,197,197,},
				{ 45,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 45,},
				{  0,179,  0,  0,  0,  0,  0,  0,180,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,179,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,152,  0,  0,  0,146,  0,  0,191,  0,  0,},
				{  0,199,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{193,  0,  0,  0,  0,  0,  0,  0,193,  0,150,  0,},
				{  0,  0,  0,150,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[20] = {
			.bg = {{
				{4,4,4,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,156,161,  0,  0,  0,  0,  0,  0,189,},
				{154,  0,154,  0,  0,152,  0,  0,  0,  0,  0,  0,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{165,165,165,165,165,165,165,165,165,165,165,165,},
				{166,166,166,166,166,166,166,166,166,166,166,166,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{  0,  0,  0,171,  0,  0,  0,  0,183,  0,  0,171,},
				{  0,179,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,152,  0,  0,  0,171,  0,  0,},
				{171,  0,  0,  0,  0,  0,  0,  0,  0,  0,180,  0,},
				{  0,  0,171,  0,  0,  0,179,  0,  0,  0,  0,171,},
			}},
		},
		[21] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{  0,  0,111,  0, 64, 65,111,  0, 83, 93, 94,  0,},
				{  0, 62, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 36, 36, 19,  2,  2,  2,  2,  2,  2, 14, 36, 36,},
				{ 81, 59,  1, 25,  1, 25,  1, 34,  1,  1, 59, 81,},
				{ 59, 59,  3,  3,  3,  3,  3,  3,  3,  3, 59, 59,},
				{ 81, 59,  5,  0,108,  0,  0,  0, 44,  4, 59, 81,},
				{ 59, 59,  5,  0,  0,  0,149,  0,  0,  4, 59, 59,},
				{ 37, 37,  7,  0,  0,  0,  0,  0,  0, 11, 37, 37,},
				{  3,  3,  8,  0,  0,  0,  0,  0,  0, 13,  3,  3,},
				{  3,  3,  8,  0,  0,179,  0,  0,  0, 13,  3, 21,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,186,},
				{150,  0,  0,155,160,  0,  0,  0,  0,  0,  0,186,},
			}},
		},
		[22] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{185,185,188,  0,  0, 98, 99,  0,  0,  0,  0,  0,},
				{ 60, 60,186,  0,  0,100,101,  0,  0, 40, 41,  0,},
				{ 74, 74,186,  0,  0,102,103,  0,  0, 42, 43,  0,},
				{148,148,186,  0,  0,  0,  0,  0,  0, 31, 31, 31,},
				{185,185,190,  0,  0,  0,  0,  0,  0, 31, 35, 31,},
				{  0,  0,  0,145,184,  0,145,  0,  0, 31, 31, 31,},
				{  0,  0,145,145,144,  0,  0,  0,  0, 54,208,208,},
				{  0,  0,  0,110,  0,  0,  0,  0,  0, 75,  0,  0,},
				{109,  0,109, 95,  0,  0,  0,  0,  0, 75, 96,  0,},
				{110,  0, 95,111,  0,  0,  0,  0,  0, 79, 45, 45,},
				{111,  0,110,  0, 62, 63,109,  0, 83, 93, 94,  0,},
			}},
		},
	},
	.bonus_index = {
		2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 16, 17, 18, 21,
	},
	.bonus_screens = {
		[0] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,  0,},
			{  0,120,  0,  0,119,  8,  0,  0,  0,  0,  0,  0,},
			{  0, 22,  0,  0, 49,  8,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[1] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{123,  0, 62, 63,  0,  0,  0,  0,  0,116,  0,116,},
			{  0,123, 64, 65,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{124,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,124,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{118,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 45, 45, 45, 45,  0,  0,  0,  0, 45, 45, 45, 45,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},

		}},
		[2] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 39, 39, 39, 39, 39, 39,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[3] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 83, 93, 94, 83, 93, 94,},
			{  0,  0,  0,  0,  0,  0,  0,  0,109,109,109,109,},
			{  0,  0,  0,  0,  0,  0,  0,  0,110, 95, 95,110,},
			{  0,  0,  0,  0,  0,  0,  0,  0,111,111,111,111,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[4] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 10,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[5] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 62,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 64, 62, 63,  0, 62,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[6] = {{
			{110,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 95,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{111,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[7] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{109,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{110,  0,  0,109,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 95,  0,  0,110,  0,  0,  0,  0,  0,  0,  0,  0,},
			{110,  0,  0,111,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[8] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,108,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,203,  0,  0,  0,},
		}},
		[9] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0, 11,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[10] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 39, 39, 39, 96,  0,  0,  0,  0,  0, 96, 39, 39,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[11] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 62,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0, 45, 45, 45, 45,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[12] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 54, 53,120, 55,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 54,  0, 22, 55,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[13] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,109,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0, 95,109,109,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,111,110, 95,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,111,111,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[14] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0, 53,  0, 53,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[15] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0, 17,  0,  0,  0,  0,  0,  0,  4,  0,  0,},
			{  0,  0,  5,  0,  0,  0,  0,  0,  0,  4,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,118,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
	},
};

#undef SCREEN_COUNT
#undef BONUS_COUNT


