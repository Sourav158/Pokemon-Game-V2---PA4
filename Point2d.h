#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2d.h"
using namespace std;

class Point2d{
    public:
    double x;
    double y;
    Point2d();
    Point2d(double, double);
};
double GetDistanceBetween(Point2d, Point2d );
ostream& operator<<(ostream&, Point2d);
Point2d operator+(Point2d, Vector2d);
Vector2d operator-(Point2d, Point2d); 
#endif