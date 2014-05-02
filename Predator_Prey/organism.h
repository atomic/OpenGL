#ifndef ORGANISM_H
#define ORGANISM_H

#include <stdlib.h> //for random
#include <time.h> // for random
using namespace std;

#include "constants.h"
#include <QDebug>

class Organism
{

public:
    Organism();
    int breedCount; //breed if 3 for prey, 8 for predator
    Gene Genotype;
    int starvation;
    Dir orientation; //only used by mutalisk head
    bool isMoved;
    virtual void breed(Organism* &);
    virtual void move(Organism* &);
    virtual bool breedReady() const;
    virtual bool isStarved() const;
    virtual void print();
    virtual ~Organism();
};

class Wall : public Organism
{

public:
    Wall();
    virtual void breed(Organism* &) const;
    virtual void move(Organism* &);
    virtual bool breedReady() const;
    virtual bool isStarved() const;
    virtual void print();
    virtual ~Wall();
};

#endif // ORGANISM_H
