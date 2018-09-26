#include <stdio.h>

int main() {
    int n = 15;
    unsigned char* bytes = (unsigned char*)(&n);
    printf("%d %d %d %d\n", (char)bytes[0],
                            (char)bytes[1],
                            (char)bytes[2],
                            (char)bytes[3]);
}