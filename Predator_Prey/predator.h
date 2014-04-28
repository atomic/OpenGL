#ifndef PREDATOR_H
#define PREDATOR_H
#include "organism.h"

class Predator : public Organism
{
private:
    int startcount;

public:
    Predator();
    virtual breed();
    virtual move();
    virtual ~Organism();
};

#endif // PREDATOR_H
