#include "colony.h"

Colony::Colony(int v, int h) : v_grids(v), h_grids(h)
{
    srand(time(NULL)); //libraries included in grid.h
    universe = new grid*[v];
    for (int i = 0; i < v; ++i)
        universe[i] = new grid[h];
}

void Colony::print()
{
    for (int i = 0; i < v_grids; ++i) {
        for (int j = 0; j < h_grids; ++j) {
            if(universe[i][j].isOccupied())
                cout << (*(universe[i][j])).Genotype << " ";
            cout << "- ";
        }
        cout << endl;
    }
}

void Colony::randomize()
{
    for (int i = 0; i < v_grids; ++i)
        for (int j = 0; j < h_grids; ++j)
            universe[i][j].RandomBreed();
}
