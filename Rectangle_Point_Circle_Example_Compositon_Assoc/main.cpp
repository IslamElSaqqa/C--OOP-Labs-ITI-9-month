#include <iostream>
#include"include/point.h"
#include"include/rectangle.h"
#include"include/circle.h"
using namespace std;

int main()
{
    Rectangle_C R(10, 20, 15, 30);

    cout << "Composition between Rectangle and Point!" << endl;
    cout << "Rectangle Created: "<<endl;
    cout << "P1 = (" << R.getP1().getX() << ", " << R.getP1().getY() << ")"<< endl;
    cout << "P2 = (" << R.getP2().getX() << ", " << R.getP2().getY() << ")"<<endl;

    cout << "Area = " << R.getArea() << endl;

    // Modify P1
    R.setP1(5, 5);

    cout << "After Modifying P1: "<<endl;
    cout << "P1 = (" << R.getP1().getX() << ", " << R.getP1().getY() << ")"<<endl;
    cout << "Area = " << R.getArea() << endl;
    cout << "*************************" << endl;
    cout << "Association Relationship between Circle and Point" << endl;
    Point p3(100,100);
    Point p4(200, 200);
    Circle circle(&p3, &p4);
    cout << "Area of Circle: "<< circle.getArea()<<endl;


    return 0;
}
