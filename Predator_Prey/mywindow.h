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
   void updateptSizeText(int value){ptSize->setText(QString("%1").arg(value)); }
//    void updateCount();

private:
    QSlider *ptSizeSlider;
    QPushButton *exitButton;
    QPushButton *nextButton;
    QPushButton *runButton;
    QPushButton *stopButton;
    glWidget *canvas;
    QLabel *ptSize;


};
#endif // MYWINDOW_H
