#ifndef COLONY_H
#define COLONY_H
#include "grid.h"

#include <QList>

class Colony
{
private:
    grid** universe;
    QList<QPoint> availableGrids; //this list are going to be constantly updated in scanPerimeter()
    QList<QPoint> availableFoods; //this list are going to be constantly updated
    QPoint aheadPoint;

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


    /* These are the function for Mutalisk */
    void spawnMutaliskBody          (const int i, const int j);// spawn 9x9 grid
    void spawnMutalisk              (const int i, const int j);// call spawn MutaliskBody
    bool scanAhead                  (const int i, const int j, const Dir on);
    Dir findHeadDirection           (const QPoint body, const QPoint head);
    QPoint whereIsHead              (const QPoint body, const Dir on);
    // This scan is scan in front of direction for NOT WALL
    Dir scanMTKRotateSpace          (const int i, const int j);//i,j is the head position
    // This scan available direction for Mutalisk to rotate


    void mainPhase                  ();
    void refreshPhase               ();
    void PredatorPhase              ();
    void PreyPhase                  ();
    void MutaliskPhase              ();
    void MutaliskMarch              (const int i, const int j); //location of its head

    void predatorAdvance            (int i, int j);
    void preyAdvance                (int i, int j);
    void breedAroundHere            (int i, int j);

    void rotateMutalisk             (const int i, const int j);
    int whatsHere                   (int i, int j) const;

};

#endif // COLONY_H
