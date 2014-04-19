#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <iostream>
using namespace std;

#include <QGLWidget>
#include <QList>
#include <QPolygonF>
#include <QDebug>
#include <stdlib.h> //for random
#include <time.h> // for random

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    glWidget();
private:
    QList<QPolygonF> PolyBots;
    QVector<float> colorComb;

public slots:
    void changeColor();
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

};

#endif // GLWIDGET_H
