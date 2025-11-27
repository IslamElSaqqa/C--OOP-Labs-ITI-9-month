#include"../include/Base2.h"

Base2::Base2() { y = 0; } // x = 0;
Base2::Base2(int m) : Base(m) {
    y = m; 
    }

void Base2::setY(int n) { y = n; }
int Base2::getY() { return y; }