//6-2

#include <stdio.h>

int main(void) {
	//Greatest Common Divisor(최대공약수)

	int  m, n, tmp;

	printf("Enter two integers: ");
	scanf_s("%d %d",  &m, &n);
	
	if (m > n) {
		tmp = m;
		m = n;
		n = tmp;
	}

	if (m < 0 || n < 0 || (m == 0 && n == 0)) {
		printf("Invalid Value");
		return 0;
	}
	if (m == 0) {
		printf("Greates common divisor: %d", n);
		return 0;
	}
	while (1) {
		tmp = m % n;
		m = n;
		n = tmp;
		if (n == 0) {
			printf("Greates common divisor: %d", m);
			return 0;
		}
	}
}