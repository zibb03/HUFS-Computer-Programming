#include <stdio.h>

int main() {
	float volume, radius;
	
	printf("Enter the radius of the sphere : ");
	scanf_s("%f", &radius);
	volume = 4.0f / 3.0f * 3.14 * radius * radius * radius;
	printf("%.2f", volume);

	return 0;
}