#ifndef SCEENS_H
#define SCEENS_H

#include "raylib.h"
#include "menu.h"

void InitializeMainMenuSceen(Menu* main_menu, Camera2D* camera, Options options);
void UpdateMainMenuSceen(Menu* main_menu);
void DrawMainMenuSceen(Menu main_menu, Options options);

#endif /* SCEENS_H */