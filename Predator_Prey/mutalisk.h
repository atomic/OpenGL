#ifndef MUTALISK_H
#define MUTALISK_H
#include "organism.h"

class Mutalisk_H : public Organism
{
public:
    Mutalisk_H();
    virtual move(Organism *&target);
    virtual bool isStarved() const;
    virtual ~Organism();
    //not use full actually
};

class Mutalisk_B : public Organism
{
public:
    Mutalisk_B();
};
#endif // MUTALISK_H
