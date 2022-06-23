//Question No. 1
// Write a C program that counts the number of characters in a given file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num;
	char str[100];

	FILE* fptr;
	int error = fopen_s(&fptr, "File_A.txt", "r");
	if (error != 0) {
		printf("Error! opening file");
		exit(1);
	}

	fgets(str, 60, fptr);

	printf("number of characters : %d", strlen(str));
	fclose(fptr);

	return 0;
}