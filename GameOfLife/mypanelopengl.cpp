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
    random_World(world);
    float length = 1.0/m;
    pSize = 0.9;
    glPointSize((r));
    for(int i = -m ;i < m;i++) {
        for(int j= -n;j<n;j++) {
            if(world[i][j] == 1)
                glColor3f(1.9f, 0.0f, 0.0f);
            else
                glColor3f(0.0f, 1.9f, 0.0f);
             glBegin(GL_POINTS);
              glVertex2f(i*length,j*length);
            glEnd();
        }

    }
}

void MyPanelOpenGL::mousePressEvent(QMouseEvent *mouse)
{
    switch(mouse->button() == Qt::LeftButton) {
       //later on for clicking screen
    }
}

void MyPanelOpenGL::changePointSize(int pSize)
{
    r = static_cast<float>(pSize/10);
}



void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Right:
        process();
        break;
    case Qt::Key_Left:
        random_World(world);
        process();
        break;
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
        connect(timer, SIGNAL(timeout()),
                this, SLOT(process()));
        timer->start(100); //delay
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
    generate_World(world);
    mirror_edges(world);
    repaint(); //This is from GL library
    updateGL(); //This is from library too
}


void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();   // Reset the camera
    gluPerspective( 45.0f,
                    (GLfloat)width/(GLfloat)height,
                    1.0f,
                    100.0f );
}
