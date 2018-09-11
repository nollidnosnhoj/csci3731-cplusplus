#include "swapvar.h"

// input: 2 pointers, each pointing to an integer.
void swapVariables(int* a, int* b) {
    // if the value in a is greater than the value in b.
    if (*a > *b) {
        // declare temporary variable
        int temp = 0;
        // the data pointed by b is stored inside the temp variable.
        temp = *b;
        // the data pointed by a is stored into the data pointed by b.
        *b = *a;
        // the temp value is stored inside the data pointed by a.
        *a = temp;
    }
}