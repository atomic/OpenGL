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

protected:
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);

public slots:

    void next();
    void Run();
    void Stop();


    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // GLWIDGET_H
