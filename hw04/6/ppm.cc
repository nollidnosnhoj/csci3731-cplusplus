#include <stdio.h>
#include "ppm.h"

/*
    Reads a ppm image and returns an array of characters (that stores binary data).
    Also stores information about the ppm into the appropriate pointers (width, height, max pixels, etc.)
*/
char* readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber) {
    FILE* fp = fopen(fileName, "rb");                                   // open file for binary reading
    if (fp == NULL) {                                                   // if the file pointer is empty
        printf("ERROR: File cannot be found");                          // return null
        return NULL;
    }
    fscanf(fp, "%s", magicNumber);                                      // scan for strings until whitespace is found
    if (magicNumber[0] != 'P' && magicNumber[1] != '6') {               // if the magic number is not P6
        printf("ERROR: This is not a PPM file.");                       // return null
        return NULL;
    }
    fscanf(fp, "%d %d\n", width, height);                               // scan for 2 integers followed by a new line, store into width and height int
    fscanf(fp, "%d\n", max);                                            // scan for an integer followed by new line, store into max pixels int
    *size = *width * *height * 3;                                       // calculate the total pixel size by multiplying width, height, and rgb (3).
    char* pixels = new char[*size];                                     // allocate memory for char array for pixels.
    fread(pixels, sizeof(char), *size, fp);                             // scan the  binary data into the starting point of the pixels array.
    fclose(fp);                                                         // close file pointer
    return pixels;                                                      // return pixels array
}

/**
 *  Writes information into the ppm image.
**/
void writePPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber, char* pixels) {
    FILE* fp = fopen(fileName, "wb");           // open file to write (create file to write)
    fprintf(fp, "%s\n", magicNumber);           // print the magic number
    fprintf(fp, "%d %d\n", *width, *height);    // print width and height
    fprintf(fp, "%d\n", *max);                  // print max pixels
    fwrite(pixels, sizeof(char), *size, fp);    // print binary data
    fclose(fp);                                 // close :D
}