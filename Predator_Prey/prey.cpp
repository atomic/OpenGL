#include "prey.h"

Prey::Prey() : Organism()
{
    Genotype = 'O';
}

void Prey::breed(Organism *&target)
{
    if(target)
        qDebug() << "ERROR: cannot breed occupied space";
    target = new Prey;
    breedCount = 0;
}

void Prey::move(Organism *&target)
{
    if(target)
        qDebug() << "ERROR : Your prey move to non empty grid";
    isMoved = true;
    target = this;
}

bool Prey::breedReady() const
{
    return (breedCount == 3 ? true : false);
}

bool Prey::isStarved() const
{
    qDebug() << "ERROR : You should never call isStarved on prey";
    return false;
}

void Prey::print()
{
    cout << "Prey(" << breedCount << ")";
}

Prey::~Prey(){}
