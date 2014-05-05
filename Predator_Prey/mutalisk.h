#ifndef MUTALISK_H
#define MUTALISK_H
#include "organism.h"

class Mutalisk_H : public Organism
{
public:
    Mutalisk_H(Dir Ori = NONE);
    virtual void move(Organism *&target);
    virtual void evolve();
    virtual ~Mutalisk_H();
    virtual bool isStarved() const;
    //not use full actually
};

class Mutalisk_B : public Organism
{
public:
    Mutalisk_B();
    virtual void move(Organism *&target);
    virtual ~Mutalisk_B();
};
#endif // MUTALISK_H
