#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"
class Circle {
    // Data members
    Point *centpt;  // center
    Point *circumference;   // circumference
    double r;
    // Constructor headers
    public:
        Circle();   //centpt = NULL , radius = 0
        Circle(Point *centpt, Point *circumference);  // centpt = p, ci, 

        // setters prototypes
        void setcentpt(Point *p1);
        void setcircumferencept(Point *p2);



        // getters prototypes
        double getArea() const;
    };
#endif