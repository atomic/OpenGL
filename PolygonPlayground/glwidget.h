#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <iostream>
using namespace std;

#include <QGLWidget>
#include <QList>
#include "polygon.h"

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    glWidget();
    QList<Polygon> PolygonObjects;

public slots:
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

};

#endif // GLWIDGET_H
