//6-11

#include <stdio.h>

int main(void) {
	int cnt = 0;
	char first_name, ch = ' ';
	
	printf("Enter a fist and last name: ");

	while (1) {
		ch = getchar();

		if (ch != ' ' && cnt != 1) {
			first_name = ch;
			cnt++;
		}
		else if (ch == ' ' && cnt == 1)
			break;
	}

	while (1) {
		ch = getchar();

		if (ch == '\n')
			break;
		else if (ch != ' ') {
			printf("%c", ch);
		}
	}
	printf(", %c.", first_name);

	return 0;
}