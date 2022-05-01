//7. Fibonacci Sequence

#include <stdio.h>

int main(void) {
	int n, pastpast = 0, past = 1;
	unsigned int current = 0;

	printf("Enter the you want to know the Fibonacci Sequence: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Invalid Value");
		return 0;
	}
	if (n == 1) {
		printf("Fibonacci Sequence of 1 is 1");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		current = past + pastpast;
		pastpast = past;
		past = current;
	}

	printf("Fibonacci Sequence of %d is %d", n, current);

	return 0;
}