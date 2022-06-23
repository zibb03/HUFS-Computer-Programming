//Question No. 2
//Write a C program that finds the intersection of two sets and also displays a list of prime numbers in the
//intersection set.

#include <stdio.h>
#include <math.h>

int X[100], Y[100], in[100], n, cnt = 0, check = 0;

//void intersection() {
//	while (true) {
//		if (xx == n - 1 && yy == n - 1) {
//			break;
//		}
//		if (X[xx] == Y[yy]) {
//			in[cnt] = X[xx];
//			if (xx != n - 1)
//				xx++;
//			if (yy != n - 1)
//				yy++;
//		}
//		else if (X[xx] > Y[yy]) {
//			if (yy != n - 1)
//				yy++;
//		}
//		else {
//			if (xx != n - 1)
//				xx++;
//		}
//	}
//}

void print_prime() {
	for (int i = 0; i < cnt; i++) {
		check = 0;
		for (int j = 2; j <= sqrt(in[i]); j++) {
			if (in[i] % j == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0)
			printf("%d ", in[i]);
	}
}

int main() {
	printf("Write a length of set: ");
	scanf_s("%d", &n);

	printf("Write set of X: ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &X[i]);
	}
	printf("Write set of Y: ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &Y[i]);
		for (int j = 0; j < n; j++) {
			if (X[j] == Y[i]) {
				in[cnt] = Y[i];
				cnt++;
			}
		}
	}
	//for (int i = 0; i < cnt; i++) {
	//	printf("%d", in[i]);
	//}

	print_prime();
	return 0;
}