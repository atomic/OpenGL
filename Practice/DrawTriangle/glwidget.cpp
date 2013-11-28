#include "glwidget.h"
#include <GL/glut.h>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}


void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2 ,0);

}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glutWireTeapot(0.6);



//    glBegin(GL_TRIANGLES);
//        glColor3f(1,0,0);
//        glVertex3d(-0.5, -0.5, 0);
//        glColor3f(0,1,0);
//        glVertex3d(0.5, -0.5, 0);
//        glColor3f(0,0,1);
//        glVertex3d(0.0, 0.5, 0);
//    glEnd();
}

void GLWidget::resizeGL(int w, int h) {

}
