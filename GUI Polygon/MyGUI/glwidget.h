#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <iostream>

using namespace std;

#include <QGLWidget>
#include "coord.h"
#include "polygon.h"

class glWidget : public QGLWidget
{
    Q_OBJECT

public:
    glWidget();

public slots:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
public:
    PolyNOTgon* PList;
};

#endif // GLWIDGET_H
