#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <iostream>
using namespace std;

#include <QtWidgets>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>

#include "glwidget.h"


class MyWindow : public QWidget
{
    Q_OBJECT
public:
    MyWindow();
signals:
    void saveSignal(); //function without codes
    void actionSignal();
    void loadSignal();

public slots:

private:
    QPushButton *exitButton;
    QPushButton *runButton;
    QPushButton *stopButton;
    glWidget *canvas;


};

#endif // MYWINDOW_H
