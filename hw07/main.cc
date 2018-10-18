#include <iostream>
#include "angle.h"

int main() {
    int d1; /* first angle's degrees */
    int d2; /* second angle's degrees */

    // user's input
    std::cout << "Insert two degrees for the two angles: " << std::endl;
    std::cin >> d1 >> d2;

    // Create angle classes
    Angle a1(d1), a2(d2);

    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;

    std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;

    // option integer
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
    std::cout << "11) assign double to angle" << std::endl;
    std::cout << "0) DONE" << std::endl;

    std::cin >> s;

    // a whole bunch of switch statements
    switch (s) {
        case 1: {
            Angle a3 = a1 + a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 2:
            a1 += a2;
            std::cout << a1 << std::endl;
            break;
        case 3: {
            Angle a3 = a1 - a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 4:
            a1 -= a2;
            std::cout << a1 << std::endl;
            break;
        case 5: {
            Angle a3 = a1 * a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 6:
            a1 *= a2;
            std::cout << a1 << std::endl;
            break;
        case 7: {
            Angle a3 = a1 / a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 8:
            a1 /= a2;
            std::cout << a1 << std::endl;
            break;
        case 9:
            if (a1 == a2) {
                std::cout << "True" << std::endl;
            } else {
                std::cout << "False" << std::endl;
            }
            break;
        case 10:
            a1 = a2;
            std::cout << a1 << std::endl;
            break;
        case 11: {
            double dub;
            std::cout << "enter double: " << std::endl;
            std::cin >> dub;
            a1 = dub;
            std::cout << a1 << std::endl;
            break;
        }
        default:
            std::cout << "invalid option :D" << std::endl;
    }
}