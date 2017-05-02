#ifndef MENU_H
#define MENU_H

#include "raylib.h"

#define MENUSIZE 2

typedef struct {
    char* text;
    int pos_x, pos_y, font_size;
} MenuItem;

typedef struct {
    int selected_item;
    Color default_color, selected_color;
    MenuItem items[MENUSIZE];
} Menu;

void MenuMoveUp(Menu* menu);
void MenuMoveDown(Menu* menu);

#endif /* MENU_H */