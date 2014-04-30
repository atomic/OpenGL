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
    breedCount++;
    isMoved = true;
    target = this;
}

bool Prey::breedReady() const{return (breedCount == 3 ? true : false);}
bool Prey::isStarved() const{return false;}
Prey::~Prey(){}
