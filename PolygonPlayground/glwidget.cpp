#include "glwidget.h"

glWidget::glWidget()
{
}

void glWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3,0.1,0.4);
    glBegin(GL_QUADS);
        glVertex3f(-0.7,-0.7,0.5);
        glVertex3f(-0.7,0.7,0.5);
        glVertex3f(0.7,0.7,0.5);
        glVertex3f(0.7,-0.7,0.5);
    glEnd();
    glColor3f(0.5,0.2,0.7);
    glBegin(GL_QUADS);
        glVertex3f(-0.5,-0.5,0);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(0.5,0.5,0);
        glVertex3f(0.5,-0.5,0);
    glEnd();

}

void glWidget::initializeGL()
{
    glClearColor(0.7,0.7,0.4,0.5);
}

void glWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
}
