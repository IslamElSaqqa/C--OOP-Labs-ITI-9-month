#ifndef Base1_H
#define Base1_H
#include "Base.h"
class Base1 : virtual public Base{
    protected:
        int x;

    public:
        Base1(); // x = 0;
        Base1(int m);

        void setx(int n);
        int getX();
};
#endif