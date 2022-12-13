#include <iostream>
#include <math.h>
#include "Point2d.h"

using namespace std;

    Point2d::Point2d(){
        x = 0;
        y = 0;
    }
    Point2d::Point2d(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

double GetDistanceBetween(Point2d p1, Point2d p2){
        return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    }

ostream& operator<<(ostream& out, Point2d in){
        out <<  "(" << in.x << ", " << in.y << ")";
        return out;
        
    }

Point2d operator+(Point2d p1, Vector2d v1){
        Point2d sum_o;      
        sum_o.x = p1.x + v1.x;
        sum_o.y = p1.y + v1.y; 
        return sum_o;
    }

Vector2d operator-(Point2d p1, Point2d p2){
        Vector2d sum_o;
        sum_o.x = p1.x - p2.x;
        sum_o.y = p1.y - p2.y;       
        return sum_o;
    }