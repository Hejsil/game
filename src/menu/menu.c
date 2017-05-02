#include "assert.h"
#include "menu.h"

void MenuMoveUp(Menu* menu) {
    assert(menu->selected_item < MENUSIZE);
    assert(menu->selected_item >= 0);

    menu->selected_item--;

    if (menu->selected_item < 0)
        menu->selected_item = MENUSIZE - 1;
}

void MenuMoveDown(Menu* menu) {
    assert(menu->selected_item < MENUSIZE);
    assert(menu->selected_item >= 0);

    menu->selected_item++;
    
    if (menu->selected_item >= MENUSIZE)
        menu->selected_item = 0;
}