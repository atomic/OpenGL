#include "colony.h"


int main()
{
    grid leGrid; //test
    //Test detect empty grid
    leGrid.print();
    leGrid.PredatorBreed();
    leGrid.print();
    leGrid.kill();
    leGrid.print();
    leGrid.PreyBreed();
    leGrid.print();

    Colony Kashyiik(20,20);
    Kashyiik.print();
    Kashyiik.randomize();
    Kashyiik.print();

    return 0;
}

