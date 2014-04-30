#include "predator.h"

Predator::Predator() : Organism()
{
    Genotype = 'X';
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
    delete target;
    breedCount++;
    starvation++;
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

void Predator::print()
{
    cout << "Predator(" << breedCount << "," << starvation << ")";
}

Predator::~Predator(){}
