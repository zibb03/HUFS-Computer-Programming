//4. Prime Number (range)
#include <stdio.h>

int main(void) {
	int r1, r2, cnt = 0, i;
	printf("Enter the range: ");
	scanf_s("%d %d", &r1, &r2);

	if (r1 < 0 || r2 < 0 || r1 > r2) {
		printf("Invalid Value");
		return 0;
	}

	for (; r1 <= r2; r1++) {
		for (i = 2; i < r1; i++) {
			if (r1 % i == 0)
				cnt++;
		}
		
		if (cnt == 0)
			printf("%d ", r1);
		
		cnt = 0;
	}

	return 0;
}