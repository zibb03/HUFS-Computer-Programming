//6 - 4

#include <stdio.h>

int main(void) {
	float value;

	while (1) {
		printf("Enter value of trade: ");
		scanf_s("%f", &value);

		if (value == 0)
			return 0;

		if (value < 0) {
			printf("ERROR: Lower than the minimum charge");
			return 0;
		}
		else {
			if (value < 2500) {
				printf("Commision: $%.2f\n", 30.00 + value * 0.0017);
			}
			else if (value < 6250)
				printf("Commision: $%.2f\n", 56.00 + value * 0.0066);
			else if (value < 20000)
				printf("Commision: $%.2f\n", 76.00 + value * 0.0034);
			else if (value < 50000)
				printf("Commision: $%.2f\n", 100.00 + value * 0.0022);
			else if (value < 500000)
				printf("Commision: $%.2f\n", 155.00 + value * 0.0011);
			else
				printf("Commision: $%.2f\n", 255.00 + value * 0.0009);
		}
	}

	return 0;
}