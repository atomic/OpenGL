#include "prey.h"

Prey::Prey() : Organism()
{
    Genotype = 'O';
}

void Prey::advance()
{
    breedCount++;
}

void Prey::breed(Organism *&target)
{
    if(target)
        qDebug() << "ERROR: cannot breed occupied space";
    target = new Prey;
}

void Prey::move(Organism *&target)
{
    if(target)
        qDebug() << "ERROR : Your prey move to non empty grid";
    advance();
    target = this;
}

bool Prey::breedReady() const
{
    return (breedCount == 3 ? true : false);
}

void Prey::print()
{
    cout << "Prey(" << breedCount << ")";
}

Prey::~Prey(){}
