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

void DrawMenu(Menu menu) {
    for (int i = 0; i < menu.item_count; i++) {
        MenuItem menu_selected = menu.items[i];

        Vector2 text_size = MeasureTextEx(*menu_selected.font, menu_selected.text, menu_selected.font_size, menu_selected.spacing);  
        Vector2 position = menu_selected.position;

        position.x -= text_size.x / 2;
        position.y -= text_size.y / 2;

        DrawTextEx(
            *menu_selected.font, menu_selected.text, 
            position, menu_selected.font_size, menu_selected.spacing,
            menu.selected_item == i ? menu.selected_color : menu.default_color
        );
    }
}