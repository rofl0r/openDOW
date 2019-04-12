#ifndef FONT_H
#define FONT_H
#include "palpic.h"
void font_print(int x, int y, const char *str, size_t len, unsigned scale, prgb color);
#pragma RcB2 DEP "font.c"
#endif
