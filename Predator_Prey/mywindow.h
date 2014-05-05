#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtWidgets>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>

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
   void updateptSizeText(int value){ptSizeDisplay->setText(QString("%1").arg(value)); }
//    void updateCount();

private:
    QSlider *ptSizeSlider;
    QPushButton *exitButton;
    QPushButton *nextButton;
    QPushButton *runButton;
    QPushButton *stopButton;
    QPushButton *spawnMTKButton;
    QSpinBox *iPosButton;
    QSpinBox *jPosButton;
    glWidget *canvas;
    QLabel *ptSizeDisplay;

};
#endif // MYWINDOW_H
