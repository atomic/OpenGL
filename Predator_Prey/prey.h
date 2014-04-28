#ifndef PREY_H
#define PREY_H
#include "organism.h"

class Prey : public Organism
{

public:
    Prey();
    virtual breed();
    virtual move();
    virtual ~Organism();
};

#endif // PREY_H
