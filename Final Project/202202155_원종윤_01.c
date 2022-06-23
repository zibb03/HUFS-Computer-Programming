#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Books {
	int bookID;
	char bookName[60];
	char publicationDate[40];
	char publisherName[60];
	int authorID;
};

struct Authors {
	int authorID;
	char authorName[60];
	char authorAddress[100];
	char authorPhoneNumber[100];
	char authorEmailAddress[100];
	char authorBio[60];
};

struct Books bk[20];
struct Authors ars[20];
int authorcnt = 0;
int next;

struct Authors storeDataInAuthorStruct(char line[]) {
	struct Authors ars;

	char *seps = " ,";

	char* token = NULL;
	char* next_token = NULL;

	token = strtok_s(line, seps, &next_token);

	int tempID;
	sscanf_s(token, "%d", &tempID);

	ars.authorID = tempID;

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(ars.authorName, 60, token);

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(ars.authorAddress, 100, token);

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(ars.authorPhoneNumber, 100, token);

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(ars.authorEmailAddress, 100, token);

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(ars.authorBio, 60, token);

	token = strtok_s(NULL, seps, &next_token);

	return ars;
}

struct Books storeDataInBookStruct(char line[]) {
	struct Books bk;

	char *seps = " ,";

	char* token = NULL;
	char* next_token = NULL;

	token = strtok_s(line, seps, &next_token);

	int tempID;
	int tempAID;
	sscanf_s(token, "%d", &tempID);
	bk.bookID = tempID;

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(bk.bookName, 60, token);

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(bk.publicationDate, 40, token);

	token = strtok_s(NULL, seps, &next_token);
	strcpy_s(bk.publisherName, 60, token);

	token = strtok_s(NULL, seps, &next_token);
	sscanf_s(token, "%d", &tempAID);
	bk.authorID = tempAID;

	token = strtok_s(NULL, seps, &next_token);

	return bk;
}

void addAuthorInfo() {
	// ask user to enter book ID.

	FILE* fAuthorPtr;
	int error = fopen_s(&fAuthorPtr, "AuthorsData.txt", "a+");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	FILE* tempfAuthorPtr;
	error = fopen_s(&tempfAuthorPtr, "tempAuthorsData.txt", "w");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Authors ars;
	while (fgets(line, 600, fAuthorPtr) != NULL) {
		ars = storeDataInAuthorStruct(line);
		fprintf(tempfAuthorPtr, "%d ,", ars.authorID);
		fprintf(tempfAuthorPtr, "%s ,", ars.	authorName);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorAddress);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorPhoneNumber);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorEmailAddress);
		fprintf(tempfAuthorPtr, "%s ,\n", ars.authorBio);
	}

	while (1) {
		printf("\nEnter Book ID: ");
		scanf_s("%d", &ars.authorID);
		getchar();
		printf("Enter New Author Name: ");
		gets(ars.authorName);
		printf("Enter New Author Address: ");
		gets(ars.authorAddress);
		printf("Enter New Author Phone Number: ");
		gets(ars.authorPhoneNumber);
		printf("Enter New Author Email Address: ");
		gets(ars.authorEmailAddress);
		printf("Enter New Author Bio: ");
		gets(ars.authorBio);

		fprintf(tempfAuthorPtr, "%d ,", ars.authorID);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorName);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorAddress);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorPhoneNumber);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorEmailAddress);
		fprintf(tempfAuthorPtr, "%s ,\n", ars.authorBio);
		printf("\nRecord saved\n");
		printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
		scanf_s("%d", &next);
		getchar();
		if (next == 0) break;
	}
	authorcnt++;

	fclose(fAuthorPtr);
	fclose(tempfAuthorPtr);
	int flag = remove("AuthorsData.txt");
	if (flag != 0) puts("Unable to remove AuthorsData.txt");
	int flagR = rename("tempAuthorsData.txt", "AuthorsData.txt");
	if (flagR != 0) puts("Unable to remove tempAuthorsData.txt");
}

