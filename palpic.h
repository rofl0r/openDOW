#ifndef PALPIC_H
#define PALPIC_H

#include <stdint.h>
#include <netinet/in.h>
#include "../lib/include/endianness.h"

typedef union {
	struct colors {
#ifdef IS_LITTLE_ENDIAN
		uint8_t a;
		uint8_t b;
		uint8_t g;
		uint8_t r;
#else
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
#endif
	} colors;
	uint32_t val;
} prgb;

typedef struct palpic {
	char magic[4];
	uint8_t version;
	uint8_t palcount;
	uint8_t reserved1;
	uint8_t reserved2;
	uint16_t width;
	uint16_t height;
	uint32_t padding;
	//prgb palette[];
	//uint8_t data[];
} palpic;

#define palpic_empty { {'p', 'P', 'i', 'C', }, 1, 0, 0, 0, 0, 0, 0 }

#ifdef IS_LITTLE_ENDIAN
#define RGB(x,y,z) ((rgb_t) {{0, z, y, x}})
#else
#define RGB(x,y,z) ((rgb_t) {{x, y, z, 0}})
#endif

#define PRGB(R,G,B) ((prgb) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0})


static inline void palpic_hostformat(struct palpic *p) {
	p->width = ntohs(p->width);
	p->height = ntohs(p->width);
}

static inline void palpic_fileformat(struct palpic *p) {
	p->width = htons(p->width);
	p->height = htons(p->width);
}

static inline prgb* palpic_getpalette(struct palpic* p) {
	return (prgb*) (p+1);
}

static inline uint8_t* palpic_getdata(struct palpic* p) {
	return (uint8_t*)(p + 1) + (sizeof(prgb) * p->palcount);
}

static uint32_t palpic_getfilesize(struct palpic* p) {
	return sizeof(palpic) + (sizeof(prgb) * p->palcount) + (p->width * p->height);
}

#endif

