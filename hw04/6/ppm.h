#ifndef PPM_H
#define PPM_H

// Add function headers
char* readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber);
void writePPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber, char* pixels);
void printPPM(char* pixels, int length);
int isPPM(const char* fileName, char* magicNumber);

#endif