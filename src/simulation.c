#include "simulation.h"

static unsigned long generation = 0;

static int count_neighbors(const Grid* grid, int row, int col) {
    int count = 0;
    
    for (int y = row - 1; y <= row + 1; ++y) {
        for (int x = col - 1; x <= col + 1; ++x) {
            if (y == row && x == col)
                continue;
            

            if (y < 0 || y >= grid->rows ||
                x < 0 || x >= grid->cols)
                continue;

            if (grid_get_cell(grid, y, x))
                count++;
        }
    }

    return count;
}

void simulation_step(Grid* grid) {
    for (int row = 0; row < grid->rows; ++row) {
        for (int col = 0; col < grid->cols; ++col) {
            bool alive = grid_get_cell(grid, row, col);

            int neighbors = count_neighbors(grid, row, col);

            bool next_alive = false;

            if (alive) {
                next_alive = (neighbors == 2 || neighbors == 3);
            } else {
                next_alive = (neighbors == 3);
            }

            grid_set_next_cell(grid, row, col, next_alive);
        }
    }

    grid_swap_buffers(grid);

    generation++;
}

unsigned long simulation_get_generation(void) {
    return generation;
}

void simulation_reset_generation(void) {
    generation = 0;
}