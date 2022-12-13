#include <iostream>
#include <math.h>
#include "Vector2d.h"
using namespace std;
    
    Vector2d::Vector2d(){
        x = 0;
        y = 0;
    }
    Vector2d::Vector2d(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

ostream& operator<<(ostream& out, Vector2d in){
        out <<  "<" << in.x << ", " << in.y << ">";
        return out;
    }

Vector2d operator*(Vector2d v1, double m){
    Vector2d prod_o;
    prod_o.x = v1.x * m;
    prod_o.y = v1.y * m;
    return prod_o;
    }

Vector2d operator/(Vector2d v1, double d){
    Vector2d prod_o;
    prod_o.x = v1.x / d;
    prod_o.y = v1.y / d;
    return prod_o;
}