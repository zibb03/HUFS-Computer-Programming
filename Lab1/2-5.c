#include <stdio.h>

int main() {
	int x;

	printf("Enter a value x: ");
	scanf_s("%d", &x);

	printf("%d", 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);

	return 0;
}