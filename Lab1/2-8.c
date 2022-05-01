#include <stdio.h>

int main() {
	float loan, rate, payment, remaining;

	printf("Enter amount of loan: ");
	scanf_s("%f", &loan);
	printf("Enter interest rate: ");
	scanf_s("%f", &rate);
	printf("Enter monthly payment: ");
	scanf_s("%f", &payment);

	remaining = loan + (loan * 0.01 * rate) / 12 - payment;
	printf("Balance remaining after first payment: $%.2f\n", remaining);
	remaining = remaining + (remaining * 0.01 * rate) / 12 - payment;
	printf("Balance remaining after second payment: $%.2f\n", remaining);
	remaining = remaining + (remaining * 0.01 * rate) / 12 - payment;
	printf("Balance remaining after third payment: $%.2f", remaining);

	return 0;
}