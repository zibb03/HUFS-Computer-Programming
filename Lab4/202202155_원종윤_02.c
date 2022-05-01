//6-10
//vowels

#include <stdio.h> 

int main(void) {
	int cnt = 0;
	char ch;

	printf("Enter a sentence: ");
	
	ch = getchar();
	while (ch != '\n') {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			cnt++;
		ch = getchar();
	}
	printf("Your sentence contains %d vowels.", cnt);

	return 0;
}