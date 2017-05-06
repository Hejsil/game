#include "game_state.h"
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