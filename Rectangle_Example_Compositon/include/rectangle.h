#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
class Rectangle_C {
    int length, width;
    Point p1, p2;

    public:
    // Constructor Prototype
    Rectangle_C(int x1, int y1, int x2, int y2);

    // setters headers
    void setP1(int x, int y);
    void setP2(int x, int y);

    // getters headers
    Point getP1() const;
    Point getP2() const;
    int getArea() const;
};
#endif