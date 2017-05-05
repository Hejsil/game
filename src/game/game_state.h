#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "menu.h"
#include "screens.h"

typedef struct {
    Menu main_menu, option_menu;
    Camera2D camera;
    Options options;
    Screen current_screen;
} GameState;


#endif /* GAME_STATE_H */