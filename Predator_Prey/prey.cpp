#include "prey.h"

Prey::Prey() : Organism()
{
    Genotype = 'O';
}

void Prey::print()
{
    cout << "Prey(" << steps << ")";
}
