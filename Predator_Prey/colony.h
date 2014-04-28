#ifndef COLONY_H
#define COLONY_H
#include "grid.h"

enum Direction { LEFT = 1, RIGHT = 2,
                 UP = 3, DOWN = 4}; //testing still

class Colony
{
private:
    grid** universe;
    int v_grids;
    int h_grids;
public:
    Colony(int v = 5, int h = 5);
    void print();
    void randomize();
};

#endif // COLONY_H
