#pragma once
#include "base_menu.h"

typedef enum {
    MAIN_MENU,
    OPTIONS_MENU,
    LOAD_MENU,
    GAME
} Screen;

typedef struct {
    Vector2 position;
    Vector2 size;
} Player;

typedef struct {
    Player player;
} GameLevel;

typedef struct {
    // Screen state
    Screen current_screen;

    // Window state
    Vector2 base_size;
    float zoom;

    Vector2* size_options;
    int size_options_count, window_size_index;
    Vector2 window_size;

    Camera2D camera;

    // Menu state
    Menu main_menu, option_menu;

    // Game level state
    GameLevel current_level;
} GameState;

void SetWindowsSize(GameState* game_state, int window_size_index);
void ResetCamera(GameState* game_state);

void InitGame(GameState* game_state);
void UpdateGame(GameState* game_state);
void DrawGame(GameState* game_state);