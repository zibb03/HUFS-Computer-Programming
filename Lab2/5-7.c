#include <stdio.h>

int main() {
	int a, b, c, d, max = 0, min = 99999999;

	printf("Enter four integers: ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);

	if (a < min)
		min = a;
	if (a > max)
		max = a;
	if (b < min)
		min = b;
	if (b > max)
		max = b;
	if (c < min)
		min = c;
	if (c> max)
		max = c;
	if (d < min)
		min = d;
	if (d > max)
		max = d;

	printf("Largest: %d\n", max);
	printf("Smallest: %d\n", min);

	return 0;
}