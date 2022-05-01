#include <stdio.h>

int main() {
	int a, b, time;

	printf("Enter a 24-hour time: ");
	scanf_s("%d:%d", &a, &b);
	time = a * 60 + b;

	if (time < 480)
		printf("Closest departure time is 8:00 a.m, arriving at 10:16 a.m");
	else if (480 <= time && time < 583) {
		if (time - 480 < 583 - time)
			printf("Closest departure time is 8:00 a.m, arriving at 10:16 a.m");
		else
			printf("Closest departure time is 9:43 a.m, arriving at 11:52 a.m");
	}
	else if (583 <= time && time < 679) {
		if (time - 583 < 679 - time)
			printf("Closest departure time is 9:43 a.m, arriving at 11:52 a.m");
		else
			printf("Closest departure time is 11:19 a.m, arriving at 1:31 p.m");
	}
	else if (679 <= time && time < 767) {
		if (time - 679 < 767 - time)
			printf("Closest departure time is 11:19 a.m, arriving at 1:31 p.m");
		else
			printf("Closest departure time is 12:47 p.m, arriving at 3:00 p.m");
	}
	else if (767 <= time && time < 840) {
		if (time - 767 < 840 - time)
			printf("Closest departure time is 12:47 p.m, arriving at 3:00 p.m");
		else
			printf("Closest departure time is 2:00 p.m, arriving at 4:08 p.m");
	}
	else if (840 <= time && time < 945) {
		if (time - 840 < 945 - time)
			printf("Closest departure time is 2:00 p.m, arriving at 4:08 p.m");
		else
			printf("Closest departure time is 3:45 p.m, arriving at 5:55 p.m");
	}
	else if (945 <= time && time < 1140) {
		if (time - 945 < 1140 - time)
			printf("Closest departure time is 3:45 p.m, arriving at 5:55 p.m");
		else
			printf("Closest departure time is 7:00 p.m, arriving at 9:20 p.m");
	}
	else if (1140 <= time && time < 1305) {
		if (time - 1140 < 1305 - time)
			printf("Closest departure time is 7:00 p.m, arriving at 9:20 p.m");
		else 
			printf("Closest departure time is 9:45 p.m, arriving at 11:58 p.m");
	}
	else 
		printf("Closest departure time is 9:45 p.m, arriving at 11:58 p.m");

	return 0;
}