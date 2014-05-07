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
               if(universe[V][H].getGene() == EMPTY) //if empty
                   availableGrids << QPoint(V,H);
               else if( (universe[V][H].getGene() == PREY) && (Type == 1)) //only for Predator
                   availableFoods << QPoint(V,H);
            }
        }
    }
}

void Colony::spawnMutaliskBody(const int i, const int j)
{
    //before using this, make sure your i,j is not close to WALL
    for (int o_i = i-1; o_i < i+2; ++o_i)
        for (int o_j = j-1; o_j < j+2; ++o_j)
            universe[o_i][o_j].spawnMutaliskBody();
}

void Colony::killMutaliskBody(const QPoint body)
{
    for (int v = body.x()-1; v < body.x()+2; ++v)
        for (int h = body.y()-1; h < body.y()+2; ++h)
            universe[v][h].kill();
}

void Colony::spawnMutalisk(const int i, const int j, Dir Ori)
{
    universe[i][j].spawnMutaliskHead(Ori);
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

void Colony::spawnMTLKShell(const int i, const int j)
{
    for (int v = i -1 ; v < i + 2; ++v)
        for (int h = j - 1; h < j + 2; ++h)
            if(!(v == i && h == j))
                universe[v][h].spawnMutaliskEgg_S();
}

void Colony::spawnRandomMutalisk()
{
    bool done = false;
    for (int i = MAX_i/2 - 5; i < MAX_i - 6 && !done; ++i) {
        for (int j = MAX_j/2 - 5; j < MAX_j - 6 && !done; ++j) {
            if(scanDeploymentArea(i,j) && !done)  {
                spawnMutalisk(i-2,j,UP);
                done = true;
            }
        }
    }
}

void Colony::killMutalisk(const int i, const int j)
{
    //first look for direction, and get the Body coordinate
    killMutaliskBody(getBodyCenter(i,j));
    universe[i][j].kill();
}

bool Colony::scanAhead(const int i, const int j, const Dir on)
{
    // Use aheadPoint here, because you are going to need the
    // the point to move later on, so you dont have to double convert
    switch (on) {
    case UP:
        aheadPoint.setX(i-1);
        aheadPoint.setY(j);
        return (universe[i][j-1].isEdible() && universe[i][j+1].isEdible() && universe[i-1][j].isEdible());
        break;
    case DOWN:
        aheadPoint.setX(i+1);
        aheadPoint.setY(j);
        return (universe[i][j-1].isEdible() && universe[i][j+1].isEdible() && universe[i+1][j].isEdible());
        break;
    case LEFT:
        aheadPoint.setX(i);
        aheadPoint.setY(j-1);
        return (universe[i-1][j].isEdible() && universe[i+1][j].isEdible() && universe[i][j-1].isEdible());
        break;
    case RIGHT:
        aheadPoint.setX(i);
        aheadPoint.setY(j+1);
        return (universe[i-1][j].isEdible() && universe[i+1][j].isEdible() && universe[i][j+1].isEdible());
        break;
    default:
        break;
    }
    return false;//not necessary if 'on' exists
}

bool Colony::scanDeploymentArea(const int i, const int j, const int size)
{
    for (int v = i - size/2; v < i + size/2 + 1; ++v)
        for (int h = j - size/2; h < j + size/2 + 1; ++h)
            if( !(v == i && h == j) && !universe[v][h].isEdible() )
                return false;
    return true;
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

void Colony::mainPhase()
{
    refreshPhase();
    PredatorPhase();
    PreyPhase();
    MutaliskPhase();
    MutaliskHatchPhase();
}

void Colony::refreshPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            if(universe[i][j].getGene() == PREY
                    || universe[i][j].getGene() == PREDATOR
                    || universe[i][j].getGene() == MTLK_H)
                universe[i][j].refresh();
}

void Colony::PredatorPhase()
{
    /*Corners*/
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].getGene() == PREDATOR) {
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
            if(universe[i][j].getGene() == PREDATOR)
                if(universe[i][j].isStarving())
                    universe[i][j].kill();
}

