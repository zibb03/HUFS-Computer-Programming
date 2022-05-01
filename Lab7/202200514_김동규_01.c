#include <stdio.h>
#include <string.h>

struct Book
{
	int Book_ID;
	char Book_Name[20];
	char Publication_Date[20];
	char Publisher_Name[20];
	char Publisher_Phone_Number[20];
	char Author_Name[20];
	char Author_Email_Address[20];

};

int main(void)
{
	struct Book Books[20];
	int Book_index = 0, del_index = 0, search_index = 0;
	int Condition = 1, flag = 0;
	int choise, choise_in;
	int Book_ID_temp, temp_ID;
	char Book_Name_temp[20], Publication_Date_temp[20], Book_Publisher_Name_temp[20], Book_Publisher_Phone_Number_temp[20], Book_Author_Name_temp[20], Book_Author_Email_Address_temp[20], temp_info[20];
	while (Condition)
	{
		printf("\n                       * Menu *                           ");
		printf("\n=========================================================\n");
		printf(" 1. Add book information.\n");
		printf(" 2. Update book information.\n");
		printf(" 3. Delete book information.\n");
		printf(" 4. Search book information.\n");
		printf(" 5. Display a list of book(s) published by an author.a \n");
		printf(" 6. Display a list of book(s) published by a publisher.p\n");
		printf(" 7. A list of all book(s).\n");
		printf(" 8. Quit.\n");
		printf("=========================================================\n");
		printf(" Enter a your choise : ");
		scanf_s("%d", &choise);
		getchar();
		switch (choise)
		{
		case 1: // Add book information
			printf("\n* Add book information.\n");
			printf("===================================\n");
			printf("Enter a Book ID ( Don't Enter negative number ) : ");
			scanf_s("%d", &Books[Book_index].Book_ID);
			getchar();
			if (Books[Book_index].Book_ID <= 0)
			{
				printf("It is Negative Number.");
				break;
			}

			printf("\nEnter a Book Name : ");
			gets(Books[Book_index].Book_Name);

			printf("\nEnter a Book Pubication Date (YY/MM/DD): ");
			gets(Books[Book_index].Publication_Date);

			printf("\nEnter a Publisher Name : ");
			gets(Books[Book_index].Publisher_Name);

			printf("\nEnter a Publisher Phone Number : ");
			gets(Books[Book_index].Publisher_Phone_Number);

			printf("\nEnter a Author Name : ");
			gets(Books[Book_index].Author_Name);

			printf("\nEnter a Author Email Address : ");
			gets(Books[Book_index].Author_Email_Address);

			Book_index += 1;
			break;
		case 2:  // Update book information
			printf("\n* Update book information. \n");
			printf("===================================\n");
			printf("* Choise a Book information to be updated. \n");
			printf("1.Book ID. \n");
			printf("2.Book Name. \n");
			printf("3.Book Publication Date. \n");
			printf("4.Book Publication Name. \n");
			printf("5.Book Publisher Phone Number. \n");
			printf("6.Book Author Name. \n");
			printf("7.Book Email Address. \n");
			printf("===================================\n");
			printf("Enter a number : ");
			scanf_s("%d", &choise_in);
			getchar();
			switch (choise_in)
			{
			case 1:
				printf("Enter a Book ID (finding): ");
				scanf_s("%d", &temp_ID);
				getchar();
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (temp_ID == Books[i].Book_ID)
					{
						printf("Enter a Book ID to be updated : ");
						scanf_s("%d", &Book_ID_temp);
						flag = 1;
						Books[i].Book_ID = Book_ID_temp;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%d ID does not exist in Books\n", temp_ID);
				}
				break;
			case 2:
				printf("Enter a Book Name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Book_Name) == 0)
					{
						printf("Enter a Book Name to be updated : ");
						gets(Book_Name_temp);
						flag = 1;
						strcpy_s(Books[i].Book_Name, 20, Book_Name_temp); // arr is not ivalue(It can not be modified) , so it need copy.
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book Name does not exist in Books\n", temp_info);
				}
				break;
			case 3:
				printf("Enter a Book publication date (finding) (YY/MM/DD) : ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publication_Date) == 0)
					{
						printf("Enter a Book Pulication Date to be updated (YY/MM/DD) : ");
						gets(Publication_Date_temp);
						flag = 1;
						strcpy_s(Books[i].Publication_Date, 20, Publication_Date_temp); // arr is not ivalue(It can not be modified) , so it need copy(strcpy).
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book Pubilcation date does not exist in Books\n", temp_info);
				}
				break;
			case 4:
				printf("Enter a Book publisher Name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publisher_Name) == 0)
					{
						printf("Enter a Book publisher name to be updated : ");
						gets(Book_Publisher_Name_temp);
						flag = 1;
						strcpy_s(Books[i].Publisher_Name, 20, Book_Publisher_Name_temp); // arr is not ivalue(It can not be modified) , so it need copy.
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Publisher name does not exist in Books\n", temp_info);
				}
				break;
			case 5:
				printf("Enter a Book publisher phone number (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publisher_Phone_Number) == 0)
					{
						printf("Enter a Book publisher phone number to be updated : ");
						gets(Book_Publisher_Phone_Number_temp);
						flag = 1;
						strcpy_s(Books[i].Publisher_Phone_Number, 20, Book_Publisher_Phone_Number_temp); // arr is not ivalue(It can not be modified) , so it need copy.
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s ID does not exist in Books\n", temp_info);
				}
				break;
			case 6:
				printf("Enter a Book author name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Author_Name) == 0)
					{
						printf("Enter a Book author name to be updated : ");
						gets(Book_Author_Name_temp);
						flag = 1;
						strcpy_s(Books[i].Author_Name, 20, Book_Author_Name_temp); // arr is not ivalue(It can not be modified) , so it need copy.
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Author Name does not exist in Books\n", temp_info);
				}
				break;
			case 7:
				printf("Enter a Book author email address (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Author_Email_Address) == 0)
					{
						printf("Enter a Book author email address to be updated : ");
						gets(Book_Author_Email_Address_temp);
						flag = 1;
						strcpy_s(Books[i].Author_Email_Address, 20, Book_Author_Email_Address_temp); // arr is not ivalue(It can not be modified) , so it need copy.
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Author Email Address does not exist in Books\n", temp_info);
				}
				break;
			default:
				printf("Invalid choice \n");
				break;
			}
			break;
		case 3:   // Delete book information.
			printf("\n* Delete book information.\n");
			printf("===================================\n");
			printf("* Choise a Book information to be delete. \n");
			printf("1.Book ID. \n");
			printf("2.Book Name. \n");
			printf("3.Book Publication Date. \n");
			printf("4.Book Publication Name. \n");
			printf("5.Book Publisher Phone Number. \n");
			printf("6.Book Author Name. \n");
			printf("7.Book Email Address. \n");
			printf("===================================\n");
			printf("Enter a number : ");
			scanf_s("%d", &choise_in);
			getchar();
			switch (choise_in)
			{
			case 1:
				printf("Enter a Book ID (finding): ");
				scanf_s("%d", &temp_ID);
				getchar();
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (temp_ID == Books[i].Book_ID)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%d ID does not exist in Books\n", temp_ID);
				}
				else
				{

					Books[del_index].Book_ID = 0; //None 
				}
				break;
			case 2:
				printf("Enter a Book Name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Book_Name) == 0)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book Name does not exist in Books\n", temp_info);
				}
				else
				{
					strcpy_s(Books[del_index].Book_Name, 20, "None");
				}
				break;
			case 3:
				printf("Enter a Book publication date (finding) (YY/MM/DD) : ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publication_Date) == 0)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book publication date does not exist in Books\n", temp_info);
				}
				else
				{
					strcpy_s(Books[del_index].Publication_Date, 20, "None");
				}
				break;
			case 4:
				printf("Enter a Book publication date Name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publisher_Name) == 0)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book publication date does not exist in Books\n", temp_info);
				}
				else
				{
					strcpy_s(Books[del_index].Publisher_Name, 20, "None");
				}
				break;
			case 5:
				printf("Enter a Book publisher phone number (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publisher_Phone_Number) == 0)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book publisher phone number does not exist in Books\n", temp_info);
				}
				else
				{
					strcpy_s(Books[del_index].Publisher_Phone_Number, 20, "None");
				}
				break;
			case 6:
				printf("Enter a Book author name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Author_Name) == 0)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s  Book author name does not exist in Books\n", temp_info);
				}
				else
				{
					strcpy_s(Books[del_index].Author_Name, 20, "None");
				}
				break;
			case 7:
				printf("Enter a Book author email address (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Author_Email_Address) == 0)
					{
						flag = 1;
						del_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book author email address does not exist in Books\n", temp_info);
				}
				else
				{
					strcpy_s(Books[del_index].Author_Email_Address, 20, "None");
				}
				break;
			default:
				printf("Invalid choice \n");
				break;
			}
			break;
		case 4:  // Search book information.
			printf("\n* Search book information.\n");
			printf("===================================\n");
			printf("* Choise a Book information to be delete. \n");
			printf("1.Book ID. \n");
			printf("2.Book Name. \n");
			printf("3.Book Publication Date. \n");
			printf("4.Book Publication Name. \n");
			printf("5.Book Publisher Phone Number. \n");
			printf("6.Book Author Name. \n");
			printf("7.Book Email Address. \n");
			printf("===================================\n");
			printf("Enter a number : ");
			scanf_s("%d", &choise_in);
			getchar();
			switch (choise_in)
			{
			case 1:
				printf("Enter a Book ID (finding): ");
				scanf_s("%d", &temp_ID);
				getchar();
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (temp_ID == Books[i].Book_ID)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%d ID does not exist in Books\n", temp_ID);
				}
				else
				{
					printf("%d is in Books Number %d", temp_ID, search_index + 1);
				}
				break;
			case 2:
				printf("Enter a Book Name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Book_Name) == 0)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book Name does not exist in Books\n", temp_info);
				}
				else
				{
					printf("%s is in Books Number %d", temp_info, search_index + 1);
				}
				break;
			case 3:
				printf("Enter a Book publication date (finding) (YY/MM/DD) : ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publication_Date) == 0)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book publication date does not exist in Books\n", temp_info);
				}
				else
				{
					printf("%s is in Books Number %d", temp_info, search_index + 1);
				}
				break;
			case 4:
				printf("Enter a Book publisher Name (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publisher_Name) == 0)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book publisher Name does not exist in Books\n", temp_info);
				}
				else
				{
					printf("%s is in Books Number %d", temp_info, search_index + 1);
				}
				break;
			case 5:
				printf("Enter a Book publisher phone number (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Publisher_Phone_Number) == 0)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book publisher phone number does not exist in Books\n", temp_info);
				}
				else
				{
					printf("%s is in Books Number %d", temp_info, search_index + 1);
				}
				break;
			case 6:
				printf("Enter a  Book author (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Author_Name) == 0)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book author does not exist in Books\n", temp_info);
				}
				else
				{
					printf("%s is in Books Number %d", temp_info, search_index + 1);
				}
				break;
			case 7:
				printf("Enter a Book author email address (finding): ");
				gets(temp_info);
				flag = 0;
				for (int i = 0; i < Book_index; i++)
				{
					if (strcmp(temp_info, Books[i].Author_Email_Address) == 0)
					{
						flag = 1;
						search_index = i;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n%s Book author email address does not exist in Books\n", temp_info);
				}
				else
				{
					printf("%s is in Books Number %d", temp_info, search_index + 1);
				}
				break;
			default:
				printf("Invalid choice \n");
				break;
			}
			break;
		case 5:  // Display a list of book(s) published by an author.a
			printf("\n* Display a list of book(s) published by an author \n");
			printf("=========================================================\n");
			printf("Enter a Book author name : ");
			gets(temp_info);
			flag = 0;
			for (int i = 0; i < Book_index; i++)
			{
				if (strcmp(temp_info, Books[i].Author_Name) == 0)
				{
					printf("Number %d. Book ID is %d\n", i + 1, Books[i].Book_ID);
					printf("Number %d. Book Name is %s\n", i + 1, Books[i].Book_Name);
					printf("Number %d. Book Publication Date is %s\n", i + 1, Books[i].Publication_Date);
					printf("Number %d. Book Publisher Name is %s\n", i + 1, Books[i].Publisher_Name);
					printf("Number %d. Book Publicher Number is %s\n", i + 1, Books[i].Publisher_Phone_Number);
					printf("Number %d. Book Author Name is %s\n", i + 1, Books[i].Author_Name);
					printf("Number %d. Book Author Email Address is %s\n", i + 1, Books[i].Author_Email_Address);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0)
			{
				printf("\n%s of Author name does not exist in Books\n", temp_info);
			}
			break;
		case 6:  // Display a list of book(s) published by a publisher.p
			printf("\n* Display a list of book(s) published by a publisher\n");
			printf("===========================================================\n");
			printf("Enter a Book publisher name : ");
			gets(temp_info);
			flag = 0;
			for (int i = 0; i < Book_index; i++)
			{
				if (strcmp(temp_info, Books[i].Publisher_Name) == 0)
				{
					printf("Number %d. Book ID is %d\n", i + 1, Books[i].Book_ID);
					printf("Number %d. Book Name is %s\n", i + 1, Books[i].Book_Name);
					printf("Number %d. Book Publication Date is %s\n", i + 1, Books[i].Publication_Date);
					printf("Number %d. Book Publisher Name is %s\n", i + 1, Books[i].Publisher_Name);
					printf("Number %d. Book Publicher Number is %s\n", i + 1, Books[i].Publisher_Phone_Number);
					printf("Number %d. Book Author Name is %s\n", i + 1, Books[i].Author_Name);
					printf("Number %d. Book Author Email Address is %s\n", i + 1, Books[i].Author_Email_Address);
					printf("\n\n");
					flag = 1;
				}
			}
			if (flag == 0)
			{
				printf("\n%s of Publisher Name does not exist in Books\n", temp_info);
			}

			break;
		case 7: // Display A list of all book(s)
			printf("\n* A list of all book(s).\n");
			for (int i = 0; i < Book_index; i++)
			{
				printf("======================================================\n");
				printf("Number %d. Book ID is %d\n", i + 1, Books[i].Book_ID);
				printf("Number %d. Book Name is %s\n", i + 1, Books[i].Book_Name);
				printf("Number %d. Book Publication Date is %s\n", i + 1, Books[i].Publication_Date);
				printf("Number %d. Book Publisher Name is %s\n", i + 1, Books[i].Publisher_Name);
				printf("Number %d. Book Publicher Number is %s\n", i + 1, Books[i].Publisher_Phone_Number);
				printf("Number %d. Book Author Name is %s\n", i + 1, Books[i].Author_Name);
				printf("Number %d. Book Author Email Address is %s\n", i + 1, Books[i].Author_Email_Address);
				printf("======================================================\n");
			}
			break;
		case 8: // Quit.
			Condition = 0;
			break;
		default:
			printf("Invalid choice \n");
			break;
		}
	}
	return 0;
}