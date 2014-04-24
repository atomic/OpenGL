#include "polygon.h"


Polygon::Polygon() : QPolygonF() , color(3)
{
    srand(time(NULL));
    changeColor();
//    angular_vf = rand_FloatRange(4.0,10.0);
    angular_vf = rand_FloatRange(M_PI/30,M_PI/20);
    velocity.rx() = rand_FloatRange(-0.05,0.05);
    velocity.ry() = rand_FloatRange(-0.05,0.05);
    centroid = QPointF(0.0,0.0);
    sides = rand() % 4 + 3;
    radius = static_cast <float> (rand() % RAND_MAX/6) / static_cast <float> (RAND_MAX);
    for (int i = 0; i < sides; ++i)
        append(QPointF(radius*cos(i*2*M_PI/sides),radius*sin(i*2*M_PI/sides)));
    updateCentroid();
}

Polygon::Polygon(const QPointF &c) : Polygon() //Delegating cons C++11 only
{
    centroid.setX(c.x());
    centroid.setY(c.y());
}

void Polygon::move(bool isRotate)
{
    if(isRotate) {
        rotatePolygon();
    }
    translate(velocity); //add velocity to every QPointF in vector
    centroid.rx() += velocity.x();
    centroid.ry() += velocity.y();
    if(horizontalCollide())
        velocity.rx() *= -1;
    if(verticalCollide())
        velocity.ry() *= -1;
}

void Polygon::rotatePolygon() //not working
{
    /*
     * Formula : x : x*cos(angle) - y*sin(angle)
     *           y : x*sin(angle) + y*cos(angle)
     */
    for (int n = 0; n < size(); ++n) {
        temp.rx() = ((*this)[n].x() - centroid.x() )*cos(angular_vf) -
                    ((*this)[n].y() - centroid.y() )*sin(angular_vf);
        temp.ry() = ((*this)[n].x() - centroid.x() )*sin(angular_vf) +
                    ((*this)[n].y() - centroid.y() )*cos(angular_vf);
        //TODO : Fix polygon here, rotation about origin already working
        (*this)[n].rx() = temp.rx();
        (*this)[n].ry() = temp.ry();
    }
}

void Polygon::changeColor()
{
    for (int i = 0; i < 3; ++i)
        color[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}


bool Polygon::horizontalCollide() const
{
    for (int i = 0; i < size(); ++i)
        if( (*this)[i].x() > 1 || (*this)[i].x() < -1  )
            return true;
    return false;
}

bool Polygon::verticalCollide() const
{
    for (int i = 0; i < size(); ++i)
        if( (*this)[i].y() > 1 || (*this)[i].y() < -1  )
            return true;
    return false;
}
