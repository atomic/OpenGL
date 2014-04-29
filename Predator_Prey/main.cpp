#include "colony.h"


int main()
{
    Colony Exodus(20,20);
    Exodus.print();
    cout << "Now, lets randomize them. \n";
    Exodus.randomize();
    Exodus.print();
    Exodus.PredatorPhase();
    Exodus.print();

    return 0;
}

