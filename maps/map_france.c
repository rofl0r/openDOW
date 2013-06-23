#include "../map.h"

#define SCREEN_COUNT 24
#define BONUS_COUNT 9

const struct {
	struct map header;
	struct map_screen screens[SCREEN_COUNT];
	mapscreen_index bonus_index[BONUS_COUNT];
	struct map_fglayer bonus_screens[BONUS_COUNT];
} map_france = {
	.header = {
		.maptype = MT_URBAN,
		.mission_text = {
			" a terrorist group has threatened",
			"to assassinate me. will you save",
			"me by killing their leader? i am",
			"prepared to pay you $13000 if you",
			"will help.",
		},
		.rewardk = 13,
		.client_face = 2,
		.mini_pic = 0,
		.worldmap_coords = VEC(128,28),
		.bonuslayer_count = BONUS_COUNT,
		.enemy_type = ET_WESTERN,
		.enemy_palette = {
			PRGB(  0,   0,   0), 
			PRGB( 51,  85,  85), 
			PRGB( 51, 119,  51), 
			PRGB(119,  85,  17), 
			PRGB(187, 153,  85), 
			PRGB(187, 119,  85), 
			PRGB(0x99,0x33,0x11), 
			PRGB( 17,  51,  51), 
		},
		.screen_map = {
			#define X MAPSCREEN_BLOCKED
			[ 0] = { X, X, X, X, X, X, X },
			[ 1] = { X, X, X, X, X, X, X },
			[ 2] = { X,23, X, X, X, X, X },
			[ 3] = { X,22, X, X, X, X, X },
			[ 4] = { X,21, X, X, X, X, X },
			[ 5] = { X,20, X, X, X, X, X },
			[ 6] = { X,19, X, X, X, X, X },
			[ 7] = { X,18, X, X, X, X, X },
			[ 8] = { X,12,12,12,12,12, X },
			[ 9] = { X,12,12,12,12,17, X },
			[10] = { X, X, X, X, X,16, X },
			[11] = { X, X, X, X, X,15, X },
			[12] = { X, X, X, X, X,14, X },
			[13] = { X, X, X, X, X,13, X },
			[14] = { X,12,12,12,12,12, X },
			[15] = { X,11,12,12,12,12, X },
			[16] = { X,10, X, X, X, X, X },
			[17] = { X, 9, X, X, X, X, X },
			[18] = { X, 8, X, X, X, X, X },
			[19] = { X, 7, X, X, X, X, X },
			[20] = { X, 6, 6, 6, 6, 6, X },
			[21] = { X, 6, 6, 6, 6, 5, X },
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
		[1] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{183,125,  0,  0,  0,  0,  0,129,129,129,125,184,},
				{127,172,  0,  0,  0,  0,  0,  0,  0,  0,172,127,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,194,195,  0,  0,  0,},
				{129,  0,129,  0,129,  0,129,  0,129,  0,129,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,140,  0,  0,  0,  0,  0,  0,  0,  0,174,},
				{127,127,127,127,127,127,127,127,127,127,127,127,},
				{179,179,179,179,179,179,179,179,179,179,179,179,},
				{  0,174,  0,  0,  0,  0,  0,  0,  0,136,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[2] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{181,125,  0,  0,  0,  0,174,  0,  0,  0,125,184,},
				{183,125,  0,  0,  0,  0,128,  0,  0,  0,172,127,},
				{127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{128,  0,  0,  0,136,  0,128,  6,  7,  0,  0,189,},
				{128,  0,  0,  0,  0,  0,  0,  8,  9,  0,  0,  0,},
				{127,  0,  0,  0,  0,  0,128, 10, 11,  0,  0,  0,},
				{185,125,141,  0,  0,  0,187,  0,  0,  0,172,127,},
				{181,125,  0,  0,  0,  0,128,  0,  0,  0,125,186,},
				{181,125,  0,174,  0,  0,174,  0,  0,  0,125,182,},
				{181,125,  0,  0,  0,  0,128,  0,  0,  0,125,182,},
				{181,125,  0,  0,  0,  0,  0,  0,  0,  0,125,182,},
				{181,125,  0,  0,  0,140,128,  0,134,135,125,182,},
			}},
		},
		[3] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{127,  0,  0,  0,  0,  0,  0, 24, 25, 26,125,182,},
				{185,125,  0,  0,  0,  0,128, 18, 27, 20,125,182,},
				{181,125,  0,  0,  0,  0,195, 18, 19, 20,125,182,},
				{181,125,  0,194,  0,  0,128, 18, 19, 20,125,184,},
				{181,125,  0,  0,  0,  0,174, 18, 27, 20,172,127,},
				{183,125,  0,  0,  0,  0,128, 18, 19, 20,  0,140,},
				{127,  0,  0,  0,137,  0,  0, 18, 19, 20,  0,  0,},
				{  0,  0,  0,  0,  0,  0,128, 18, 27, 20,172,127,},
				{136,  0,  0,  0,  0,  0,  0, 18, 19, 20,125,186,},
				{127,  0,  0,  0,  0,  0,128, 28, 29, 30,125,182,},
				{185,125,132,133,  0,  0,  0, 21, 22, 23,125,182,},
				{181,125,  0,  0,  0,  0,128,  0,  0,  0,125,182,},
			}},
		},
		[4] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{127,  0,  0,  0,  0,  0,  0,  0,  0,  0,125,182,},
				{  0,  0,  0,  0,  0,141,128,  0,174,  0,125,182,},
				{127,  0,  0,  0,  0,  0,  0,  0,  0,  0,125,182,},
				{185,125,195,  0,  0,  0,128,  0,  0,  0,125,182,},
				{181,125,  0,174,  0,  0,  0,  0,  0,  0,125,182,},
				{181,125,  0,  0,  0,  0,128,  0,  0,  0,125,184,},
				{181,125,  0,  0,140,  0,174,  0,  0,  0,172,127,},
				{183,125,132,133,  0,  0,128,  0,136,  0,  0,128,},
				{127,  0, 12, 13,  0,  0,  0,  0,  0,  0,172,127,},
				{  0,  0, 14, 15,  0,  0,128,  0,  0,  0,125,186,},
				{  0,  0, 16, 17,  0,  0,  0,  0,  0,  0,125,182,},
				{  0,  0,  0,  0,  0,  0,128,  0,  0,195,125,182,},
			}},
		},
		[5] = {
			.bg = {{
				{5,5,5,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{180,180,180,180,180,180,180,180,180,180,180,180,},
				{127,127,127,127,127,127,127,127,127,127,127,127,},
				{  0,  0,  0,  0,  0,  0,  0,136,  0,  0,  0,140,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{137,129,129,  0,129,129,174,129,129,  0,129,129,},
				{  0,  0,  0,  0,  0,  0,195,  0,  0,  0,  0,194,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{127,  0,  0,  0,136,  0,  0,  0,  0,  0,172,127,},
				{185,125,  0,  0,  0,  0,  0,  0,  0,  0,125,186,},
				{183,125,  0,  0,  0,  0,  0,  0,  0,  0,125,182,},
			}},
		},
		[6] = {
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
		[7] = {
			.bg = {{
				{3,3,5,},
				{3,3,5,},
				{3,3,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,  0,130,  0,  0,  0,125,182,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,125,182,  0,  0,  0,},
				{  0,131,  0,174,  0,  0,  0,125,182,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,125,182,139,  0,  0,},
				{208,  0,  0,  0,  0,  0,  0,125,182,  0,  0,  0,},
				{127,127,127,127,127,127,127,172,182,  0,  0,  0,},
				{179,179,179,179,179,179,179,179,171,  0,140,  0,},
				{203,189,203,  0,  0,  0,  0,187,  0,  0,  0,191,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,192,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[8] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,5,},
				{3,3,5,},
				{3,3,5,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,131,174,131,  0,131,  0,131,  0,131,174,131,},
				{  0,  0,  0,  0,192,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,137,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,172,},
				{129,129,129,129,  0,  0,  0,  0,186,179,179,179,},
				{  0,134,135,  0,  0,  0,  0,125,182,  0,  0,  0,},
				{  0,  0,  0,130,  0,  0,  0,125,182,187,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,125,182,  0,  0,139,},
				{  0,  0,  0,130,  0,  0,  0,125,182,  0,  0,  0,},
				{  0,137,  0,  0,  0,  0,  0,125,182,  0,  0,  0,},
			}},
		},
		[9] = {
			.bg = {{
				{3,3,5,},
				{3,3,5,},
				{3,3,5,},
				{3,3,5,},
				{3,3,5,},
				{3,3,3,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,172,182,  0,202,202,},
				{178,178,178,178,178,178,178,178,182,  0,  0,  0,},
				{178,178,178,178,178,178,178,178,182, 50, 50, 50,},
				{178,178,178,178,178,178,178,178,182, 50, 50, 50,},
				{  0,  0,  0,  0,  0,  0,  0,  0,182,200,166,167,},
				{  0,  0,  0,130,192,  0,  0,  0,182,200,168,169,},
				{  0,  0,  0,174,  0,  0,  0,  0,182,200,200,200,},
				{  0,  0,  0,130,  0,  0,  0,  0,182,200,200,200,},
				{  0,137,  0,  0,  0,  0,  0,  0,182,198,107,107,},
				{  0,  0,  0,  0,129,129,129,129,184,180,180,180,},
				{  0,  0,  0,  0,  0,  0,  0,  0,136,172,  0,174,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[10] = {
			.bg = {{
				{1,1,1,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,3,},
				{3,3,5,},
			}},
			.fg = {{
				{  0,141,  0,  0,  0, 95, 95, 95, 95, 95, 95, 95,},
				{180,180,180,180,180,180,180,180,180,180,180,180,},
				{127,127,127,127,127,127,127,127,127,127,127,127,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,},
				{  0,  0,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,174,  0,131,  0,131,  0,131,  0,131,},
				{  0,  0,  0,130,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,137,  0,  0,  0,  0,},
				{  0,  0,  0,130,  0,  0,  0,  0,  0,  0,172,192,},
				{  0,  0,192,  0,  0,  0,  0,  0,186,179,179,179,},
				{  0,  0,  0,130,  0,  0,  0,  0,182,  0,202,202,},
			}},
		},
		[11] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{209,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,207,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0, 96, 97,  0,  0,  0,  0,  0,  0,189,194,},
				{ 50, 50, 50, 50, 50, 50, 50, 50, 50,204,204,204,},
				{ 50, 50, 50, 50, 50, 50, 50, 50, 50,  0,  0,  0,},
				{ 50, 50, 50, 50, 50, 50, 50, 50, 50,  0,  0,  0,},
				{161,162, 60, 60, 60,154,155,156, 60,  0,  0,187,},
				{164,165, 53, 60, 55,157,158,159, 60,  0,  0,  0,},
				{139,  0,  0,187,  0,  0,  0,  0,191,  0,  0,  0,},
				{189,  0,  0,  0,  0,187,  0,  0,  0,  0,187,  0,},
				{  0,195,  0,191,  0,  0,  0,187,194,  0,  0,141,},
			}},
		},
		[12] = {
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
		[13] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{0,0,0,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{107,107,107,  0,208,  0,  0,  0,  0,  0,  0,  0,},
				{ 84,  0,  0,  0,  0,  0,  0,  0,195,  0,  0,  0,},
				{ 85,  0,  0,  0,  0,  0,  0,  0,  0,192,  0,  0,},
				{  0,  0,195,  0,  0,  0,  0,  0,208,139,  0,  0,},
				{  0,193,  0,  0,  0,139,  0,  0,  0,  0,107,107,},
				{107,107,107,  0,  0,  0,  0,  0,  0,  0,141,139,},
				{204,204,204,204,204,204,204,204,204,204,204,204,},
				{203,  0,203,203,192,  0,203,203,  0,  0,194,203,},
				{ 96, 97,  0,209,  0,  0,  0,  0,  0,107,107,107,},
				{ 98, 99,  0,  0,  0,  0,  0,  0,  0,139,192,141,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[14] = {
			.bg = {{
				{0,0,0,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{179,179,179,179,179,179,179,179,179,179,179,179,},
				{203,203,  0,203,203,  0,203,203,  0,203,203,203,},
				{  0,  0,  0,141,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,194,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 86,},
				{  0,  0,  0,  0,  0,  0,  0, 96, 97,  0,  0, 87,},
				{107,107,107,  0,  0,  0,  0, 98, 99,  0,  0,141,},
				{141,139,141,  0,192,  0,208,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,193,  0, 52,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,107,107,107,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,139,  0,},
			}},
		},
		[15] = {
			.bg = {{
				{2,0,2,},
				{2,0,2,},
				{0,0,0,},
				{2,0,0,},
				{3,3,3,},
				{3,3,3,},
			}},
			.fg = {{
				{194,  0,  0,195,205,  0,  0,206,  0,  0,141,  0,},
				{  0,  0,  0,  0,205,  0,  0,206,208,  0,137,  0,},
				{ 84,  0,  0,  0,205,  0,  0,206,  0,  0,  0,  0,},
				{ 85,  0,  0,139,205,  0,  0,206,  0,  0,141,139,},
				{204,204,204,204,  0, 50, 50, 50, 50, 50,204,204,},
				{203,203,203,203,137, 50, 50, 50, 50, 50,  0,  0,},
				{139,141,208,141,205, 73,148,149,150, 74,  0,  0,},
				{141,139,141,139,205, 73,151,152,153, 74,111,111,},
				{179,179,179,179,179,179,179,179,179,179,179,179,},
				{  0,172,  0,  0,  0,  0,  0,  0,  0,195,  0,  0,},
				{  0,  0,  0,  0,  0,174,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,187,  0,  0,  0,  0,  0,172,  0,  0,},
			}},
		},
		[16] = {
			.bg = {{
				{3,3,3,},
				{3,3,3,},
				{0,0,0,},
				{2,0,2,},
				{2,0,2,},
				{2,0,2,},
			}},
			.fg = {{
				{129,174,129,  0,129,  0,129,  0,129,174,129,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{172,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{179,179,179,179,179,179,179,179,179,179,179,179,},
				{  0,  0,208,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{203,203,203,203,136,  0,  0,  0,203,203,203,203,},
				{139,141,139,141,205,  0,195,206,  0,  0,  0, 86,},
				{107,107,107,107,205,  0,  0,206,  0,  0,  0, 87,},
				{141,139,141,139,205,  0,  0,206,  0,  0,136,141,},
				{  0,195,  0,  0,205,136,  0,206,  0,  0,  0,139,},
				{  0,197,  0,  0,205,  0,  0,206,141,107,107,107,},
				{  0,  0,  0,  0,205,  0,  0,206,197,  0,  0,  0,},
			}},
		},
		[17] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{0,0,0,},
				{3,3,3,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0, 52, 52, 84,},
				{141,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 85,},
				{ 84,  0,  0,  0,  0,  0,  0,  0,136,195,  0,141,},
				{ 85,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{141,  0,  0,  0,  0,  0,136,  0,  0,  0,  0,  0,},
				{  0,  0,192,  0,208,  0,  0,  0,  0, 52, 52, 52,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,141,141, 52,},
				{204,204,204,204,204,204,204,204,204,204,204,204,},
				{180,180,180,180,180,180,180,180,180,180,180,180,},
				{  0,  0,  0,172,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[18] = {
			.bg = {{
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{202,  0,  0,  0,192,  0,  0,  0,  0,  0,139, 86,},
				{202,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 87,},
				{ 84,  0,  0,  0,  0,  0,  0, 52,  0,  0,199,202,},
				{ 85,141,  0,  0,  0,139,  0,  0,  0,190,  0,202,},
				{202,  0,  0,  0,  0,  0,  0,  0,139,  0,  0,202,},
				{202,  0,  0,  0,  0,  0,193,  0,  0,  0,199,202,},
				{202,  0,  0,  0,  0,  0,  0,  0,  0,141,  0,202,},
				{202,141,  0, 52,  0,  0,  0,  0,  0,  0,  0,202,},
				{100,100,100,100,  0,  0,  0,  0,100,100,100,100,},
				{  0,139,  0,141,  0,  0,  0,  0,  0,139,  0,141,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[19] = {
			.bg = {{
				{5,5,5,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{107,107,107,107,107,138,203,173,107,107,107,107,},
				{201,201,201,201,201,  0,  0,  0,201,201,201,201,},
				{202,141,  0,  0,  0,  0,  0,  0,141,  0,  0,202,},
				{202,  0,  0,  0,139,  0,  0,  0,  0,  0,  0,202,},
				{202,  0,  0,  0,  0,  0,  0,  0,  0, 52, 52, 52,},
				{202,  0,139,  0,  0,  0,193,  0,  0,  0,  0,202,},
				{202,  0,  0,  0,  0,  0,  0,  0,  0,141,  0,202,},
				{202,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,202,},
				{202,  0,  0,  0,139,  0,  0,139,  0,  0,  0,202,},
				{202,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,202,},
				{202,  0,  0,  0,  0,  0,  0,141,  0,  0,  0,202,},
			}},
		},
		[20] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{190,  0,  0,  0,  0,  0,  0,  0,  0,  0,194,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,208,  0,},
				{  0,  0,  0,194,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,208,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,207,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{207,  0,  0,  0,  0,  0,  0,  0,  0,195,  0,  0,},
			}},
		},
		[21] = {
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
				{195,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,208,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,194,  0,  0,208,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,190,  0,  0,  0,},
				{  0,  0,  0,  0,208,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[22] = {
			.bg = {{
				{1,1,1,},
				{1,1,1,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  2,  3,  0, 16, 17,  0,  0,  0,  0,  0,  0,},
				{  0,  4,  5,  0,  0,  0,  0,  0,  0, 31, 32,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0, 33, 34,  0,},
				{ 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,},
				{ 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,},
				{ 54, 54,166,167, 54, 54, 54, 54, 54,161,162, 54,},
				{ 54, 54,168,169, 54, 54, 55, 54, 54,164,165, 54,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,194,  0,},
				{194,  0,  0,  0,208,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,208,  0,  0,  0,  0,  0,  0,  0,  0,  0,190,},
			}},
		},
		[23] = {
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
				{  0,  0,  0,  0, 12, 13,  0,  0,  0,  0,  0,  0,},
				{  0, 92,  1,  0, 14, 15,  0,  0,  0,  0,  0,  0,},
			}},
		},
	},

	.bonus_index = {
		7,8,9,10,11,14,15,19,22,
	},
	.bonus_screens = {
		[0] = {{
			{  0,  0,  0,  0,  0,  0, 43, 44,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  6,  7,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  8,  9,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 10, 11,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
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
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 39, 40,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 41, 42,  0,  0,  0,  0,},
		}},
		[2] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,105,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0, 69, 88, 90,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0, 69, 48, 49,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,108,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,108,111,111,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,110,  0,  0,},
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
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 96, 97,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 98, 99,},
		}},
		[4] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,105,  0,  0,  0,  0,  0,105,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 64, 63, 66, 61, 65, 62, 64, 63,113,  0,  0,  0,},
			{ 59, 57,  0,  0,  0, 56, 59, 57,113,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[5] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,111,  0,  0,111,111,},
			{  0,  0,  0,  0,  0,  0,137,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,137,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[6] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,105,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 62, 64, 63,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0, 56, 59, 57,  0,  0,  0,},
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
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 96, 97,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 98, 99,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 52,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
		}},
		[8] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,105,  0,  0,  0,105,  0,  0,105,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 61,  0, 88, 90,113,  0, 65,  0,113, 88, 90,  0,},
			{  0,  0, 48, 49,113,  0,  0,  0,113, 48, 49,  0,},
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


