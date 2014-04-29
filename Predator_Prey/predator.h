#ifndef PREDATOR_H
#define PREDATOR_H
#include "organism.h"

class Predator : public Organism
{

public:
    Predator();
    /*
     * Before calling these virtual, target has to be already defined */
    virtual void advance();
    virtual void breed(Organism* &target);
    virtual void move(Organism* &target);
    virtual bool breedReady() const;
    virtual ~Predator();

    int starvation;
    //Debug
    void print();
};

#endif // PREDATOR_H
