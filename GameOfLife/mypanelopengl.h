#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QGLWidget>
//#include "gameoflife.h" cannot do this,
//    mypanelopengl.cpp include both m and n from .h already.


class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT

public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
    
signals:
    
private slots:
    void process();

public slots:
    void changePointSize(int pSize);
    void changeSpeed(int v);

private:
    int world[52][52];
    float speed;
    float r;
    float pSize;
    float x, y;
    float glWidth;
    float glHeight;
    int   gridWidth;//size of array
    int   gridHeight;//size of array
    float boxHeight;
    float boxWidth;
    QTimer* timer;


protected:
    void initializeGL();
    void convCoordinates(int i, int j);
    void paintGL();
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *mouse);
    void run();
    void stop();
    void resizeGL(int w, int h);
    
};

#endif // MYPANELOPENGL_H
