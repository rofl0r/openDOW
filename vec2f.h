#ifndef VEC2F_H
#define VEC2F_H

#include <math.h>

typedef struct { float x, y; } vec2f;

#define VEC(a, b) (vec2f) { .x = a, .y = b }

static inline vec2f velocity(vec2f* from, vec2f* to) {
	return VEC(to->x - from->x, to->y - from->y);
}

static inline float veclength(vec2f *v) {
	return sqrtf((v->x * v->x) + (v->y * v->y));
}

static inline float vecdist(vec2f* a, vec2f* b) {
	vec2f vel = velocity(a, b);
	return veclength(&vel);
}

#endif
