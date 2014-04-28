#include "colony.h"

Colony::Colony(int v, int h) : v_grids(v), h_grids(h)
{
    for (int i = 0; i < v; ++i)
        universe[i] = new grid[h];
}
