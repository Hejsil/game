#ifndef SCREEN_H
#define SCREEN_H

#include "raylib.h"

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pixel_size;
    Vector2 unit_size;
} Screen;

Point CalculateScreenPosition(Screen* screen, Vector2 unit_pos);

#endif /* SCREEN_H */