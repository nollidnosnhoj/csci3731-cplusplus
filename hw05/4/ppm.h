#ifndef PPM_H
#define PPM_H

int** readPPM(const char* fileName, unsigned int* width, unsigned int* height, unsigned int* max, unsigned int* size, char* header);
void writePPM(const char* fileName,unsigned int width,unsigned int height,unsigned int max,unsigned int size,const char* header,int** pixels);

#endif