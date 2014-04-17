#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class glWidget : public QGLWidget
{
public:
    glWidget();
    void paintGL();
    void initializeGL();
    void resizeGL(int width,int height);
};

#endif // GLWIDGET_H
