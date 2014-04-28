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
 * Also, all of the points in the polygon is stored in parent class as vector<QPointF>
 */
class Polygon : public QPolygonF
{
public:
    Polygon();
//    Polygon(const QPointF &);
    QVector<float> color;
    void move(bool isTranslate = true, bool isRotate = false);
    void changeColor();
    int sides;
    float radius;
    float rand_FloatRange(float a, float b)
    {
        return ((b-a)*((float)rand()/RAND_MAX))+a;
    }

private:
    void rotatePolygon();
    bool horizontalCollide () const;
    bool verticalCollide () const;
    float angular_vf;
    QPointF temp; //store temporary points
    QPointF centroid; //centroid
    QPointF velocity;
};

#endif // POLYGON_H


/* NOTE: LIST of BUGS:
 * - When translating, or rotating, you need a temp variable to hold your new values
 *    Wrong example:
 *
 *       (*this)[n].rx() = (cos(angular_vf) * ( (*this)[n].rx() - centroid.x() )) -
 *                         (sin(angular_vf) * ( (*this)[n].ry() - centroid.y() )) ;
 *       (*this)[n].ry() = (sin(angular_vf) * ( (*this)[n].rx() - centroid.x() )) +
 *                         (cos(angular_vf) * ( (*this)[n].ry() - centroid.y() ));
 *      Correct example: see rotatePolygon()
 *
 */
