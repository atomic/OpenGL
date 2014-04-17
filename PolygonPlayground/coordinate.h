#ifndef COORDINATE_H
#define COORDINATE_H

struct coordinate
{
    float x;
    float y;
public:
    coordinate() {
        x = 0;
        y = 0;
    }

    coordinate(float new_x, float new_y);
    void reset();
};

coordinate::coordinate(float new_x, float new_y)
{
    x = new_x;
    y = new_y;
}

void coordinate::reset()
{
    x = 0;
    y = 0;
}

#endif // COORDINATE_H
