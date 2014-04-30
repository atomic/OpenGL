#include "colony.h"


int main()
{
    Colony Exodus(20,20);
    Exodus.print();
    cout << "Now, lets randomize them. \n";
    Exodus.randomize();
    Exodus.buildWalls();
    Exodus.print();
    cout << "GO PREDATOR ....\n";

    bool done = false;
    while(!done) {
        Exodus.PredatorPhase();
        Exodus.print();
        cin.get();
    }
    return 0;
}

