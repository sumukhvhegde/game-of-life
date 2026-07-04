#ifndef SIMULATION_H
#define SIMULATION_H

#include "grid.h"

void simulation_step(Grid* grid);

unsigned long simulation_get_generation(void);

void simulation_reset_generation(void);

#endif