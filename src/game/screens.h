#ifndef SCREENS_H
#define SCREENS_H

typedef enum {
    MAINMENU,
    OPTIONSMENU
} Screen;

#include "raylib.h"
#include "menu.h"
#include "game_state.h"

void InitializeMainMenuScreen(GameState* game_state);
void UpdateMainMenuScreen(GameState* game_state);
void DrawMainMenuScreen(GameState* game_state);

#endif /* SCREENS_H */