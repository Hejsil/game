#ifndef SCREENS_H
#define SCREENS_H

#include "raylib.h"
#include "menu.h"
#include "game_state.h"

// Main menu
void InitializeMainMenuScreen(GameState* game_state);
void UpdateMainMenuScreen(GameState* game_state);
void DrawMainMenuScreen(GameState* game_state);

// Options menu
void InitializeOptionMenuScreen(GameState* game_state);
void UpdateOptionMenuScreen(GameState* game_state);
void DrawOptionMenuScreen(GameState* game_state);

// Load menu
void InitializeLoadMenuScreen(GameState* game_state);
void UpdateLoadMenuScreen(GameState* game_state);
void DrawLoadMenuScreen(GameState* game_state);

#endif /* SCREENS_H */