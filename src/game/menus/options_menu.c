#include "options_menu.h"
#include "base_menu.h"
#include "raylib.h"

void InitializeOptionMenuScreen(GameState* game_state) {
    ResetCamera(game_state);
    game_state->current_screen = OPTIONS_MENU;
}

void UpdateOptionMenuScreen(GameState* game_state) {
    Menu* option_menu = &game_state->option_menu;

    switch (option_menu->selected_item) {
        case 0: // Resolution
            if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT)) {
                int new_index = game_state->window_size_index;

                new_index += IsKeyPressed(KEY_RIGHT) ? 1 : -1;

                if (new_index < 0) {
                    new_index = game_state->size_options_count - 1;
                } else if (game_state->size_options_count <= new_index) {
                    new_index = 0;
                }

                // TODO: Figure out how to actually resize the window
                //SetWindowsSize(game_state, new_index);
                CloseWindow();
            }

            break;
    }

    UpdateMenu(option_menu);
}

void DrawOptionMenuScreen(GameState* game_state) {
    DrawMenu(game_state->option_menu);
}