#include "mypanelopengl.h"
#include <cmath>


MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{

    sides = 3;
    radius = 1.0;
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
	glTranslated(5.0, 5.0, 0.0);
	glLineWidth(1);
	glColor3f(0,0.7f,0.7f);

	glBegin(GL_POLYGON);
	for (int i = 0; i < sides; ++i) {
		glVertex2f(radius*cos(i*2*3.14159265/sides),
				   radius*sin(i*2*3.14159265/sides));
	} glEnd();
	glLineWidth(2);
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < sides; ++i) {
		glVertex2f(radius*cos(i*2*3.14159265/sides),
				   radius*sin(i*2*3.14159265/sides));
	} glEnd();

}
void MyPanelOpenGL::resizeGL(int x, int h)
{
	
}

void MyPanelOpenGL::changeSides(int s){}
void MyPanelOpenGL::changeRadius(double r){}
