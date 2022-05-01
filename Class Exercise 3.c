#include <stdio.h>

void even(int n) {
	printf("EVEN NUMBER\n");
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0)
			printf("%4d", i);
	}
}

void odd(int n) {
	printf("ODD NUMBER\n");
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1)
			printf("%4d", i);
	}
}

int main(){
	int n;
	printf("Enter the range: ");
	scanf_s("%d", &n);
	printf("\n");
	
	even(n);
	printf("\n");
	odd(n);

	return 0;
}