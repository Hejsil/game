#ifndef SCREEN_H
#define SCREEN_H

#include "raylib.h"

typedef struct {
    Vector2 pixel_size;
    Vector2 unit_size;
} Screen;

Vector2 CalculateScreenPosition(Screen* screen, Vector2 unit_pos);
float CalculateScreenX(Screen* screen, float unit_x);
float CalculateScreenY(Screen* screen, float unit_y);

#endif /* SCREEN_H */