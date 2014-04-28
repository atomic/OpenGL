#include "grid.h"


grid::grid(): occupied(0), creature(nullptr)
{
}

grid::grid(Organism *newCreature) : occupied(1), creature(newCreature)
{
}
