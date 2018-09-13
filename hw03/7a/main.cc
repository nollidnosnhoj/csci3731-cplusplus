#include <stdio.h>

int main() {

    // read file
    FILE* fp = fopen("storage.txt", "r");
    // initialize cache integer
    int cache = 0;
    // if file does exist, store data in file into where cache is pointing to
    if (fp != NULL) {
        fscanf(fp, "%d", &cache);
    }
    // write file (will re-create regardless)
    fp = fopen("storage.txt", "w");
    // increment cache integer
    cache++;
    // write the new integer in the file
    fprintf(fp, "%d", cache);
    printf("Incremented");
    // close file pointer
    fclose(fp);
    return 0;

}