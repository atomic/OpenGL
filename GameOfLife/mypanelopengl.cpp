#include "mypanelopengl.h"
#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <iostream>
#include "gameoflife.h"

using namespace std;


MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    r=0;
    x=-0.9;
    y=-0.9;
}

void MyPanelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float length = 0.9/m;
    for(int i =0;i<m;i++) {
        for(int j=0;j<n;j++) {
            glPointSize(10.0f);
            glBegin(GL_POINTS);
              glVertex2f(i,j);
            glEnd();
        }

    }
}

void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) //
    {
    case Qt::Key_Down: //run when its pressed
        run();
        break;
    case Qt::Key_Up: //stops when released
        stop();
        break;
    }

}

void MyPanelOpenGL::run()
{
    if(!timer)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(process()));
        timer->start(100);
    }
}

void MyPanelOpenGL::stop()
{
    if(timer)
    {
        delete timer;
        timer = NULL;
    }
}

void MyPanelOpenGL::process()
{
//    random_World(world);
//    generate_World(world);
//    mirror_edges(world);
    repaint(); //This is from GL library
    updateGL(); //This is from library too
}


void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height,1.0f, 100.0f );

}
