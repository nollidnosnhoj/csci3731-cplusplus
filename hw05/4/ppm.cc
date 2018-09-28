#include <stdio.h>
#include "ppm.h"

int** readPPM  (const char* fileName, 
                unsigned int* width, 
                unsigned int* height, 
                unsigned int* max, 
                unsigned int* size, 
                char* header) {
    
    // open file for binary reading
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("file does not exist.");
        return NULL;
    }
    // read header
    fscanf(fp, "%s\n", header);
    if (header[0] != 'P' && header[1] != '6') {
        printf("file is not ppm");
        return NULL;
    }
    // read width, height, max
    fscanf(fp, "%d %d\n%d\n", width, height, max);
    *size = *width * *height;
    // create char array for binary data (size is width * height * 3 because of rgb)
    unsigned char binData[*size * 3];
    // read binary data into char array
    fread(binData, sizeof(unsigned char), *size * 3, fp);
    // allocate 2D array of ints using numerical recipe trick 
    int** pixels = new int*[*height];           // length is height since height is the columns
    *pixels = new int[*width * *height];        // the flat array size is width times height
    // place pointers for rows
    for (int i = 1; i < *height; ++i) {
        pixels[i] = pixels[i - 1] + *width;
    }
    // traverse through flat array
    for (int i = 0; i < *size; ++i) {
        // point to the char pointer to the int
        unsigned char* byte = (unsigned char*)(*pixels + i);
        // start placing data
        byte[0] = (char) 255;
        byte[1] = binData[i * 3];
        byte[2] = binData[(i * 3) + 1];
        byte[3] = binData[(i * 3) + 2];
    }

    return pixels;
}

void writePPM  (const char* fileName,
                const unsigned int width,
                const unsigned int height,
                const unsigned int max,
                const unsigned int size,
                const char* header,
                int** pixels) {
    // print info
    FILE* fp = fopen(fileName, "wb");
    fprintf(fp, "%s\n", header);
    fprintf(fp, "%d %d\n", width, height); 
    fprintf(fp, "%d\n", max);
    // char array
    unsigned char binData[size * 3];
    // unpack 2d array
    int* flat = *pixels;
    int n = size;
    // store int into char array
    for (int i = 0; i < n; ++i) {
        unsigned char* byte = (unsigned char*)(flat + i);
        binData[i * 3] = byte[1];
        binData[(i * 3) + 1] = byte[2];
        binData[(i * 3) + 2] = byte[3];
    }
    // write file
    fwrite(binData, sizeof(char), n * 3, fp);
}