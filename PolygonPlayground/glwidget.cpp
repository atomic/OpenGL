#include "glwidget.h"

glWidget::glWidget()
{
    srand(time(NULL));
    colorComb.resize(3);
    changeColor();
}

void glWidget::changeColor()
{
    for (int i = 0; i < 3; ++i)
        colorComb[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    qDebug() << "New color : " << colorComb;
    updateGL();
}

void glWidget::paintGL()
{
    PolyBots << QPolygonF(); //this add new QPolygonF , dynamic?
    PolyBots[0] << QPointF(-0.5,-0.5)
                << QPointF(-0.7,0.5)
                << QPointF(0.5,0.5)
                << QPointF(0.5,-0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(colorComb[0],colorComb[1],colorComb[2]);
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
