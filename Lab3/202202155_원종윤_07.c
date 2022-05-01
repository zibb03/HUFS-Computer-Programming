//2. Odd Number

#include <stdio.h>

int main(void) {
	int n;

	printf("Enter the range: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Invalid Value");
		return 0;
	}

	for (int i = 0; i <= n; i++) {
		if (i % 2 != 0) {
			printf("%d ", i);
		}
	}

	return 0;
}