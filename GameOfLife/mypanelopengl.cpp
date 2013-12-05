#include "GL/glu.h"
#include <cmath>
#include "gameoflife.h"
#include <QDebug>
#include <QtDebug>

using namespace std;


MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
//    clickToLoadInput();
    speed=100;
    r=92;
}

void MyPanelOpenGL::i_input(int i) {
    global_i = i;
}

void MyPanelOpenGL::j_input(int j) {
    global_j = j;
}

void MyPanelOpenGL::clickToChooseIndex(int index) {
    template_index = index + 1;
    qDebug() << template_index;
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
    glPointSize((4*r/m));
    glColor3f(0.0f,1.0f,0.5f);
    //The IF statements is to print different color for the wall that is mirrored
    //Printing Top and Bot wall
    for (int i = 0; i < n+2; ++i) {
        if (world[0][i] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        glBegin(GL_POINTS);
            convCoordinates(0,i);
            glVertex2f(x,y);
        glEnd();
        glColor3f(0.0f,1.0f,0.5f);
        if (world[n+1][i] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        glBegin(GL_POINTS);
            convCoordinates(n+1,i);
            glVertex2f(x,y);
        glEnd();
        //reset default color
        glColor3f(0.0f,1.0f,0.5f);
    }
    //Printing left and right wall
    for (int i = 0; i < m+2; ++i) {
        if (world[i][0] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        glBegin(GL_POINTS);
            convCoordinates(i,0);
            glVertex2f(x,y);
        glEnd();
        glColor3f(0.0f,1.0f,0.5f);
        if (world[i][n+1] == 1)
            glColor3f(0.7f,0.3f,0.5f);
        glBegin(GL_POINTS);
            convCoordinates(i,n+1);
            glVertex2f(x,y);;
        glEnd();
        glColor3f(0.0f,1.0f,0.5f);
    }
    for(int i = 1 ;i < m+1; i++) {
        for(int j=  1 ; j < n+1; j++) {
               convCoordinates(i,j);
            if(world[i][j] == 1)
                glColor3f(1.9f, 0.0f, 0.0f);
            else
                glColor3f(0.0f, 0.0f,0.0f);
             glBegin(GL_POINTS);
             glVertex2f(x,y);
            glEnd();
        }

    }
}
void MyPanelOpenGL::clickToLoadInput() {
    stop();
    load_World(world);
    repaint();
    updateGL();
}

void MyPanelOpenGL::clickToLoadTemplate() {
    int in_m, in_n;
    in_m = global_i; qDebug() << in_m;
    in_n = global_j; qDebug() << in_n;
    int row, col;
    ifstream fin;
    if (template_index == 1)
        fin.open("glider.txt");
    else if (template_index == 2)
        fin.open("pentomino.txt");
    else if (template_index == 3)
        fin.open("pulsar.txt");
    else if (template_index == 4)
        fin.open("exploder.txt");
    else if (template_index == 5)
        fin.open("ten.txt");
    else if (template_index == 6)
        fin.open("spaceship.txt");
    else if (template_index == 7)
        fin.open("glidergun.txt");
    fin >> row;
    fin >> col;
    for (int i = in_m; i < in_m + row; ++i)
        for (int j = in_n; j < in_n + col; ++j)
            fin >> world[i][j];
    fin.close();
    repaint();
    updateGL();
}
#include <iostream>
void MyPanelOpenGL::clickToSave() {
    stop();
    write_World(world);
}

void MyPanelOpenGL::clickToReset() {
    stop();
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
    y = static_cast<float>(1.0 - (2.0/m)*i);
}

void MyPanelOpenGL::mousePressEvent(QMouseEvent *mouse) {
    switch(mouse->button() == Qt::LeftButton) {
       //later on for clicking screen
    }
}

void MyPanelOpenGL::changePointSize(int pSize)  //scroll bar is on ui
{
    r = static_cast<float>(pSize);
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
