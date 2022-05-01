//3: Write a C program to find largest element in a list.

#include <stdio.h>

int main(void) {
	int A[100];
	int len, max = 0;

	printf("Enter the length of list: ");
	scanf_s("%d", &len);

	for (int i = 0; i < len; i++) {
		printf("Enter the value of list: ");
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < len; i++) {
		if (max < A[i])
			max = A[i];
	}

	printf("Largest element in a list is: %d", max);

	return 0;
}