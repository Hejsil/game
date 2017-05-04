#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "screen.h"

typedef struct {
    SpriteFont* font;
    char* text;
    float size;
    int spacing;
    Vector2 pos;
} MenuItem;

typedef struct {
    Screen* screen;

    int selected_item, item_count;
    Color default_color, selected_color;

    MenuItem* items;
} Menu;

void MenuMoveUp(Menu* menu);
void MenuMoveDown(Menu* menu);
void UpdateMenu(Menu* menu);
void DrawMenu(Menu* menu);

#endif /* MENU_H */