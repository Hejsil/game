#ifndef OPTIONS_H
#define OPTIONS_H

#include "raylib.h"

typedef struct {
    Vector2 pixel_size;
    Vector2 unit_size;
} Options;

Vector2 CalculateScreenPosition(Options options, Vector2 unit_pos);
float CalculateScreenX(Options options, float unit_x);
float CalculateScreenY(Options options, float unit_y);

#endif /* OPTIONS_H */