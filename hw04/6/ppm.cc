#include <stdio.h>
#include "ppm.h"

char* readPPM(const char* fileName, int* width, int* height, int* max, char* magicNumber) {
    // open binary file to read
    FILE* fp = fopen(fileName, "rb");
    // read the magic number, and assign to magic number pointer
    fscanf(fp, "%s", magicNumber);
    // if the first two letters are not P6, then return null
    if (magicNumber[0] != 'P' && magicNumber[1] != '6') {
        // not a ppm file
        return NULL;
    }
    // read and store the width and height
    fscanf(fp, "%d %d\n", width, height);
    // read and store the maximum pixels
    fscanf(fp, "%d\n", max);
    // define the size of the ppm image (pixels)
    int size = *width * *height;
    // allocate memory for the binary pixels
    char* pixels = new char[size];
    // read the binary file, and store them into memory.
    fread(pixels, sizeof(char), size, fp);

}