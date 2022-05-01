#include <stdio.h>

int main() {
	int n;

	printf("Enter a number: ");
	scanf_s("%d", &n);

	if (0 <= n && n <= 9)
		printf("The number %d has 1 digits", n);
	else if (10 <= n && n <= 99)
		printf("The number %d has 2 digits", n);
	else if (100 <= n && n <= 999)
		printf("The number %d has 3 digits", n);
	else if (1000 <= n && n <= 9999)
		printf("The number %d has 4 digits", n);
	else if (1000 <= n && n <= 99999)
		printf("The number %d has 5 digits", n);
	else if (10000 <= n && n <= 999999)
		printf("The number %d has 6 digits", n);

	return 0;
}