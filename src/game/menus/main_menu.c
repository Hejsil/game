#include "main_menu.h"
#include "base_menu.h"
#include "load_menu.h"
#include "options_menu.h"
#include "raylib.h"

void InitializeMainMenuScreen(GameState* game_state) {
    ResetCamera(game_state);
}

void UpdateMainMenuScreen(GameState* game_state) {
    Menu* main_menu = &game_state->main_menu;

    if (IsKeyPressed(KEY_ENTER)) {
        switch (main_menu->selected_item) {
            case 0: // New game
                InitGame(game_state);
                break;
            case 1: // Load Game
                InitializeLoadMenuScreen(game_state);
                break;
            case 2: // Options
                InitializeOptionMenuScreen(game_state);
                break;
            case 3: // Exit
                CloseWindow();
                break;
        }
    }

    UpdateMenu(&game_state->main_menu);
}

void DrawMainMenuScreen(GameState* game_state) {
    DrawMenu(game_state->main_menu);
}