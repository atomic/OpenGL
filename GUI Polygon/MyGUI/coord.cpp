#include "coord.h"
#include <iostream>

using namespace std;
Coord::Coord()
{
}
Coord::Coord(float newX, float newY):x(newX), y(newY)
{ }

ostream& operator <<(ostream& out, const Coord& p){
    out<<"("<<p.x<<", "<<p.y<<")";
    return out;
}
