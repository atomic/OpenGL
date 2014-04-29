#include "colony.h"


int main()
{
    Colony Exodus(20,20);
    Exodus.print();
    cout << "Now, lets randomize them. \n";
    Exodus.randomize();
    Exodus.print();
    cout << "GO PREDATOR ....";

    bool done = false;
    while(!done) {
        Exodus.PredatorPhase();
        Exodus.print();
        cin.get();
    }
    return 0;
}

