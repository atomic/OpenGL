#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <iostream>
using namespace std;

#include <QGLWidget>
#include <QList>
#include <QPolygonF>

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    glWidget();
private:
    QList<QPolygonF> PolyBots;

public slots:
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

};

#endif // GLWIDGET_H
