#include "polygon.h"

Polygon::Polygon()
{}

Polygon::Polygon(const vertices &in_corners)
{
    corners = in_corners;
}

ostream &operator <<(ostream &out, const Polygon &p)
{
    for (int i = 0; i < p.corners.vertex; i++)
        out << p.corners << " ";
    out << endl;
    return out;
}
