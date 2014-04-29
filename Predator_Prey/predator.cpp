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

}

void Predator::move(Organism *&target)
{
    if(target)
        delete target;
    target = this;
}

void Predator::print()
{
    cout << "Predator(" << breedCount << "," << starvation << ")";
}

Predator::~Predator(){}
