#include "sceens.h"

void InitializeMainMenuSceen(Menu* main_menu, Camera2D* camera, Options options) {
    camera->target = (Vector2){ 0, 0 }; 
    camera->rotation = 0;
    camera->zoom = 1;

    camera->offset.x = options.pixel_size.x / 2 - camera->target.x; 
    camera->offset.y = options.pixel_size.y / 2 - camera->target.y;
}

void UpdateMainMenuSceen(Menu* main_menu) {
    UpdateMenu(main_menu);
}

void DrawMainMenuSceen(Menu main_menu, Options options) {
    DrawMenu(main_menu, options);
}