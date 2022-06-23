#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fptr;

    char str[60];

    int error = fopen_s(&fptr, "File_A.txt", "r");

    if (error != 0) {
        printf("Error! opening file");
        exit(1);
    }

    while (fgets(str, 60, fptr) != NULL) {
        puts(str);
    }

    fclose(fptr);

    return 0;
}
