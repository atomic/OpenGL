#ifndef POLYGON_H
#define POLYGON_H

#include <QPolygonF>
#include <stdlib.h> //for random
#include <time.h> // for random
#include <cmath>
#include <math.h>
#include <QDebug>

/**
 * @brief The Polygon class
 * Polygon is inherited from QVector<QPoint>
 * so, it has feature vector has
 */
class Polygon : public QPolygonF
{
public:
    Polygon();
    Polygon(const QPointF &);
    QVector<float> color;
    void move();
    void changeColor();
    int sides;
    float radius;

private:
    bool horizontalCollide () const;
    bool verticalCollide () const;
    QPointF velocity;
    QPointF center;
};

#endif // POLYGON_H
