#include <stdio.h>

int main() {
    // read file
	FILE* fp = fopen("storage.txt", "r");
    // if file does not exist
    if (fp == NULL) {
        printf("File does not exist. Create storage.txt");
    } else {
        // storing integer content into cache variable
        int cache = 0;
        // read (scan) contents into the cache variable
        // will read until reaches whitespace or ends
        fscanf(fp, "%d", &cache);
        // increment 
        cache++;
        // write file
        fp = fopen("storage.txt", "w");
        // add new value
        fprintf(fp, "%d", cache);
        printf("Incremented!");
    }
    // close file
    fclose(fp);
}