void updateAuthorInfo() {
	// ask user to enter book ID.
	int authorID;
	printf("\nEnter Author ID: ");
	scanf_s("%d", &authorID);
	getchar();
	FILE* fAuthorPtr;
	int error = fopen_s(&fAuthorPtr, "AuthorsData.txt", "a+");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	FILE* tempfAuthorPtr;
	error = fopen_s(&tempfAuthorPtr, "tempAuthorsData.txt", "w");
	if (error != 0) {
		printf("Error! opening temp file");
		return;
	}
	char line[600];
	struct Authors ars;
	while (fgets(line, 600, fAuthorPtr) != NULL) {
		ars = storeDataInAuthorStruct(line);
		if (ars.authorID == authorID) {
			printf("Enter New Author Name: ");
			gets(ars.authorName);
			printf("Enter New Author Address: ");
			gets(ars.authorAddress);
			printf("Enter New Author Phone Number: ");
			gets(ars.authorPhoneNumber);
			printf("Enter New Author Email Address: ");
			gets(ars.authorEmailAddress);
			printf("Enter New Author Bio: ");
			gets(ars.authorBio);
			fprintf(tempfAuthorPtr, "%d ,", ars.authorID);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorName);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorAddress);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorPhoneNumber);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorEmailAddress);
			fprintf(tempfAuthorPtr, "%s ,\n", ars.authorBio);
			continue;
		}
		fprintf(tempfAuthorPtr, "%d ,", ars.authorID);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorName);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorAddress);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorPhoneNumber);
		fprintf(tempfAuthorPtr, "%s ,", ars.authorEmailAddress);
		fprintf(tempfAuthorPtr, "%s ,\n", ars.authorBio);
	}
	fclose(fAuthorPtr);
	fclose(tempfAuthorPtr);
	int flag = remove("AuthorsData.txt");
	if (flag != 0) puts("Unable to remove AuthorsData.txt");
	int flagR = rename("tempAuthorsData.txt", "AuthorsData.txt");
	if (flagR != 0) puts("Unable to remove tempAuthorsData.txt");
}

void deleteAuthorInfo() {
	// ask user to enter book ID.
	int authorID;
	printf("\nEnter Author ID you want to delete: ");
	scanf_s("%d", &authorID);
	getchar();
	FILE* fAuthorPtr;
	int error = fopen_s(&fAuthorPtr, "AuthorsData.txt", "a+");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	FILE* tempfAuthorPtr;
	error = fopen_s(&tempfAuthorPtr, "tempAuthorsData.txt", "w");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Authors ars;
	while (fgets(line, 600, fAuthorPtr) != NULL) {
		ars = storeDataInAuthorStruct(line);
		if (ars.authorID != authorID) {
			fprintf(tempfAuthorPtr, "%d ,", ars.authorID);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorName);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorAddress);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorPhoneNumber);
			fprintf(tempfAuthorPtr, "%s ,", ars.authorEmailAddress);
			fprintf(tempfAuthorPtr, "%s ,\n", ars.authorBio);
		}
	}
	fclose(fAuthorPtr);
	fclose(tempfAuthorPtr);
	int flag = remove("AuthorsData.txt");
	if (flag != 0) puts("Unable to remove AuthorsData.txt");
	int flagR = rename("tempAuthorsData.txt", "AuthorsData.txt");
	if (flagR != 0) puts("Unable to remove tempAuthorsData.txt");
}

void searchAuthorInfo() {
	// ask user to enter Author Name.
	char deleteauthor[60];
	printf("\nEnter Author Name: ");
	getchar();
	gets(deleteauthor);
	
	FILE* fAuthorPtr;
	int error = fopen_s(&fAuthorPtr, "AuthorsData.txt", "r");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Authors ars;

	while (fgets(line, 600, fAuthorPtr) != NULL) {
		ars = storeDataInAuthorStruct(line);
		if (strcmp(deleteauthor, ars.authorName) == 0) {
			printf("%d ,", ars.authorID);
			printf("%s ,", ars.authorName);
			printf("%s ,", ars.authorAddress);
			printf("%s ,", ars.authorPhoneNumber);
			printf("%s ,", ars.authorEmailAddress);
			printf("%s ,\n", ars.authorBio);
		}
	}

	fclose(fAuthorPtr);
}

