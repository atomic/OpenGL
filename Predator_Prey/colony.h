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
    QList<QPoint> availableGrids; //this list are going to be constantly updated in scanPerimeter()
    QList<QPoint> availableFoods; //this list are going to be constantly updated

public:
    Colony                          ();

    void buildWalls                  ();
    void randomize                  ();
    /*
     * This scan perimeters will fill the QLists with coordinates
     * that particular creature can go to
     */
    void scanPerimeters             (const int i, const int j, const int Type = 0);
    // Type 0 will scan according passive(only empty grids)
    // Type 1 will scan according aggressive(include food)


    void mainPhase                  ();
    void refreshPhase               ();
    void PredatorPhase              ();
    void PreyPhase                  ();

    void predatorAdvance            (int i, int j);
    void preyAdvance                (int i, int j);
    void breedAroundHere            (int i, int j);

    int whatsHere                   (int i, int j) const;

};

#endif // COLONY_H
