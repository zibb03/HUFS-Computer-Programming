//2: Write a C program to find union of two sets.

#include <stdio.h>

int main(void) {
	int A[100];
	int len_A, len_B, tmp, i, j;

	printf("Enter the length of A: ");
	scanf_s("%d", &len_A);
	for (i = 0; i < len_A; i++) {
		printf("Enter the value of A: ");
		scanf_s("%d", &A[i]);
	}

	printf("Enter the length of B: ");
	scanf_s("%d", &len_B);

	for (i = 0; i < len_B; i++) {
		printf("Enter the value of B: ");
		scanf_s("%d", &tmp);

		for (j = 0; j < len_A; j++) {
			if (A[j] == tmp)
				break;
			else if (j == len_A - 1) {
				A[j + 1] = tmp;
				len_A++;
			}
		}
	}

	for (i = 0; i < len_A; i++) {
		for (j = 0; j < len_A - 1; j++) {
			if (A[j] > A[j + 1]) {
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}

	printf("Union of A and B: \n");
	for (i = 0; i < len_A; i++) {
		printf("%d ", A[i]);
	}

	return 0;
}