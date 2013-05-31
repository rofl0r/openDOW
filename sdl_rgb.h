#ifndef SDL_RGB_H
#define SDL_RGB_H

#include "../lib/include/endianness.h"

typedef union {
	struct {
#ifdef IS_LITTLE_ENDIAN
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
#else
		unsigned char a;
		unsigned char r;
		unsigned char g;
		unsigned char b;
#endif
	} colors;
	uint32_t asInt;
} sdl_rgb_t;

#ifndef IN_KDEVELOP_PARSER

#define SRGB(R, G, B) ((sdl_rgb_t) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0})
#define SRGB_BLUE SRGB(0x0,0x0,0xFF)

//#define SRGB2(R, G, B) ((union { struct {uint8_t b;uint8_t g;uint8_t r;uint8_t a;} colors; uint32_t asInt; }) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0})
#define SRGB_WHITE SRGB(0xFF,0xFF,0xFF)
#define SRGB_BLACK SRGB(0x00,0x00,0x00)

#endif

#if __GNUC__ + 0 > 3
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#endif
