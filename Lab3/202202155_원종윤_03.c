//6-3

/*
#include <stdio.h>

int main(void) {
	//Greatest Common Divisor(최대공약수)

	int  m1, m2, n1, n2, tmp, GCD, m = 0;

	printf("Entera fraction: ");
	scanf_s("%d/%d", &m1, &n1);
	
	if (m1 < 0 && n1 < 0) {
		printf("Invalid Value");
		return 0;
	}
	if (m1 < 0) {
		m = 1;
		m1 *= -1;
	}

	m2 = m1;
	n2 = n1;

	if (m2 > n2) {
		while (1) {
			tmp = m2 % n2;
			m2 = n2;
			n2 = tmp;
			if (n2 == 0) {
				GCD = m2;
				break;
			}
		}
	}
	else {
		while (1) {
			tmp = n2 % m2;
			n2 = m2;
			m2 = tmp;
			if (m2 == 0) {
				GCD = n2;
				break;
			}
		}
	}

	if (m)
		m1 *= -1;

	printf("In lowest terms: %d/%d", m1 / GCD, n1 / GCD);
	return 0;
}
*/

#include <stdio.h>

int main() {
	int n1, n2, i;
	int gcd = 1;
	printf("Enter a fraction : ");
	scanf_s("%d/%d", &n1, &n2);

	for (i = 1; i <= n2; i++) {
		if (n2 % i == 0) {
			if (n1 % i == 0) gcd = i;
		}
	}

	printf("In lowest terms : %d/%d\n", n1 / gcd, n2 / gcd);
	return 0;
}