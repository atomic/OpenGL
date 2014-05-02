#ifndef GRID_H
#define GRID_H

#include "prey.h"
#include "predator.h"
#include "mutalisk.h"

class grid
{
private:
    Organism* creature;
    void PreyBreed              ();
    void PredatorBreed          ();
    //  NOTE : to breed next generation, use the organism method, these are for starter

public:
    grid                        ();
    grid                        (Organism* newCreature);

    void spawnWall              ();
    void spawnMutaliskHead      ();
    void spawnMutaliskBody      ();
    void RandomBreed            ();

    bool isMoved                () const;
    bool isStarving             () const;
    bool isPregnant             () const;
    void kill                   ();

    void refresh                (); //reset the isMoved to false
    int Status() const; //0 for unoccupied, 1 for prey, 2 for pred
    Dir getOrientaton           () const;
    QPoint getBodyCenter        (const int i, const int j);


    grid  &operator  >>         (grid &to); //MOVE Operator
    void operator    >=         (grid &to); //BREED OPERATOR

    const Organism& operator *  (); // later can be used to pass something
    //  functions like moves and breed are called by Organism
    //debug
    ~grid                       ();
};

#endif // GRID_H
