#include <stdio.h>
#include "ppm.h"

int** readPPM  (const char* fileName, 
                unsigned int* width, 
                unsigned int* height, 
                unsigned int* max, 
                unsigned int* size, 
                char* header) {

    FILE* fp = fopen(fileName, "rb");
    // errorchecking
    fscanf(fp, "%s\n", header);
    // errorchecking
    fscanf(fp, "%d %d\n%d\n", width, height, max);
    *size = *width * *height;
    int** pixels = new int*[*height];
    *pixels = new int[*size];
    fread(*pixels, sizeof(int), *size, fp);
    for (int i = 1; i < *height; ++i) {
        pixels[i] = pixels[i - 1] + *width;
    }

    return pixels;
}

void writePPM  (const char* fileName,
                unsigned int width,
                unsigned int height,
                unsigned int max,
                unsigned int size,
                const char* header,
                int** pixels) {

    int* flat = *pixels;
    int n = size;
    for (int i = 0; i < n; ++i) {
        unsigned char* byte = (unsigned char*)(flat + i);
        
    }
}