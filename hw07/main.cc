#include <iostream>
#include "angle.h"

int main() {
    Angle a1(300), a2(100);
    Angle a3 = a1 + a2;
    a3.print();
}