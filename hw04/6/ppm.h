#ifndef PPM_H
#define PPM_H

char* readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber);
void writePPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* magicNumber, char* pixels);

#endif