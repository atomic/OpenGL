#include "mutalisk.h"
#include "QPoint"

Mutalisk_H::Mutalisk_H(Dir Ori) : Organism()
{
    Genotype = MTLK_H;
    orientation = Ori;
    if(orientation == NONE)
        orientation = Dir(rand() % 4 + 1); //between 1 to
    starveLevel = 10;
}

void Mutalisk_H::move(Organism *& target)
{
    if(target) { //if there exists a food there, can it be Wall?
        delete target;
        starvation -= (rand() % 3); //eat up to 2, but actually, it kills 3 in a row
        evolutionPoint++;
        if(evolutionPoint > 10) {
            evolve();
            evolutionPoint -= 10;
        }
    }
    else
        starvation++;
    isMoved = true;
    target = this;
}

void Mutalisk_H::evolve()
{
    starveLevel++;
}
bool Mutalisk_H::isStarved() const {  return ( starvation > starveLevel ? true : false); }

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
