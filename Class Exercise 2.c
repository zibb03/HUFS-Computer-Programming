#include <stdio.h>
#include <string.h>
#include <conio.h>

struct student {
	int ID;
	char name[20];
};

int main() {
	int choice, tmp1, len = 0, flag = 0;
	char check[20];
	struct student HUFS[100];

	while (1) {
		//system("cls");

		printf("1) Add a Student Information\n2) Search Student by ID\n3) Search Student by Name\n4) Display a List of all students\n5) Exit\n");
		printf("\nEnter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nEnter Student ID : ");
			scanf_s("%d", &HUFS[len].ID);

			printf("\nEnter Student Name : ");
			//scanf_s("%s", HUFS[len].name, 20);
			gets(HUFS[len].name);
			len++;
			break;

		case 2:
			printf("\nEnter Student ID : ");
			scanf_s("%d", &tmp1);
			for (int i = 0; i <= len; i++) {
				if (tmp1 == HUFS[i].ID) {
					printf("\n %d is at %d index.\n", tmp1, i);
					flag = 1;
					break;
				}
			}
			if (!flag) {
				printf("\n %d does not exist.\n", tmp1);
			}
			break;

		case 3:
			printf("\nEnter Student ID : ");
			gets(check);
			for (int i = 0; i <= len; i++) {
				if (strcmp(check, HUFS[i].name) == 0) {
					printf("\n %d is at %d index.\n", tmp1, i);
					flag = 1;
					break;
				}
			}
			if (!flag) {
				printf("\n %s does not exist.\n", check);
			}
			break;

		case 4:
			for (int i = 0; i < len; i++)
				printf("%d %s\n", HUFS[i].ID, HUFS[i].name);
			break;

		case 5:
			return 0;

		default:
			printf("Invalid choice \n");
			break;
		}
	}
	//system("cls");
}