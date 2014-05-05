#include "colony.h"


Colony::Colony()
{
    universe = new grid*[MAX_i+2];
    for (int i = 0; i < MAX_i + 2; ++i)
        universe[i] = new grid[MAX_j + 2];
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

void Colony::randomize()
{
    // in normal scenario, this should only be called once
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            universe[i][j].RandomBreed();
    spawnMutalisk(25,25);
}

void Colony::scanPerimeters(const int i, const int j, const int Type)
{
    availableGrids.clear();
    availableFoods.clear();

    for (int V = i-1; V < i + 2; ++V) {
        for (int H = j-1; H < j + 2; ++H) {
            if( !(V == i && H == j) ) {
               if(universe[V][H].Status() == 0) //if empty
                   availableGrids << QPoint(V,H);
               else if( (universe[V][H].Status() == PREY) && (Type == 1)) //only for Predator
                   availableFoods << QPoint(V,H);
            }
        }
    }
}

void Colony::spawnMutaliskBody(const int i, const int j)
{
    //before using this, make sure your i,j is not close to WALL
    for (int o_i = i-1; o_i < i+2; ++o_i) {
        for (int o_j = j-1; o_j < j+2; ++o_j) {
            universe[o_i][o_j].kill();
            universe[o_i][o_j].spawnMutaliskBody();
        }
    }
}

void Colony::spawnMutalisk(const int i, const int j)
{
    universe[i][j].kill();
    universe[i][j].spawnMutaliskHead();
    switch (universe[i][j].getOrientaton()) {
    case UP:
        spawnMutaliskBody(i+2,j);
        break;
    case DOWN:
        spawnMutaliskBody(i-2,j);
        break;
    case LEFT:
        spawnMutaliskBody(i, j + 2);
        break;
    case RIGHT:
        spawnMutaliskBody(i, j - 2);
        break;
    default:
        break;
    }
}

bool Colony::scanAhead(const int i, const int j, const Dir on)
{
    // Use aheadPoint here, because you are going to need the
    // the point to move later on, so you dont have to double convert
    switch (on) {
    case UP:
        aheadPoint.setX(i-1);
        aheadPoint.setY(j);
        return (universe[i-1][j].Status() != WALL) ? true : false;
        break;
    case DOWN:
        aheadPoint.setX(i+1);
        aheadPoint.setY(j);
        return (universe[i+1][j].Status() != WALL) ? true : false;
        break;
    case LEFT:
        aheadPoint.setX(i);
        aheadPoint.setY(j-1);
        return (universe[i][j-1].Status() != WALL) ? true : false;
        break;
    case RIGHT:
        aheadPoint.setX(i);
        aheadPoint.setY(j+1);
        return (universe[i][j+1].Status() != WALL) ? true : false;
        break;
    default:
        break;
    }
    return false;//not necessary if 'on' exists
}

Dir Colony::findHeadDirection(const QPoint body, const QPoint head)
{
    if( body.x() != head.x()) {
        if( body.x() > head.x())  //body i is larger than head?
            return UP;
        else
            return DOWN;
    }
    if( body.y() != head.y() ){
        if( body.y() < head.y())  //body j is less than head?
            return RIGHT;
        else
            return LEFT;
    }
    qDebug() << "Error: Mutalisk has no sense of direction";
    return NONE;
}

QPoint Colony::whereIsHead(const QPoint body ,const Dir on)
{
    switch (on) { //x is i, y is j
    case UP:
        return QPoint(body.x() + 2, body.y());
        break;
    case DOWN:
        return QPoint(body.x() + 2, body.y());
        break;
    case LEFT:
        return QPoint(body.x(), body.y() - 2);
        break;
    case RIGHT:
        return QPoint(body.x(), body.y() + 2);
        break;
    default:
        break;
    }
    //else, NO HEAD? WTF
    return QPoint();
}

QPoint Colony::getBodyCenter(const int i, const int j)
{
    switch (universe[i][j].getOrientaton()) {
        case UP:
            return QPoint(i + 2, j);
            break;
        case DOWN:
            return QPoint(i - 2, j);
            break;
        case LEFT:
            return QPoint(i, j + 2);
            break;
        case RIGHT:
            return QPoint(i, j - 2);
            break;
        default:
            qDebug() << "Wrong Head Passed to Body";
            break;
    }
    return QPoint();//in case no orientation
}

Dir Colony::scanMTKRotateSpace(const int i, const int j)
{
    availableGrids.clear();
    QPoint center = getBodyCenter(i,j); //its inefficient, but whatever
    availableGrids << QPoint(center.x() - 2 ,center.y() );
    availableGrids << QPoint(center.x() + 2 ,center.y() );
    availableGrids << QPoint(center.x() ,center.y() + 2 );
    availableGrids << QPoint(center.x() ,center.y() - 2);
    for (int comb = 0; comb < availableGrids.size(); ++comb)
        if(availableGrids[comb].x() == i && availableGrids[comb].y())
            availableGrids.removeAt(comb);
    for (int comb = 0; comb < availableGrids.size(); ++comb) {
        if(universe[availableGrids[comb].x()][availableGrids[comb].y()].Status() == WALL
         ||universe[availableGrids[comb].x()][availableGrids[comb].y()].Status() == MTLK_B
         ||universe[availableGrids[comb].x()][availableGrids[comb].y()].Status() == MTLK_H) {
            availableGrids.removeAt(comb);
            comb = 0;
        }
    }
    //no check for if availableGrid == 0, there has to be some space to rotate
    int choosenIndex = rand() % availableGrids.size();
    return findHeadDirection(center,availableGrids[choosenIndex]);
}

void Colony::mainPhase()
{
    refreshPhase();
    PredatorPhase();
    PreyPhase();
    MutaliskPhase();
}

void Colony::refreshPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            if(universe[i][j].Status() == PREY
                    || universe[i][j].Status() == PREDATOR
                    || universe[i][j].Status() == MTLK_H)
                universe[i][j].refresh();
}

