#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
using namespace std;

class Vector2d{
    public:
    double x;
    double y;
    Vector2d();
    Vector2d(double in_x, double in_y);
};

ostream& operator<<(ostream& out, Vector2d in);
Vector2d operator*(Vector2d v1, double m);
Vector2d operator/(Vector2d v1, double d);
#endif