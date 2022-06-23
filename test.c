#include <stdio.h>

int main() {
	int a, *b;

	scanf_s("%d", &a);
	b = &a;

	printf("%d\n", a);
	printf("%d\n", *b);
	printf("%x\n", b);

	return 0;
}