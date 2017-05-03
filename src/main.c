#include "raylib.h"
#include "menu.h"

#define MENUSIZE 4

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 1600;
    const int screen_height = 900;
    
    Screen screen = {
        { screen_width, screen_height },
        { 16, 9 }
    };

    MenuItem items[MENUSIZE] = {
        { "Test1", { 1, 1 }, 20 },
        { "Test2", { 1, 2 }, 20 },
        { "Test3", { 1, 3 }, 20 },
        { "Test4", { 1, 4 }, 20 },
    };

    Menu menu = { 
        &screen, 0, MENUSIZE, LIGHTGRAY, GREEN, items
    };

    InitWindow(screen.pixel_size.x, screen.pixel_size.y, "Random game");
    
    SetTargetFPS(240);
    
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateMenu(&menu);
            
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);

            DrawMenu(&menu);
        
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