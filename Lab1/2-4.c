#include <stdio.h>

int main() {
	float x;

	printf("Enter an amount: ");
	scanf_s("%f", &x);

	printf("With tax added: $%.2f", x * 1.05);

	return 0;
}