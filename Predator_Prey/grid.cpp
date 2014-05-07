#include "grid.h"


grid::grid(): creature(NULL) , MTLKhatchery(false)
{
}

grid::grid(Organism *newCreature) : creature(newCreature)
{
}

void grid::MTLKHatchEvo(){creature->evolve();}
bool grid::MTLKEggMature(){return (creature->geneLevel > 125 ? true : false);}
void grid::MTLKHatchEgg()
{
    MTLKhatchery = true;
    creature->breedCount = 0;
}

void grid::spawnWall()
{
    if(creature)
        delete creature;
    creature = new Wall;
}

void grid::spawnMutaliskHead(Dir Ori)
{
    if(creature)
        delete creature;
    creature = new Mutalisk_H(Ori);
}

void grid::spawnMutaliskBody()
{
    if(creature)
        delete creature;
    creature = new Mutalisk_B;
}

void grid::spawnMutaliskEgg_O()
{
    if(creature)
        delete creature;
    creature = new Mutalisk_Egg_O;
}

void grid::spawnMutaliskEgg_S()
{
    if(creature)
        delete creature;
    creature = new Mutalisk_Egg_S;
}

void grid::RandomBreed()
{
    kill();
    int breed = rand() % 5;
    if(breed == 0 || breed == 2 || breed == 3) // 0 for Prey, 1 for Predator
        PreyBreed();
    else if (breed == 1)
        PredatorBreed();
}

bool grid::isMoved() const {return( creature->isMoved);}

bool grid::isEdible() const
{
    return (getGene() != MTLK_B &&
            getGene() != MTLK_H &&
            getGene() != MTLK_E_O &&
            getGene() != MTLK_E_S &&
            getGene() != WALL) ? true : false;

}

bool grid::isStarving() const{return creature->isStarved();}

bool grid::isPregnant() const {return creature->breedReady();}

void grid::PreyBreed()
{
    if(creature)
        qDebug() << "Error : Hey, there is creature here.\n";
    else
        creature = new Prey;
}

void grid::PredatorBreed()
{
    if(creature)
        qDebug() << "Error : Hey, there is creature here.\n";
    else
        creature = new Predator;
}

void grid::kill()
{
    if(creature) {
        delete creature;
        creature = NULL;
    }
}

void grid::refresh() {creature->isMoved = false;}

Gene grid::getGene() const {
    /* If not occupied, return 0, if Prey is there return 1,
     *                            if Predator is there return 2.
     */
    if(!creature)
        return EMPTY;
    return creature->Genotype;
}

Dir  grid::getOrientaton() const{return creature->orientation;}
void grid::setOrientaton(Dir newDir) {creature->orientation = newDir;}

grid& grid::operator >>(grid &to)
{
    creature->move(to.creature); //this handle memory allocation
    creature = NULL;
    return to;
}

void grid::operator >=(grid &to)
{
    creature->breed(to.creature);
}

const Organism &grid::operator *()
{
    return *creature;
}

grid::~grid()
{
    delete creature;
}
