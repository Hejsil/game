#include "screens.h"

void InitializeMainMenuScreen(GameState* game_state) {
    Camera2D* camera = &game_state->camera;
    Options* options = &game_state->options;

    camera->target = (Vector2){ 0, 0 }; 
    camera->rotation = 0;
    camera->zoom = 1;

    camera->offset.x = options->pixel_size.x / 2 - camera->target.x; 
    camera->offset.y = options->pixel_size.y / 2 - camera->target.y;
}

void UpdateMainMenuScreen(GameState* game_state) {
    Menu* main_menu = &game_state->main_menu;

    if (IsKeyPressed(KEY_ENTER)) {
        switch (main_menu->selected_item) {
            case 0: // New game
                break;
            case 1: // Load Game
                break;
            case 2: // Options
                game_state->current_screen = OPTIONSMENU;
                break;
            case 3: // Exit
                break;
        }
    }

    UpdateMenu(&game_state->main_menu);
}

void DrawMainMenuScreen(GameState* game_state) {
    DrawMenu(game_state->main_menu, game_state->options);
}