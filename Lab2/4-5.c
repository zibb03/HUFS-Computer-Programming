#include <stdio.h>

int main() {
	int d, i1, i2, i3 ,i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;
	
	printf("Enter the fist 11 digits of a UPC: ");
	scanf_s("%1d", &d);
	scanf_s("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
	scanf_s("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;

	printf("Check digit: %d", 9 - ((total - 1) % 10));

	return 0;
}