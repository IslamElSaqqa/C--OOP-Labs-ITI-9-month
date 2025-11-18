#include <iostream>
using namespace std;

class Complex {
	int real, imag;
public:

	// default constructor
	Complex()
	{
		real = imag = 0;
	}

	// parameterized constructor
	Complex(int r, int i)
	{
		real = r; imag = i;
	}

	// parameterized constructor
	Complex(int m)
	{
		real = imag = m;
	}

	// setters
	void setR(int r) { real = r; }
	void setImag(int i) { imag = i; }
	int getR() { return real; }
	int getImag() { return imag; }

	Complex operator+(Complex c); 			// c1 + c2
	Complex operator-(Complex c); 			// c1 - c2
	Complex operator+(int m); 				// c1 + int 
	Complex operator++();					// ++c1
	Complex operator++(int);				// c1++
	Complex &operator=(Complex &c);			// c1 = c2
	int operator==(Complex c);				// c1 == c2
	operator int();							// (int) c -> casting
	// int + c	
	friend Complex operator+(int n, Complex c);
};



int main() {
	cout << "=== Constructor Tests ===\n";
	Complex c0;                     // default constructor
	Complex c1(10, 10);             // parametrized constructor
	Complex c2(20, 20);             // parametrized constructor
	Complex c3(5);                  // one-parameter constructor

	cout << "c0: " << c0.getR() << "," << c0.getImag() << endl;       // 0,0
	cout << "c1: " << c1.getR() << "," << c1.getImag() << endl;       // 10,10
	cout << "c2: " << c2.getR() << "," << c2.getImag() << endl;       // 20,20
	cout << "c3: " << c3.getR() << "," << c3.getImag() << endl;       // 5,5


	cout << "\n=== Operator + (Complex + Complex) ===\n";
	Complex sum = c1 + c2;
	cout << "c1 + c2 = " << sum.getR() << "," << sum.getImag() << endl;   // 30,30


	cout << "\n=== Operator - (Complex - Complex) ===\n";
	Complex diff = c2 - c1;
	cout << "c2 - c1 = " << diff.getR() << "," << diff.getImag() << endl; // 10,10


	cout << "\n=== Operator + (Complex + int) ===\n";
	Complex addInt = c1 + 5;
	cout << "c1 + 5 = " << addInt.getR() << "," << addInt.getImag() << endl; // 15,10


	cout << "\n=== Friend Operator + (int + Complex) ===\n";
	Complex intAdd = 5 + c1;
	cout << "5 + c1 = " << intAdd.getR() << "," << intAdd.getImag() << endl; // 15,10


	cout << "\n=== Prefix ++c ===\n";
	Complex pre = ++c1;
	cout << "++c1 = " << pre.getR() << "," << pre.getImag() << endl;        // 11,11
	cout << "c1 now = " << c1.getR() << "," << c1.getImag() << endl;        // 11,11


	cout << "\n=== Postfix c++ ===\n";
	Complex post = c1++;
	cout << "c1++ result = " << post.getR() << "," << post.getImag() << endl; // 11,11
	cout << "c1 now = " << c1.getR() << "," << c1.getImag() << endl;          // 12,12


	cout << "\n=== Operator = (Assignment) ===\n";
	Complex a, b(7, 8);
	a = b;
	cout << "a = b → a: " << a.getR() << "," << a.getImag() << endl;          // 7,8


	cout << "\n=== Operator == (Equality) ===\n";
	Complex e1(3, 4), e2(3, 4), e3(5, 6);
	cout << "(e1 == e2) = " << (e1 == e2) << endl;   // 1 (true)
	cout << "(e1 == e3) = " << (e1 == e3) << endl;   // 0 (false)


	cout << "\n=== Cast Operator (int)c ===\n";
	Complex castTest(99, 123);
	int x = (int)castTest;
	cout << "(int)castTest = " << x << endl;         // 99


	cout << "\n=== All Tests Complete ===\n";

	return 0;
}


// c1 + c2
Complex Complex::operator+(Complex c) 
{
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;

	return temp;
} 			

// c1 - c2
Complex Complex::operator-(Complex c) 
{
	Complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;

	return temp;

}

// c1 + int 
Complex Complex::operator+(int m) 
{
	Complex temp;
	temp.real = real + m;
	temp.imag = imag;
	return temp;
} 		

// ++c1
Complex Complex::operator++() 
{
	real++; imag++;
	return *this;

}	

// c1++
Complex Complex::operator++(int) 
{
	Complex temp;
	temp = *this;
	real++; imag++;
	return temp;
}				

// c1 = c2
Complex& Complex::operator=(Complex& c)
{
	real = c.real;
	imag = c.imag;
	return c;  // or *this
}

// c1 == c2
int Complex::operator==(Complex c) 
{	
	return (real == c.real) && (imag == c.imag);
}

// (int) c -> casting complex to integer	
Complex::operator int(){return real;}

// int + c
Complex operator+(int n, Complex c){ return (c + n); }
