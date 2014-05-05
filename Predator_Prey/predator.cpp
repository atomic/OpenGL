#include "predator.h"

Predator::Predator() : Organism()
{
    Genotype = PREDATOR;
    starveLevel = 3;
}

void Predator::breed(Organism *&target)
{
    if(target)
        qDebug() << "ERROR: cannot breed occupied space";
    target = new Predator;
    evolutionPoint++;
    if(evolutionPoint > geneLevel*10)
        evolve(); //no idea yet
    breedCount = 0;
}

void Predator::evolve()
{
    evolutionPoint -= geneLevel*10;
    geneLevel++;
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
    return (starvation == starveLevel ? true : false);
}
Predator::~Predator(){}
