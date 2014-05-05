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
    //these are coordinate input for mutalisk
    Colony* Exodus;
    QTimer* timer;
    QPointF ScreenPos;
    QPointF** glCoord;
    bool isRun;
    int ptSize;
    int i_temp;
    int j_temp;
    void convAllCoordinates();

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

public slots:

    void setPtSize(int NewPtSize) { ptSize = NewPtSize; updateGL(); }
    void set_i_Pos(int new_i) { i_temp = new_i; }
    void set_j_Pos(int new_j) { j_temp = new_j; }
    void spawnMutaliskHere() {Exodus->spawnMutalisk(i_temp,j_temp); updateGL();}
    void spawnRandomMutalisk() {Exodus->spawnRandomMutalisk(); updateGL(); }
    void Next();
    void Run();
    void Stop();


    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);

};

#endif // GLWIDGET_H
