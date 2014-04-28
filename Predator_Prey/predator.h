#ifndef PREDATOR_H
#define PREDATOR_H
#include "organism.h"

class Predator : public Organism
{
private:
    int starvation;

public:
    Predator();
    /*
     * Before calling these virtual, target has to be already defined */
    virtual void breed(Organism* &target);
    virtual void move(Organism* &target);
    virtual ~Predator();

    //Debug
    void print();
};

#endif // PREDATOR_H
