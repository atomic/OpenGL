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
    int starvation;
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
