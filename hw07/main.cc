#include <iostream>
#include "angle.h"

int main()
{
    int d1;
    int d2;

    std::cout << "Insert two degrees for the two angles: " << std::endl;
    std::cin >> d1 >> d2;

    Angle a1(d1), a2(d2);

    std::cout << "Angle 1: " << a1.get() << ", Angle 2: " << a2.get() << std::endl;

    std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;

    int s;

    std::cout << "Choose Options: " << std::endl;

    std::cout << "1) addition" << std::endl;
    std::cout << "2) increment" << std::endl;
    std::cout << "3) subtraction" << std::endl;
    std::cout << "4) decrement" << std::endl;
    std::cout << "5) multiplication" << std::endl;
    std::cout << "6) multiply increment" << std::endl;
    std::cout << "7) division" << std::endl;
    std::cout << "8) division decrement" << std::endl;
    std::cout << "9) comparison" << std::endl;
    std::cout << "10) assignment" << std::endl;
    std::cout << "0) DONE" << std::endl;

    std::cin >> s;

    switch (s)
    {
    case 1:
    {
        Angle a3 = a1 + a2;
        a3.print();
    }
    break;
    case 2:
        a1 += a2;
        a1.print();
        break;
    case 3:
    {
        Angle a3 = a1 - a2;
        a3.print();
    }
    break;
    case 4:
        a1 -= a2;
        a1.print();
        break;
    case 5:
    {
        Angle a3 = a1 * a2;
        a3.print();
    }
    break;
    case 6:
        a1 *= a2;
        a1.print();
        break;
    case 7:
    {
        Angle a3 = a1 / a2;
        a3.print();
    }
    break;
    case 8:
        a1 /= a2;
        a1.print();
        break;
    case 9:
        if (a1 == a2)
        {
            std::cout << "True" << std::endl;
        }
        else
        {
            std::cout << "False" << std::endl;
        }
        break;
    case 10:
        a1 = a2;
        a1.print();
        break;
    default:
        std::cout << "invalid option :D" << std::endl;
    }
}