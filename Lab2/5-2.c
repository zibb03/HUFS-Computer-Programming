#include <stdio.h>

int main() {
	int a, b;

	printf("Enter a 24-hour time: ");
	scanf_s("%d:%d", &a, &b);

	if (a > 12)
		if (b < 10)
			printf("Equivalent 12-hour time: %d:0%d PM", a - 12, b);
		else 
			printf("Equivalent 12-hour time: %d:%d PM", a - 12, b);
	else 
		if (b < 10)
			printf("Equivalent 12-hour time: %d:0%d AM", a, b);
		else
			printf("Equivalent 12-hour time: %d:%d AM", a, b);

	return 0;
}