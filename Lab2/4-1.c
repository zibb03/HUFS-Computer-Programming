#include <stdio.h>

int main() {
	int n, a, b, c;

	printf("Enter a two-digit number: ");
	scanf_s("%d", &n);
	
	a = n / 10;
	b = n % 10;
	printf("The reversal is: %d", (b * 10 + a));

	return 0;
}