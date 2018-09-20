#include <stdio.h>
#include "ppm.h"

int main() {
    char magicNumber[3];
    unsigned int width = 0;
    unsigned int height = 0;
    unsigned int maxPx = 0;
    unsigned int size = 0;
    
    char* pixels = readPPM("test.ppm", &width, &height, &maxPx, &size, magicNumber);

    printf("Width: %d, Height: %d\n", width, height);
    printf("Maximum pixels: %d\n", maxPx);
    printf("Size of image: %d\n", size);
    // printPPM(pixels, size);
    printf("Copying ppm file\n");
    writePPM("newtest.ppm", &width, &height, &maxPx, &size, magicNumber, pixels);
    printf("Copying completed !\n");

    delete [] pixels;
    pixels = NULL;
    
}

