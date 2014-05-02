#include "organism.h"

Organism::Organism() : breedCount(0), starvation(0), isMoved(false), orientation(NONE)
{
}

void Organism::breed(Organism* &) {}
void Organism::move(Organism* &){}
bool Organism::breedReady() const{ return false;}
bool Organism::isStarved() const{ return false;}
void Organism::print(){}
Organism::~Organism(){}


//HERE ARE THE WALL
Wall::Wall() : Organism()
{
    Genotype = WALL;
}

void Wall::breed(Organism *&) const {}
void Wall::move(Organism *&) {}
bool Wall::breedReady() const { return false;}
bool Wall::isStarved() const { return false; }
void Wall::print() {}
Wall::~Wall() {}


