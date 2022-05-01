//5. Factorial

#include <stdio.h>

int main(void) {
	int n;
	unsigned long long factorial = 1;

	printf("Enter the you want to know the factorial: ");
	scanf_s("%d", &n);

	if (n < 0) {
		printf("Invalid Value");
		return 0;
	}
	else if (n == 0) {
		printf("%d! = %lld", n, factorial);
		return 0;
	}
	else {
		for (int i = 2; i <= n; i++)
			factorial *= i;

		printf("%d! = %lld", n, factorial);
	}

	return 0;
}