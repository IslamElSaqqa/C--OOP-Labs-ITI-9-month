#ifndef POINT_H
#define POINT_H
class Point {
    // Data members
    int x, y;

    // Constructor headers
    public:
        Point();
        Point(int m);
        Point(int m, int n);

        // setters prototypes
        void setX(int X);
        void setY(int Y);

        // getters prototypes
        int getX() const;
        int getY() const;
    };
#endif