#include <iostream>
using namespace std;
#include  <QApplication>
#include <QLayout>
//#include  "mywindow.h"
#include "glwidget.h"

int main(int argc, char **argv)
{
    //I . Making window
    QApplication app(argc,argv);
//    MyWindow window;
//    window.show();

    //II. Drawing
    glWidget canvas;
    canvas.show();



    return app.exec();
}