void Colony::PreyPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            if(universe[i][j].getGene() == PREY) {
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
            if(universe[i][j].getGene() == MTLK_H) {
                if( !universe[i][j].isMoved() ) {
                    if(universe[i][j].isPregnant() && !universe[i][j].MTLKhatchery)
                        universe[i][j].MTLKHatchEgg();
                    randomTemp = rand() % 15;
                    if(randomTemp == 1)
                        rotateMutalisk(i,j);
                    else {
                        if(scanAhead(i,j,universe[i][j].getOrientaton()))
                            MutaliskMarch(i,j);
                        else
                            rotateMutalisk(i,j);
                    }
                }
            }
        }
    }
    //Check starvation
    for (int i = 1; i < MAX_i + 1; ++i)
        for (int j = 1; j < MAX_j + 1; ++j)
            if(universe[i][j].getGene() == MTLK_H)
                if(universe[i][j].isStarving())
                    killMutalisk(i,j);
}

void Colony::MutaliskHatchPhase()
{
    for (int i = 1; i < MAX_i + 1; ++i) {
        for (int j = 1; j < MAX_j + 1; ++j) {
            switch (universe[i][j].getGene()) {
            case EMPTY:
                if(universe[i][j].MTLKhatchery)
                    universe[i][j].spawnMutaliskEgg_O();
                break;
            case MTLK_E_O:
                universe[i][j].MTLKHatchEvo(); //Egg cant move so, this is the move
                if(universe[i][j].isPregnant() && scanDeploymentArea(i,j,3)) //scan 3x3
                    spawnMTLKShell(i,j);
                else if (universe[i][j].MTLKEggMature() ) {
                    if(universe[i-2][j].isEdible()) {
                        spawnMutalisk(i-2,j,UP);
                        universe[i][j].MTLKhatchery = false;
                    }
                }
            default:
                break;
            }
            //TODO: Still need to finish the final spawn
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
    //after Head kill and evolve, set all of its body level to the same level
    //the head has
    MutaliskBodyMarch(tempBodyCoor,tempDir,universe[aheadPoint.x()][aheadPoint.y()].getLevel());
}

void Colony::MutaliskBodyMarch(const QPoint &bodyCoor, const Dir &on, const int headLV)
{
    switch (on) {
    case UP:
        for (int i = bodyCoor.x() - 1; i < bodyCoor.x() + 2; ++i) {
            for (int j = bodyCoor.y() - 1; j < bodyCoor.y() + 2; ++j) {
                universe[i][j].setLevel(headLV);
                universe[i][j] >> universe[i-1][j];
            }
        }
        break;
    case DOWN:
        for (int i = bodyCoor.x() + 1; i > bodyCoor.x() - 2; --i) {
            for (int j = bodyCoor.y() - 1; j < bodyCoor.y() + 2; ++j) {
                universe[i][j].setLevel(headLV);
                universe[i][j] >> universe[i+1][j];
            }
        }
        break;
    case LEFT:
        for (int j = bodyCoor.y() - 1; j < bodyCoor.y() + 2; ++j) {
            for (int i = bodyCoor.x() - 1; i < bodyCoor.x() + 2; ++i) {
                universe[i][j].setLevel(headLV);
                universe[i][j] >> universe[i][j-1];
            }
        }
        break;
    case RIGHT:
        for (int j = bodyCoor.y() + 1; j > bodyCoor.y() - 2; --j) {
            for (int i = bodyCoor.x() - 1; i < bodyCoor.x() + 2; ++i) {
                universe[i][j].setLevel(headLV);
                universe[i][j] >> universe[i][j+1];
            }
        }
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
        if(! universe[availableGrids[comb].x()][availableGrids[comb].y()].isEdible()) {
            availableGrids.removeAt(comb);
            comb = 0;
        }
    }
    //no check for if availableGrid == 0, there has to be some space to rotate
    //TODO: I was wrong, there might be a case where Mutalisk can't rotate at all
    int choosenIndex = rand() % availableGrids.size();

    //At this point, the point for head to rotate to is already choosen
    //So, we just need to give new direction for the head to move
    Dir newHeadDirection = findHeadDirection(center,availableGrids[choosenIndex]);
    //Now, lets set the head direction to newHeadDirection
    universe[i][j].setOrientaton(newHeadDirection);
    universe[i][j] >> universe[availableGrids[choosenIndex].x() ][ availableGrids[choosenIndex].y()];

}

int Colony::whatsHere(int i, int j) const
{
    return universe[i][j].getGene();
}
