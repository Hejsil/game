#include "raylib.h"
#include "menu.h"
#include "screen.h"

#define MENUSIZE 4

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Screen screen = {
        { 1600, 900 },
        { 16, 9 }
    };
    
    InitWindow(screen.pixel_size.x, screen.pixel_size.y, "Random game");
    SetTargetFPS(240);

    SpriteFont font = GetDefaultFont();     

    MenuItem items[MENUSIZE] = {
        { &font, "New Game",  0.4, 2, { 0, -1 } },
        { &font, "Load Game", 0.4, 2, { 0,  0 } },
        { &font, "Options",   0.4, 2, { 0,  1 } },
        { &font, "Exit",      0.4, 2, { 0,  2 } }
    };

    Menu menu = { 
        &screen, 0, MENUSIZE, LIGHTGRAY, GREEN, items
    };

    Camera2D camera = {
        { screen.pixel_size.x / 2, screen.pixel_size.y / 2 },
        { 0, 0 },
        0, 1
    };
    
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateMenu(&menu);




        // Calculate camera position
        //MenuItem* selected_item = &menu.items[menu.selected_item];

        //camera.target = CalculateScreenPosition(&screen, selected_item->pos);

        // Center the offset based on the screens size, and the cameras target
        camera.offset.x = screen.pixel_size.x / 2 - camera.target.x; 
        camera.offset.y = screen.pixel_size.y / 2 - camera.target.y;
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            Begin2dMode(camera); 
                DrawMenu(&menu);
            End2dMode();  


            DrawFPS(10, 10);
        
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