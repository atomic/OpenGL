#ifndef VERTICES_H
#define VERTICES_H
#include "coordinate.h"

using namespace std;

struct vertices
{
public:
    coor2* coordinates;
    int vertex; //this is to keep track how many vertices
    void clear();
    vertices();
    vertices(int n);
    vertices(int n, coor2* points);
    ~vertices();

    coor2 &operator [](const int i);
    vertices &operator =(const vertices &right);
    friend ostream& operator <<(ostream& out, const vertices& verticus);
};

void vertices::clear()
{
    if(vertex > 0)
        for(int i = 0; i < vertex; ++i)
            delete &coordinates[i];
    vertex = 0;
}

vertices::vertices() : vertex(0)
{
}

vertices::vertices(int n) : vertex(n)
{
    coordinates = new coor2[n];
}

vertices::vertices(int n, coor2 *points) : vertex(n)
{
    coordinates = new coor2[n];
    for (int i = 0; i < vertex; ++i)
        coordinates[i] = points[i];
}

coor2 &vertices::operator [](const int i){
    return coordinates[i];
}

vertices &vertices::operator =(const vertices &right)
{
    clear();
    vertex = right.vertex;
    for (int i = 0; i < vertex; ++i)
        coordinates[i] = right.coordinates[i];
    return *this;
}

ostream &operator <<(ostream &out, const vertices &verticus)
{
    for (int j = 0; j < verticus.vertex; ++j)
        out << verticus.coordinates[j] << " , ";
    return out;
}


vertices::~vertices()
{
    for(int i = 0; i < vertex; ++i)
        delete &coordinates[i];
}

#endif // VERTICES_H
