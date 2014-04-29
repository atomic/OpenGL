#include "organism.h"

Organism::Organism() : breedCount(0), Genotype(0)
{
    DirGene = rand() % 4; //four types of orientation gene
}

void Organism::advance(){}
void Organism::breed(Organism* &target) const{}
void Organism::move(Organism* &target){}

bool Organism::breedReady() const{}
void Organism::print(){}

Organism::~Organism(){}
