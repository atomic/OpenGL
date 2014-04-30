#include "colony.h"

Colony::Colony(int v, int h) : MAX_i(v), MAX_j(h)
{
    srand(time(NULL)); //libraries included in grid.h
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

bool Colony::isCorner(const int i, const int j)
{
    if(i == 0 || i == (MAX_i -1) )
        return true;
    if(j == 0 || j == (MAX_j -1) )
        return true;
    return false;
}

void Colony::scanPerimeters(const int i, const int j, const int Type)
{
    availableGrids.clear();
    if(Type == 0)
        availableFoods.clear();

    for (int V = i-1; V < i + 2; ++V) {
        for (int H = j-1; H < j + 2; ++H) {
            if(H != V) {
               if(universe[V][H].Status() == 0)
                   availableGrids << QPoint(V,H);
               else if( (universe[V][H].Status() == 1) && (Type == 0)) //only for Predator
                   availableFoods << QPoint(V,H);
            }
        }
    }
    //NOTE : By the end of this function, avb_grids are either filled or empty
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
    for (int i = 0; i < MAX_i + 1; ++i)
        for (int j = 0; j < MAX_j + 1; ++j)
            if(universe[i][j].Status() == 2)
                if(universe[i][j].isStarving())
                    universe[i][j].kill();
}

void Colony::PreyPhase()
{
    //NOTE: finish this
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
    //BUG: Grid destructor kept getting called, WHY?
    //NOTE: [SOLVED], your << operator is passed by value, instead of reference

    int maxAvbGrids = availableGrids.size();
    int maxAvbFoods = availableFoods.size();
    QPoint choosenCoordinate;
    if(!availableFoods.isEmpty())
        choosenCoordinate = availableFoods[rand() % maxAvbFoods];
    else if(!availableGrids.isEmpty())
        choosenCoordinate = availableGrids[rand() % maxAvbGrids];

//    qDebug() << "Moving " << i << "," << j << " to " << choosenCoordinate;
    if(!availableFoods.isEmpty() || !availableGrids.isEmpty()) //has someone to move
        universe[i][j] >> universe[choosenCoordinate.x()][choosenCoordinate.y()];

//    //breeding time [NOT WORKING]
//    scanPerimeters(choosenCoordinate.x(),choosenCoordinate.y()); //update available space to breed
//    maxAvbGrids = availableGrids.size();
//    choosenCoordinate = availableGrids[rand() % maxAvbGrids];
    //NOTE: Have not finished yet here

}

void Colony::preyAdvance(int i, int j)
{
    int maxAvbGrids = availableGrids.size();
    QPoint choosenCoordinate;
    if(!availableGrids.isEmpty())
        choosenCoordinate = availableGrids[rand() % maxAvbGrids];

    if(!availableGrids.isEmpty())//place to move?
        universe[i][j] >> universe[choosenCoordinate.x()][choosenCoordinate.y()];

    scanPerimeters(choosenCoordinate.x(),choosenCoordinate.y(),0);//type 0 for passive
    QPoint breedCoordinate;
    maxAvbGrids = availableGrids.size(); //available breed grids
    if(!availableGrids.isEmpty())
        breedCoordinate = availableGrids[rand() % maxAvbGrids];
    if(!availableGrids.isEmpty())
        universe[choosenCoordinate.x()][choosenCoordinate.y()]
                >= universe[breedCoordinate.x()][breedCoordinate.y()];
}

void Colony::breedHere(int i, int j)
{
    universe[i][j] >= universe[i_dest][j_dest]; // breeding? yes
}
