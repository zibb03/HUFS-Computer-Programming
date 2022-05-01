//6-12
//1 
//+
//2.5
//*
//3
//\n

#include <stdio.h>

int main(void) {
	float value = 0, tmp;
	char ch = ' ';

	printf("Enter an expression: ");

	scanf_s("%f", &value);
	while (1) {
		ch = getchar();
		
		if (ch == '\n') {
			break;
		}

		if (ch == '+') {
			scanf_s("%f", &tmp);
			value += tmp;
		}
		else if (ch == '-') {
			scanf_s("%f", &tmp);
			value -= tmp;
		}
		else if (ch == '*') {
			scanf_s("%f", &tmp);
			value *= tmp;
		}
		else {
			scanf_s("%f", &tmp);
			value /= tmp;
		}
	}
	printf("Value of expression: %f", value);

	return 0;
}