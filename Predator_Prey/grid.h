#ifndef GRID_H
#define GRID_H

#include "prey.h"
#include "predator.h"

class grid
{
private:
    Organism* creature;

public:
    grid                        ();
    grid                        (Organism* newCreature);

    void RandomBreed            ();
    void PreyBreed              ();
    void PredatorBreed          ();
    void kill                   ();
    int Status                  () const;

    void print                  (); //DEBUG function

    grid  operator<<            (grid &from);
    const Organism& operator ++ ();
    const Organism& operator *  (); // later can be used to pass something
    //  functions like moves are called by Organism
    //debug
    ~grid                       ();
};

#endif // GRID_H
