#ifndef PolyNOTgon_H
#define PolyNOTgon_H

#include <iostream>

using namespace std;

#include "coord.h"
class PolyNOTgon
{
public:
    PolyNOTgon();
    PolyNOTgon(int n, Coord* v);
    void SetVertices(int n, Coord* v);
    Coord* vertices;
    int numOfVertices;
    friend ostream& operator <<(ostream& out, const PolyNOTgon& p);
};

#endif // PolyNOTgon
