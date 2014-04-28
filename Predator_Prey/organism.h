#ifndef ORGANISM_H
#define ORGANISM_H

#include "iostream"
using namespace std;

#include <QDebug>

class Organism
{
protected:
    int steps; //breed if 3 for prey, 8 for predator

public:
    Organism();
    char Genotype;
//    virtual void breed();
//    virtual void move();

    virtual void print();
};

#endif // ORGANISM_H
