#ifndef GRID_H
#define GRID_H
#include <stdlib.h> //for random
#include <time.h> // for random
using namespace std;

#include "prey.h"
#include "predator.h"

class grid
{
    Organism* creature;
public:
    grid                        ();
    grid                        (Organism* newCreature);

    void RandomBreed            ();
    void PreyBreed              ();
    void PredatorBreed          ();
    void kill                   ();
    bool isOccupied             () const;

    void print                  (); //DEBUG function

    grid  operator<<            (grid &from);
    const Organism& operator *  (); // later can be used to pass something
    //  functions like moves are called by Organism
    //debug
    ~grid                       ();
};

#endif // GRID_H
