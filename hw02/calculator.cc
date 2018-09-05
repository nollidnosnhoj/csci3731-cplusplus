#include "calculator.h"

int calculate(int x, int y, char opp) {
    switch(opp) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y != 0) {
                return x / y;
            }
        default:
            return 0;
    }
}