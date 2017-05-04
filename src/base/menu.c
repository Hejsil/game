#include "assert.h"
#include "menu.h"

void MenuMoveUp(Menu* menu) {
    assert(menu->selected_item < menu->item_count && menu->selected_item >= 0);

    menu->selected_item--;

    if (menu->selected_item < 0)
        menu->selected_item = menu->item_count - 1;
}

void MenuMoveDown(Menu* menu) {
    assert(menu->selected_item < menu->item_count && menu->selected_item >= 0);

    menu->selected_item++;
    
    if (menu->selected_item >= menu->item_count)
        menu->selected_item = 0;
}

void UpdateMenu(Menu* menu) {
    if (IsKeyPressed(KEY_UP))
        MenuMoveUp(menu);
    if (IsKeyPressed(KEY_DOWN))
        MenuMoveDown(menu);
}

void DrawMenu(Menu* menu) {
    for (int i = 0; i < menu->item_count; i++) {
        MenuItem* menu_selected = &menu->items[i];

        Vector2 position = CalculateScreenPosition(menu->screen, menu_selected->pos);
        float height = CalculateScreenY(menu->screen, menu_selected->size);
        Vector2 actual_size = MeasureTextEx(*menu_selected->font, menu_selected->text, height, menu_selected->spacing);  

        position.x -= actual_size.x / 2;
        position.y -= height / 2;

        DrawTextEx(
            *menu_selected->font, menu_selected->text, 
            position, height, menu_selected->spacing,
            menu->selected_item == i ? menu->selected_color : menu->default_color
        );
    }
}