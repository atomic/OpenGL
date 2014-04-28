#ifndef PREDATOR_H
#define PREDATOR_H
#include "organism.h"

class Predator : public Organism
{
private:
    int starvation;

public:
    Predator();
//    virtual void breed();
//    virtual void move();
    virtual void print();
};

#endif // PREDATOR_H
