//6-11

#include <stdio.h>

int main(void) {
	int n, i, j;
	float e = 1.00f, factorial = 1.00f;

	printf("Write a number: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Invalid Value");
		return 0;
	}

	for (i = 2; i <= n; i++) {
		factorial *= i;
		e += 1.00f / factorial;
	}

	printf("The result is %f", e);

	return 0;
}