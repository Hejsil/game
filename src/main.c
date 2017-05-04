#include "raylib.h"
#include "menu.h"

#define MENUSIZE 4

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    Screen screen = {
        { screen_width, screen_height },
        { 8, 6 }
    };
    
    InitWindow(screen.pixel_size.x, screen.pixel_size.y, "Random game");
    SetTargetFPS(240);

    SpriteFont font = GetDefaultFont();     

    MenuItem items[MENUSIZE] = {
        { "Test1", 1, { 0, -1 }, &font },
        { "Test2", 1, { 0, 0 }, &font },
        { "Test3", 1, { 0, 1 }, &font },
        { "Test4", 1, { 0, 2 }, &font },
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
        //int text_width = MeasureText(selected_item->text, selected_item->font_size);
        camera.target.x = 0;
        camera.target.y = 0;

        camera.offset.x = screen.pixel_size.x / 2 - camera.target.x; 
        camera.offset.y = screen.pixel_size.y / 2 - camera.target.y;
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            Begin2dMode(camera); 

                DrawMenu(&menu);

                DrawRectangle(camera.target.x, -500, 1, screen.pixel_size.y * 4, GREEN);
                DrawRectangle(-500, camera.target.y, screen.pixel_size.x * 4, 1, GREEN);
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