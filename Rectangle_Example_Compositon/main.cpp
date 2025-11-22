#include <iostream>
#include"include/point.h"
#include"include/rectangle.h"
using namespace std;

int main()
{
    Rectangle_C R(10, 20, 15, 30);

    cout << "Rectangle Created: "<<endl;
    cout << "P1 = (" << R.getP1().getX() << ", " << R.getP1().getY() << ")"<< endl;
    cout << "P2 = (" << R.getP2().getX() << ", " << R.getP2().getY() << ")"<<endl;

    cout << "Area = " << R.getArea() << endl;

    // Modify P1
    R.setP1(5, 5);

    cout << "After Modifying P1: "<<endl;
    cout << "P1 = (" << R.getP1().getX() << ", " << R.getP1().getY() << ")"<<endl;
    cout << "Area = " << R.getArea() << endl;

    return 0;
}
