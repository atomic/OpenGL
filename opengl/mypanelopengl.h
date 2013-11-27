#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>
#include <Qtimer>
#include <QKeyEvent>
#include <QResizeEvent>

const int size = 2;

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);

signals:


protected:
    void initializeGL();
    void paintGL();
    void keyPressEvent(QKeyEvent *e);
    void run();
    void stop();
    void resizeGL(int width, int height);

 private slots:
    void process();

private:
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
};

#endif // MYPANELOPENGL_H
