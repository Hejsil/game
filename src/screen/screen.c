#include "screen.h"

Point CalculateScreenPosition(Screen* screen, Vector2 unit_pos) {
    Vector2 pixels_per_unit = {
        screen->pixel_size.x / screen->unit_size.x,
        screen->pixel_size.y / screen->unit_size.y
    };

    Point result = {
        (int)(unit_pos.x * pixels_per_unit.x),
        (int)(unit_pos.y * pixels_per_unit.y)
    };

    return result;    
}