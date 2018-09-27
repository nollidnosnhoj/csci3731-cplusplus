#include <stdio.h>
#include "ppm.h"

int** readPPM  (const char* fileName, 
                unsigned int* width, 
                unsigned int* height, 
                unsigned int* max, 
                unsigned int* size, 
                char* header) {

    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("file does not exist.");
        return NULL;
    }
    fscanf(fp, "%s\n", header);
    if (header[0] != 'P' && header[1] != '6') {
        printf("file is not ppm");
        return NULL;
    }
    fscanf(fp, "%d %d\n%d\n", width, height, max);
    *size = *width * *height;
    unsigned char* binData[*size * 3];
    fread(binData, sizeof(unsigned char), *size * 3, fp);

    int** pixels = new int*[*height];
    *pixels = new int[*width * *height];

    for (int i = 1; i < *height; ++i) {
        pixels[i] = pixels[i - 1] + *width;
    }

    int* flat = *pixels;
    int n = *size;

    for (int i = 0; i < n; ++i) {
        unsigned char* byte = (unsigned char*)(flat + i);
        byte[0] = (char) 225;
        byte[1] = *binData[i * 3];
        byte[2] = *binData[(i * 3) + 1];
        byte[3] = *binData[(i * 3) + 2];
        flat[i] = *byte;
        byte = NULL;
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
    
    FILE* fp = fopen(fileName, "wb");
    fprintf(fp, "%s\n", header);
    fprintf(fp, "%d %d\n", width, height); 
    fprintf(fp, "%d\n", max);
    int* flat = *pixels;
    int n = size;
    fwrite(flat, sizeof(int), n, fp);
}