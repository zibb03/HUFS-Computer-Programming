//#7-6

#include <stdio.h>

int main(void) {
	int a;
	short b;
	long c;
	float d;
	double e;
	long double f;

	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(c));
	printf("%d\n", sizeof(d));
	printf("%d\n", sizeof(e));
	printf("%d\n", sizeof(f));

	return 0;
}