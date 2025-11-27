#ifndef Drived_H
#define Drived_H
#include "Base1.h"
#include "Base2.h"
class Drived : public Base1, Base2{

    public:
        Drived(int m, int n);
        int Sum();
        int Product();
};
#endif