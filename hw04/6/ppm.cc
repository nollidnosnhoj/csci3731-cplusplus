#include <stdio.h>
#include "ppm.h"


char* readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber) {
    FILE* fp = fopen(fileName, "rb");                                   // open file for binary reading
    fscanf(fp, "%s", magicNumber);                                      // scan for strings until whitespace is found
    if (magicNumber[0] != 'P' && magicNumber[1] != '6') return NULL;    // if the magic number does not contain P6
    fscanf(fp, "%d %d\n", width, height);                               // scan for 2 integers followed by a new line, store into width and height int
    fscanf(fp, "%d\n", max);                                            // scan for an integer followed by new line, store into max pixels int
    *size = *width * *height;                                           // calculate the total pixel size by multiplying width by height.
    char* pixels = new char[*size];                                     // allocate memory for char array for pixels.
    fread(pixels, sizeof(char), *size, fp);                             // scan the  binary data into the starting point of the pixels array.
    fclose(fp);                                                         // close file pointer
    return pixels;                                                      // return pixels array
}

void writePPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber, char* pixels) {
    FILE* fp = fopen(fileName, "wb");           // open file to write (create file to write)
    fprintf(fp, "%s\n", magicNumber);           // print the magic number
    fprintf(fp, "%d %d\n", *width, *height);    // print width and height
    fprintf(fp, "%d\n", *max);                  // print max pixels
    fwrite(pixels, sizeof(char), *size, fp);    // print binary data
    fclose(fp);                                 // close :D
}

void printPPM(char* pixels, int length) {
    for (int i = 0; i < length && pixels[i] != '\n'; ++i) {
        printf("%c", pixels[i]);
    }
}



int isPPM(const char* fileName, char* magicNumber) {
    FILE* fp = fopen(fileName, "rb");
    fscanf(fp, "%s", magicNumber);
    printf("%s\n", magicNumber);
    fclose(fp);
    if (magicNumber[0] == 'P' && magicNumber[1] == '6') {
        return 1;
    } else {
        return 0;
    }
}