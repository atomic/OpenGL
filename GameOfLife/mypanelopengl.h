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
#include <QMessageBox>

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
    void countGeneration(int c);
    void template_display_i(int i);
    void template_display_j(int j);

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
    void clickToSavePattern();

private:
    QMessageBox messageBox;
    bool SAVE_READY;
    bool SAVE_MAP_DISPLAY;
    bool dragSAVE;
    bool scribbling;
    int savePos1_i, savePos1_j,savePos2_i, savePos2_j;
    float mouse_x, mouse_y;
    int template_index;
    int template_i, template_j;
    int world[m+2][n+2];
    float speed;
    int temp_i, temp_j;
    float r;
    float x, y;
    int global_gen;
    QTimer* timer;


protected:
    void initializeGL();
    void convCoordinates(int i, int j);
    int conv_x_j(int x);
    int conv_y_i(int y);
    void paintGL();
    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void run();
    void stop();
    void resizeGL(int w, int h);
    
};

#endif // MYPANELOPENGL_H
