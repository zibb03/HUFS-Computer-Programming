#include <stdio.h>

int main() {
	int x;

	printf("Enter a dollar amount: ");
	scanf_s("%d", &x);

	printf("$20 bills: %d\n", x / 20);
	printf("$10 bills: %d\n", x % 20 / 10);
	printf(" $5 bills: %d\n", x % 20 % 10 / 5);
	printf(" $1 bills: %d", x % 20 % 10 % 5);

	return 0;
}