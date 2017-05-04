#include "options.h"

Vector2 CalculateScreenPosition(Options options, Vector2 unit_pos) {
    Vector2 result = {
        CalculateScreenX(options, unit_pos.x),
        CalculateScreenY(options, unit_pos.y)
    };

    return result;    
}

float CalculateScreenX(Options options, float unit_x) {
    float pixels_per_unit = options.pixel_size.x / options.unit_size.x;

    return unit_x * pixels_per_unit;    
}

float CalculateScreenY(Options options, float unit_y) {
    float pixels_per_unit = options.pixel_size.y / options.unit_size.y;
    
    return unit_y * pixels_per_unit;    
}