#include <stdio.h>

int main() {
	int n;

	printf("Enter a number between 0 and 32767: ");
	scanf_s("%d", &n);

	printf("%d", n / 8 / 8 / 8 / 8% 8);
	printf("%d", n / 8 / 8 / 8 % 8);
	printf("%d", n / 8 / 8 % 8);
	printf("%d", n / 8 % 8);
	printf("%d", n % 8);
	
	return 0;
}