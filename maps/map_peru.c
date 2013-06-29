#include "../map.h"

#define SCREEN_COUNT 22
#define BONUS_COUNT 13

const struct {
	struct map header;
	struct map_screen screens[SCREEN_COUNT];
	mapscreen_index bonus_index[BONUS_COUNT];
	struct map_fglayer bonus_screens[BONUS_COUNT];
} map_peru = {
	.header = {
		.maptype = MT_FOREST,
		.mission_text = {
			" an invaluable inca statue has",
			"been stolen from me by some local",
			"criminals. if you can return it",
			"to me i would be most grateful",
			"and will pay you $5000.",
		},
		.rewardk = 5,
		.client_face = 9,
		.mini_pic = 0,
		.boss_id = 7,
		.worldmap_coords = VEC(70,81),
		.bonuslayer_count = BONUS_COUNT,
		.enemy_type = ET_WESTERN,
		.enemy_palette = {
			PRGB(  0,   0,   0), 
			PRGB( 51,  85,  85), 
			PRGB( 51, 119,  51), 
			PRGB(119,  85,  17), 
			PRGB(187, 153,  85), 
			PRGB(187, 119,  85), 
			PRGB( 85, 119, 153), 
			PRGB( 17,  51,  51), 
		},
		.screen_map = {
			#define X MAPSCREEN_BLOCKED
			[ 0] = { X, X, X, X, X, X, X },
			[ 1] = { X, X, X, X, X, X, X },
			[ 2] = { X, X, X, X, X, X, X },
			[ 3] = { X,21, X, X, X, X, X },
			[ 4] = { X,20, X, X, X, X, X },
			[ 5] = { X,19, X, X, X, X, X },
			[ 6] = { X,18, X, X, X, X, X },
			[ 7] = { X,17, X, X, X, X, X },
			[ 8] = { X,16,16,16,16,16, X },
			[ 9] = { X,16,16,16,16,15, X },
			[10] = { X, X, X, X, X,14, X },
			[11] = { X, X, X, X, X,13, X },
			[12] = { X, X, X, X, X,12, X },
			[13] = { X, X, X, X, X,11, X },
			[14] = { X, 0, 0, 0, 0, 0, X },
			[15] = { X,10, 0, 0, 0, 0, X },
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
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
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
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{176,176,176,176,176,176,176,176,176,175,186,176,},
				{116,178,116,178,116,192,116, 76,181,  0,186,182,},
				{117,178,117,193,117,178,117, 76,  0,  0,186,  0,},
				{116,180,116,199,116,178,116, 76,  0,  0,186,  0,},
				{117,178,117,178,117,180,117, 76,  0,  0,186,181,},
				{116,178,116,178,116,178,116, 76,182,  0,186,  0,},
				{117,193,117,192,117,178,117, 76,  0,  0,186,  0,},
				{ 45, 45, 45, 45, 45, 45, 45, 80,  0,  0,186,  0,},
				{  0,182,199,  0,  0,  0,181,  0,  0,182,186,  0,},
				{185,185,185,185,185,185,185,185,185,185,190,193,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[2] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{  0,  0,117,  0,  0,117,199,  0,117,192,186,117,},
				{185,185,185,185,185,185,185,185,185,185,186,185,},
				{  0,193,  0,  0,182,  0,181,  0,  0,  0,186,  0,},
				{  0,192,116,  0,  0,116,  0,  0,116,199,186,116,},
				{  0,  0,117,199,  0,117,  0,192,117,  0,186,117,},
				{185,185,185,185,185,185,185,185,185,185,186,185,},
				{193,  0,  0,  0,  0,  0,193,  0,  0,  0,186,193,},
				{  0,183,  0,182,  0,  0,  0,  0,  0,  0,186,  0,},
				{181,  0,116,  0,  0,116,  0,192,116,  0,186,116,},
				{  0,199,117,  0,  0,117,  0,  0,117,199,186,117,},
				{185,185,185,185,185,185,185,185,185,185,186,185,},
				{193,  0,  0,  0,181,  0,  0,  0,182,  0,186,  0,},
			}},
		},
		[3] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,180,  0,  0,186,  0,},
				{  0,  0,184,  0,  0,  0,  0,  0,  0,  0,186,  0,},
				{  0,  0,  0,  0,  0,193,  0,  0,  0,  0,186,  0,},
				{193,  0,  0,  0,  0,  0,  0,  0,  0,  0,186,  0,},
				{  0,  0,199,  0,  0,192,  0,  0,  0,  0,186,  0,},
				{169,170,170,170,169,170,170,170,170,170,186,170,},
				{  0,  0,207,  0,  0,  0,  0,  0,181,  0,186,184,},
				{  0,182,  0,181,  0,  0,181,  0,  0,  0,186,  0,},
				{  0,  0,  0,  0,  0,  0,  0,193,  0,192,186,181,},
				{185,185,185,185,185,185,185,185,185,185,186,185,},
				{  0,  0,  0,181,  0,  0,  0,  0,  0,183,186,193,},
				{  0,199,116,  0,  0,116,  0,  0,116,  0,186,116,},
			}},
		},
		[4] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,  0,  0,186,  0,  0,  0,  0,  0,180,193,},
				{  0,  0,  0,  0,186,  0,  0,  0,  0,  0,199,  0,},
				{  0,  0,  0,  0,186,  0,  0,  0,  0,  0,  0,  0,},
				{  0,180,  0,  0,186,  0,  0,180,  0,  0,  0,  0,},
				{  0,  0,  0,  0,186,  0,  0,  0,  0,  0,  0,192,},
				{  0,  0,  0,180,186,  0,  0,  0,199,  0,  0,  0,},
				{  0,  0,  0,  0,186,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,199,  0,189,185,185,185,185,185,186,185,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,186,  0,},
				{182,  0,181,  0,  0,  0,193,  0,  0,  0,186,  0,},
				{104,105,105,105,104,105,  0,  0,  0,182,186,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,186,  0,},
			}},
		},
		[5] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{182,  0,  0,209,209,209,209,209,209,209,  0,  0,},
				{  0,  0,  0, 57, 57, 57, 57, 57, 57, 57,  0,  0,},
				{  0,  0,194,194,208,208, 52, 52,208,194,194,194,},
				{192,  0,194,194, 49, 52, 52, 52,208,194,194,194,},
				{  0,  0,195,195,195,195,195,195,195,195,195,195,},
				{204,  0,  0,  0,186,  0,  0,  0,  0,182,  0,193,},
				{185,185,185,185,186,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,181,  0,186,  0,  0,199,  0,  0,180,  0,},
				{  0,  0,  0,  0,186,199,  0,  0,  0,  0,  0,192,},
				{180,  0,  0,  0,186,  0,  0,  0,  0,105,104,105,},
			}},
		},
		[6] = {
			.bg = {{
				{3,2,3,},
				{3,3,3,},
				{3,3,3,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,180, 72, 73,  0,186,  0,  0,155,160,156,},
				{185,185,185,185,185,185,186,  0,  0,156,161,181,},
				{183,  0,  0,  0,  0,180,186,191,184,  0,  0,  0,},
				{  2,  2,  2,  2,  2,  0,186,  2,  2,  2,  2,  2,},
				{  3,  3,  3, 82,  3,  0,186,  3, 82,  3,  3,  3,},
				{  3,  3,  3,  3,  3,  0,186,  3,  3,  3,  3,  3,},
				{174,175,174,174,176,174,186,174,174,175,174,175,},
				{172,  0,  0,  0,  0,  0,186,  0,  0,173,  0,172,},
				{185,185,185,185,185,185,186,185,185,185,185,185,},
				{172,179,  0,  0,  0,  0,  0,180,  0,  0, 42, 43,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[7] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{202,202,202,186,185,185,185,185,185,186, 45, 45,},
				{203,203,203,186,202,202,202,202,202,202,202,202,},
				{185,185,185,186,202,202,202,202,202,202,202,202,},
				{160,  0,180,186,202, 56, 56, 56, 56, 56, 56, 56,},
				{158,  0,192,186,202, 57, 57, 57, 57, 57, 57, 57,},
				{161,  0,  0,186,202,202,208,208,208,208,208,202,},
				{  0,155,160,186,202,202,208,208,208,208,208,202,},
				{  0,156,161,186,202,202,202,202,202,202,202,202,},
				{160,  0,  0,186,203,203,203,203,203,203,203,203,},
				{158,184,  0,189,185,185,186,185,185,185,185,185,},
				{161,  0,  0,  0,  0,180,186, 44,  0,  0,192,155,},
				{  0,  0,  0, 70, 71,  0,186,  0,180,  0,192,159,},
			}},
		},
		[8] = {
			.bg = {{
				{3,3,3,},
				{3,2,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{185,185,185,186,  0,  0,202, 57, 57, 57, 57, 57,},
				{199,  0,192,186,  0,179,202,202,208, 52,208, 52,},
				{160,  0,  0,186,  0,  0,202,202, 52, 52, 52, 52,},
				{161,  0,206,186,155,160,202,202,202,202,202,202,},
				{  0,180,192,186,156,161,203,203,203,203,203,203,},
				{  0,  0,  0,186,185,185,185,185,185,185,185,185,},
				{  0,  0,  0,186,155,162,160,192,  0,  0,  0,179,},
				{ 56, 56,  0,186,159,167,158,  0,  0,  0,155,160,},
				{ 57, 57,202,186,156,157,161,  0,  0,  0,156,161,},
				{ 52,202,202,186,  0,  0,181,  0,  0,187,185,185,},
				{ 50,202,202,186,  0,  0,  0,205,  0,186,192,155,},
				{202,202,202,186,205,  0,  0,  0,180,186,  0,156,},
			}},
		},
		[9] = {
			.bg = {{
				{3,3,3,},
				{3,2,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{2,3,3,},
			}},
			.fg = {{
				{  0,  0,  0,186,  0,205,  0,  0,  0,  0,  0,186,},
				{ 56,  0,  0,186,155,162,160,  0,  0,  0,181,186,},
				{ 57,  0,  0,186,159,167,158,  0,179,  0,  0,186,},
				{202,202,  0,186,156,157,161,  0,  0,  0,  0,186,},
				{202,202,  0,186,  0,  0,207,  0,180,  0,  0,186,},
				{203,203,192,186,179,  0,  0,  0,  0,  0,201,186,},
				{185,185,185,186,  0,  0,155,160,  0,  0,  0,186,},
				{  0,  0,180,186,204,  0,156,161,192,  0,  0,186,},
				{207,  0,  0,186,  0,  0,  0,  0,  0,  0,179,186,},
				{  0,  0, 66,186,  0,181,  0,  0,  0,  0,  0,186,},
				{160,  0, 68,186,  0,  0,  0,  0,  0,  0,180,186,},
				{161,  0,192,186,201,  0,  0,209,209,209,209,209,},
			}},
		},
		[10] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{3,2,2,},
				{3,3,2,},
				{1,3,3,},
				{3,3,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 39,  0,171,  0, 39, 39, 39, 39,  0,  0,171, 39,},
				{170,169,169,169,169,170,169,169,170,169,169,169,},
				{  0,181,  0,  0,  0,  0,181,  0,  0,180,  0,205,},
				{185,185,185,186,185,185,185,185,185,185,185,186,},
				{160,  0,180,186,179,  0, 66, 67,  0,  0,192,186,},
				{158,  0,  0,186,  0,  0, 68, 69,  0,  0,180,186,},
				{158,  0,  0,186,  0,  0,192,  0,155,160,  0,186,},
				{161,  0,  0,186,  0,  0,  0,  0,156,161,  0,186,},
				{  0,  0,  0,186,  0,179,  0,192,  0,  0,  0,186,},
				{  0,  0,  0,186,181,  0,  0,  0,  0,179,  0,186,},
			}},
		},
		[11] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,3,},
				{5,5,3,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,181,  0,144,  0,  0,  0,144,  0, 64, 65,},
				{  0,  0,  0,  0,  0,  0,  0,179,  0,  0,  0,  0,},
				{144,155,160,  0,180,  0,  0,  0,  0,144,  0,183,},
				{  0,156,161,  0,  0,  0,144,171,170,169,170,170,},
				{  0,  0,144,  0,  0,173,  0,200,192,  0, 62, 63,},
				{  0,  0,  0,179,  0,  0,171,200,  0,  0, 64, 65,},
				{  0,  0,  0,  0,144,  0,173,200,174, 62, 63,192,},
				{  0,  0,  0,  0,  0,  0,  0,200,  0, 64, 65, 96,},
				{  0,150,  0,  0,  0,  0,  0,172,175,174,175,174,},
				{ 44,  0,  0,144,  0,  0,150,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[12] = {
			.bg = {{
				{1,3,3,},
				{3,3,3,},
				{3,1,2,},
				{3,3,3,},
				{3,2,3,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,  0,186,  0,  0,  0,  0,  0,  0,  0,155,},
				{  0,149,  0,186,180,  0,155,160,150,  0,  0,159,},
				{185,185,185,186,  0,  0,156,161,  0,  0,  0,159,},
				{193,  0,192,186,  0,  0,179,  0,  0,  0,181,156,},
				{160,  0,  0,186,185,185,185,185,185,185,185,185,},
				{158,  0,180,186,192,  0,  0,  0,193,  0,155,162,},
				{158,  0,  0,186,  0,  0,  0,183,  0,  0,159,167,},
				{161,  0,  0,186,150,  0,  0,  0,  0,193,156,157,},
				{179,  0,193,186,  0,  0,193,  0,170,  0,  0,108,},
				{185,185,185,186,185,185,185,185,185,185,185,185,},
				{174,175,174,176,174,176,174,174,175,176,174,175,},
				{150,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62, 63,},
			}},
		},
		[13] = {
			.bg = {{
				{1,1,3,},
				{3,2,2,},
				{2,3,3,},
				{1,3,3,},
				{2,3,2,},
				{3,3,3,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,186,  0,180,  0,  0,108,},
				{182,  0,  0,  0,  0,170,186,199,  0, 38, 38, 38,},
				{185,185,185,186,185,185,186,185,185,185,185,185,},
				{160,  0,199,186,199,  0,  0,  0,  0,  0,  0,183,},
				{158,193,  0,186,  0,  0,  0,181,  0,155,160,  0,},
				{158,  0,180,186,  0,  0,  0,  0,  0,156,161,  0,},
				{158,  0,  0,186, 39, 39, 39, 39, 39, 39, 39, 39,},
				{161,  0,  0,186,177,177,177,177,177,177,177,177,},
				{185,185,185,186,185,185,185,185,185,185,185,185,},
				{193,  0,192,186,108,  0,  0,155,160,  0,  0,181,},
				{  0,  0,  0,186,  0,  0,  0,156,161,  0,  0,  0,},
				{150,  0,  0,186,  0,  0,184,  0,  0,  0,180,  0,},
			}},
		},
		[14] = {
			.bg = {{
				{3,3,2,},
				{3,3,3,},
				{3,2,3,},
				{3,3,3,},
				{1,1,1,},
				{3,2,2,},
			}},
			.fg = {{
				{  0,  0,  0,182,  0,  0,186,192,  0, 74, 74, 74,},
				{  0,  0,  0,  0,  0,  0,186,  0,183,148,148,148,},
				{  0,  0,180,  0, 70, 71,186,  0,199,  0, 74, 74,},
				{  0,  0,  0,  0, 72, 73,186,  0,  0,  0,148,148,},
				{  0,  0,  0,  0,  0,  0,186,181,  0, 74, 74, 74,},
				{ 70, 71,  0,  0,  0,191,186,  0,199,148,148,148,},
				{ 72, 73,  0,  0,  0,  0,186,  0,  0,  0, 74, 74,},
				{ 38, 38, 38,  0,182,  0,186,  0,  0,  0,148,148,},
				{  0,  0,  0,  0,  0,  0,186,192,  0,  0,  0,199,},
				{183,  0,  0,  0,  0,149,186,185,185,185,185,185,},
				{  0,  0,  0,  0,  0,  0,186,192,  0,170,  0,192,},
				{  0,  0,  0,192,  0,  0,186,  0,  0,  0,  0,  0,},
			}},
		},
		[15] = {
			.bg = {{
				{0,0,0,},
				{0,0,0,},
				{3,3,2,},
				{1,3,3,},
				{3,3,3,},
				{3,1,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  1,  1,168,169,168,168,186,168,168,169,168,169,},
				{ 70, 71,  0,  0,182,192,186,199,  0,  0,  0,108,},
				{ 72, 73,  0,  0,  0,  0,186,  0,  0,  0,  0,  0,},
				{199,  0,  0,  0,  0,  0,186,  0,  0,183,  0,  0,},
				{  0,191,  0,  0,  0,199,186,  0,  0,  0,  0,199,},
				{  0,  0,  0,  0,  0,  0,186,  0,192,  0,  0,  0,},
				{199,  0,  0,  0,179,  0,186,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,186,199,  0,  0,184,192,},
				{184,  0,  0,  0,  0,  0,186,185,185,185,185,185,},
			}},
		},
		[16] = {
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
		[17] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{0,0,0,},
				{0,0,0,},
			}},
			.fg = {{
				{186,  0,194,194, 52, 52, 52, 52,194,194, 43, 42,},
				{186,191,195,195,195,195,195,195,195,195, 39, 39,},
				{189,185,185,185,185,188,201,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,189,185,185,185,185,185,185,},
				{194,194,194,194,  0,  0,  0,  0,194,194,194,194,},
				{194,194,194,194,192,  0,  0,  0,194,194,194,194,},
				{ 56, 56, 56,194,  0,  0,  0,201,194, 56, 56, 56,},
				{ 57, 57, 57,194,  0,  0,  0,  0,194, 57, 57, 57,},
				{ 52, 52,194,194,131,131,131,131,194,194, 52,208,},
				{195,195,195,195,  0,  0,  0,207,195,195,195,195,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[18] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{194,194,  0,186,  0,194,194,208,194,194,  0,  0,},
				{194,194,  0,186,  0,195,195,195,195,195,  0,  0,},
				{195,195,  0,186,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 44,  0,  0,186,  0,  0,192,  0,  0,  0,  0,  0,},
				{187,185,185,186,185,185,185,185,185,185,185,185,},
				{186,  0,199,  0,207,  0,  0,  0,  0, 45, 45, 45,},
				{186,  0,194,194,194,194,194,194,194,194,  0,  0,},
				{186,  0,194,194,194,194,194,194,194,194,192,  0,},
				{186,  0,194, 31, 31, 31, 31, 31, 31,194,  0,207,},
				{186,199,194, 31, 31, 31, 32, 31, 31,194,  0,  0,},
				{186,  0,194,194,194, 32, 32,194,194,194,  0,  0,},
				{186,  0,194,194, 52,208,208,208,194,194, 41, 40,},
			}},
		},
		[19] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{195,195,195,195,195,157,157,157,157,195,195,195,},
				{  0,  0,201,186,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,186,  0,  0,  0,  0,  0,207,  0,  0,},
				{  0,199,  0,186,  0,  0,201,  0,  0,  0,  0,  0,},
				{  0,  0,  0,186,  0,  0,  0,  0,  0,  0,  0, 44,},
				{185,185,185,186,185,185,185,185,185,185,185,185,},
				{  0,  0,201,186,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,186,207,  0,  0,  0,  0,  0,199,  0,},
				{194,194,  0,186,  0,194,194,194,194,194,  0,  0,},
				{194,194,  0,186,  0,194,194,194,194,194,  0,  0,},
				{ 56,194,  0,186,  0,194, 56, 56, 56,194,  0,  0,},
				{ 57,194,  0,186,  0,194, 57, 57, 57,194,  0,  0,},
			}},
		},
		[20] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{185,185,185,186,185,185,185,185,185,185,185,185,},
				{  0,206,  0,186,  0,199,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,186,  0,  0,  0,  0,  0,205,  0,  0,},
				{  0,  0,  0,186,  0,  0,201,  0,  0,  0,  0,  0,},
				{  0,  0,  0,186,201,  0,  0,  0,  0,  0,199,  0,},
				{  0,  0,  0,186,  0,  0,  0,204,  0,  0,  0,206,},
				{ 44,  0,  0,186,  0,  0,  0,  0,  0,207,  0,  0,},
				{  0,  0,  0,186,  0,  0,  0,  0,  0,  0,  0,  0,},
				{194,194,194,194,194,162,162,162,162,194,194,194,},
				{194,194,194,194,194,167,167,167,167,194,194,194,},
				{194,194,194,194,194,167,167,167,167,194,194,194,},
				{194,194,194,194,194,167,167,167,167,194,194,194,},
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
				{ 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,},
				{ 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,},
				{ 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57,},
				{ 52, 52, 52, 52, 52, 52, 52, 52, 52,208, 52, 52,},
				{ 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,},
				{ 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,},
				{194,194,194,194,194,194,194,194,194,194,194,194,},
				{195,195,195,195,195,195,195,195,195,195,195,195,},
			}},
		},
	},
	.bonus_index = {
		1,3,5,6,7,8,9,15,17,18,19,20,21,
	},
	.bonus_screens = {
		[0] = {{
			{ 45, 45, 45, 45, 45, 45, 45, 78,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{109,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{111,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[1] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 83, 94, 94, 93, 94, 94,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},

		}},
		[2] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 54,119, 53,  0,  0, 53, 55,  0,  0,},
			{  0,  0,  0, 54,  0,  0,  0,  0,  0, 55,  0,  0,},
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
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 40, 41,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[4] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 46,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 47,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 47,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 54,120,  0,120,  0, 51, 55,},
			{  0,  0,  0,  0,  0, 54, 22,  0, 22,  0,  0, 55,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[5] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0, 54,119,  0,119,  0,},
			{  0,  0,  0,  0,  0,  0,  0, 54, 49,  0, 49,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0, 55,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0, 55,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[6] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 55,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 55,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 67,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 69,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[7] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0, 39, 39, 39,  0,  0,  0,  0, 39, 39, 39,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[8] = {{
			{  0,  0,  0, 54,  0, 49,  0,  0, 55, 42,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0, 47, 39,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 53,  0, 55,  0,  0,  0,  0,  0,  0, 54,  0, 53,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[9] = {{
			{ 55,  0,  0,  0,  0,  0, 54, 53, 55,  0,  0,  0,},
			{ 55,  0,  0,  0,  0,  0, 46,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 32, 32,  0,  0, 32, 32,  0,  0,  0,},
			{  0,  0,  0, 54,  0,119, 53, 53, 55, 40,  0,  0,},
		}},
		[10] = {{
			{  0,  0,  0,  0,  0,  0,  0, 42, 43,  0,  0,  0,},
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
		[11] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 40, 41,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 42, 43, 70, 71,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 66, 67, 72, 73,  0,  0,  0,},
			{  0,  0,  0,  0,  0, 68, 69, 40, 41,  0,  0,  0,},
		}},
		[12] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0, 53,  0,120,  0, 53,  0,119,  0, 53,  0,},
			{  0,  0,  0,  0, 22,  0,  0,  0, 49,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},

		}},
	},
};

#undef SCREEN_COUNT
#undef BONUS_COUNT


