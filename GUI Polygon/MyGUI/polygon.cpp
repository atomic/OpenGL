#include "polygon.h"

PolyNOTgon::PolyNOTgon()
{
}
PolyNOTgon::PolyNOTgon(int n, Coord* v){
    SetVertices(n, v);
}

void PolyNOTgon::SetVertices(int n, Coord* v){
    vertices = v;
    numOfVertices = n;

}
ostream& operator <<(ostream& out, const PolyNOTgon& p){
    for (int i = 0; i<p.numOfVertices; i++){
        out<<p.vertices[i]<<" ";
    }
    out<<endl;
    return out;
}
