#include <stdio.h>
#include "ppm.h"

int main() {
    char header[3];        // array of characters for magic number
    unsigned int width = 0;     // ppm width
    unsigned int height = 0;    // ppm height
    unsigned int max = 0;     // ppm max pixel value
    unsigned int size = 0;      // ppm size of image
    
    int** pixels = readPPM("test.ppm", &width, &height, &max, &size, header);

    if (pixels != NULL) {
        printf("Width: %d, Height: %d\n", width, height);
        printf("Maximum pixels: %d\n", max);
        printf("Size of image: %d\n\n", size);

        printf("Copying ppm file\n");
        writePPM("newtest.ppm", width, height, max, size, header, pixels);
        printf("Copying completed !\n");
    }

    delete [] *pixels;
    delete [] pixels;
    pixels = NULL;
}

