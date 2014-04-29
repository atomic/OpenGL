#ifndef ORGANISM_H
#define ORGANISM_H

#include <stdlib.h> //for random
#include <time.h> // for random
#include "iostream"
using namespace std;

#include <QDebug>

class Organism
{
public:
    Organism();
    int breedCount; //breed if 3 for prey, 8 for predator
    char Genotype;
    int DirGene;
    virtual void advance();
    virtual void breed(Organism* &target) const;
    virtual void move(Organism* &target);
    virtual bool breedReady() const;

    virtual void print();
    virtual ~Organism();
};

#endif // ORGANISM_H
