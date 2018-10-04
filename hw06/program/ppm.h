#ifndef PPM_H
#define PPM_H

int** readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* header);
void writeAsJPEG(const char* fileName, const unsigned int width, const unsigned int height, const unsigned int size, const int quality, int** pixels);
#endif