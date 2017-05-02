/*******************************************************************************************
*
*   raylib - Template for basic test
*
*   <Test description>
*
*   This example has been created using raylib v1.2 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (Ray San - raysan@raysanweb.com)
*
********************************************************************************************/

#include "raylib.h"
#include "menu.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Menu menu = (Menu){ 
        0, LIGHTGRAY, GREEN,

        (MenuItem){ "Test1", 20, 20, 20 },
        (MenuItem){ "Test2", 60, 60, 20 }
    };

    const int screen_width = 800;
    const int screen_height = 450;
    
    InitWindow(screen_width, screen_height, "raylib basic test - <test description>");
    
    // TODO: Initialize all required variables and load all required data here!
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_UP))
            MenuMoveUp(&menu);
        if (IsKeyPressed(KEY_DOWN))
            MenuMoveDown(&menu);
            
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            for (int i = 0; i < MENUSIZE; i++) {
                MenuItem* menu_selected = &menu.items[i];

                DrawText(
                    menu_selected->text, menu_selected->pos_x, menu_selected->pos_y, 
                    menu_selected->font_size, menu.selected_item == i ? menu.selected_color : menu.default_color
                );
            }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    // TODO: Unload all loaded data (textures, fonts, audio) here!
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    
    return 0;
}