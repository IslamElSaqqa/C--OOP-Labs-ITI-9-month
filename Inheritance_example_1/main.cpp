#include <iostream>
#include"include/Base.h"
#include"include/Base1.h"
#include"include/Base2.h"
#include"include/Drived.h"
using namespace std;

int main()
{
    Drived drv(3, 4);
    cout << drv.Product();
    return 0;
}