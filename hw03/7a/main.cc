#include <stdio.h>

int main() {
	FILE* fp = fopen("storage.txt", "r");
    if (fp == NULL) {
        printf("File does not exist. Create storage.txt");
    } else {
        int cache = 0;
        int value = 0;
        if(fscanf(fp, "%d", &cache) != EOF) {
            value = cache;
        }
        value++;
        fp = fopen("storage.txt", "w");
        fprintf(fp, "%d", value);
        printf("Incremented!");
    }
    fclose(fp);
}