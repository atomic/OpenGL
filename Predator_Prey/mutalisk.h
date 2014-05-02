#ifndef MUTALISK_H
#define MUTALISK_H
#include "organism.h"

class Mutalisk_H : public Organism
{
public:
    Mutalisk_H();
    virtual void move(Organism *&target);
    virtual ~Mutalisk_H();
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