void displayAllAuthors() {
	FILE* fAuthorPtr;
	int error = fopen_s(&fAuthorPtr, "AuthorsData.txt", "r");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Authors ars;

	while (fgets(line, 600, fAuthorPtr) != NULL) {
		ars = storeDataInAuthorStruct(line);
		printf("%d ,", ars.authorID);
		printf("%s ,", ars.authorName);
		printf("%s ,", ars.authorAddress);
		printf("%s ,", ars.authorPhoneNumber);
		printf("%s ,", ars.authorEmailAddress);
		printf("%s ,\n", ars.authorBio);
	}

	fclose(fAuthorPtr);
}

void addBookInfo() {
	// ask user to enter book ID.

	FILE* fBookPtr;
	int error = fopen_s(&fBookPtr, "BooksData.txt", "a+");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	FILE* tempfBookPtr;
	error = fopen_s(&tempfBookPtr, "tempBooksData.txt", "w");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}

	char line[600];
	struct Books bk;
	while (fgets(line, 600, fBookPtr) != NULL) {
		bk = storeDataInBookStruct(line);
		fprintf(tempfBookPtr, "%d ,", bk.bookID);
		fprintf(tempfBookPtr, "%s ,", bk.bookName);
		fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
		fprintf(tempfBookPtr, "%s ,", bk.publisherName);
		fprintf(tempfBookPtr, "%d ,\n", bk.authorID);
	}

	while (1) {
		printf("\nEnter Book ID: ");
		scanf_s("%d", &bk.bookID);
		getchar();
		printf("Enter New Book Name: ");
		gets(bk.bookName);
		printf("Enter New Publication Date: ");
		gets(bk.publicationDate);
		printf("Enter New Publisher Name: ");
		gets(bk.publisherName);
		displayAllAuthors();
		printf("Choose the Author Information: ");
		scanf_s("%d", &bk.authorID);

		fprintf(tempfBookPtr, "%d ,", bk.bookID);
		fprintf(tempfBookPtr, "%s ,", bk.bookName);
		fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
		fprintf(tempfBookPtr, "%s ,", bk.publisherName);
		fprintf(tempfBookPtr, "%d ,\n", bk.authorID);
		printf("\nRecord saved\n");
		printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
		scanf_s("%d", &next);
		getchar();
		if (next == 0) break;
	}

	fclose(fBookPtr);
	fclose(tempfBookPtr);
	int flag = remove("BooksData.txt");
	if (flag != 0) puts("Unable to remove BooksData.txt");
	int flagR = rename("tempBooksData.txt", "BooksData.txt");
	if (flagR != 0) puts("Unable to remove tempBooksData.txt");
}

void updateBookInfo() {
	// ask user to enter book ID.
	int bookID;
	printf("\nEnter Book ID: ");
	scanf_s("%d", &bookID);
	getchar();
	FILE* fBookPtr;
	int error = fopen_s(&fBookPtr, "BooksData.txt", "a+");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	FILE* tempfBookPtr;
	error = fopen_s(&tempfBookPtr, "tempBooksData.txt", "w");
	if (error != 0) {
		printf("Error! opening temp file");
		return;
	}
	char line[600];
	struct Books bk;
	while (fgets(line, 600, fBookPtr) != NULL) {
		bk = storeDataInBookStruct(line);
		if (bk.bookID == bookID) {
			printf("Enter New Book Name: ");
			gets(bk.bookName);
			printf("Enter New Publication Date: ");
			gets(bk.publicationDate);
			printf("Enter New Publisher Name: ");
			gets(bk.publisherName);		
			displayAllAuthors();
			printf("Choose the Author Information: ");
			scanf_s("%d", &bk.authorID);
			fprintf(tempfBookPtr, "%d ,", bk.bookID);
			fprintf(tempfBookPtr, "%s ,", bk.bookName);
			fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
			fprintf(tempfBookPtr, "%s ,", bk.publisherName);
			fprintf(tempfBookPtr, "%d ,", bk.authorID);
			continue;
		}
		fprintf(tempfBookPtr, "%d ,", bk.bookID);
		fprintf(tempfBookPtr, "%s ,", bk.bookName);
		fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
		fprintf(tempfBookPtr, "%s ,", bk.publisherName);
		fprintf(tempfBookPtr, "%d ,\n", bk.authorID);
	}
	fclose(fBookPtr);
	fclose(tempfBookPtr);
	int flag = remove("BooksData.txt");
	if (flag != 0) puts("Unable to remove BooksData.txt");
	int flagR = rename("tempBooksData.txt", "BooksData.txt");
	if (flagR != 0) puts("Unable to remove tempBooksData.txt");
}

