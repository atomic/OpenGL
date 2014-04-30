#include "glwidget.h"

glWidget::glWidget(QWidget *parent) :
    QGLWidget(parent), i_MAX(30), j_MAX(40)
{
    //Allocating memories to store coordinates that will be converted to glCoordinates
    glCoord = new QPointF*[i_MAX + 2];
    for (int i = 0; i < i_MAX + 2; ++i)
        glCoord[i] = new QPointF[j_MAX+2];
    convAllCoordinates();
    Exodus = new Colony(i_MAX,j_MAX);
    Exodus->randomize();
    Exodus->buildWalls();
}

void glWidget::convAllCoordinates()
{
    //NOTE: This is unchecked, conversion may be wrong
    for (int i = 0; i < i_MAX + 2; ++i)
        for (int j = 0; j < j_MAX + 2; ++j)
            glCoord[i][j] = QPointF(static_cast<float>(-1.0 + (2.0/(j_MAX+1))*j,
                                    static_cast<float>(1.0 - (2.0/(i_MAX+1))*i)));
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
        timer->start(20); //in ms
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPointSize((4*r/m));
    glColor3f(0.0f,1.0f,0.5f);
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 1 ;i < m+1; i++) {
        for(int j=  1 ; j < n+1; j++) {
               convCoordinates(i,j);
            if(Exodus[i][j])
                glColor3f(1.9f, 0.0f, 0.0f);
            else
                glColor3f(0.0f, 0.0f,0.0f);
             glBegin(GL_POINTS);
             glVertex2f(x,y);
            glEnd();
        }
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
