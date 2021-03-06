#include <stdio.h>
#include "ppm.h"
#include <jpeglib.h>

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

void writeAsJPEG   (const char* fileName,
                    const unsigned int width,
                    const unsigned int height,
                    const unsigned int size,
                    const int quality,
                    int** pixels) {
    
    struct jpeg_compress_struct cInfo; /* jpeg "working space" */
    struct jpeg_error_mgr jError;    /* jpeg error handler */

    JSAMPROW row_pointer[1];    // pointer for jpeg compression
    int row_stride; // rows
    
    FILE* fp = fopen(fileName, "wb");   /* setup file pointer */
    if (!fp) {
        fprintf(stderr, "cannot open %s\n", fileName);
        exit(1);
    }

    cInfo.err = jpeg_std_error(&jError);    /* setup error handler */
    jpeg_create_compress(&cInfo);  /* initialize jpeg compression object */
    jpeg_stdio_dest(&cInfo, fp);   /* tell jpeg compression object about the file */

    cInfo.image_width = width; /* image width */
    cInfo.image_height = height;   /* image height */
    cInfo.input_components = 3;    /* # of color components per pixel (rgb) */
    cInfo.in_color_space = JCS_RGB;    /* some color space thingy...
    * to be honest... don't know what it does, but it's essential.
    */

    jpeg_set_defaults(&cInfo); /* set default compression parameters */
    jpeg_set_quality(&cInfo, quality, TRUE);   /* set quality compression parameters */

    unsigned char data[size * 3];   /* setup flat array for binary data */
    int* flat = *pixels;    /* unpack 2d array into a flat array */
    for (int i = 0; i < size; ++i) {    /* store rgb value into flat array for comp */
        unsigned char* byte = (unsigned char*)(flat + i);
        data[i * 3] = byte[1];
        data[(i * 3) + 1] = byte[2];
        data[(i * 3) + 2] = byte[3];
    }

    jpeg_start_compress(&cInfo, TRUE);  /* start compression */

    row_stride = width * 3;

    /* write into jpeg */
    while(cInfo.next_scanline < cInfo.image_height) {
        row_pointer[0] = (JSAMPROW) &data[cInfo.next_scanline * row_stride];
        jpeg_write_scanlines(&cInfo, row_pointer, 1);
    }

    /* finish jpeg writing */

    jpeg_finish_compress(&cInfo);
    fclose(fp);
    jpeg_destroy_compress(&cInfo);

}