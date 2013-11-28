#include "glwidget.h"
#include <GL/glut.h>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16); //This is the delay
}


void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2 ,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(0.5, 1, 1, 1);
    glColor3f(1, 0.6, 0);
    glutSolidTeapot(0.6);

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
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5, 0,0,0, 0,1,0);
}
