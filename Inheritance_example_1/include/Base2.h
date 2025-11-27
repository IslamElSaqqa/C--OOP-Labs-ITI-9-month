#ifndef Base2_H
#define Base2_H
#include "Base.h"
class Base2 : virtual public Base{
    protected:
        int y;

    public:
        Base2();    // y = 0;
        Base2(int q);

        void setY(int n);
        int getY();
};
#endif