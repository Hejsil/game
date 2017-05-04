#include "raylib.h"
#include "menu.h"
#include "options.h"
#include "sceens.h"

#define MENUSIZE 4

int main()
{
    //--------------------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------------------
    Options options = {
        { 1600, 900 },
        { 16, 9 }
    };
    
    // We init window before getting the font, as we get a an unusable font, if we do it after
    InitWindow(options.pixel_size.x, options.pixel_size.y, "Random game");
    SetTargetFPS(240);

    // Locals
    SpriteFont font = GetDefaultFont();
    Camera2D camera;
    
    // Initialize menus
    MenuItem main_menu_items[MENUSIZE] = {
        { &font, "New Game",  0.4, 2, { 0, -1 } },
        { &font, "Load Game", 0.4, 2, { 0,  0 } },
        { &font, "Options",   0.4, 2, { 0,  1 } },
        { &font, "Exit",      0.4, 2, { 0,  2 } }
    };

    Menu main_menu = { 
        0, MENUSIZE, LIGHTGRAY, GREEN, main_menu_items
    };

    MenuItem option_menu_items[MENUSIZE] = {
        { &font, "New Game",  0.4, 2, { 0, -1 } },
        { &font, "Load Game", 0.4, 2, { 0,  0 } },
        { &font, "Options",   0.4, 2, { 0,  1 } },
        { &font, "Exit",      0.4, 2, { 0,  2 } }
    };

    Menu option_menu = {
        0, MENUSIZE, LIGHTGRAY, GREEN, option_menu_items
    };


    InitializeMainMenuSceen(&main_menu, &camera, options);

    //--------------------------------------------------------------------------------------
    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose()) {
        //--------------------------------------------------------------------------------------
        // Update
        //--------------------------------------------------------------------------------------
        UpdateMainMenuSceen(&main_menu);

        
        //--------------------------------------------------------------------------------------
        // Draw
        //--------------------------------------------------------------------------------------
        BeginDrawing(); {
            ClearBackground(RAYWHITE);

            Begin2dMode(camera); {
                DrawMainMenuSceen(main_menu, options);

            } End2dMode();  


            DrawFPS(10, 10);

        } EndDrawing();
    }

    //--------------------------------------------------------------------------------------
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); 
    
    return 0;
}