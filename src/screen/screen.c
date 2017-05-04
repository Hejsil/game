#include "screen.h"

Vector2 CalculateScreenPosition(Screen* screen, Vector2 unit_pos) {
    Vector2 result = {
        CalculateScreenX(screen, unit_pos.x),
        CalculateScreenY(screen, unit_pos.y)
    };

    return result;    
}

float CalculateScreenX(Screen* screen, float unit_x) {
    float pixels_per_unit = screen->pixel_size.x / screen->unit_size.x;

    return unit_x * pixels_per_unit;    
}

float CalculateScreenY(Screen* screen, float unit_y) {
    float pixels_per_unit = screen->pixel_size.y / screen->unit_size.y;
    
    return unit_y * pixels_per_unit;    
}