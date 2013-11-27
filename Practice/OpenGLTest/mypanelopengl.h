#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);

signals:


protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();


private:
    int sides;
    double radius;

public slots:
    void changeSides(int s);
    void changeRadius(double r);

};

#endif // MYPANELOPENGL_H
