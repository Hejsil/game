#include "raylib.h"
#include "menu.h"
#include "options.h"
#include "screens.h"
#include "game_state.h"

#define MAINMENUSIZE 4

int main()
{
    //--------------------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------------------

    // Initialize game_state
    GameState game_state;
    game_state.current_screen = MAINMENU;

    game_state.options = (Options){
        { 800, 450 },
        { 16, 9 }
    };
    
    // We init window before getting the font, as we get a an unusable font, if we do it after
    InitWindow(
        game_state.options.pixel_size.x, 
        game_state.options.pixel_size.y, 
        "Random game"
    );

    SetTargetFPS(240);

    // Locals
    SpriteFont font = GetDefaultFont();
    
    // Initialize menus
    MenuItem main_menu_items[MAINMENUSIZE] = {
        { &font, "New Game",  0.4, 2, { 0, -1 } },
        { &font, "Load Game", 0.4, 2, { 0,  0 } },
        { &font, "Options",   0.4, 2, { 0,  1 } },
        { &font, "Exit",      0.4, 2, { 0,  2 } }
    };

    game_state.main_menu = (Menu){ 
        0, sizeof(main_menu_items), LIGHTGRAY, GREEN, main_menu_items
    };

    MenuItem option_menu_items[MAINMENUSIZE] = {
        { &font, "New Game",  0.4, 2, { 0, -1 } },
        { &font, "Load Game", 0.4, 2, { 0,  0 } },
        { &font, "Options",   0.4, 2, { 0,  1 } },
        { &font, "Exit",      0.4, 2, { 0,  2 } }
    };

    game_state.option_menu = (Menu){
        0, sizeof(option_menu_items), LIGHTGRAY, GREEN, option_menu_items
    };


    InitializeMainMenuScreen(&game_state);

    //--------------------------------------------------------------------------------------
    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose()) {
        //--------------------------------------------------------------------------------------
        // Update
        //--------------------------------------------------------------------------------------
        switch (game_state.current_screen) {
            case MAINMENU:
                UpdateMainMenuScreen(&game_state);
                break;
            case OPTIONSMENU:
                break;
        }
        

        
        //--------------------------------------------------------------------------------------
        // Draw
        //--------------------------------------------------------------------------------------
        BeginDrawing(); {
            ClearBackground(RAYWHITE);

            Begin2dMode(game_state.camera); {

                switch (game_state.current_screen) {
                    case MAINMENU:
                        DrawMainMenuScreen(&game_state);
                        break;
                    case OPTIONSMENU:
                        break;
                }

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