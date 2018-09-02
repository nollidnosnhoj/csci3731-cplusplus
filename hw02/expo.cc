#include "expo.h"

int expo (int x, int y) {
    int total = 1;
    while (y != 0) {
        total *= x;
        y--;
    }
    return total;
}