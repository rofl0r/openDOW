#include "../map.h"

#define SCREEN_COUNT 23
#define BONUS_COUNT 14

struct {
	struct map header;
	struct map_screen screens[SCREEN_COUNT];
	mapscreen_index bonus_index[BONUS_COUNT];
	struct map_fglayer bonus_screens[BONUS_COUNT];
} map_florida = {
	.header = {
		.maptype = MT_FOREST,
		.mission_text = {
			" a drug baron has recently caused",
			"the death of my dear son,and the",
			"police can't touch him. will",
			"you kill this evil man and allow",
			"justice? i will pay you $15000.",
		},
		.client_face = 0,
		.mini_pic = 0,
		.worldmap_coords = VEC(0,0),
		.bonuslayer_count = BONUS_COUNT,
		.enemy_type = ET_WESTERN,
		.enemy_palette = {
			PRGB(  0,   0,   0), 
			PRGB( 51,  85,  85), 
			PRGB( 51, 119,  51), 
			PRGB(119,  85,  17), 
			PRGB(187, 153,  85), 
			PRGB(187, 119,  85), 
			PRGB( 51, 119, 119), 
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
		[1] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{1,2,3,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{177,177,177,186,178,  0,  0,178,186,177,177,177,},
				{177,177,177,186,178,  0,  0,178,186,177,177,177,},
				{185,185,185,186,185,185,185,185,186,185,185,185,},
				{100,101,177,186,177,100,101,177,186,177,100,101,},
				{102,103,177,186,177,102,103,177,186,177,102,103,},
				{185,185,185,186,185,185,185,185,186,185,185,185,},
				{  0,150,  0,  0,  0,  0,  0,182,  0,  0,  0,183,},
				{  0,  0,207,  0,  0,  0,  0,  0,  0,152,  0,  0,},
				{  2,  2,  2,  0,  0,180,  0,  0,  0,  2,  2,  2,},
				{ 23, 24,  1, 97,  0,  0,  0,  0,184,  1, 24, 23,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[2] = {
			.bg = {{
				{2,2,3,},
				{2,2,2,},
				{2,2,2,},
				{2,3,2,},
				{1,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{177,177,100,101,177,177,177,186,  0,  0,152,  0,},
				{177,177,100,101,177,177,177,186,  0,  0,  0,  0,},
				{177,177,100,101,177,177,177,186,  0,  0,  0,  0,},
				{ 96, 96,102,103,177,177,177,186,152,202,202,202,},
				{104,  0,185,185,185,185,185,186,188,203,203,203,},
				{ 63,  0,180,186,178,  0,  0,178,186,185,185,185,},
				{ 65,152,  0,186,178,  0,  0,178,186,177,177,177,},
				{ 63, 62, 63,186,178,  0,  0,178,186,177,177,177,},
				{ 65, 64, 65,186,178,  0,  0,178,186,185,185,185,},
				{  0,  0,  0,186,178,  0,  0,178,186,177,177,100,},
				{  0,  0,152,186,178,  0,  0,178,186,177,177,102,},
				{185,185,185,186,178,  0,  0,178,186,185,185,185,},
			}},
		},
		[3] = {
			.bg = {{
				{2,1,2,},
				{2,2,3,},
				{2,2,2,},
				{2,2,2,},
				{3,2,2,},
				{2,2,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,186,  0,  0,  0,  0,},
				{  0,152,  0,  0,  0,  0,183,186,  0,  0,152,  0,},
				{  0,  0,  0,  0,  0,  0,  0,186,  0, 66, 67, 70,},
				{  0,181,  0,  0,152,  0,  0,186,  0, 68, 69, 72,},
				{  0,  0,  0,  0,  0,  0,  0,186,  0,  0,  0,152,},
				{ 39, 39, 39, 39,  0,  0,  0,186,  0,  0,  0,  0,},
				{ 97,  0,  0,  0,  0,182,  0,186,  0,  0,  0,152,},
				{  0,  0,  0,  0,152,  0,  0,186,  0,180,  0,  0,},
				{  0,  0,  0,  0,  0,  0,183,186,  0,  0,  0,  0,},
				{  0,181,  0,  0,  0,  0,  0,186,152,  0,  0, 97,},
				{ 39, 39, 39, 39, 39, 39, 39,186,  0,  0, 39, 39,},
				{185,185,185,185,185,185,185,186,  0,  0,  0,  0,},
			}},
		},
		[4] = {
			.bg = {{
				{3,2,2,},
				{2,1,2,},
				{2,2,2,},
				{2,2,2,},
				{3,3,2,},
				{3,2,2,},
			}},
			.fg = {{
				{186,  0,  0,  0,  0,  0,  0,  0,100,101,177,177,},
				{186,  0,  0,180,  0,207,  0,  0,100,101,177,177,},
				{186,179,  0,  0,  0,  0,199,  0,100,101,177,177,},
				{186,  0,  0,  0,  0,  0,  0,  0,102,103,177,177,},
				{186,  0,  0,  0,  0,199,  0,  0,186,185,185,185,},
				{186,  0,  0,  0,  0,  0,  0,  0,186,178,177,177,},
				{186,  0,199,  0,  0,  0,193,  0,186,178,  0,  0,},
				{186,185,185,185,185,185,185,185,186,178,  0,  0,},
				{186,177,100,101,177,177,177,177,186,178,  0,  0,},
				{186,177,102,103,177,177,177,177,186,178,177,177,},
				{189,185,185,185,185,185,185,185,186,185,185,185,},
				{152,  0,  0,182,  0,  0,  0,186,152,  0,  0,  0,},
			}},
		},
		[5] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,3,2,},
				{2,2,2,},
				{2,2,1,},
				{2,2,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  2,  2,  2,  2,  2,  0,  0,  2,  2,  2,  2,  2,},
				{  1, 82,  1,  1, 82,  0,  0, 82,  1,  1, 82,  1,},
				{  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{185,185,185,185,185,185,185,185,188,  0,  0,  0,},
				{101,  0,  0,  0,  0,  0,  0,199,186,  0,  0,154,},
				{101,  0,  0,201,  0,  0,150,  0,186,  0,  0,  0,},
				{101,  0,  0,  0,  0,  0,  0,  0,186,  0,199,  0,},
				{101,  0,  0,207,  0,  0,  0,201,189,185,185,185,},
				{103,  0,  0,  0,199,  0,  0,  0,100,101,177,177,},
			}},
		},
		[6] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{ 89, 92, 92, 92, 92, 90,132,163,142,164,133,159,},
				{ 89, 92, 92, 92, 92, 90,132,163,142,164,133,159,},
				{ 86, 91, 91, 91, 91, 87,132,163,142,164,133,156,},
				{131,131,131,131,131,131,134,163,142,164,135,131,},
				{165,165,165,165,165,165,165,138,142,139,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,166,166,166,166,166,166,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{ 62, 63,  0,155,160,  0,  0,  0,  0,180, 62, 63,},
				{ 64, 65,  0,156,161,  0,150,  0,  0,  0, 64, 65,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[7] = {
			.bg = {{
				{2,2,2,},
				{2,1,2,},
				{2,3,1,},
				{2,2,2,},
				{2,2,2,},
				{1,2,2,},
			}},
			.fg = {{
				{166,166,140,142,141,166,166,166,166,166,166,166,},
				{130,136,163,142,164,137,130,130,130,130,130,130,},
				{114,132,163,142,164,133,  0,  0,180,  0,  0,150,},
				{114,132,163,142,164,133,150,  0,  0,155,160,  0,},
				{114,132,163,142,164,133,  0,183,  0,156,161,  0,},
				{114,132,163,142,164,133,  0,  0,  0,  0,182,  0,},
				{131,134,163,142,164,135,131,131,131,131,131,131,},
				{165,165,138,142,139,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,166,140,142,141,166,166,},
				{130,130,130,130,130,130,136,163,142,164,137,130,},
				{ 84, 88, 88, 88, 88, 85,132,163,142,164,133,155,},
			}},
		},
		[8] = {
			.bg = {{
				{3,2,2,},
				{3,3,3,},
				{3,3,3,},
				{2,1,2,},
				{3,2,2,},
				{3,3,3,},
			}},
			.fg = {{
				{130,130,130,130,130,136,163,142,164,137,130,130,},
				{150,  0,  0,180,  0,132,163,142,164,133,  0,180,},
				{131,131,131,131,131,134,163,142,164,135,131,131,},
				{165,165,165,165,165,165,138,142,139,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,166,166,166,166,140,142,},
				{130,130,130,130,130,130,130,130,130,136,163,142,},
				{  0,  0,155,160, 63,  0,  0,182,  0,132,163,142,},
				{154,  0,156,161, 65,181,  0,  0,  0,132,163,142,},
				{131,131,131,131,131,131,131,131,131,134,163,142,},
				{165,165,165,165,165,165,165,165,165,165,138,142,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
			}},
		},
		[9] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{1,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{132,163,142,164,133,  0, 50, 52, 50,  0, 97,108,},
				{134,163,142,164,135,131,131,131,131,131,131,131,},
				{165,138,142,139,165,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,140,142,141,166,166,166,166,166,166,166,},
				{130,136,163,142,164,137,130,130,130,130,130,130,},
				{ 44,132,163,142,164,133, 84, 88, 88, 88, 88, 85,},
				{ 44,132,163,142,164,133, 86, 91, 91, 91, 91, 87,},
				{131,134,163,142,164,135,131,131,131,131,131,131,},
				{165,165,138,142,139,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,140,142,141,166,166,166,},
			}},
		},
		[10] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,1,3,},
				{2,3,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{165,165,165,165,165,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,140,142,141,166,166,166,166,166,166,166,166,},
				{136,163,142,164,137,130,130,130,130,130,130,130,},
				{132,163,142,164,133,  0,  0,  0,  0,  0, 66, 67,},
				{132,163,142,164,133,  0,155,162,162,160, 68,155,},
				{132,163,142,164,133, 56, 56, 56, 56, 56, 70,159,},
				{132,163,142,164,133, 57, 57, 57, 57, 57, 72,156,},
				{132,163,142,164,133,  0, 52, 52, 52,  0, 96, 96,},
			}},
		},
		[11] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{162,162,162,160,186,156,157,157,161,186,159,167,},
				{167,167,167,158,186,185,185,185,185,186,159,167,},
				{167,167,167,158,186,177,177,177,177,186,159,167,},
				{157,157,157,161,186,177,177,177,177,186,156,157,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
				{165,165,165,165,165,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,166,166,166,166,166,166,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{ 39, 39, 39,  0,  0,  0,  0,  0,  0, 39, 39, 39,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[12] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{165,165,165,165,165,165,165,165,165,165,165,165,},
				{142,142,142,142,142,142,142,142,142,142,142,142,},
				{166,166,166,166,166,166,166,166,166,166,166,166,},
				{130,130,130,130,130,130,130,130,130,130,130,130,},
				{162,162,162,160,186,177,177,177,177,186,155,162,},
				{167,167,167,158,186,178,  0,  0,178,186,159,167,},
				{167,167,167,158,186,178,  0,  0,178,186,159,167,},
				{157,157,157,161,186,177,177,177,177,186,156,157,},
				{185,185,185,185,186,185,185,185,185,186,185,185,},
				{177,177,177,177,186,155,162,162,160,186,155,162,},
				{177,177,177,177,186,159,167,167,158,186,159,167,},
				{185,185,185,185,186,159,167,167,158,186,159,167,},
			}},
		},
		[13] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{194,194,  0,  0,  0,  0,  0,184,  0,  0,  0,  0,},
				{194,194,194,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{194,194,194,194,193,  0,  0,  0,  0,  0,  0,  0,},
				{194,194,194,194,194,  0,  0,  0,  0,  0,184,204,},
				{ 56, 56, 56, 56, 56, 56,  0,  0,  0,  0,  0,199,},
				{ 57, 57, 57, 57, 57, 57,  0,199,  0,  0,  0,199,},
				{194, 52, 52, 52, 52,194,  0,  0,  0,  0,  0,199,},
				{194, 50, 52, 52, 50,194,  0,  0,  0,  0,183,199,},
				{195,195,195,195,195,195,  0,  0,  0,  0,  0,204,},
				{207,192,207,207,192,207,  0,  0,  0,  0,  0,  0,},
				{184,  0,  0,  0,  0,  0,  0,  0,  0,  0,206,205,},
				{131,131,131,131,131,131,131,131,131,131,131,131,},
			}},
		},
		[14] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,193,  0,  0,  0,  0,  0,  0,  0,},
				{ 96,  0,  0,  0,  0,199,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,183,  0,  0,},
				{184,  0,  0,  0,  0,  0,207,  0,  0,  0,  0,199,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,199,  0,  0,  0,},
				{199,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,204,  0,  0,  0,  0,  0,184,},
				{ 44,  0,183,  0,  0,  0,  0,  0,  0,199,  0,  0,},
				{194,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[15] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 40, 41,  0,  0,  0,  0,  0,  0,  0,  0,  0,199,},
				{ 42, 43,  0,  0,201,  0,  0,  0,  0,183,  0,  0,},
				{  0,  0,  0,  0,  0,201,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,182,  0,  0,  0,  0,  0, 66, 67,207,  0,  0,},
				{  0,183,  0,  0,  0,  0,  0, 68, 69,  0,  0,  0,},
				{  0,  0,  0,  0,  0,182,  0,  0,  0,  0,  0,182,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,201,  0,  0,  0,  0,  0,  0,199,  0,  0,},
				{199,  0,  0,  0,  0,  0,  0,201,  0,  0,  0, 96,},
			}},
		},
		[16] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
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
				{1,1,2,},
				{1,1,3,},
				{1,1,3,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{  0,  0, 62, 63,  0,178,186,178,  0,192,156,157,},
				{  0,184, 64,155,160,178,186,178,182,  0,  0,184,},
				{204,  0,180,156,161,178,186,178,  0,179,  0,  0,},
				{177,177,177,177,177,178,186,178,184,207,  0,180,},
				{185,185,185,185,185,185,186,178,155,162,160,  0,},
				{177,177,177,177,177,178,186,178,159,167,158,182,},
				{  0,182,155,162,160,178,186,178,156,157,161,180,},
				{179,  0,159,167,158,178,186,177,177,177,177,177,},
				{ 67,193,156,157,161,178,189,185,185,185,185,185,},
				{204,180,  0,  0,205,177,177,177,177,177,177,177,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[18] = {
			.bg = {{
				{1,3,2,},
				{2,3,3,},
				{3,3,3,},
				{1,3,3,},
				{1,3,3,},
				{1,3,3,},
			}},
			.fg = {{
				{  0,199,159,167,158,178,186,178,180,  0,  0,182,},
				{  0,199,159,167,158,178,186,177,177,177,177,177,},
				{  0,180,159,167,158,178,186,185,185,185,185,185,},
				{  0,199,156,157,161,178,186,177,177,177,177,177,},
				{177,177,177,177,177,178,186,178,155,160,  0, 96,},
				{185,185,185,185,185,185,186,178,156,161,  0,179,},
				{177,177,177,177,177,177,186,178,  0,184,155,162,},
				{ 72, 73,155,162,160,178,186,178,192,  0,159,167,},
				{180,  0,159,167,158,178,186,178,  0,182,159,167,},
				{  0,  0,156,157,161,178,186,178,192,  0,159,167,},
				{  0,179,  0,193,  0,178,186,178,205,  0,159,167,},
				{184,  0,  0,  0,180,178,186,178,  0,184,159,167,},
			}},
		},
		[19] = {
			.bg = {{
				{1,3,3,},
				{1,1,3,},
				{1,1,3,},
				{1,1,3,},
				{3,3,3,},
				{1,1,3,},
			}},
			.fg = {{
				{192,  0,159,167,158,178,186,178,192,184,  0,180,},
				{179,  0,156,157,161,178,186,178,205,  0,  0,  0,},
				{ 62, 63,  0,  0,  0,178,186,178,  0,  0,179,  0,},
				{ 64, 65,  0,184,  0,178,186,178,  0,182,  0,193,},
				{184,  0,155,162,160,178,186,178,  0,  0,  0,207,},
				{  0,192,159,167,158,178,186,178,180,  0,184,  0,},
				{  0,  0,156,157,161,178,186,178,  0,179,  0,  0,},
				{177,177,177,177,177,178,186,178,193,  0,  0,182,},
				{185,185,185,185,185,185,186,178,  0,  0,181,  0,},
				{177,177,177,177,177,178,186,178,182,  0,  0,184,},
				{  0,199,155,162,160,178,186,178,  0,184,  0,192,},
				{  0,180,159,167,158,178,186,178,  0,  0,179,  0,},
			}},
		},
		[20] = {
			.bg = {{
				{3,1,1,},
				{1,2,2,},
				{1,1,3,},
				{1,2,3,},
				{1,1,3,},
				{2,2,3,},
			}},
			.fg = {{
				{177,178,186,177,177,177,177,177,177,177,177,177,},
				{185,185,186,185,185,185,185,185,185,185,185,185,},
				{177,177,177,177,177,177,186,177,177,177,177,177,},
				{180,180,  0,155,160,178,186,178,180,  0,  0,184,},
				{  0,  0,184,156,161,178,186,178,  0,  0,182,  0,},
				{179,  0,  0,206,  0,178,186,178,182,  0,193,184,},
				{  0,  0,182,155,160,178,186,178,155,162,160,  0,},
				{180,  0,  0,156,161,178,186,178,159,167,158,  0,},
				{177,177,177,177,177,178,186,178,156,157,161,180,},
				{185,185,185,185,185,185,186,177,177,177,177,177,},
				{177,177,177,177,177,177,186,185,185,185,185,185,},
				{  0,180,155,162,160,178,186,177,177,177,177,177,},
			}},
		},
		[21] = {
			.bg = {{
				{3,3,3,},
				{3,3,2,},
				{2,3,3,},
				{3,3,3,},
				{1,1,3,},
				{1,2,3,},
			}},
			.fg = {{
				{  0, 42, 43,  0,  0,  0,181, 70, 71,  0,  0, 40,},
				{  0,  0,  0,184,  0,  0,  0, 72, 73,  0,  0, 42,},
				{ 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,},
				{ 96,192,  0,  0,192,192,192,205,  0,  0,  0, 96,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{177,177,177,177,177,177,177,177,177,177,177,177,},
				{104,104,187,185,185,185,185,185,185,185,185,185,},
				{104,104,186,178,177,177,177,177,177,177,177,177,},
				{160,178,186,178,180,184,  0,  0,182,  0,  0,179,},
				{158,178,186,178,  0,  0,180,  0,184,  0,180,  0,},
				{158,178,186,178,  0,182,  0,184,  0,  0,184,193,},
				{161,178,186,178,179,  0,193,182,  0,204,  0,180,},
			}},
		},
		[22] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{ 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0, 40, 41,  0,  0,  0,  0,  0, 66, 67,},
				{  0,  0,  0, 42, 43,  0,183,  0,  0,  0, 68, 69,},
				{180,  0,  0,  0,  0,  0,  0, 40, 41,  0,  0,  0,},
				{  0,  0,  0,  0, 66, 67,  0, 42, 43,  0,  0,  0,},
				{  0, 40, 41,  0, 68, 69,  0,  0,  0,182,  0,  0,},
			}},
		},
	},
	.bonus_index = {
		1,2,3,4,5,8,9,10,13,17,18,19,20,21,
	},
	.bonus_screens = {
		[0] = {{
			{ 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 98, 99,  0,  0,  0, 98, 99,  0,  0,  0, 98, 99,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0, 44,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[1] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 98,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[2] = {{
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
			{  0,  0, 98, 99,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[3] = {{
			{ 44,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 70, 71,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 72, 73,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0, 98, 99,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0, 44,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[4] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 99,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0, 98, 99,  0,  0,},
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
			{  0,  0,  0, 62,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 64,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
					}},
		[6] = {{
			{  0,  0,  0,  0,  0, 54,  0,  0,  0, 55,  0,  0,},
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
		[7] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 39, 39, 39, 39, 39,  0,  0, 39, 39, 39, 39, 39,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 69,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 73,},
			{  0,  0,  0,  0,  0, 54,  0,  0,  0, 55,  0,  0,},
		}},
		[8] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 54,  0,  0,  0,  0, 55,  0,  0,  0,  0,  0,  0,},
			{ 54,  0,  0,  0,  0, 55,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[9] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0, 65,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62, 63,},
			{ 69,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 65,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[10] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0, 62, 63, 64,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 65,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 70, 71,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
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
			{206,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0, 62, 63,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0, 64, 65,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[12] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 62, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 64, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0, 62, 63,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0, 64, 65,  0,  0,},
		}},
		[13] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,105,104,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
	},
};

#undef SCREEN_COUNT
#undef BONUS_COUNT


