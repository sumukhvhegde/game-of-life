#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

typedef struct {
    bool* current;
    bool* next;

    int rows;
    int cols;
} Grid;

void grid_init(Grid* grid, int rows, int cols);
void grid_clear(Grid* grid);
void grid_destroy(Grid* grid);

bool grid_get_cell(const Grid* grid, int row, int col);
void grid_set_cell(Grid* grid, int row, int col, bool alive);

void grid_swap_buffers(Grid* grid);

void grid_set_next_cell(Grid* grid, int row, int col, bool alive);

void grid_randomize(Grid* grid);

#endif