void Colony::PredatorPhase()
{
    /*Corners*/
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].Status() == PREDATOR) {
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
            if(universe[i][j].Status() == PREDATOR)
                if(universe[i][j].isStarving())
                    universe[i][j].kill();
}

void Colony::PreyPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].Status() == PREY) {
                if( !universe[i][j].isMoved() ) {
                    scanPerimeters(i,j,0); //type 0 for passive
                    preyAdvance(i,j);
                }
            }
        }
    }
}

void Colony::MutaliskPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].Status() == MTLK_H) {
                if( !universe[i][j].isMoved() ) {
                    if(scanAhead(i,j,universe[i][j].getOrientaton()))
                        MutaliskMarch(i,j);
                }
            }
        }
    }

}

void Colony::MutaliskMarch(const int i, const int j)
{
    //go forward, and destroy surrounding and move body
    //aheadPoint is update by the scanAhead
    QPoint tempBodyCoor = getBodyCenter(i,j);
    Dir tempDir = universe[i][j].getOrientaton();
    switch (universe[i][j].getOrientaton()){
        case UP:
        case DOWN:
            universe[i][j - 1].kill();
            universe[i][j + 1].kill();
            break;
        case LEFT:
        case RIGHT:
            universe[i-1][j].kill();
            universe[i+1][j].kill();
            break;
        default:
            break;
    }
    universe[i][j] >> universe[aheadPoint.x()][aheadPoint.y()];
    MutaliskBodyMarch(tempBodyCoor,tempDir);
}

void Colony::MutaliskBodyMarch(const QPoint &bodyCoor, const Dir &on)
{
    switch (on) {
    case UP:
        for (int i = bodyCoor.x() - 1; i < bodyCoor.x() + 2; ++i)
            for (int j = bodyCoor.y() - 1; j < bodyCoor.y() + 2; ++j)
                universe[i][j] >> universe[i-1][j];
        break;
    case DOWN:
        for (int i = bodyCoor.x() + 1; i > bodyCoor.x() - 2; --i)
            for (int j = bodyCoor.y() - 1; j < bodyCoor.y() + 2; ++j)
                universe[i][j] >> universe[i+1][j];
        break;
    case LEFT:
        for (int j = bodyCoor.y() - 1; j < bodyCoor.y() + 2; ++j)
            for (int i = bodyCoor.x() - 1; i < bodyCoor.x() + 2; ++i)
                universe[i][j] >> universe[i][j-1];
        break;
    case RIGHT:
        for (int j = bodyCoor.y() + 1; j > bodyCoor.y() - 2; --j)
            for (int i = bodyCoor.x() - 1; i < bodyCoor.x() + 2; ++i)
                universe[i][j] >> universe[i][j+1];
        break;
    default:
        break;
    }

}

void Colony::predatorAdvance(int i, int j)
{
    //BUG: [SOLVED]Grid destructor kept getting called, WHY?
    //ANSWER: [SOLVED], your << operator is passed by value, instead of reference

    //BUG : [SOLVED] Somewhere the diagonal creature is always get killed
    //ANSWER: Your condition in scan perimeter was not correct

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

void Colony::rotateMutalisk(const int i, const int j)
{
    Dir rotateDirection = scanMTKRotateSpace(i,j);
    QPoint newHead = whereIsHead(QPoint(i,j),rotateDirection);
    universe[i][j] >> universe[newHead.x() ][ newHead.y()];
}

int Colony::whatsHere(int i, int j) const
{
    return universe[i][j].Status();
}
