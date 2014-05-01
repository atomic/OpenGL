#ifndef GLWIDGET_H
#define GLWIDGET_H

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
#include "colony.h"

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit glWidget(QWidget *parent = 0);

private:
    Colony* Exodus;
    QTimer* timer;
    QPointF ScreenPos;
    QPointF** glCoord;
    int i_MAX,j_MAX;
    int r; //size of the point?
    bool isRun;
    void convAllCoordinates();

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

public slots:

    void Next();
    void Run();
    void Stop();
    void setPtSize(int pt);


    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // GLWIDGET_H
