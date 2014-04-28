#ifndef ORGANISM_H
#define ORGANISM_H

class Organism
{
private:
    int steps; //breed if 3 for prey, 8 for predator
    bool isPredator;

public:
    Organism();
    virtual breed();
    virtual move();
    virtual ~Organism();
};

#endif // ORGANISM_H
