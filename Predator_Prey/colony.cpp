#include "colony.h"

Colony::Colony(int v, int h) : v_grids(v), h_grids(h)
{
    srand(time(NULL)); //libraries included in grid.h
    universe = new grid*[v];
    for (int i = 0; i < v; ++i)
        universe[i] = new grid[h];
    //all creature are automatically set to NULL
}

void Colony::print()
{
    for (int i = 0; i < v_grids; ++i) {
        for (int j = 0; j < h_grids; ++j) {
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
    for (int i = 0; i < v_grids; ++i)
        for (int j = 0; j < h_grids; ++j)
            universe[i][j].RandomBreed();
}

bool Colony::upEmpty(const int i, const int j)
{
    if(universe[i-1][j].Status() == 0)
        return true;
    return false;
}

bool Colony::downEmpty(const int i, const int j)
{
    if(universe[i+1][j].Status() == 0)
        return true;
    return false;
}

bool Colony::leftEmpty(const int i, const int j)
{
    if(universe[i][j-1].Status() == 0)
        return true;
    return false;
}

bool Colony::rightEmpty(const int i, const int j)
{
    if(universe[i][j+1].Status() == 0)
        return true;
    return false;
}

bool Colony::isCorner(const int i, const int j)
{
    if(i == 0 || i == (v_grids -1) )
        return true;
    if(j == 0 || j == (h_grids -1) )
        return true;
    return false;
}

Dir Colony::scanSpace(const int i, const int j)
{
    /* For My Type: Creatures have 4 types of movement orientation(genetic)
     *              These 4 types of movement are predefined.
     * When they breed, they pass on the movement orientation.
     */
    /* Scan Vertical Corners (UP,DOWN)*/
    if(i == 0) {
        if(universe[1][j].Status() == 0)
            return DOWN;
    }
    else if(i == (v_grids - 1)) {
        if(universe[v_grids - 2][j].Status() == 0)
            return UP;
    }

    /* Scan Horizontal Corners (LEFT, RIGHT)*/
    if(j == 0) {
        if(universe[i][1].Status() == 0)
            return RIGHT;
    }
    else if(j == (h_grids - 1)) {
        if(universe[i][h_grids - 2].Status() == 0)
            return LEFT;
    }

    //If the position is somewhere else beside wall, scan according to genetic
    if(!isCorner(i,j)) {
        int DirGeneType = (*(universe[i][j])).DirGene;
        for (int n = 0; n < 4; ++n) {
            //rotation of direction is executed depending on their type
            switch (OrientationSet[DirGeneType][n]){
            case UP:
                if(upEmpty(i,j))
                    return UP;
                break;
            case DOWN:
                if(downEmpty(i,j))
                    return DOWN;
                break;
            case LEFT:
                if(leftEmpty(i,j))
                    return LEFT;
                break;
            case RIGHT:
                if(rightEmpty(i,j))
                    return RIGHT;
                break;
            default:
                break;
            }
        }
    }
    qDebug() << "WARNING : " <<i<<","<<j<<" can't move";
    return NONE;
}

Dir Colony::scanPreys(const int i, const int j)
{
    //NOTE: Scans order are not random
                    /* Scan Vertical Corners (UP,DOWN)*/
    if(i == 0) {
        if(universe[1][j].Status() == 1)
            return DOWN;
    }
    else if(i == v_grids - 1){
        if(universe[v_grids - 2][j].Status() == 1)
            return UP;
    }

                   /* Scan Horizontal Corners (LEFT, RIGHT)*/
    if(j == 0) {
        if(universe[i][1].Status() == 1)
            return RIGHT;
    }
    else if(j == h_grids - 1) {
        if(universe[i][h_grids - 2].Status() == 1)
            return LEFT;
    }

                 /* Scan vertical, Above, Bottom*/
    if(!isCorner(i,j)) {
        if(universe[i-1][j].Status() == 1)
            return UP;
        else if(universe[i+1][j].Status() == 1)
            return DOWN;
        else if(universe[i][j-1].Status() == 1)
            return LEFT;
        else if(universe[i+1][j].Status() == 1)
            return RIGHT;
    }
    return NONE; //if no preys are found return 0, or NONE.
}

void Colony::PredatorPhase()
{
    /* This function will loop the whole system to tell predators to move
     * First, the scan method for corners are different
     * Second, the scan methods for wall creatures are different
     */
    /*Corners*/
    Dir huntDir;
    Dir moveDir;
    for (int i = 0; i < v_grids; ++i) {
        for (int j = 0; j < h_grids; ++j) {
            if(universe[i][j].Status() == 2) { //if the grid is predator
                huntDir = scanPreys(i,j);
                moveDir = scanSpace(i,j);
                if(huntDir != NONE)
                    Advance(i,j,huntDir);
                else if(huntDir == NONE && moveDir != NONE)
                    Advance(i,j,moveDir);
            }
        }
    }
}

void Colony::Advance(int i, int j, Dir Orient)
{
    //BUG: Grid destructor kept getting called, WHY?
    //NOTE: [SOLVED], your << operator is passed by value, instead of reference

//    qDebug() << "In Advance(" << i << j << ") , Orient : " << Orient;
    i_dest = i;
    j_dest = j;
    switch (Orient){
    case UP:
        i_dest--;
        break;
    case DOWN:
        i_dest++;
        break;
    case LEFT:
        j_dest--;
        break;
    case RIGHT:
        j_dest++;
        break;
    default:
        break;
    }
    universe[i][j] >> universe[i_dest][j_dest];

    //breeding time
    breedDir = scanSpace(i_dest,j_dest);
    if( (*(universe[i_dest][j_dest])).breedReady() )
        breedHere(i_dest,j_dest,breedDir);
}

void Colony::breedHere(int i, int j, Dir Orient)
{
    i_dest = i;
    j_dest = j;
    switch (Orient){
    case UP:
        i_dest--;
        break;
    case DOWN:
        i_dest++;
        break;
    case LEFT:
        j_dest--;
        break;
    case RIGHT:
        j_dest++;
        break;
    default:
        break;
    }
    universe[i][j] >= universe[i_dest][j_dest]; // breeding? yes
}
