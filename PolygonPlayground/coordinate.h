#ifndef COORDINATE_H
#define COORDINATE_H

struct coor2
{
    coor2(float new_x = 0, float new_y = 0);

    coor2   operator = (const coor2 right);
    coor2   operator + (const coor2 right);
    coor2   operator - (const coor2 right);
    coor2   operator * (const coor2 right);
    coor2   operator * (const int  constant);

    coor2   operator += (const coor2 right);
    coor2   operator -= (const coor2 right);
    coor2   operator *= (const coor2 right);
    coor2   operator *= (const int &constant);

    friend ostream& operator <<(ostream& out, const coor2& p);
    void reset();

    //vars
    float x;
    float y;
};

coor2::coor2(float new_x, float new_y)
{
    x = new_x;
    y = new_y;
}

coor2  coor2::operator =(const coor2  right)
{
    x = right.x;
    y = right.y;
    return *this;
}

coor2  coor2::operator +(const coor2  right)
{
    return coor2(x + right.x, y + right.y);
}

coor2  coor2::operator -(const coor2  right)
{
    return coor2(x - right.x, y - right.y);
}

coor2  coor2::operator *(const coor2  right)
{
    return coor2(x * right.x, y * right.y);
}

coor2  coor2::operator *(const int  constant){
    return coor2(x * constant, y * constant);
}

coor2  coor2::operator +=(const coor2  right){
    x += right.x;
    y += right.y;
    return *this;
}

coor2  coor2::operator -=(const coor2  right){
    x -= right.x;
    y -= right.y;
    return *this;
}

coor2  coor2::operator *=(const coor2  right){
    x *= right.x;
    y -= right.y;
    return *this;
}

ostream &operator <<(ostream &out, const coor2 &p)
{
    out << "("  << p.x << "," << p.y << ")";
    return out;
}

void coor2::reset()
{
    x = 0;
    y = 0;
}

#endif // COORDINATE_H
