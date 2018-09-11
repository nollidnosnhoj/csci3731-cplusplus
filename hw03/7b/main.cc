#include <stdio.h>
#include "swapvar.h"

int main() {
    int x = 0;
    int y = 0;
    printf("Enter two integers:\n");
    scanf("%d", &x);
    scanf("%d", &y);
    swapVariables(&x, &y);
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}