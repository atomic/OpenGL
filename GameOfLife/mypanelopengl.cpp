#include "GL/glu.h"
#include <cmath>
#include <iostream>
#include "gameoflife.h"
#include <QDebug>
#include <QtDebug>

using namespace std;


MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    speed=100;
}

void MyPanelOpenGL::initializeGL() {
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f,0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void MyPanelOpenGL::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    float h_box_length = 1.0/n;
    float v_box_length = 1.0/m;
    glColor3f(0.0f,1.0f,0.5f); //default
    //The IF statements is to print different color for the wall that is mirrored
    //BUGS : Top, Right Wall not displaying
    //Printing Top and Bot wall
    for (int j = 0; j < n+2; ++j) {
        if (world[0][j] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        convCoordinates(0,j);
        qDebug() << x << "," << y;
        glBegin(GL_QUADS);
            glVertex2f(x-h_box_length,y+v_box_length);
            glVertex2f(x-h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y+v_box_length);
        glEnd();
        glColor3f(0.0f,1.0f,0.5f); //default
        if (world[m+1][j] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        convCoordinates(m+1,j);
        glBegin(GL_QUADS);
            glVertex2f(x-h_box_length,y+v_box_length);
            glVertex2f(x-h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y+v_box_length);
        glEnd();
        glColor3f(0.0f,1.0f,0.5f); //default
    }
    //---------------Printing left and right wall-----
    for (int i = 0; i < m+2; ++i) {
        if (world[i][0] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        convCoordinates(i,0);
        glBegin(GL_QUADS);
            glVertex2f(x-h_box_length,y+v_box_length);
            glVertex2f(x-h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y+v_box_length);
        glEnd();
        glColor3f(0.0f,1.0f,0.5f); //default
        if (world[i][n+1] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        convCoordinates(i,n+1);
        glBegin(GL_QUADS);
            glVertex2f(x-h_box_length,y+v_box_length);
            glVertex2f(x-h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y-v_box_length);
            glVertex2f(x+h_box_length,y+v_box_length);
        glEnd();
        glColor3f(0.0f,1.0f,0.5f); //default
    }

    //--------------PRINTING WORLDS------------------
    for(int i = 1 ;i < m+1; i++) {
        for(int j=  1 ; j < n+1; j++) {
            if(world[i][j] == 1)
                glColor3f(1.9f, 0.0f, 0.0f);
            else
                glColor3f(0.0f, 0.0f,0.0f);
            convCoordinates(i,j);
            glBegin(GL_QUADS);
                glVertex2f(x-h_box_length,y+v_box_length);
                glVertex2f(x-h_box_length,y-v_box_length);
                glVertex2f(x+h_box_length,y-v_box_length);
                glVertex2f(x+h_box_length,y+v_box_length);
            glEnd();
        }

    }
}
void MyPanelOpenGL::clickToLoadInput() {
    load_World(world);
    repaint();
    updateGL();
}

void MyPanelOpenGL::clickToReset() {
    reset(world);
    repaint();
    updateGL();
}

void MyPanelOpenGL::clickToGenerate() {
    process();
}

void MyPanelOpenGL::clickToRandomize() {
    random_World(world);
    repaint(); //This is from GL library
    updateGL();
}

void MyPanelOpenGL::clickToRun() {
    run();
}

void MyPanelOpenGL::clickToStop() {
    stop();
}


void MyPanelOpenGL::convCoordinates(int i, int j) {

    x = static_cast<float>(-1.0 + (2.0/n)*j); //Int times float? Float?
    y = static_cast<float>(-1.0 + (2.0/m)*i);
}

void MyPanelOpenGL::mousePressEvent(QMouseEvent *mouse) {
    switch(mouse->button() == Qt::LeftButton) {
       //later on for clicking screen
    }
}

void MyPanelOpenGL::changeSpeed(int v) {
    speed = static_cast<float>(v);
//    qDebug() << " speed = " << speed;
    stop();
    run();
}


void MyPanelOpenGL::keyPressEvent(QKeyEvent *e) {
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
        timer->start(speed); //delay
    }
}

void MyPanelOpenGL::stop() {
    if(timer) {
        delete timer;
        timer = NULL;
    }
}

void MyPanelOpenGL::process() {
    generate_World(world);
    mirror_edges(world);
    repaint(); //This is from GL library
    updateGL(); //This is from library too
}


void MyPanelOpenGL::resizeGL(int width, int height) {
    glViewport( 0, 0, (GLint)width,(GLint)height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();   // Reset the camera
    gluPerspective( 45.0f,
                    (GLfloat)width/(GLfloat)height,
                    1.0f,
                    100.0f );
}
