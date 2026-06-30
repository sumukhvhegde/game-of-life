#include "input.h"

#include "config.h"

#include "raylib.h"

void input_update(Grid* grid) {
    
    Vector2 mouse = GetMousePosition();

    int col = mouse.x / CELL_SIZE;
    int row = mouse.y / CELL_SIZE;

    if (row < 0 || row >= grid->rows ||
        col < 0 || col >= grid->cols)
        return;

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        grid_set_cell(grid, row, col, true);
    } 

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        grid_set_cell(grid, row, col, false);
    }
}