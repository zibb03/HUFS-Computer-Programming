//3. Prime Number

#include <stdio.h>

int main(void) {
	int n;

	printf("Enter the number: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Invalid Value");
		return 0;
	}

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			printf("%d is not a prime number", n);
			return 0;
		}
	}

	printf("%d is a prime number", n);

	return 0;
}