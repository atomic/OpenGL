#ifndef COLONY_H
#define COLONY_H
#include "grid.h"

enum Dir { NONE = 0, LEFT = 1, RIGHT = 2,
                 UP = 3, DOWN = 4}; //testing still

class Colony
{
private:
    grid** universe;
    int v_grids;
    int h_grids;
    const Dir OrientationSet[4][4] = {
        {LEFT, DOWN, RIGHT, UP},
        {RIGHT, DOWN, LEFT, UP},
        {UP, DOWN, RIGHT, LEFT},
        {RIGHT, LEFT, UP, DOWN}
    };

public:
    Colony                          (int v = 5, int h = 5);
    void randomize                  ();

    bool upEmpty                    (int i, int j);
    bool downEmpty                  (int i, int j);
    bool leftEmpty                  (int i, int j);
    bool rightEmpty                 (int i, int j);
    bool isCorner                   (const int i, const int j);

    Dir scanPreys                   (int i, int j);
    Dir scanSpace                   (int i, int j);


    void PredatorPhase              ();
    void PreyPhase                  ();

    void Advance                    (int i, int j, Dir Orient);

    //DEBUG function
    void print                      ();
};

#endif // COLONY_H
