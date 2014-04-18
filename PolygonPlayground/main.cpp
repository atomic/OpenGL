#include <iostream>
using namespace std;
#include  <QApplication>
#include  "mywindow.h"
//#include "glwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    MyWindow window;
    window.show();

//    glWidget canvas;
//    canvas.show();



    return app.exec();
    return 0;
}
