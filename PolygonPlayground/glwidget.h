#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <iostream>
using namespace std;

//QT TOOLSkkkkkkk
#include <QGLWidget>
#include <QList>
#include <QTimer>
#include <QMessageBox>

//Usr Inputs
#include <QKeyEvent>
#include <QMouseEvent>
#include <QEvent>

//written classs
#include "polygon.h" //derived from QPolygonF

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit glWidget(QWidget *parent = 0);

private:
    QList<Polygon> PolyBots; // polygon is inherited from QPolygonF
    QVector<float> colorComb;
    QTimer* timer;
    QPointF ScreenPos;
    bool isRotate;

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

public slots:
    void addPolygon();
    void changeRotate();
    void changeAllColor();
    void next();
    void Run();
    void Stop();


    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // GLWIDGET_H
