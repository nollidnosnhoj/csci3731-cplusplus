#include <stdio.h>
#include "ppm.h"

int main() {
    char magicNumber[3];        // array of characters for magic number
    unsigned int width = 0;     // ppm width
    unsigned int height = 0;    // ppm height
    unsigned int maxPx = 0;     // ppm max pixel value
    unsigned int size = 0;      // ppm size of image
    
    char* pixels = readPPM("test.ppm", &width, &height, &maxPx, &size, magicNumber);

    if (pixels == NULL) {
        printf("Unable to copy file. Please see error above.");
    } else {
        printf("Width: %d, Height: %d\n", width, height);
        printf("Maximum pixels: %d\n", maxPx);
        printf("Size of image: %d\n\n", size);

        printf("Copying ppm file\n");
        writePPM("newtest.ppm", &width, &height, &maxPx, &size, magicNumber, pixels);
        printf("Copying completed !\n");

        // remove array from heap
        delete [] pixels;
        pixels = NULL;
    }
    
}