void deleteBookInfo() {
	// ask user to enter book ID.
	int bookID;
	printf("\nEnter Book ID you want to delete: ");
	scanf_s("%d", &bookID);
	getchar();
	FILE* fBookPtr;
	int error = fopen_s(&fBookPtr, "BooksData.txt", "a+");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	FILE* tempfBookPtr;
	error = fopen_s(&tempfBookPtr, "tempBooksData.txt", "w");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Books bk;
	while (fgets(line, 600, fBookPtr) != NULL) {
		bk = storeDataInBookStruct(line);
		if (bk.bookID != bookID) {
			fprintf(tempfBookPtr, "%d ,", bk.bookID);
			fprintf(tempfBookPtr, "%s ,", bk.bookName);
			fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
			fprintf(tempfBookPtr, "%s ,", bk.publisherName);
			fprintf(tempfBookPtr, "%d ,\n", bk.authorID);
		}
	}
	fclose(fBookPtr);
	fclose(tempfBookPtr);
	int flag = remove("BooksData.txt");
	if (flag != 0) puts("Unable to remove BooksData.txt");
	int flagR = rename("tempBooksData.txt", "BooksData.txt");
	if (flagR != 0) puts("Unable to remove tempBooksData.txt");
}

void searchBookInfo() {
	char deletename[60];
	// ask user to enter book Name.
	printf("\nEnter Book Name: ");
	getchar();
	gets(deletename);

	FILE* fBookPtr;
	int error = fopen_s(&fBookPtr, "BooksData.txt", "r");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Books bk;
	while (fgets(line, 600, fBookPtr) != NULL) {
		bk = storeDataInBookStruct(line);
		if (strcmp(deletename, bk.bookName) == 0) {
			printf("%d ,", bk.bookID);
			printf("%s ,", bk.bookName);
			printf("%s ,", bk.publicationDate);
			printf("%s ,", bk.publisherName);
			printf("%d ,\n", bk.authorID);
		}
	}
	fclose(fBookPtr);
}

void displayAllBooks() {
	FILE* fBookPtr;
	int error = fopen_s(&fBookPtr, "BooksData.txt", "r");
	if (error != 0) {
		printf("Error! opening file");
		return;
	}
	char line[600];
	struct Books bk;
	while (fgets(line, 600, fBookPtr) != NULL) {
		bk = storeDataInBookStruct(line);
		printf("%d ,", bk.bookID);
		printf("%s ,", bk.bookName);
		printf("%s ,", bk.publicationDate);
		printf("%s ,", bk.publisherName);
		printf("%d ,\n", bk.authorID);
	}

	fclose(fBookPtr);
}

int main(void) {
	int cmd;

	do {
		printf("\n\n<< Book Management System >>\n");
		printf("1. Add author information\n");
		printf("2. Update author information\n");
		printf("3. Delete author information\n");
		printf("4. Search author information\n");
		printf("5. Add book information\n");
		printf("6. Update book information\n");
		printf("7. Delete book information\n");
		printf("8. Search book information\n");
		printf("9. Display a list of all books\n");
		printf("10. Exit\n\n");
		scanf_s("%d", &cmd);

		switch (cmd) {
		case 1:
			addAuthorInfo();
			break;

		case 2:
			updateAuthorInfo();
			break;

		case 3:
			deleteAuthorInfo();
			break;

		case 4:
			searchAuthorInfo();
			break;

		case 5:
			addBookInfo();
			break;

		case 6:
			updateBookInfo();
			break;

		case 7:
			deleteBookInfo();
			break;

		case 8:
			searchBookInfo();
			break;

		case 9:
			displayAllBooks();
			break;

		case 10:
			return;

		default:
			printf("Invalid Menu Number\n");
			break;

		}
	} while (cmd != 10);

	return 0;
}
