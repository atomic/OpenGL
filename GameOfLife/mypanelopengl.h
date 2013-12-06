#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QGLWidget>

#include <QDebug>
#include <QMouseEvent>
#include <QPoint>
#include <QEvent>

//#include "gameoflife.h" cannot do this,
//    mypanelopengl.cpp include both m and n from .h already.

const int m = 100;
const int n = 100;

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT

public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
    
signals:
    
private slots:
    void process();

public slots:
    void clickToSave();
    void changePointSize(int pSize);
    void changeSpeed(int v);
    void clickToRandomize();
    void clickToGenerate();
    void clickToLoadInput();
    void clickToReset();
    void clickToRun();
    void clickToStop();
    void i_input(int i);
    void j_input(int j);
    void clickToChooseIndex(int index);
    void clickToLoadTemplate();

private:
    float mouse_x, mouse_y;
    int template_index;
    int global_i, global_j;
    int world[m+2][n+2];
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
    int conv_x_j(float x);
    int conv_y_i(float y);
    void paintGL();
    void keyPressEvent(QKeyEvent *e);


    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

    void run();
    void stop();
    void resizeGL(int w, int h);
    
};

#endif // MYPANELOPENGL_H
