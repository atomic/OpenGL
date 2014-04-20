#include "polygon.h"

Polygon::Polygon() : QPolygonF() , velocity(0.01,0.01), color(3)
{
    srand(time(NULL));
    changeColor();
    sides = rand() % 4 + 3;
    radius = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    qDebug() << "Radius " << radius;
    qDebug() << "Sides " << sides;
    for (int i = 0; i < sides; ++i)
        append(QPointF(radius*cos(i*2*M_PI/sides),radius*sin(i*2*M_PI/sides)));
    qDebug() << "New polygon coordinate: "  << *this;
}

Polygon::Polygon(const QPointF &c) : Polygon() //Delegating cons C++11 only
{
    center.setX(c.x());
    center.setY(c.y());
}

void Polygon::move()
{
    translate(velocity);
    if(horizontalCollide())
        velocity.rx() *= -1;
    if(verticalCollide())
        velocity.ry() *= -1;

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
