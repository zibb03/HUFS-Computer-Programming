//6. Factorial (range)

#include <stdio.h>

int main(void) {
	int r1, r2, i;
	unsigned long long factorial = 1;

	printf("Enter the range you want to know the factorial: ");
	scanf_s("%d %d", &r1, &r2);

	if (r1 < 0 || r2 < 0 || r1 > r2) {
		printf("Invalid Value");
		return 0;
	}
	else {
		for (; r1 <= r2; r1++) {
			for (i = 2; i <= r1; i++)
				factorial *= i;
			
			printf("%d! = %lld\n", r1, factorial);
			factorial = 1;
		}
	}

	return 0;
}