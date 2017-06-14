#include "screens.h"

void DefaultScreenInitializer(GameState* game_state) {
    Camera2D* camera = &game_state->camera;

    camera->target = (Vector2){ 0, 0 }; 
    camera->rotation = 0;
    camera->zoom = game_state->zoom;

    camera->offset.x = game_state->window_size.x / 2 - camera->target.x; 
    camera->offset.y = game_state->window_size.y / 2 - camera->target.y;
}

// --------------
// Main menu
// --------------
void InitializeMainMenuScreen(GameState* game_state) {
    DefaultScreenInitializer(game_state);
}

void UpdateMainMenuScreen(GameState* game_state) {
    Menu* main_menu = &game_state->main_menu;

    if (IsKeyPressed(KEY_ENTER)) {
        switch (main_menu->selected_item) {
            case 0: // New game
                break;
            case 1: // Load Game
                InitializeLoadMenuScreen(game_state);
                game_state->current_screen = LOAD_MENU;
                break;
            case 2: // Options
                InitializeOptionMenuScreen(game_state);
                game_state->current_screen = OPTIONS_MENU;
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

// --------------
// Options menu
// --------------
void InitializeOptionMenuScreen(GameState* game_state) {
    DefaultScreenInitializer(game_state);
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

// --------------
// Load menu
// --------------
void InitializeLoadMenuScreen(GameState* game_state) {
    DefaultScreenInitializer(game_state);
}

void UpdateLoadMenuScreen(GameState* game_state) {
    //UpdateMenu(&game_state->main_menu);
}

void DrawLoadMenuScreen(GameState* game_state) {
    //DrawMenu(game_state->main_menu);
}