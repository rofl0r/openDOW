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
	uint16_t spritecount;
	uint16_t width;
	uint16_t height;
	uint16_t flags;
	uint16_t padding;
	//prgb palette[];
	//uint8_t data[];
} palpic;

enum palpic_flags {
	PPF_TRANSPARENT = 1,
};

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

static inline prgb* palpic_getpalette(const struct palpic* p) {
	return (prgb*) (p+1);
}

static inline uint8_t* palpic_getdata(const struct palpic* p) {
	return (uint8_t*)(p + 1) + (sizeof(prgb) * p->palcount);
}

static inline uint32_t palpic_getfilesize(const struct palpic* p) {
	return sizeof(palpic) + (sizeof(prgb) * p->palcount) + (p->width * p->height);
}

static inline unsigned palpic_getspriteheight(const struct palpic* p) {
	return p->height / p->spritecount;
}

static inline unsigned palpic_getspritewidth(const struct palpic* p) {
	return p->width;
}

static inline unsigned palpic_getspritecount(const struct palpic* p) {
	return p->spritecount;
}

static inline uint8_t* palpic_getspritedata(const struct palpic* p, uint16_t spritenum) {
	return palpic_getdata(p) + (spritenum * palpic_getspriteheight(p) * palpic_getspritewidth(p));
}

void blit_sprite(int x_pos, int y_pos, void *video_mem, unsigned videomem_pitch, 
	         unsigned scale, const struct palpic* pic, uint16_t spritenum, const prgb *palette);

//RcB: DEP "palpic.c"

#endif

