#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "menu.h"

typedef enum {
    MAIN_MENU,
    OPTIONS_MENU,
    LOAD_MENU
} Screen;

typedef struct {
    // Window state
    Vector2 base_size;
    float zoom;

    Vector2* size_options;
    int size_options_count, window_size_index;
    Vector2 window_size;

    // Menu state
    Menu main_menu, option_menu;
    Camera2D camera;
    Screen current_screen;
} GameState;

void SetWindowsSize(GameState* game_state, int window_size_index);

#endif /* GAME_STATE_H */