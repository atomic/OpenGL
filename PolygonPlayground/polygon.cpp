#include "polygon.h"


Polygon::Polygon() : QPolygonF() , color(3)
{
    srand(time(NULL));
    changeColor();
    angular_v_f = rand_FloatRange(0.1,M_PI/2);
    velocity.rx() = rand_FloatRange(-0.05,0.05);
    velocity.ry() = rand_FloatRange(-0.05,0.05);
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
//    updateCentroid();
    if(isRotate) {
        rotatePolygon();
    }
    translate(velocity);
    centroid.rx() += velocity.x();
    centroid.ry() += velocity.y();
    if(horizontalCollide())
        velocity.rx() *= -1;
    if(verticalCollide())
        velocity.ry() *= -1;
}

void Polygon::rotatePolygon() //not working
{
    for (int n = 0; n < size(); ++n) {
        (*this)[n].rx() = cos(angular_v_f) * ( (*this)[n].rx() - centroid.x() ) - sin(angular_v_f) * ((*this)[n].ry()-centroid.y()) + centroid.x();
        (*this)[n].ry() = sin(angular_v_f) * ( (*this)[n].rx() - centroid.x() ) + cos(angular_v_f) * ((*this)[n].ry()-centroid.y()) + centroid.y();
    }
}

void Polygon::changeColor()
{
    for (int i = 0; i < 3; ++i)
        color[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Polygon::updateCentroid()
{
    float xtot(0), ytot(0);
    for (int i = 0; i < size(); ++i) {
        xtot += (*this)[i].x();
        ytot += (*this)[i].y();
    }
    centroid.setX(xtot/size());
    centroid.setY(ytot/size());
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
