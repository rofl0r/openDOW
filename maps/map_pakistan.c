#include "../map.h"

#define SCREEN_COUNT 24
#define BONUS_COUNT 1

const struct {
	struct map header;
	struct map_screen screens[SCREEN_COUNT];
	mapscreen_index bonus_index[BONUS_COUNT];
	struct map_fglayer bonus_screens[BONUS_COUNT];
} map_pakistan = {
	.header = {
		.maptype = MT_DESERT,
		.mission_text = {
			" a group of terrorists threatens",
			"to overthrow our government in a",
			"violent revolution. we will pay",
			"you $6000 to kill their leader.",
			"",
		},
		.rewardk = 6,
		.client_face = 7,
		.mini_pic = 0,
		.boss_id = 4,
		.worldmap_coords = VEC(170,45),
		.bonuslayer_count = BONUS_COUNT,
		.enemy_type = ET_ASIAN,
		.enemy_palette = {
			PRGB(  0,   0,   0), 
			PRGB(119,  85,  17), 
			PRGB( 17,  51,  51), 
			PRGB(187, 119,  85), 
			PRGB(187, 153,  85), 
			PRGB( 51,  85,  85), 
			PRGB( 51, 119,  51), 
			PRGB( 51, 119,  51), 
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
				{0,0,3,},
				{1,0,0,},
				{3,1,2,},
				{0,1,0,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,160,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,161, 28, 29, 29,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 28, 29,},
				{  0,  0,  0,  0,153,  0,  0,  0,154,  0,  0,  0,},
				{ 48, 48,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 87, 87, 87, 87,204,204,204, 87, 87, 87, 87, 87,},
				{ 84, 84, 84, 84,204,204,204, 84, 84, 84, 84, 84,},
				{ 86, 86, 86, 86,204,204,204, 86, 86, 86, 86, 86,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[2] = {
			.bg = {{
				{0,1,0,},
				{0,3,0,},
				{0,0,2,},
				{3,0,1,},
				{0,0,0,},
				{0,1,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,149,147,147,147,147,},
				{  0,154,  0,  0,  0,  0,  0,  0,  0,  0,154,  0,},
				{  0,  0,  0,  0,  0,161,163,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 16, 17,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 18, 19,  0,  0, 83, 83, 28, 29, 83, 83,  0,  0,},
				{  0,154,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,154,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 29, 29, 29,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,157,  0,  0,  0,154,  0,},
			}},
		},
		[3] = {
			.bg = {{
				{0,3,0,},
				{2,0,0,},
				{1,0,3,},
				{0,3,3,},
				{0,0,0,},
				{1,0,0,},
			}},
			.fg = {{
				{  0,148,  0,  0,  0,  0,  0, 16, 23, 23, 23, 17,},
				{  0,148,  0,  0,  0,  0,  0, 20, 24, 24, 24, 21,},
				{  0,148,  0,  0, 25,  0,  0, 20, 24, 24, 24, 21,},
				{  0,148,  0,  0,  0,  0,  0, 20, 24, 24, 24, 21,},
				{  0,148,  0,160,  0,  0,  0, 18, 22, 22, 22, 19,},
				{  0,148,  0,  0,162,  0,  0,  0,  0,  0,154,  0,},
				{  0,148,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,149,147,147,147,147,147,151,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,148,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,148,  0,  0,  0,  0,},
				{ 29, 29, 29, 29, 29,  0,  0,148,  0,157,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,148,  0,  0,  0,  0,},
			}},
		},
		[4] = {
			.bg = {{
				{1,0,3,},
				{0,3,3,},
				{0,0,0,},
				{1,1,1,},
				{0,0,3,},
				{3,3,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,158,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,154,  0,  0,  0,  0,  0,  0,  0,154,  0,},
				{  0,  0,  0,164,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,154,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,157,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{147,151,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[5] = {
			.bg = {{
				{2,2,2,},
				{2,3,0,},
				{0,3,3,},
				{1,0,0,},
				{0,1,0,},
				{2,0,0,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,157,  0,},
				{  0,  0,158,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,154,  0,  0,  0,  0,},
				{  0,  0,154,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,153,  0,  0,  0,  0,  0,  0,},
				{  0,  0,157,  0,  0,  0,  0,  0,  0,154,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
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
				{1,1,1,},
				{1,2,1,},
				{1,2,1,},
				{1,1,2,},
				{2,2,2,},
				{2,2,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,165,  0,  0,  0,123,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0, 12, 13,  0,  0,  0,  0,  0,},
				{  0,166,  0,  0,  0, 14, 15,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,168,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 89, 90, 91,  0,  0,  0, 28, 29, 29, 29, 29, 29,},
				{ 92, 93, 95,  0,  0,  0,  0,  0,  0,  0,  0, 30,},
				{ 96, 97, 98,  0,  0,  0,161,  0,  0,161,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[8] = {
			.bg = {{
				{1,3,1,},
				{2,1,3,},
				{1,1,1,},
				{1,1,1,},
				{1,3,1,},
				{2,1,1,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,123,123,123,},
				{  0,  0,  0,169,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,161,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{165,  0,  0,  0,  0,168,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,168,  0,  0,},
				{  0,  0,  0,  0,123,123,123,123,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,161,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,164,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[9] = {
			.bg = {{
				{1,1,1,},
				{1,1,0,},
				{3,1,1,},
				{2,1,1,},
				{2,1,2,},
				{2,1,2,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,157,  0,  0,  0,  0,  0,  0,  0,  0,171,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,168,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,165,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 44, 44, 44, 45,  0,  0,  0,  0, 46, 44, 44, 44,},
				{161,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,168,  0,  0,  0,},
				{123,123,123,  0,168,  0,  0,  0,161,  0,  0,  0,},
			}},
		},
		[10] = {
			.bg = {{
				{1,1,1,},
				{3,1,1,},
				{1,1,1,},
				{1,1,1,},
				{3,1,1,},
				{1,1,0,},
			}},
			.fg = {{
				{ 21,159,  0,163,162,  0,154,  0,160,157,  0, 20,},
				{ 21,  0,165,  0,160,  0,  0,  0,  0,159,  0, 20,},
				{ 21,  0,  0,  0,  0,  0,  0,  0,  0,  0,161, 20,},
				{ 21,160,  0,  0,  0,  0,  0,  0,  0,  0,  0, 20,},
				{ 24, 23, 23, 23, 17,  0,  0, 16, 23, 23, 23, 24,},
				{ 22, 22, 22, 22, 19,  0,160, 18, 22, 22, 22, 22,},
				{  0,157,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,161,  0,  0,  0,  0,168,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,161,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,157,  0,},
				{  0,  0,  0,  0, 88,  0,  0, 88,  0,168,  0,  0,},
			}},
		},
		[11] = {
			.bg = {{
				{4,4,4,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
				{1,1,1,},
			}},
			.fg = {{
                                {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
                                {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
                                {131,131,131,131,131,131,131,131,131,131,131,131,},
                                { 17,  0,  0,179,  0,  0,  0,  0,179,  0,  0, 16,},
                                { 21,  0,  0,  0,157,  0,  0,  0,  0,  0,161, 20,},
                                { 21,  0,  0,  0,  0,  0,159,  0,  0,  0,  0, 20,},
                                { 21,  0,  0, 11,160,163,  0,  0, 11,  0,  0, 20,},
                                { 21,  0,162,179,  0,  0,  0,  0,179,  0,  0, 20,},
                                { 21,  0,163,  0,159,  0,  0,  0,163,159,  0, 20,},
                                { 21,  0,154,  0,  0,  0,  0,  0,  0,  0,  0, 20,},
                                { 21,  0,  0, 11,  0,  0,  0,  0, 11,  0,  0, 20,},
                                { 21,  0,  0,179,  0,  0,  0,159,179,  0,  0, 20,},
			}},
		},
		[12] = {
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
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 92,},
				{147,147,147,147,151,  0,  0,121,  0,  0,  0, 92,},
				{ 89, 90, 91,  0,148,154,  0,122,  0,  0,  0, 92,},
				{ 92, 94, 95,  0,148,  0,  0,  0,  0,  0,  0, 92,},
				{ 92, 94, 95,  0,148,  0,  0,  0,  0,  0,175, 96,},
				{ 96, 97, 98,  0,149,147,147,147,147,147,147,147,},
				{175,  0,  0,  0,  0,  0,156,  0,  0,  0,157,  0,},
				{147,147,147,147,147,147,147,147,147,147,147,147,},
				{  0,  0,  0,  0,  0,154,156,  0,  0,156,  0,  0,},
				{  0,  0, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[14] = {
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
				{  0,  0,156,  0,  0,  0,  0,  0,  0,154,  0,  0,},
				{  0,  0,  0,  0,175,  0,  0,  0,  0,  0,  0,157,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,152,147,147,147,147,147,147,147,147,},
				{154,  0,  0,148, 89, 90, 91, 89, 90, 91,154,  0,},
				{  0,  0,  0,148, 92, 94, 95, 92, 93, 95,  0,152,},
				{  0,  0,  0,148, 96, 97, 98, 92, 94, 95,  0,149,},
				{  0,  0,  0,148,  0,  0,  0, 92, 93, 95,  0,  0,},
				{147,147,147,150,  0,  0,  0, 96, 97, 98,  0,  0,},
				{  0,  0,  0,  0,  0,154,  0,175,  0,  0,  0,  0,},
				{  0,157,  0,  0,  0,  0,  0,  0,  0,154,  0, 89,},
			}},
		},
		[15] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{  0,165,  0,  0,  0,156,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,161,  0,  0,  0,  0,},
				{  0,  0,  0,  0,157,  0,163,  0,  0,  0,  0,  0,},
				{188,188,188,188,188,188,188,188,188,188,188,188,},
				{187,187,187,187,187,187,187,187,187,187,187,187,},
				{  0,  0,160,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{154,  0,  0,162,  0,  0,  0,  0,  0,167,  0,  0,},
				{206,206,207,207,206,207,207,207,207,207,206,206,},
				{157,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{206,206,207,206,206,206,206,206,207,206,206,206,},
				{  0,  0,  0,  0,  0,  0,156,  0,  0,  0,154,  0,},
				{  0,175,  0,  0,  0,  0,  0,  0,175,  0,  0,  0,},
			}},
		},
		[16] = {
			.bg = {{
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{  0,166,  0,  0,  0,122,  0,152,147,147,147,151,},
				{  0,  0,  0,  0,  0,  0,  0,148,  0,121,  0,148,},
				{147,151,157,  0,152,147,147,150,  0,122,  0,148,},
				{  0,149,147,147,150,  0,  0,  0,  0,  0,  0,148,},
				{  0,  0,  0,  0,  0,152,147,147,147,147,147,150,},
				{  0,154,  0,  0,  0,148,165,  0,  0,  0,  0,  0,},
				{  0,  0,121,  0,154,148,  0,  0,  0,  0,  0,  0,},
				{  0,  0,122,  0,  0,148,  0,  0,156,  0,154,  0,},
				{156,  0,  0,  0,  0,148,154,  0,  0,  0,  0,  0,},
				{  0,  0,  0,154,  0,148,  0,  0,  0,157,  0,  0,},
				{147,147,147,147,147,150,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,166,  0,},
			}},
		},
		[17] = {
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
				{157,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{147,151, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29,},
				{  0,148,  0,154, 89, 90, 91, 89, 90, 91, 89, 90,},
				{156,148,  0,154, 92, 93, 95, 92, 93, 95, 92, 93,},
				{  0,148,  0,  0, 96, 97, 98, 92, 94, 95, 92, 94,},
				{  0,148,  0,  0,  0,  0,  0, 96, 97, 98, 92, 93,},
				{  0,148,  0,168,  0,  0,  0,  0,  0,  0, 96, 97,},
				{  0,148,  0,  0,  0,  0,165,  0,  0,  0,  0,157,},
				{156,148,  0,  0,  0,  0,  0,  0,156,  0,  0,  0,},
				{  0,149,147,147,147,147,147,147,147,147,147,147,},
				{  0,  0,  0,  0,  0,121,  0,  0,  0,  0,  0,  0,},
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
				{  0,  0,  0,  0,  0,148,  0,  0,  0,  0,  0,  0,},
				{154,  0,  0,  0,  0,148,  0,  0,  0,156,  0,  0,},
				{  0,  0,  0,161,  0,148,154,  0,  0,175,  0,  0,},
				{  0,  0,  0,  0,  0,148, 89, 90, 91,  0,  0,  0,},
				{  0,  0,  0,  0,  0,148, 92, 94, 95,  0,  0,  0,},
				{ 12, 13,  0,  0,  0,148, 96, 97, 98,  0,157,  0,},
				{ 14, 15,  0,  0,  0,148,  0,  0,  0,  0,  0,164,},
				{  0,  0,  0,  0,155,148,  0,  0,  0,  0,  0,163,},
				{  0,  0,  0,  0,  0,148, 26, 27,  0,154,  0,  0,},
				{154,  0,  0,  0,175,149,147,147,147,147,147,147,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
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
				{148,  0,  0,  0, 89, 90, 91,  0,  0,  0,  0,  0,},
				{148,  0,  0,  0, 92, 94, 95,  0,  0,154,  0,  0,},
				{148,  0,  0,  0, 96, 97, 98,  0,  0,  0,  0,  0,},
				{148,164,  0,  0,  0,  0,155,  0,  0,  0,  0,175,},
				{148,  0,  0,  0,154,  0,  0,  0, 26, 27,  0,  0,},
				{148,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{149,147,147,147,147,151,  0,  0,  0,155,  0,  0,},
				{154,  0,  0,  0,  0,148,  0,  0,  0,  0,  0,  0,},
				{  0,175,  0,  0,  0,148, 16, 17,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,148, 18, 19,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,148,  0,  0,  0,  0,154,  0,},
				{  0,156,  0,  0,  0,148,  0,  0,  0,  0,  0,  0,},
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
				{155,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,158,  0,  0,155,  0,},
				{  0,  0,  0,156,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,157,  0,  0,  0,  0,  0,  0,  0,175,  0,  0,},
				{  0,  0,  0,  0,  0,  0,156,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,153,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{155,  0,  0,  0,175,  0,  0,155,  0,  0,  0,  0,},
				{  0,  0,158,  0,  0,  0,  0,  0,  0,161,162,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{152,147,147,147,147,147,147,147,147,147,147,147,},
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
				{ 19,  0,168,  0,  0,  0,  0,  0,  0,  0,  0, 18,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,153,  0,  0,  0,  0,153,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,167,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,153,  0,},
				{  0,  0,  0, 26, 27,  0,  0,  0,  0,  0,  0,  0,},
				{  0,175,  0,  0,  0,  0,  0,  0,  0,  0,  0,164,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,166,  0,  0,  0,  0,  0,},
				{147,147,147,147,147,147,147,147,147,147,147,147,},
				{  0,161,  0,  0,  0,  0,  0,  0,155,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
		[22] = {
			.bg = {{
				{5,5,5,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
				{4,4,4,},
			}},
			.fg = {{
				{ 51, 52,  0,112,113,  0,  0,  0,  1,  2,  0,  0,},
				{ 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,},
				{ 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,},
				{161,  0,  0,  0,  0,  0,  0,  0,  0,  0,155,  0,},
				{  0,  0,175,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 17,  0,  0,  0,  0,168,  0,  0,164,  0,  0, 16,},
				{ 21,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 20,},
				{ 21,  0,  0,160,  0,  0,  0,  0,155,  0,  0, 20,},
				{ 21,  0,  0,  0,162,  0,  0,  0,  0,  0,  0, 20,},
				{ 21,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 20,},
				{ 21,  0,  0,  0,  0,  0,  0,  0,175,  0,  0, 20,},
				{ 21,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 20,},
			}},
		},
		[23] = {
			.bg = {{
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
				{5,5,5,},
			}},
			.fg = {{
				{  0,  0,  0,  0,  0,  0,189,  0,  0,  0,  0,  0,},
				{ 88, 31, 88,  0,  0, 88, 34, 35, 31, 88,  0,  0,},
				{  0,  0,  0,  0,  0,  0, 36, 37,  0,  0,  0,  0,},
				{  0,  0,  0,  0,  0,  0, 57,  0,  0,  0,171,  0,},
				{ 50,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
				{ 52,178,  0,  1,  4,110,111,  0, 53, 54,  0,  0,},
				{  0, 53, 54,  3,  4,112,113,178, 55, 56,  0,  0,},
				{  0, 55, 56,  0, 49, 50,  0,174,  0,  0,  0,177,},
				{  0,  0,  0,176, 51, 52,  0,178,  0,110,111,  0,},
				{111,  0,  0,  0,  0,  0, 53, 54,  0,112,113, 49,},
				{113,169,  0,  0,  0,  0, 55, 56,  0,  0,  0, 51,},
				{ 49, 50,  0,110,111,  0,  0,  0,  0,  0,  0,  0,},
			}},
		},
	},
	.bonus_index = {
		11,
	},
	.bonus_screens = {
		[0] = {{
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
			{ 44, 44, 45, 11,  0,  0,  0,  0, 11, 46, 44, 44,},
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
};

#undef SCREEN_COUNT
#undef BONUS_COUNT
