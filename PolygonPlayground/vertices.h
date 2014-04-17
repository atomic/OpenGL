#ifndef VERTICES_H
#define VERTICES_H
#include "coordinate.h"

using namespace std;

struct vertices
{
public:
    coordinate* coordinates;
    int vertex;
    vertices();
    ~vertices();
};

vertices::vertices() : vertex(0)
{
}

vertices::~vertices()
{
    for(int i = 0; i < vertex; ++i)
        delete &coordinates[i];
}


#endif // VERTICES_H
