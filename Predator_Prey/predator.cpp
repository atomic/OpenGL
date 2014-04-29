#include "predator.h"

Predator::Predator() : Organism(), starvation(0)
{
    Genotype = 'X';
}

void Predator::advance()
{
    breedCount++;
    starvation++;
}

void Predator::breed(Organism *&target)
{
    if(target)
        qDebug() << "ERROR: cannot breed occupied space";
    target = new Predator;
}

void Predator::move(Organism *&target)
{
    if(target)//if there are target, it has to be prey
        advance();
    delete target;
    target = this;
}

bool Predator::breedReady() const
{
    return (breedCount == 8 ? true : false);
}

void Predator::print()
{
    cout << "Predator(" << breedCount << "," << starvation << ")";
}

Predator::~Predator(){}
