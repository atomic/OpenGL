#include "glwidget.h"

glWidget::glWidget()
{
}

void glWidget::initializeGL()
{
    //Sequence: first clear the screen to get ready to draw:
    glClearColor(0, 0, 0, 0);
}

void glWidget::paintGL()
{
    //Same concept as above, clear the color:
    glClear(GL_COLOR_BUFFER_BIT);


    //build a Polygon object.
    //here is your coords...
    Coord* v= new Coord[4];
    v[0] = Coord(-0.1,-0.1);
    v[1] = Coord(0.1,-0.1);
    v[2] = Coord(0.1,0.1);
    v[3] = Coord(-0.1,0.1);
    //build my polygon:
    PolyNOTgon P(4, v);

    glColor3f(0, 1, 0); //RGB

    //now... draw my polygon!
    glBegin(GL_POLYGON); //Begins the drawing; quads == 4 Vertices.

        //replace all these numbers with P.v1.x, p.v2.y etc....
    glVertex3f(P.vertices[0].x,P.vertices[0].y, 0);
    glVertex3f(P.vertices[1].x,P.vertices[1].y, 0);
    glVertex3f(P.vertices[2].x,P.vertices[2].y, 0);
    glVertex3f(P.vertices[3].x,P.vertices[3].y, 0);

    glEnd(); //Ends the drawing.
}

void glWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}
