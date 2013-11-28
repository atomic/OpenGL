#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QGLWidget>


class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT

public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
    
signals:
    
private slots:
    void process();

private:
    int world[50][50];
    float r;
    float x, y;
    float glWidth;
    float glHeight;
    int   gridWidth;//size of array
    int   gridHeight;//size of array
    float boxHeight;
    float boxWidth;
//    int cell[size][size];
    QTimer* timer;


protected:
    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *e);
    void run();
    void stop();
    void resizeGL(int w, int h);
    
};

#endif // MYPANELOPENGL_H
