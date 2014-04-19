#include "glwidget.h"

glWidget::glWidget()
{
}

void glWidget::paintGL()
{
    PolyBots << QPolygonF(); //this add new QPolygonF , dynamic?
    PolyBots[0] << QPointF(-0.5,-0.5)
                << QPointF(-0.7,0.5)
                << QPointF(0.5,0.5)
                << QPointF(0.5,-0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3,0.1,0.4);
    glBegin(GL_QUADS);
       for (int i = 0; i < 4; ++i)
            glVertex3f(PolyBots[0][i].x(),PolyBots[0][i].y(),0);
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
