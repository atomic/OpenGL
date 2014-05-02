#include "predator.h"

Predator::Predator() : Organism()
{
    Genotype = PREDATOR;
}

void Predator::breed(Organism *&target)
{
    if(target)
        qDebug() << "ERROR: cannot breed occupied space";
    target = new Predator;
    breedCount = 0;
}

void Predator::move(Organism *&target)
{
    if(target) //if there exists a food there, can it be Wall?
        starvation = 0;
    else
        starvation++;
    delete target;
    breedCount++;
    isMoved = true;
    target = this;
}

bool Predator::breedReady() const
{
    return (breedCount == 8 ? true : false);
}

bool Predator::isStarved() const
{
    return (starvation == 3 ? true : false);
}
Predator::~Predator(){}
