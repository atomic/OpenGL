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
    int randomTemp;

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
    void spawnMutalisk              (const int i, const int j, Dir Ori = NONE);// call spawn MutaliskBody
    void spawnMTLKShell             (const int i, const int j);
    void spawnRandomMutalisk        ();

    void killMutalisk               (const int i, const int j);
    void killMutaliskBody           (const QPoint body);//get rid of 9x9 grid

    void rotateMutalisk             (const int i, const int j);
    // NOTE: no need to scan, there will always be a space to rotate
    void MutaliskMarch              (const int i, const int j); //location of its head
    void MutaliskBodyMarch          (const QPoint &bodyCoor, const Dir &on ,const int headLV); //location of body
    bool scanAhead                  (const int i, const int j, const Dir on);
    bool scanDeploymentArea         (const int i, const int j, const int size = 5); //scan 5x5 grid for deployment
    // This will scan sizexsize area for no mutalisk around, will crash if i,j DNE
    Dir findHeadDirection           (const QPoint body, const QPoint head);
    QPoint whereIsHead              (const QPoint body, const Dir on);
    QPoint getBodyCenter            (const int i, const int j);


    void mainPhase                  ();
    void refreshPhase               ();
    void PredatorPhase              ();
    void PreyPhase                  ();
    void MutaliskPhase              ();
    void MutaliskHatchPhase         ();

    void predatorAdvance            (int i, int j);
    void preyAdvance                (int i, int j);
    void breedAroundHere            (int i, int j);

    int whatsHere                   (int i, int j) const;
    int getLevel                    (int i, int j) const { return universe[i][j].getLevel(); }

};

#endif // COLONY_H
