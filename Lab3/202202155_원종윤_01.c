// 6 - 1

#include <stdio.h>

int main(void) {
	float tmp, max = -2147283640;

	while (1) {
		printf("Enter a number: ");
		scanf_s("%f", &tmp);

		if (tmp <= 0) {
			if (max < tmp)
				max = tmp;
			break;
		}
		else {
			if (max < tmp)
				max = tmp;
		}
	}

	printf("The largest number entered was %.2f", max);

	return 0;
}