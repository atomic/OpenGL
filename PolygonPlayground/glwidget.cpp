#include "glwidget.h"

glWidget::glWidget()
{
}

void glWidget::paintGL()
{
    //using QList to store polygon objects
    vertices boxCorner(4);
    boxCorner[0] = coor2(-7.5,-7.5);
    boxCorner[1] = coor2(-7.5, 7.5);
    boxCorner[2] = coor2( 7.5, 7.5);
    boxCorner[3] = coor2( 7.5,-7.5);
    PolygonObjects.append(Polygon(boxCorner));

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3,0.1,0.4);
    glBegin(GL_QUADS);
        glVertex3f(boxCorner[0].x,boxCorner[0].y,0);
        glVertex3f(boxCorner[1].x,boxCorner[1].y,0);
        glVertex3f(boxCorner[2].x,boxCorner[2].y,0);
        glVertex3f(boxCorner[3].x,boxCorner[3].y,0);
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
