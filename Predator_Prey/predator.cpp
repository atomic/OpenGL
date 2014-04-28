#include "predator.h"

Predator::Predator() : Organism(), starvation(0)
{
    Genotype = 'X';
}

void Predator::print()
{
    cout << "Predator(" << steps << "," << starvation << ")";
}
