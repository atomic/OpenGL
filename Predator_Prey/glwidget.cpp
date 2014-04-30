#include "glwidget.h"

glWidget::glWidget(QWidget *parent) :
    QGLWidget(parent)
{
    Exodus = new Colony(30,40);
    Exodus->randomize();
    Exodus->buildWalls();
}

void glWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.5);
}
void glWidget::Run()
{
    if(!timer){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()),
                this, SLOT(next()));
        timer->start(5); //in ms
    }
}

void glWidget::Stop()
{
    if(timer) {
        delete timer;
        timer = NULL;
    }
}

void glWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int n = 0; n < Exodus->getMAX_i(); ++n) {
        glBegin(GL_POLYGON);
//        for (int j = 0; j < Exodus->getMAX_j(); ++j)
//            glVertex4f();
        glEnd();
    }
}

void glWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();   // Reset the camera
}

void glWidget::next()
{
    Exodus->mainPhase();
    updateGL(); // this calls paintGL();
}

void glWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()){
    case Qt::Key_Right:
        break;
    case Qt::Key_Left:
        break;
    case Qt::Key_Up: //run when its pressed
        break;
    case Qt::Key_Down: //stops when released
        break;
    case Qt::Key_Space:
        break;
    case Qt::Key_Escape:
        break;
    case Qt::Key_S:
        break;
    case Qt::Key_L:
        break;
    }
}

void glWidget::mousePressEvent(QMouseEvent *e)
{
    ScreenPos = e->windowPos();
}

void glWidget::mouseReleaseEvent(QMouseEvent *e)
{
}
