#include"../include/rectangle.h"
#include <cmath>

// Constructor Prototype
// part of + containment => Composition
Rectangle_C::Rectangle_C(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
{
    length = std::abs(x2 - x1);
    width = std::abs(y2 - y1);
}

// setters Implementation
void Rectangle_C::setP1(int x, int y)
{
    p1.setX(x);
    p1.setY(y);
    length = std::abs(p2.getX() - x);
    width = std::abs(p2.getY() - y);
}
void Rectangle_C::setP2(int x, int y) 
{
    p2.setX(x);
    p2.setY(y);
    length = std::abs(x - p1.getX());
    width = std::abs(y- p1.getY());
}


// getters Implementation
Point Rectangle_C::getP1() const {return p1;}
Point Rectangle_C::getP2() const { return p2;}
int Rectangle_C::getArea()const { return length * width; }
