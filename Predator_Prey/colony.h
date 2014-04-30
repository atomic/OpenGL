#ifndef COLONY_H
#define COLONY_H
#include "grid.h"

#include <QList>
#include <QPoint>

enum Dir { NONE = 0, LEFT = 1, RIGHT = 2,
                 UP = 3, DOWN = 4}; //testing still

class Colony
{
private:
    grid** universe;
    QList<QPoint> availableGrids;
    QList<QPoint> availableFoods;
    int MAX_i;
    int MAX_j;
    int i_dest, j_dest; //helper variable

public:
    Colony                          (int v = 5, int h = 5);

    void buildWalls                  ();
    void randomize                  ();
    bool isCorner                   (const int i, const int j);

    /*
     * This scan perimeters will fill the QLists with coordinates
     * that particular creature can go to
     */
    void scanPerimeters             (const int i, const int j);


    void mainPhase                  ();
    void refreshPhase               ();
    void PredatorPhase              ();
    void PreyPhase                  ();

    void Advance                    (int i, int j);
    void breedHere                  (int i, int j);

    //DEBUG function
    void print                      ();
};

#endif // COLONY_H
