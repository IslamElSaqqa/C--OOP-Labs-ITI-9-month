#include"../include/Drived.h"
Drived::Drived(int m, int n) : Base1(m), Base2(n), Base(m){}
int Drived::Sum() { return x + y + z; }
int Drived::Product() { return x*y*z; }