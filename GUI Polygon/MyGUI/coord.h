#ifndef COORD_H
#define COORD_H
#include <iostream>
using namespace std;
class Coord
{
public:
    Coord();
    Coord(float newX, float newY);
    friend ostream& operator <<(ostream& out, const Coord& p);

    float x;
    float y;
};

#endif // COORD_H
