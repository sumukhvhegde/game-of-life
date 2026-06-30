#include "grid.h"

#include <stdlib.h>
#include <string.h>

static int grid_index(const Grid* grid, int row, int col) {
    return row * grid->cols + col;
}

void grid_init(Grid* grid, int rows, int cols) {
    grid->rows = rows;
    grid->cols = cols;

    int total_cells = rows * cols;

    grid->current = calloc(total_cells, sizeof(bool));
    grid->next = calloc(total_cells, sizeof(bool));
}

void grid_clear(Grid* grid) {
    int total_cells = grid->rows * grid->cols;

    memset(grid->current, 0, sizeof(bool) * total_cells);
    memset(grid->next, 0, sizeof(bool) * total_cells);
}

void grid_destroy(Grid* grid) {
    free(grid->current);
    free(grid->next);

    grid->current = NULL;
    grid->next = NULL;
}

bool grid_get_cell(const Grid* grid, int row, int col) {
    int index = grid_index(grid, row, col);

    return grid->current[index];
}

void grid_set_cell(Grid* grid, int row, int col, bool alive) {
    int index = grid_index(grid, row, col);

    grid->current[index] = alive;
}

void grid_swap_buffers(Grid* grid) {
    bool* temp = grid->current;
    grid->current = grid->next;
    grid->next = temp;
}

void grid_set_next_cell(Grid* grid, int row, int col, bool alive) {
    int index = grid_index(grid, row, col);
    grid->next[index] = alive;
}

void grid_randomize(Grid* grid) {
    int total_cells = grid->rows * grid->cols;

    for (int i = 0; i < total_cells; i++) {
        grid->current[i] = rand() % 2;
    }

    memset(grid->next, 0, total_cells * sizeof(bool));
}