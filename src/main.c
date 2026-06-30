#include "raylib.h"

#include "config.h"
#include "app.h"

#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);

    app_init();

    while (!WindowShouldClose()) {
        app_update();

        BeginDrawing();

        ClearBackground(BLACK);

        app_draw();

        EndDrawing();
    }

    app_shutdown();

    CloseWindow();
    
    return 0;
}