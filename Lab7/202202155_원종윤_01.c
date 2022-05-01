# include <string.h>
# include <stdio.h>

struct book {
	char ID[100];
	char BName[100][50];
	char Date[100][50];
	char PName[100][50];
	char Number[100][50];
	char AName[100][50];
	char Address[100][50];
};
struct book books;

int main() {
	int cmd, cmd2, tmp, tmp2,  i, idx = 0, next, flag;
	char ctmp[50], ctmp2[50];

	do {
		printf("\n\n<< Student ID Management Program >>\n");
		printf("1. Add Book information\n");
		printf("2. Update Book information\n");
		printf("3. Delete Book information\n");
		printf("4. Search Book information\n");
		printf("5. Display a list of book(s) published by an author\n");
		printf("6. Display a list of book(s) published by a publisher\n");
		printf("7. Display a list of all book\n");
		printf("8. Exit\n\n");

		printf("Enter your choice:\n");
		scanf_s("%d", &cmd);

		switch (cmd) {
		case 1:
			//1. Add Book information
			next = 1, flag = 0;
			while (1) {
				printf("\nEnter Book ID : ");
				scanf_s("%d", &tmp);
				if (tmp < 0) {
					flag = 1;
				}
				for (i = 0; i < idx; i++) {
					if (tmp == books.ID[i]) {
						flag = 1;
					}
				}
				if (!flag) {
					books.ID[idx] = tmp;
				}
				else if (flag == 1) {
					printf("\n This ID already exists!\n");
					break;
				}
				printf("\nEnter Book Name : ");
				scanf_s("%s", &books.BName[idx], 50);
				printf("\nEnter Publication Date : ");
				scanf_s("%s", &books.Date[idx], 50);
				printf("\nEnter Publisher Name : ");
				scanf_s("%s", &books.PName[idx], 50);
				printf("\nEnter Publisher Phone Number : ");
				scanf_s("%s", &books.Number[idx], 50);
				printf("\nEnter Auther Name : ");
				scanf_s("%s", &books.AName[idx], 50);
				printf("\nEnter Auther Email Address : ");
				scanf_s("%s", &books.Address[idx], 50);
				idx++;

				printf("\Book Information Saved\n");
				printf("\nWould you like to add another Book Information? \n<<Enter 1 to continue>> ");
				scanf_s("%d", &next);
				if (next == 0) break;
			}
			break;

		case 2:
			//2. Update Book information
			printf("\nChoose a Book information you want to update. \n");
			printf("1.Book ID. \n");
			printf("2.Book Name. \n");
			printf("3.Book Publication Date. \n");
			printf("4.Book Publication Name. \n");
			printf("5.Book Publisher Phone Number. \n");
			printf("6.Book Author Name. \n");
			printf("7.Book Email Address. \n");

			scanf_s("%d", &cmd2);
			switch (cmd2)
			{
			case 1:
				printf("Enter information (Existing Value, Value you want to update) :");
				scanf_s("%d, %d", &tmp, &tmp2);

				for (int i = 0; i < idx; i++) {
					if (tmp == books.ID[i]) {
						books.ID[i] = tmp2;
						break;
					}
				}
				break;
			case 2:
				printf("Enter existing information you want to update:");
				scanf_s("%s", &ctmp, 50);
				printf("Enter information you want to update:");
				scanf_s("%s", &ctmp2, 50);

				for (int i = 0; i < idx; i++) {
					//printf("%d", strcmp(ctmp, books.BName[i]));
					if (strcmp(ctmp, books.BName[i]) == 0) {
						strcpy_s(books.BName[i], 50, ctmp2);
						break;
					}
				}
				break;
			case 3:
				printf("Enter existing information you want to update:");
				scanf_s("%s", &ctmp, 50);
				printf("Enter information you want to update:");
				scanf_s("%s", &ctmp2, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Date[i]) == 0) {
						strcpy_s(books.Date[i], 50, ctmp2);
						break;
					}
				}
				break;
			case 4:
				printf("Enter existing information you want to update:");
				scanf_s("%s", &ctmp, 50);
				printf("Enter information you want to update:");
				scanf_s("%s", &ctmp2, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.PName[i]) == 0) {
						strcpy_s(books.PName[i], 50, ctmp2);
						break;
					}
				}
				break;
			case 5:
				printf("Enter existing information you want to update:");
				scanf_s("%s", &ctmp, 50);
				printf("Enter information you want to update:");
				scanf_s("%s", &ctmp2, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Number[i]) == 0) {
						strcpy_s(books.Number[i], 50, ctmp2);
						break;
					}
				}
				break;
			case 6:
				printf("Enter existing information you want to update:");
				scanf_s("%s", &ctmp, 50);
				printf("Enter information you want to update:");
				scanf_s("%s", &ctmp2, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.AName[i]) == 0) {
						strcpy_s(books.AName[i], 50, ctmp2);
						break;
					}
				}
				break;
			case 7:
				printf("Enter existing information you want to update:");
				scanf_s("%s", &ctmp, 50);
				printf("Enter information you want to update:");
				scanf_s("%s", &ctmp2, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Address[i]) == 0) {
						strcpy_s(books.Address[i], 50, ctmp2);
						break;
					}
				}
				break;
			default:
				printf("Invalid choice \n");
				break;
			}

			break;
		case 3:
			//3. Delete Book information
			printf("\nChoose a Book information you want to use to delete. \n");
			printf("1.Book ID. \n");
			printf("2.Book Name. \n");
			printf("3.Book Publication Date. \n");
			printf("4.Book Publication Name. \n");
			printf("5.Book Publisher Phone Number. \n");
			printf("6.Book Author Name. \n");
			printf("7.Book Email Address. \n");

			scanf_s("%d", &cmd2);
			switch (cmd2) {
			case 1:
				printf("Enter existing information you want to delete:");
				scanf_s("%d", &tmp);

				for (int i = 0; i < idx; i++) {
					if (tmp == books.ID[i]) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
				break;
			case 2:
				printf("Enter existing information you want to delete:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.BName[i]) == 0) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
			break;			
			case 3:
				printf("Enter existing information you want to delete:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Date[i]) == 0) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
				break;
			case 4:
				printf("Enter existing information you want to delete:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.PName[i]) == 0) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
				break;
			case 5:
				printf("Enter existing information you want to delete:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Number[i]) == 0) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
				break;
			case 6:
				printf("Enter existing information you want to delete:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.AName[i]) == 0) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
				break;
			case 7:
				printf("Enter existing information you want to delete:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Address[i]) == 0) {
						for (int j = i; j < idx - 1; j++) {
							books.ID[j] = books.ID[j + 1];
							strcpy_s(books.BName[i], 50, books.BName[i + 1]);
							strcpy_s(books.Date[i], 50, books.Date[i + 1]);
							strcpy_s(books.PName[i], 50, books.PName[i + 1]);
							strcpy_s(books.Number[i], 50, books.Number[i + 1]);
							strcpy_s(books.AName[i], 50, books.AName[i + 1]);
							strcpy_s(books.Address[i], 50, books.Address[i + 1]);
						}
						idx--;
						break;
					}
				}
				break;
			default:
				printf("Invalid choice \n");
				break;
			}

			break;
		case 4:
			//4. Search Book information
			printf("\nChoose a Book information you want to search. \n");
			printf("1.Book ID. \n");
			printf("2.Book Name. \n");
			printf("3.Book Publication Date. \n");
			printf("4.Book Publication Name. \n");
			printf("5.Book Publisher Phone Number. \n");
			printf("6.Book Author Name. \n");
			printf("7.Book Email Address. \n");

			scanf_s("%d", &cmd2);
			switch (cmd2) {
			case 1:
				printf("Enter existing information you want to search:");
				scanf_s("%d", &tmp);

				for (int i = 0; i < idx; i++) {
					if (tmp == books.ID[i]) {
						printf("%d is in index %d", tmp, i);
						break;
					}
				}
				break;
			case 2:
				printf("Enter existing information you want to search:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.BName[i]) == 0) {
						printf("%s is in index %d", ctmp, i);
						break;
					}
				}
				break;
			case 3:
				printf("Enter existing information you want to search:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Date[i]) == 0) {
						printf("%s is in index %d", ctmp, i);
						break;
					}
				}
				break;
			case 4:
				printf("Enter existing information you want to search:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.PName[i]) == 0) {
						printf("%s is in index %d", ctmp, i);
						break;
					}
				}
				break;
			case 5:
				printf("Enter existing information you want to search:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Number[i]) == 0) {
						printf("%s is in index %d", ctmp, i);
						break;
					}
				}
				break;
			case 6:
				printf("Enter existing information you want to search:");
				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.AName[i]) == 0) {
						printf("%s is in index %d", ctmp, i);
						break;
					}
				}
				break;
			case 7:
				printf("Enter existing information you want to search:");

				scanf_s("%s", &ctmp, 50);

				for (int i = 0; i < idx; i++) {
					if (strcmp(ctmp, books.Address[i]) == 0) {
						printf("%s is in index %d", ctmp, i);
						break;
					}
				}
				break;
			default:
				printf("Invalid choice \n");
				break;
			}
			
			break;
		case 5:
			//5. Display a list of book(s) published by an author
			printf("Enter Author Name you want to search:");
			scanf_s("%s", &ctmp, 50);

			for (int i = 0; i < idx; i++) {
				if (strcmp(ctmp, books.AName[i]) == 0) {
					printf("%d %s %s %s %s %s %s\n", books.ID[i], books.BName[i], books.Date[i], books.PName[i], books.Number[i], books.AName[i], books.Address[i]);
				}
			}
			break;
		case 6:
			//6. Display a list of book(s) published by a publisher
			printf("Enter Publisher Name you want to search:");
			scanf_s("%s", &ctmp, 50);

			for (int i = 0; i < idx; i++) {
				if (strcmp(ctmp, books.PName[i]) == 0) {
					printf("%d %s %s %s %s %s %s\n", books.ID[i], books.BName[i], books.Date[i], books.PName[i], books.Number[i], books.AName[i], books.Address[i]);
				}
			}
			break;
		case 7:
			//7. Display a list of all book
			for (int i = 0; i < idx; i++) {
				printf("%d %s %s %s %s %s %s\n", books.ID[i], books.BName[i], books.Date[i], books.PName[i], books.Number[i], books.AName[i], books.Address[i]);
			}
			break;
		case 8:
			return;

		default:
			printf("Invalid choice \n");
			break;
		}
	} while (cmd != 8);
}
