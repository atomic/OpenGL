#ifndef POLYGON_H
#define POLYGON_H
#include <QList>
#include "vertices.h"

class Polygon
{
private:
    vertices corners;
    coordinate center;

public:
    Polygon();
    Polygon(double radius, int vertex, coordinate center);
    Polygon(int duplicates);

};



#endif // POLYGON_H
