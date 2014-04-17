#include "mygui.h"
#include "glwidget.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyGui the_gui;
    the_gui.show();


    return app.exec();


    cout << "\n\n\n\n*** END OF OPERATION!\n" << endl;
    return 0;
}

