#include <stdio.h>
#include "swapvar.h"

int main() {
    // Initialize two variables
    int x = 0;
    int y = 0;
    // Ask for user to input two variables
    printf("Enter two integers:\n");
    scanf("%d", &x);
    scanf("%d", &y);
    swapVariables(&x, &y);
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}