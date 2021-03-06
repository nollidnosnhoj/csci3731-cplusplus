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
        writeAsJPEG("test.jpg", width, height, size, 50, pixels);
    }

    delete [] *pixels;
    delete [] pixels;
    pixels = NULL;
}

