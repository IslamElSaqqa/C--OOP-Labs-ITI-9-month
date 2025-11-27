#include"../include/Base1.h"

Base1::Base1() { x = 0; } // x = 0;
Base1::Base1(int m) : Base(m) {
    x = m;
}

void Base1::setx(int n) { x = n; }
int Base1::getX() { return x; }