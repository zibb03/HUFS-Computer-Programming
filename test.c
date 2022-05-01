#include <stdio.h>
#include <string>

int main() {
	int a = 1, b, c;
	int i = 1, j;

	char a[10], b[10];
	int m[2][4] = { {1, 1, 1, 1} , {1, 1, 1} };
	//c = (b = a + 2) - (a = 1);

	//printf("%d", c);
	//
	//j = i * i++;
	//printf("%d", j);

	i = 10;
	j = 20;
	int k = i == 10 && ++j;
	printf("%d", k);
	k = i != 10 && ++j;
	printf("%d", k);
	k = 10 && ++j;
	printf("%d", k);
	k = i != 1;
	printf("%d", k);
	
	return 0;
}