#include "mutalisk.h"
#include "QPoint"

Mutalisk_H::Mutalisk_H() : Organism()
{
    Genotype = MTLK_H;
    orientation = Dir(rand() % 4 + 1); //between 1 to
}

void Mutalisk_H::move(Organism *& target)
{
    if(target) //if there exists a food there, can it be Wall?
        delete target;
    isMoved = true;
    target = this;
}
Mutalisk_H::~Mutalisk_H(){}





/* MUTALISK B Part */
Mutalisk_B::Mutalisk_B() : Organism(){Genotype = MTLK_B;}
void Mutalisk_B::move(Organism *&target)
{
    if(target)
        delete target;
    isMoved = true;
    target = this;
}



Mutalisk_B::~Mutalisk_B(){}
