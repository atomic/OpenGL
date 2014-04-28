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
    grid                    ();
    grid                    (Organism* newCreature);

    void RandomBreed        ();
    void PreyBreed          ();
    void PredatorBreed      ();
    void kill               ();
    bool isOccupied         () const;

    void print              ();

    const char& operator *  ();
    //debug
    ~grid                   ();
};

#endif // GRID_H
