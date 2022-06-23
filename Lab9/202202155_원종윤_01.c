#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Books {
	char name[60];
	int ID;
	char date[40];
	char author[60];
	char address[100];
	char publisher[60];
	char p_num[40];
};

int cmd, next = 1, flag, bk_id, del_id = 0, bk_up_id, bk_idx, temp, i, idx = 0;
char name[40], author[40], publisher[40];
struct Books bk[20];

bool check(int t) {
	flag = 0;
	for (i = 0; i < idx; i++) {
		if (t == bk[i].ID)
			flag = 1;
	}
	return flag;
}

void displayi(int i) {
	printf("\n\nName : %s", bk[i].name);
	printf("\nID : %d", bk[i].ID);
	printf("\nPublication date : %s", bk[i].date);
	printf("\nAuthor name : %s", bk[i].author);
	printf("\nAuthor E-mail Address : %s", bk[i].address);
	printf("\nPublisher : %s", bk[i].publisher);
	printf("\nPublisher Phone Number : %s", bk[i].p_num);
}

void add() {
	while (1) {
		printf("\nEnter Book ID : ");
		scanf_s("%d", &temp);
		if (!check(temp) && temp > 0) {
			bk[idx].ID = temp;
		}
		else if (check(temp) == 1) {
			printf("\nThis ID already exists!\n");
			break;
		}
		else if (temp <= 0) {
			printf("\nThis ID's value is invalid\n'");
			break;
		}
		getchar();

		printf("\nEnter Book name : ");
		gets(bk[idx].name);

		printf("\nEnter Publisher name : ");
		gets(bk[idx].publisher);

		printf("\nEnter Publication date : ");
		gets(bk[idx].date);

		printf("\nEnter Author name : ");
		gets(bk[idx].author);

		printf("\nEnter Author e-mail address : ");
		gets(bk[idx].address);

		printf("\nEnter Publisher Phone Number : ");
		gets(bk[idx].p_num);

		idx++;
		printf("\nRecord saved\n");
		printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
		scanf_s("%d", &next);
		getchar();
		if (next == 0) break;
	}
}

void fdelete() {
	printf("\nEnter Book ID to delete : ");
	getchar();
	flag = 0;
	scanf_s("%d", &bk_id);
	for (i = 0; i < idx; i++) {
		if (bk_id == bk[i].ID) {
			del_id = i;
			flag = 1;
			break;
		}
	}
	if (flag) {
		for (i = del_id; i < idx; i++) {
			bk[i] = bk[i + 1];
		}
		idx--;
	}
	else if (!flag) {
		printf("\n This ID is not in this system.\n");
	}
}

void	update() {
	printf("\nEnter Book ID: ");
	scanf_s("%d", &temp);
	for (i = 0; i < idx; i++) {
		if (bk[i].ID == temp) {
			flag = 1;
			displayi(i);
			bk_idx = i;
			break;
		}
	}
	if (check(temp)) {

	}
	if (!flag) {
		printf("\nThis ID does not exist!\n");
	}
	else if (flag == 1) {
		flag = 0;
		printf("\nEnter Book ID to update : ");
		scanf_s("%d", &temp);
		for (i = 0; i < idx; i++) {
			if (bk[i].ID == temp) {
				flag = 1;
			}
		}
		if (!flag && temp > 0) {
			bk[bk_idx].ID = temp;

			getchar();

			printf("\nEnter Book name : ");
			gets(bk[bk_idx].name);

			printf("\nEnter Publisher name : ");
			gets(bk[bk_idx].publisher);

			printf("\nEnter Publisher Date : ");
			gets(bk[bk_idx].date);

			printf("\nEnter Author name : ");
			gets(bk[bk_idx].author);

			printf("\nEnter Author e-mail address : ");
			gets(bk[bk_idx].address);

			printf("\nEnter Publisher Phone Number : ");
			gets(bk[bk_idx].p_num);

			printf("\nRecord saved\n");
		}
		else if (flag == 1) {
			printf("\nThis ID already exists!\n");
		}
		else if (temp < 0) {
			printf("\nThis ID's value is invalid\n'");
		}
	}
}

void search() {
	printf("\nEnter name of book to find : ");
	getchar();
	gets(name);

	flag = 0;

	for (i = 0; i < idx; i++) {
		if (!strcmp(name, bk[i].name)) {
			displayi(i);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("\nThere is no book by that name!\n");
	}
}

void	adisplay() {
	printf("\nEnter author's name of book to find : ");
	getchar();
	gets(author);

	flag = 0;

	for (i = 0; i < idx; i++) {
		if (!strcmp(author, bk[i].author)) {
			displayi(i);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("\nThere is no book by that author's name!\n");
	}
}

void	pdisplay() {
	printf("\nEnter Publisher's name of book to find : ");
	getchar();
	gets(publisher);

	flag = 0;

	for (i = 0; i < idx; i++) {
		if (!strcmp(publisher, bk[i].publisher)) {
			displayi(i);
			flag = 1;
		}
	}

	if (flag == 0) {
		printf("\nThere is no book by that publisher's name!\n");
	}
}

void displayall() {
	for (i = 0; i < idx; i++)
		displayi(i);
}

int main(void) {
	do {
		printf("\n\n<< Library Management Program >>\n");
		printf("1. Add Book Information\n");
		printf("2. Delete Book Information\n");
		printf("3. Update Book Information\n");
		printf("4. Search by Book Name\n");
		printf("5. Display a list of book(s) published by an author a\n");
		printf("6. Display a list of book(s) published by a publisher p\n");
		printf("7. Display list of all book\n");
		printf("8. Exit\n\n");
		scanf_s("%d", &cmd);

		switch (cmd) {
		case 1:
			add();
			break;

		case 2:
			fdelete();
			break;

		case 3:
			update();
			break;

		case 4:
			search();
			break;

		case 5:
			adisplay();
			break;

		case 6:
			pdisplay();
			break;

		case 7:
			displayall();
			break;

		case 8:
			return;

		default:
			printf("Invalid choice: \n");
			break;
		}
	} while (cmd != 8);
	
	return 0;
}