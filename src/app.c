#include "app.h"

#include "config.h"
#include "grid.h"
#include "renderer.h"
#include "input.h"
#include "simulation.h"

#include "raylib.h"

static Grid grid;

static bool is_running = false;

void app_init(void) {
    grid_init(&grid, GRID_ROWS, GRID_COLS);
}

void app_update(void) {
    if (IsKeyPressed(KEY_SPACE)) {
        is_running = !is_running;
    }

    if (IsKeyPressed(KEY_C)) {
        grid_clear(&grid);
        simulation_reset_generation();
    }

    if (IsKeyPressed(KEY_R)) {
        grid_randomize(&grid);
        simulation_reset_generation();
    }

    if (IsKeyPressed(KEY_G)) {
        renderer_toggle_grid();
    }

    input_update(&grid);

    if (is_running) {
        simulation_step(&grid);
    }
}

void app_draw(void) {
    renderer_draw(&grid);
}

void app_shutdown(void) {
    grid_destroy(&grid);
}