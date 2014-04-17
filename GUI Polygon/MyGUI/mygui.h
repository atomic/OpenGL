#ifndef MYGUI_H
#define MYGUI_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
//#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGLWidget>

#include "glwidget.h"

#include <iostream>

using namespace std;

class MyGui : public QWidget
{
    Q_OBJECT

public:
    MyGui();

signals:
    void actionSignal(); //Appears to be function but WITHOUT codes.

public slots:
    void Load();
    void Save();
    void Action();


private:
    QPushButton* exitButton;
    QPushButton* saveButton;
    QPushButton* loadButton;

    glWidget* glwidget;

//    QTextEdit* textArea;
};

#endif // MYGUI_H
