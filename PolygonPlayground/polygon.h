#ifndef POLYGON_H
#define POLYGON_H

#include <QPolygonF>
#include <stdlib.h> //for random
#include <time.h> // for random
#include <cmath>
#include <math.h>
#include <QDebug>
#include <QMatrix>

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
    void move(bool isRotate = false);
    void changeColor();
    int sides;
    float radius;
    float rand_FloatRange(float a, float b)
    {
        return ((b-a)*((float)rand()/RAND_MAX))+a;
    }

private:
    void updateCentroid();
    void rotatePolygon();
    bool horizontalCollide () const;
    bool verticalCollide () const;
    float angular_v_f;
    QMatrix matrix;
    QPointF centroid; //centroid
    QPointF velocity;
};

#endif // POLYGON_H
