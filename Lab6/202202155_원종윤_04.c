//4: Write a C program to find smallest element in a list

#include <stdio.h>

int main(void) {
	int A[100];
	int len, min = 999999999;

	printf("Enter the length of list: ");
	scanf_s("%d", &len);

	for (int i = 0; i < len; i++) {
		printf("Enter the value of list: ");
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < len; i++) {
		if (min > A[i])
			min = A[i];
	}

	printf("Largest element in a list is: %d", min);

	return 0;
}