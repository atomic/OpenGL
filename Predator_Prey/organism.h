#ifndef ORGANISM_H
#define ORGANISM_H

#include "iostream"
using namespace std;

#include <QDebug>

class Organism
{
protected:
    int breedCount; //breed if 3 for prey, 8 for predator

public:
    Organism();
    char Genotype;
    virtual void breed(Organism* &target);
    virtual void move(Organism* &target);

    virtual void print();
    virtual ~Organism();
};

#endif // ORGANISM_H
