#include "grid.h"


grid::grid(): creature(NULL)
{
}

grid::grid(Organism *newCreature) : creature(newCreature)
{
}

void grid::spawnWall()
{
    if(creature)
        qDebug() << "ERROR : some creature stuck at wall before wall being build?";
    else
        creature = new Wall;
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

void grid::refresh()
{
    creature->isMoved = false;
}

int grid::Status() const {
    /* If not occupied, return 0, if Prey is there return 1,
     *                            if Predator is there return 2.
     */
    if(!creature)
        return 0;
    if(creature->Genotype == 'O')
        return 1;
    else if(creature->Genotype == 'X')
        return 2;
    else if(creature->Genotype == 'W')
        return 9;
    qDebug() << "ERROR: Status() grid.cpp no Status returned";
    return 0;
}

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
