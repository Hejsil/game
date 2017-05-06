#include "raylib.h"
#include "menu.h"
#include "screens.h"
#include "game_state.h"

#define MAINMENUSIZE 4
#define OPTIONMENUSIZE 1
#define SIZEOPTIONSSIZE 18

int main()
{
    //--------------------------------------------------------------------------------------
    // Initialization
    //--------------------------------------------------------------------------------------

    // Initialize game_state
    GameState game_state;
    game_state.current_screen = MAINMENU;

    // Initialize resolution options
    Vector2 size_options[SIZEOPTIONSSIZE] = {
        { 640 , 360  },
        { 720 , 405  },
        { 854 , 480  },
        { 960 , 540  },
        { 1024, 576  },
        { 1280, 720  },
        { 1366, 768  },
        { 1600, 900  },
        { 1920, 1080 },
        { 2048, 1152 },
        { 2560, 1440 },
        { 2880, 1620 },
        { 3200, 1800 },
        { 3840, 2160 },
        { 4096, 2304 },
        { 5120, 2880 },
        { 7680, 4320 },
        { 8192, 4608 }
    };


    // Initialize window size and scaling
    game_state.size_options = size_options;
    game_state.size_options_count = sizeof(size_options) / sizeof(Vector2);
    game_state.base_size = (Vector2){ 1920, 1080 };

    SetWindowsSize(&game_state, 7);
    
    // We init window before getting the font, as we get a an unusable font, if we do it after
    InitWindow(
        game_state.window_size.x, 
        game_state.window_size.y,
        "Random game"
    );

    SetTargetFPS(240);

    // Locals
    SpriteFont font = GetDefaultFont();
    
    // Initialize menus
    MenuItem main_menu_items[MAINMENUSIZE] = {
        { &font, "New Game",  45, 2, { 0, -100 } },
        { &font, "Load Game", 45, 2, { 0,  000 } },
        { &font, "Options",   45, 2, { 0,  100 } },
        { &font, "Exit",      45, 2, { 0,  200 } }
    };

    game_state.main_menu = (Menu){ 
        0, sizeof(main_menu_items) / sizeof(MenuItem), LIGHTGRAY, GREEN, main_menu_items
    };

    MenuItem option_menu_items[OPTIONMENUSIZE] = {
        { &font, "Resolution",  45, 2, { 0, -100 } }
    };

    game_state.option_menu = (Menu){
        0, sizeof(option_menu_items) / sizeof(MenuItem), LIGHTGRAY, GREEN, option_menu_items
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
                UpdateOptionMenuScreen(&game_state);
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
                        DrawOptionMenuScreen(&game_state);
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