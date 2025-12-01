#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;
// How many no. of shapes
// shapes = 3 for examples
class Shape {
    protected: 
        int dim1, dim2;
    public:
        Shape() : dim1(0), dim2(0) {};
        Shape(int m ) : dim1(m), dim2(m) {};
        Shape(int d1, int d2) : dim1(d1), dim2(d2) {};
        void setDimensions(int d1, int d2) {
            dim1 = d1;
            dim2 = d2;
        }
        void setD1(int m) {
            dim1 = m;
        }
        void setD2(int m) {
            dim2 = m;
        }
        int getD1()  {
            return dim1;
        }
        int getD2()  {
            return dim2;
        }
        virtual float area() = 0;
}; 

// Class Circle
class Circle : public Shape {
    public:
        Circle() : Shape() {};
        Circle(int r) : Shape(r) {};
        float area(){
            return 3.14f * dim1 * dim1;
        }
};
// class Rectangle

class Rectangle : public Shape {
    public:
        Rectangle() : Shape() {};
        Rectangle(int l, int w) : Shape(l, w) {};
        float area()  {
            return 1.0f * dim1 * dim2;
        }
};

// Class Triangle
class Triangle : public Shape {
    public:
        Triangle() : Shape() {};
        Triangle(int b, int h) : Shape(b, h) {};
        float area() {
            return 0.5f * dim1 * dim2;
        }
};

// Class Square 
class Square : public Rectangle {
    public:
        Square() {};
        Square(int s) : Rectangle(s,s) {};
};

// class Geoshape
class GeoShape {
    Shape **pt;
    int size;

    public:
        GeoShape(Shape *arr[], int n) {
            size = n;
            pt = new Shape *[size];
            for (int i = 0; i < size; ++i) {
                pt[i] = arr[i];
            }
        }
        float totalArea() {
            float sum = 0;
            // FIX: Change hardcoded '4' to the member variable 'size'
            for (int i = 0; i < size; ++i) { 
                if (pt[i] != nullptr) {
                    sum += pt[i]->area();
                }
            }
            return sum;
        }
};

int main() {
    // Circle c(7);
    // Rectangle r(20,5);   
    // Triangle t(10,20);
    // Square s(6);
    // Geoshape g(&c, &r, &t, &s);
    // cout << "Total Area: " << g.totalArea() << endl;


    // Enter No of shapes
    int n;
    cout << "How many shapes do you want? ";
    cin >> n;

    Shape **tempShapes = new Shape *[n];

    for (int i = 0; i < n; i++) {
        int t;
        cout << "\nChoose shape #" << i + 1 << ":\n";
        cout << "1- Circle\n";
        cout << "2- Rectangle\n";
        cout << "3- Square\n";
        cout << "4- Triangle\n"; 
        cout << "Enter choice (1-4): ";
        cin >> t;

        if (t == 1) { // Circle
            int r;
            cout << "Enter radius: ";
            cin >> r;
            tempShapes[i] = new Circle(r);
        } 
        else if (t == 2) { // Rectangle
            int l, w;
            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;
            tempShapes[i] = new Rectangle(l, w);
        } 
        else if (t == 3) { // Square
            int s;
            cout << "Enter side: ";
            cin >> s;
            tempShapes[i] = new Square(s);
        }
        else if (t == 4) { // Triangle
            int b, h;
            cout << "Enter base: ";
            cin >> b;
            cout << "Enter height: ";
            cin >> h;
            tempShapes[i] = new Triangle(b, h);
        }
        else {
            cout << "Invalid choice. Skipping shape #" << i + 1 << " (Area will be 0)." << endl;
            tempShapes[i] = nullptr; 
        }
    }

    GeoShape g(tempShapes, n);

    cout << "\nTotal area = " << g.totalArea() << endl;

    delete[] tempShapes;

    return 0;
}