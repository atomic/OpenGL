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
        breedCount++;
        if(evolutionPoint > geneLevel*100)
            evolve();
    }
    else
        starvation++;
    isMoved = true;
    target = this;
}

void Mutalisk_H::evolve()
{
    evolutionPoint -= geneLevel*100;
    if(geneLevel < 3)
        geneLevel++;
    starveLevel++; //become more OP after eating a lot
}

bool Mutalisk_H::breedReady() const
{
    return (breedCount > 100 ? true : false);
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

/* MUTALISK Egg Part */

Mutalisk_Egg_O::Mutalisk_Egg_O() : Organism() {
    isMoved = true;
    Genotype = MTLK_E_O;
}
void Mutalisk_Egg_O::evolve(){
    geneLevel++;
    isMoved = true;
}

bool Mutalisk_Egg_O::breedReady() const
{
    return (geneLevel > 25 ? true : false);
}
Mutalisk_Egg_O::~Mutalisk_Egg_O(){}

/* MUTALISK Egg Shell Part */
Mutalisk_Egg_S::Mutalisk_Egg_S() : Organism() {
    isMoved = true;
    Genotype = MTLK_E_S;
}
void Mutalisk_Egg_S::evolve(){
    geneLevel++;
    isMoved = true;
}

bool Mutalisk_Egg_S::breedReady() const
{
    return (geneLevel > 50 ? true : false);
}
Mutalisk_Egg_S::~Mutalisk_Egg_S(){}
