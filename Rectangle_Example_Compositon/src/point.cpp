#include"../include/point.h"

Point::Point() { x = y = 0; }
Point::Point(int m) { x = y = m; }
Point::Point(int m, int n) {
    x = m;
    y = n;
}

// setters implementation
void Point::setX(int x) { this->x= x; }
void Point::setY(int y) { this->y = y; }

// getters prototypes
int Point::getX()  const { return this->x; }
int Point::getY() const{ return this->y; }