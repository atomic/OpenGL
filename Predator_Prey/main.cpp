#include <iostream>
using namespace std;

#include  <QApplication>
#include "mywindow.h"

int main(int argc, char *argv[])
{
//    Colony Exodus(27,40); //optimum screen size
    srand(time(NULL)); //libraries included in grid.h
//    Colony Exodus(30,40);
//    Exodus.randomize();
//    Exodus.buildWalls();
//    Exodus.print();

//    bool done = false;
//    while(!done) {
//        cin.get();
//        Exodus.mainPhase();
//        Exodus.print();
//    }




    QApplication app(argc,argv);
    MyWindow window;
    window.show();

    return app.exec();
    return 0;
}

