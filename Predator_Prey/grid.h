#ifndef GRID_H
#define GRID_H
#include "prey.h"
#include "predator.h"

class grid
{
    Organism* creature;
    bool occupied;
public:
    grid();
    grid(Organism* newCreature = nullptr);
};

#endif // GRID_H
