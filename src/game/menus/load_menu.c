#include "load_menu.h"

void InitializeLoadMenuScreen(GameState* game_state) {
    ResetCamera(game_state);
    game_state->current_screen = LOAD_MENU;
}

void UpdateLoadMenuScreen(GameState* game_state) {
    //UpdateMenu(&game_state->main_menu);
}

void DrawLoadMenuScreen(GameState* game_state) {
    //DrawMenu(game_state->main_menu);
}