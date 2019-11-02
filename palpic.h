#ifndef PALPIC_H
#define PALPIC_H

#include <stdint.h>
#include <netinet/in.h>
#include "../lib/include/endianness.h"

typedef union {
	struct colors {
#if defined(IS_LITTLE_ENDIAN) && !defined(PALPIC_OPENGL)
		uint8_t a,b,g,r;
#else
		uint8_t r,g,b,a;
#endif
	} colors;
	uint32_t val;
} prgb;

typedef struct palpic {
	char magic[4];
	uint8_t version;
	uint8_t palcount; /* 0 means 256 */
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

#define PRGB(R,G,B) ((prgb) {.colors.r = R, .colors.g = G, .colors.b = B, .colors.a = 0xff,})

#if __GNUC__ + 0 > 3
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

static inline void palpic_hostformat(struct palpic *p) {
	p->spritecount = ntohs(p->spritecount);
	p->width = ntohs(p->width);
	p->height = ntohs(p->height);
}

static inline void palpic_fileformat(struct palpic *p) {
	p->spritecount = htons(p->spritecount);
	p->width = htons(p->width);
	p->height = htons(p->height);
}

static inline prgb* palpic_getpalette(const struct palpic* p) {
	return (prgb*) (p+1);
}

#define palpic_getpalcount(P) (P->palcount ? P->palcount : 256)

static inline uint8_t* palpic_getdata(const struct palpic* p) {
	return (uint8_t*)(p + 1) + (sizeof(prgb) * palpic_getpalcount(p));
}

static inline uint32_t palpic_getfilesize(const struct palpic* p) {
	return sizeof(palpic) + (sizeof(prgb) * palpic_getpalcount(p)) + (p->width * p->height);
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

struct vo_desc {
	void *mem;
	unsigned pitch;
	unsigned width;
	unsigned height;
};

void blit_sprite(int x_pos, int y_pos, struct vo_desc *video, 
	         unsigned scale, const struct palpic* pic, uint16_t spritenum, const prgb *palette);

#pragma RcB2 DEP "palpic.c"

#endif

