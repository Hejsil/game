#include "game_state.h"
#include "raylib.h"
#include "assert.h"

void SetWindowsSize(GameState* game_state, int window_size_index) {
    assert(window_size_index >= 0 && game_state->size_options_count > window_size_index);

    game_state->window_size_index = window_size_index; // 1600, 900
    game_state->window_size = game_state->size_options[window_size_index];
    game_state->zoom = game_state->window_size.x / game_state->base_size.x;
    
    Camera2D* camera = &game_state->camera;
    camera->offset.x = game_state->window_size.x / 2 - camera->target.x;
    camera->offset.y = game_state->window_size.y / 2 - camera->target.y;
}


void ResetCamera(GameState* game_state) {
    Camera2D* camera = &game_state->camera;

    camera->target = (Vector2){ 0, 0 }; 
    camera->rotation = 0;
    camera->zoom = game_state->zoom;

    camera->offset.x = game_state->window_size.x / 2 - camera->target.x; 
    camera->offset.y = game_state->window_size.y / 2 - camera->target.y;
}


void InitGame(GameState* game_state) {
    ResetCamera(game_state);
    game_state->current_screen = GAME;
    game_state->current_level = (GameLevel){
        (Player){ (Vector2){ 20, 20 }, (Vector2){ 20, 20 } }
    };
}

void UpdateGame(GameState* game_state) {
    Player* player = &game_state->current_level.player;
    float move = 500 * GetFramemove();

    if (IsKeyDown(KEY_UP)) {
        player->position.y -= move;
    }

    if (IsKeyDown(KEY_DOWN)) {
        player->position.y += move;
    }
    
    if (IsKeyDown(KEY_LEFT)) {
        player->position.x -= move;
    }
    
    if (IsKeyDown(KEY_RIGHT)) {
        player->position.x += move;
    }
}

void DrawGame(GameState* game_state) {
    Player* player = &game_state->current_level.player;
    DrawRectangle(player->position.x, player->position.y, player->size.x, player->size.y, GREEN);
}