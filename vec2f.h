#ifndef VEC2F_H
#define VEC2F_H

#include <math.h>

typedef struct { float x, y; } vec2f;

#define VEC(a, b) (vec2f) { .x = a, .y = b }

static inline vec2f velocity(const vec2f* from, const vec2f* to) {
	return VEC(to->x - from->x, to->y - from->y);
}

static inline float veclength(const vec2f *v) {
	return sqrtf((v->x * v->x) + (v->y * v->y));
}

static inline float vecdist(const vec2f* a, const vec2f* b) {
	vec2f vel = velocity(a, b);
	return veclength(&vel);
}

static inline vec2f vecadd(const vec2f* a, const vec2f* b) {
	return VEC(a->x + b->x, a->y + b->y);
}

static inline vec2f vecsub(const vec2f* a, const vec2f* b) {
	return VEC(a->x - b->x, a->y - b->y);
}

#endif
