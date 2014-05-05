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


class RGBcolors : public QVector<float>
{
public:
    RGBcolors(const float r = 0.0f, const float g = 0.0f, const float b = 0.0f)
    {
        this->push_back(r);
        this->push_back(g);
        this->push_back(b);
    }
};


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
    QList<RGBcolors> MTLK_H_colors;
    QList<RGBcolors> MTLK_B_colors;
    bool isRun;
    int ptSize;
    int i_temp;
    int j_temp;
    int level_temp;
    void convAllCoordinates();
    void setUpColorsLevel();

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
