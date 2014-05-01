#include <iostream>
using namespace std;

#include  <QApplication>
#include <QSplashScreen>
#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    srand(time(NULL)); //libraries included in grid.h

    QSplashScreen* splash= new QSplashScreen;
    splash->setPixmap(QPixmap("../Predator_Prey/splash.jpg"));
    splash->show();
    splash->showMessage("Loading world . . .", Qt::AlignBottom, Qt::white);

    MyWindow window;
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&window,SLOT(show()));
//    window.show();
    return app.exec();
}

