#ifndef PPM_H
#define PPM_H

int** readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* header);
void writePPM(const char* fileName, const unsigned int width, const unsigned int height, const unsigned int max, const unsigned int size, const char* header, const int** pixels);

#endif