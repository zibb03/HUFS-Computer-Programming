#include<stdio.h>

int main() {
	float income;

	printf("Enter the amount of taxable income: ");
	scanf_s("$%f", &income);

	if (income < 750.0)
		printf("Your tax due: $%.2f", income * 0.01);
	else if (750.0 <= income && income < 2250.0) {
		if (income == 750.0)
			printf("Your tax due: $%.2f", 7.50);
		else 	
			printf("Your tax due: $%.2f", (7.50 + income * 0.02));
	}
	else if (2250.0 <= income && income < 3750.0) {
		if (income == 2250.0)
			printf("Your tax due: $%.2f", 37.50);
		else
			printf("Your tax due: $%.2f", 37.50 + income * 0.03);
	}
	else if (3750.0 <= income && income < 5250.0) {
		if (income == 3750.0)
			printf("Your tax due: $%.2f", 82.50);
		else
			printf("Your tax due: $%.2f", 82.50 + income * 0.04);
	}
	else if (5250.0 <= income && income < 7000.0) {
		if (income == 5250.0)
			printf("Your tax due: $%.2f", 52.50);
		else
			printf("Your tax due: $%.2f", 142.50 + income * 0.05);
	}
	else {
		if (income == 7000.0)
			printf("Your tax due: $%f", 230.00);
		else
			printf("Your tax due: $%f", 52.50 + income * 0.06);
	}

	return 0;
}