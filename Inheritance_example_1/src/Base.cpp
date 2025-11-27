#include "../include/Base.h"

Base::Base() { z = 0; }
Base::Base(int m) { z = m; }

void Base::setZ(int m) { z = m; }
int Base::getZ() { return z; }