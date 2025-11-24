#include"../include/circle.h"
#include <cmath>

// Constructor Prototype
// part of + containment => Composition
Circle::Circle()
{
    centpt = circumference = NULL;
    r = 0;
}   
Circle::Circle(Point *pa, Point *pb)
{
    this->centpt = pa;
    this->circumference = pb;
    if(pa!=NULL && pb!=NULL)
    {
        r = static_cast<int>(sqrt(pow(pb->getX() - pa->getX(),2) + pow((pb->getY() - pa->getY()), 2)));
    }
    else
    {
        r = 0;
    }
}  

// setters Implementation
void Circle::setcentpt(Point *p1)
{
    centpt = p1;
}
void Circle::setcircumferencept(Point *p2)
{
    circumference = p2;
}
double Circle::getArea() const
{
    return 3.14 * r * r;
}

