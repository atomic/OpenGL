#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}


/* ------PROBLEMS:
  - Signal and Slots is unavailable from widget thread
  - How to connect QGLWidget to other display widgets
  - Widgets, widgets and widgets


  */

/* -----SYSTEM INCOMPABILITY
 * Project made on Qt 5
 * Project build on Linux
 *
 */
