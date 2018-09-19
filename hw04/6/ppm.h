#ifndef PPM_H
#define PPM_H

// Add function headers
char* readPPM(const char* fileName, int* width, int* height, int* max, char* magicNumber);
void writePPM(const char* fileName, int* width, int* height, int* max, char* magicNumber);

#endif