#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
using namespace std;

//#include <QList>
#include "vertices.h"

class Polygon
{
public:
    Polygon();
    Polygon(const vertices &in_corners);
    Polygon(double &radius, const int &vertex,const coor2 &center);
    vertices corners; //# vertices stored there
    coor2 center;
    friend ostream& operator <<(ostream& out, const Polygon& p);
};



#endif // POLYGON_H
