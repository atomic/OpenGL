#include "mutalisk.h"
#include "QPoint"

Mutalisk_H::Mutalisk_H() : Organism()
{
    Genotype = MTLK_H;
    Orientation = Dir(rand() % 4 + 1); //between 1 to
}

Mutalisk_H::move(Organism *& target)
{
    if(target) //if there exists a food there, can it be Wall?
        starvation = 0;
    else
        starvation++;
    delete target;
    breedCount++; //mutalisk gonna breed? probably not
    isMoved = true;
    target = this;
}



Mutalisk_B::Mutalisk_B() : Organism()
{
    Genotype = MTLK_B;
}
