#include <stdio.h>

int main() {
	float volume, radius = 10;

	volume = 4.0f / 3.0f * 3.14 * radius * radius * radius;
	printf("%.2f", volume);

	return 0;
}