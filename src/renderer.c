#include "renderer.h"

#include "config.h"

#include "raylib.h"

void renderer_draw(const Grid *grid) {
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->cols; col++) {
            Rectangle cell = {
                col * CELL_SIZE,
                row * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE
            };
#if SHOW_GRID
            DrawRectangleLinesEx(cell, 0.5f, DARKGRAY);
#endif
            if (grid_get_cell(grid, row, col)) {
                DrawRectangleRec(cell, WHITE);
            }
        }
    }
}