#ifndef MYWINDOW_H
#define MYWINDOW_H

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
    void updateCount();

private:
    QSlider *radiusSlider;
    QCheckBox *checkRotate;
    QCheckBox *checkTranslate;
    QPushButton *addButton;
    QLabel *polygonCount;
    QPushButton *colorButton;
    QPushButton *exitButton;
    QPushButton *runButton;
    QPushButton *stopButton;
    QPushButton *loadButton;
    glWidget *canvas;


};
#endif // MYWINDOW_H
