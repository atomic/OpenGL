#include "colony.h"

Colony::Colony(int v, int h) : MAX_i(v), MAX_j(h)
{
    universe = new grid*[v+2];
    for (int i = 0; i < v + 2; ++i)
        universe[i] = new grid[h + 2];
    //all creature are automatically set to NULL
}

void Colony::buildWalls()
{
    for (int i = 0; i < MAX_i + 2; ++i) {
        universe[i][0].spawnWall();
        universe[i][MAX_j + 1].spawnWall();
    }
    for (int j = 1; j < MAX_j + 1; ++j) {
        universe[0][j].spawnWall();
        universe[MAX_i + 1][j].spawnWall();
    }
}

void Colony::print()
{
    for (int i = 0; i < MAX_i + 2; ++i) {
        for (int j = 0; j < MAX_j + 2; ++j) {
            if(universe[i][j].Status())
                cout << " " << (*(universe[i][j])).Genotype << " ";
            else
                cout << "   ";
        }
        cout << endl;
    }
}

void Colony::randomize()
{
    // in normal scenario, this should only be called once
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            universe[i][j].RandomBreed();
}

void Colony::scanPerimeters(const int i, const int j, const int Type)
{
    availableGrids.clear();
    availableFoods.clear();

    for (int V = i-1; V < i + 2; ++V) {
        for (int H = j-1; H < j + 2; ++H) {
            if( !(V == i && H == j) ) {
               if(universe[V][H].Status() == 0)
                   availableGrids << QPoint(V,H);
               else if( (universe[V][H].Status() == 1) && (Type == 1)) //only for Predator
                   availableFoods << QPoint(V,H);
            }
        }
    }
}

void Colony::mainPhase()
{
    refreshPhase();
    PredatorPhase();
    PreyPhase();
}

void Colony::refreshPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            if(universe[i][j].Status() == 1 || universe[i][j].Status() == 2)
                universe[i][j].refresh();
}

void Colony::PredatorPhase()
{
    /*Corners*/
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].Status() == 2) {
                if( !universe[i][j].isMoved() ) {
                    scanPerimeters(i,j,1);
                    predatorAdvance(i,j);
                }
            }
        }
    }
    //check for moved predators that are starving
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            if(universe[i][j].Status() == 2)
                if(universe[i][j].isStarving())
                    universe[i][j].kill();
}

void Colony::PreyPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].Status() == 1) {
                if( !universe[i][j].isMoved() ) {
                    scanPerimeters(i,j,0); //type 0 for passive
                    preyAdvance(i,j);
                }
            }
        }
    }
}

void Colony::predatorAdvance(int i, int j)
{
    //BUG: [SOLVED]Grid destructor kept getting called, WHY?
    //ANSWER: [SOLVED], your << operator is passed by value, instead of reference

    //BUG : Somewhere the diagonal creature is always get killed

    int maxAvbGrids = availableGrids.size();
    int maxAvbFoods = availableFoods.size();
    QPoint goHere;
    if(!availableFoods.isEmpty())
        goHere = availableFoods[rand() % maxAvbFoods];
    else if(!availableGrids.isEmpty())
        goHere = availableGrids[rand() % maxAvbGrids];

    if(!availableFoods.isEmpty() || !availableGrids.isEmpty()) {
        universe[i][j] >> universe[goHere.x()][goHere.y()];
        if(universe[goHere.x()][goHere.y()].isPregnant())
            breedAroundHere(goHere.x(),goHere.y());
    }
}

void Colony::preyAdvance(int i, int j)
{
    int maxAvbGrids = availableGrids.size();
    QPoint goHere;
    if(!availableGrids.isEmpty()) {
        goHere = availableGrids[rand() % maxAvbGrids];
        universe[i][j] >> universe[goHere.x()][goHere.y()];
        if(universe[goHere.x()][goHere.y()].isPregnant())
            breedAroundHere(goHere.x(),goHere.y());
    }
}

void Colony::breedAroundHere(int i, int j)
{
    QPoint breedHere;
    scanPerimeters(i,j,0);//type 0 for passive
    int maxAvbGrids = availableGrids.size(); //available breed grids
    if(!availableGrids.isEmpty())
        breedHere = availableGrids[rand() % maxAvbGrids];
    if(!availableGrids.isEmpty())
        universe[i][j] >= universe[ breedHere.x()][ breedHere.y()];
}
