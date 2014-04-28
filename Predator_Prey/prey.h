#ifndef PREY_H
#define PREY_H
#include "organism.h"

class Prey : public Organism
{

public:
    Prey();

    virtual void breed(Organism* &target);
    virtual void move(Organism* &target);
    void print();
    virtual ~Prey();
};

#endif // PREY_H
