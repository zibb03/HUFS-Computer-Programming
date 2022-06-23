#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIRECTORY_BooksData "/Users/benny/HUFS 2022/컴퓨터프로그래밍/FinalProject/BooksData.txt"
#define DIRECTORY_tempBooksData "/Users/benny/HUFS 2022/컴퓨터프로그래밍/FinalProject/tempBooksData.txt"
#define DIRECTORY_AuthorsData "/Users/benny/HUFS 2022/컴퓨터프로그래밍/FinalProject/AuthorsData.txt"
#define DIRECTORY_tempAuthorsData "/Users/benny/HUFS 2022/컴퓨터프로그래밍/FinalProject/tempAuthorsData.txt"

struct Books
{
   int bookID;
   char bookName[60];
   char publicationDate[40];
   char publisherName[60];
   int authorID;
};

struct Authors
{
   int authorID;
   char authorName[60];
   char authorAddress[100];
   char authorPhoneNumber[40];
   char authorEmailAddress[40];
   char authorBio[100];
};

struct Books storeDataInBookStruct(char a[]) // Clear
{
   struct Books bk;
   char temp[100];

   strcpy(temp, strtok(a, ","));
   bk.bookID = atoi(temp);
   strcpy(bk.bookName, strtok(NULL, ","));
   strcpy(bk.publicationDate, strtok(NULL, ","));
   strcpy(bk.publisherName, strtok(NULL, ","));
   strcpy(temp, strtok(NULL, "\n"));
   bk.authorID = atoi(temp);

   return bk;
}

struct Authors storeDataInAuthorStruct(char a[]) // Clear
{
   struct Authors auth;
   char temp[100];

   strcpy(temp, strtok(a, ","));
   auth.authorID = atoi(temp);
   strcpy(auth.authorName, strtok(NULL, ","));
   strcpy(auth.authorAddress, strtok(NULL, ","));
   strcpy(auth.authorPhoneNumber, strtok(NULL, ","));
   strcpy(auth.authorEmailAddress, strtok(NULL, ","));
   strcpy(auth.authorBio, strtok(NULL, "\n"));

   return auth;
}

void displayAuthorInfo(int authorID) // Clear
{
   struct Authors auth;
   char temp[100];

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_AuthorsData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   while (fgets(temp, 600, fPtr) != NULL)
   {
      auth = storeDataInAuthorStruct(temp);
      if (authorID == auth.authorID)
      {
         printf("Author Name:           %s\n", auth.authorName);
         printf("Author Address:        %s\n", auth.authorAddress);
         printf("Author Phone Number:   %s\n", auth.authorPhoneNumber);
         printf("Author E-mail Address: %s\n", auth.authorEmailAddress);
         printf("Author Bio:            %s\n", auth.authorBio);
      }
   }
   fclose(fPtr);
}

int addAuthorInfo() // Clear
{
   // ask user to enter book ID.
   int authorID;

   printf("Enter New Author ID: ");
   scanf("%d", &authorID);
   getchar();

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_AuthorsData, "a+");

   char temp[600];
   struct Authors auth;

   printf("Enter New Author Name: ");
   gets(auth.authorName);
   printf("Enter New Author Address: ");
   gets(auth.authorAddress);
   printf("Enter New Author Phone Number: ");
   gets(auth.authorPhoneNumber);
   printf("Enter New Author Email Address: ");
   gets(auth.authorEmailAddress);
   printf("Enter New Author Short Bio: ");
   gets(auth.authorBio);

   fprintf(fPtr, "%d,", authorID);
   fprintf(fPtr, "%s,", auth.authorName);
   fprintf(fPtr, "%s,", auth.authorAddress);
   fprintf(fPtr, "%s,", auth.authorPhoneNumber);
   fprintf(fPtr, "%s,", auth.authorEmailAddress);
   fprintf(fPtr, "%s\n", auth.authorBio);

   fclose(fPtr);

   return authorID;
}

int searchAuthorInfo(int arg) // Clear
{ // 0: call from main(), 1: call from addBookInfo(), 2: call from updateAuthorInfo() or deleteAuthorInfo()
   char srch[100];
   char temp[600];
   int authorID = 0, flag = 0, i = -1;
   struct Books bk;
   struct Authors auth;

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_AuthorsData, "r");
   if (fPtr == 0)
   {
      printf("No Author information exist.\n");
      return 0;
   }

   if (fgets(temp, 600, fPtr) == NULL) {
      printf("No Author information exist.\n");
      return 0;
   }
   printf("Enter Author name you searching: ");
   scanf("%s", srch);
   do {
      auth = storeDataInAuthorStruct(temp);
      if (strcmp(srch, auth.authorName) == 0)
      {
         if (flag == 0)
            printf("\nAuthor Information\n");
         flag++;
         authorID = auth.authorID;
         printf("\nAuthor ID:             %.8d\n", auth.authorID);
         printf("Author Name:           %s\n", auth.authorName);
         printf("Author Address:        %s\n", auth.authorAddress);
         printf("Author Phone Number:   %s\n", auth.authorPhoneNumber);
         printf("Author E-mail Address: %s\n", auth.authorEmailAddress);
         printf("Author Bio:            %s\n", auth.authorBio);
      }
   } while (fgets(temp, 600, fPtr) != NULL);

   fclose(fPtr);

   if (arg == 0 || arg == 2)
   {
      if (flag == 0)
         printf("\nNo Author information exist.\n");
      else if (flag > 1)
      {
         printf("\nSelect Author ID: ");
         scanf("%d", &authorID);
      }
   }
   else if (arg == 1)
   {
      if (flag == 0)
      {
         printf("\nNo Author information exist. Create new Author information.\n\n");
      }
      else if (flag == 1)
      {
         printf("\nEnter '0' to create new author information, Enter '1' to use this information: ");
         scanf("%d", &i);
         if (i == 0) {
            printf("\n");
            return 0;
         }
      }
      else if (flag > 1)
      {
         printf("\nSelect Author ID or Enter '0' to create new author information: ");
         scanf("%d", &authorID);
         if (authorID == 0)
            printf("\n");
      }
   }

   if (arg == 0)
   { // call from main(): display author's all book
      flag = 0;
      fPtr = fopen(DIRECTORY_BooksData, "r");
      if (fPtr == 0)
      {
         printf("Error! opening file\n");
         return 0;
      }
      while (fgets(temp, 600, fPtr) != NULL)
      {
         bk = storeDataInBookStruct(temp);
         if (authorID == bk.authorID)
         {
            if (flag == 0)
               printf("\nAuthor's Book\n");
            flag++;
            printf("\nBook ID: %d\n", bk.bookID);
            printf("Book Name: %s\n", bk.bookName);
            printf("Publication Date: %s\n", bk.publicationDate);
            printf("Publisher Name: %s\n", bk.publisherName);
         }
      }
      if (flag == 0) printf("\nCan't found Author's book\n");
      fclose(fPtr);
   }

   return authorID;
}

void addBookInfo() // Clear
{
   // ask user to enter book ID.
   int bookID, authorID;

   printf("Enter Book ID: ");
   scanf("%d", &bookID);
   getchar();

   FILE *fPtr;

   fPtr = fopen(DIRECTORY_BooksData, "a+");

   char temp[600];
   struct Books bk;

   printf("Enter New Book Name: ");
   gets(bk.bookName);
   printf("Enter New Publication Date: ");
   gets(bk.publicationDate);
   printf("Enter New Publisher Name: ");
   gets(bk.publisherName);

   printf("\n");
   if ((authorID = searchAuthorInfo(1)) == 0)
      authorID = addAuthorInfo();

   fprintf(fPtr, "%d,", bookID);
   fprintf(fPtr, "%s,", bk.bookName);
   fprintf(fPtr, "%s,", bk.publicationDate);
   fprintf(fPtr, "%s,", bk.publisherName);
   fprintf(fPtr, "%d\n", authorID);

   fclose(fPtr);

   printf("\nAdd Successfully\n");
}

void updateBookInfo() // Clear
{
   // ask user to enter book ID.
   int bookID, authorID;

   printf("Enter Book ID: ");
   scanf("%d", &bookID);
   getchar();

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_BooksData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   FILE *tempfPtr;
   tempfPtr = fopen(DIRECTORY_tempBooksData, "w");
   if (tempfPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   char temp[600];
   struct Books bk;

   if (fgets(temp, 600, fPtr) == NULL) {
      printf("No Book information exist.");
      return;
   }
   do {
      bk = storeDataInBookStruct(temp);
      if (bk.bookID == bookID)
      {
         printf("Enter New Book Name: ");
         gets(bk.bookName);
         printf("Enter New Publication Date: ");
         gets(bk.publicationDate);
         printf("Enter New Publisher Name: ");
         gets(bk.publisherName);

         printf("\n");
         if ((authorID = searchAuthorInfo(1)) == 0)
            authorID = addAuthorInfo();

         fprintf(tempfPtr, "%d,", bk.bookID);
         fprintf(tempfPtr, "%s,", bk.bookName);
         fprintf(tempfPtr, "%s,", bk.publicationDate);
         fprintf(tempfPtr, "%s,", bk.publisherName);
         fprintf(tempfPtr, "%d\n", authorID);
         continue;
      }
      fprintf(tempfPtr, "%d,", bk.bookID);
      fprintf(tempfPtr, "%s,", bk.bookName);
      fprintf(tempfPtr, "%s,", bk.publicationDate);
      fprintf(tempfPtr, "%s,", bk.publisherName);
      fprintf(tempfPtr, "%d\n", bk.authorID);
   } while (fgets(temp, 600, fPtr) != NULL);

   fclose(fPtr);
   fclose(tempfPtr);

   int flag = remove(DIRECTORY_BooksData);
   if (flag != 0)
      puts("Unable to remove BooksData.txt");
   int flagR = rename(DIRECTORY_tempBooksData, DIRECTORY_BooksData);
   if (flagR != 0)
      puts("Unable to remove tempBooksData.txt");

   printf("\nUpdate Successfully\n");
}

void deleteBookInfo() // Clear
{
   // ask user to enter book ID.
   int bookID;

   printf("Enter Book ID: ");
   scanf("%d", &bookID);
   getchar();

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_BooksData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   FILE *tempfPtr;
   tempfPtr = fopen(DIRECTORY_tempBooksData, "w");
   if (tempfPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   char temp[600];
   struct Books bk;

   while (fgets(temp, 600, fPtr) != NULL)
   {
      bk = storeDataInBookStruct(temp);
      if (bk.bookID == bookID)
         continue;
      fprintf(tempfPtr, "%d,", bk.bookID);
      fprintf(tempfPtr, "%s,", bk.bookName);
      fprintf(tempfPtr, "%s,", bk.publicationDate);
      fprintf(tempfPtr, "%s,", bk.publisherName);
      fprintf(tempfPtr, "%d\n", bk.authorID);
   }

   fclose(fPtr);
   fclose(tempfPtr);

   int flag = remove(DIRECTORY_BooksData);
   if (flag != 0)
      puts("Unable to remove BooksData.txt");
   int flagR = rename(DIRECTORY_tempBooksData, DIRECTORY_BooksData);
   if (flagR != 0)
      puts("Unable to remove tempBooksData.txt");

   printf("\nDelete Successfully\n");
}

void searchBookInfo() // Clear
{
   char srch[100];
   char temp[600];
   int flag = 0;
   struct Books bk;

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_BooksData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   printf("Enter Book name: ");
   gets(srch);

   while (fgets(temp, 600, fPtr) != NULL)
   {
      bk = storeDataInBookStruct(temp);
      if (strcmp(srch, bk.bookName) == 0)
      {
         flag++;
         printf("\nBook ID:               %.8d\n", bk.bookID);
         printf("Book Name:             %s\n", bk.bookName);
         printf("Publication Date:      %s\n", bk.publicationDate);
         printf("Publisher Name:        %s\n", bk.publisherName);
         displayAuthorInfo(bk.authorID);
      }
   }
   if (flag == 0)
      printf("\nNo Book information exist\n");

   fclose(fPtr);
}

void showBookInfo() // Clear
{
   struct Books bk;
   char temp[600];

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_BooksData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   if (fgets(temp, 600, fPtr) == NULL) {
      printf("No Book information exist\n");
      return;
   } else {
      printf("Display all Books\n");
   }
   do {
      bk = storeDataInBookStruct(temp);
      printf("\nBook ID:               %.8d\n", bk.bookID);
      printf("Book Name:             %s\n", bk.bookName);
      printf("Publication Date:      %s\n", bk.publicationDate);
      printf("Publisher Name:        %s\n", bk.publisherName);
      displayAuthorInfo(bk.authorID);
   } while (fgets(temp, 600, fPtr) != NULL);

   fclose(fPtr);
}

void updateAuthorInfo() { // Clear
   // ask user to enter book ID.
   int authorID;

   authorID = searchAuthorInfo(2);
   getchar();

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_AuthorsData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   FILE *tempfPtr;
   tempfPtr = fopen(DIRECTORY_tempAuthorsData, "w");
   if (tempfPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   char temp[600];
   struct Authors auth;

   if (fgets(temp, 600, fPtr) == NULL) {
      printf("No Author information exist.");
      return;
   }
   do {
      auth = storeDataInAuthorStruct(temp);
      if (auth.authorID == authorID)
      {
         printf("\nEnter New Author Name: ");
         gets(auth.authorName);
         printf("Enter New Author Address: ");
         gets(auth.authorAddress);
         printf("Enter New Author Phone Number: ");
         gets(auth.authorPhoneNumber);
         printf("Enter New Author Email Address: ");
         gets(auth.authorEmailAddress);
         printf("Enter New Author Short Bio: ");
         gets(auth.authorBio);

         fprintf(tempfPtr, "%d,", authorID);
         fprintf(tempfPtr, "%s,", auth.authorName);
         fprintf(tempfPtr, "%s,", auth.authorAddress);
         fprintf(tempfPtr, "%s,", auth.authorPhoneNumber);
         fprintf(tempfPtr, "%s,", auth.authorEmailAddress);
         fprintf(tempfPtr, "%s\n", auth.authorBio);
         continue;
      }
      fprintf(tempfPtr, "%d,", auth.authorID);
      fprintf(tempfPtr, "%s,", auth.authorName);
      fprintf(tempfPtr, "%s,", auth.authorAddress);
      fprintf(tempfPtr, "%s,", auth.authorPhoneNumber);
      fprintf(tempfPtr, "%s,", auth.authorEmailAddress);
      fprintf(tempfPtr, "%s\n", auth.authorBio);
   } while (fgets(temp, 600, fPtr) != NULL);

   fclose(fPtr);
   fclose(tempfPtr);

   int flag = remove(DIRECTORY_AuthorsData);
   if (flag != 0)
      puts("Unable to remove AuthorsData.txt");
   int flagR = rename(DIRECTORY_tempAuthorsData, DIRECTORY_AuthorsData);
   if (flagR != 0)
      puts("Unable to remove tempAuthorsData.txt");

   printf("\nUpdate Successfully\n");
}

void deleteAuthorInfo() // Clear
{
   // Delete author information
   int authorID, i;

   authorID = searchAuthorInfo(2);

   printf("\nEnter '1' to remove this information OR Enter '0' to undo: ");
   scanf("%d", &i);
   if (i == 0) {
      printf("\nBack to menu\n");
      return;
   }

   FILE *fPtr;
   fPtr = fopen(DIRECTORY_AuthorsData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   FILE *tempfPtr;
   tempfPtr = fopen(DIRECTORY_tempAuthorsData, "w");
   if (tempfPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   char temp[600];
   struct Authors auth;

   while (fgets(temp, 600, fPtr) != NULL)
   {
      auth = storeDataInAuthorStruct(temp);
      if (auth.authorID == authorID)
         continue;
      fprintf(tempfPtr, "%d,", auth.authorID);
      fprintf(tempfPtr, "%s,", auth.authorName);
      fprintf(tempfPtr, "%s,", auth.authorAddress);
      fprintf(tempfPtr, "%s,", auth.authorPhoneNumber);
      fprintf(tempfPtr, "%s,", auth.authorEmailAddress);
      fprintf(tempfPtr, "%s\n", auth.authorBio);
   }

   fclose(fPtr);
   fclose(tempfPtr);

   int flag = remove(DIRECTORY_AuthorsData);
   if (flag != 0)
      puts("Unable to remove AuthorsData.txt");
   int flagR = rename(DIRECTORY_tempAuthorsData, DIRECTORY_AuthorsData);
   if (flagR != 0)
      puts("Unable to remove tempAuthorsData.txt");

   // Delete author's books
   fPtr = fopen(DIRECTORY_BooksData, "r");
   if (fPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   tempfPtr = fopen(DIRECTORY_tempBooksData, "w");
   if (tempfPtr == 0)
   {
      printf("Error! opening file\n");
      return;
   }

   struct Books bk;

   while (fgets(temp, 600, fPtr) != NULL)
   {
      bk = storeDataInBookStruct(temp);
      if (bk.authorID == authorID)
         continue;
      fprintf(tempfPtr, "%d,", bk.bookID);
      fprintf(tempfPtr, "%s,", bk.bookName);
      fprintf(tempfPtr, "%s,", bk.publicationDate);
      fprintf(tempfPtr, "%s,", bk.publisherName);
      fprintf(tempfPtr, "%d\n", bk.authorID);
   }

   fclose(fPtr);
   fclose(tempfPtr);

   flag = remove(DIRECTORY_BooksData);
   if (flag != 0)
      puts("Unable to remove BooksData.txt");
   flagR = rename(DIRECTORY_tempBooksData, DIRECTORY_BooksData);
   if (flagR != 0)
      puts("Unable to remove tempBooksData.txt");

   printf("\nDelete Successfully\n");
}

int main(void)
{
   int menu, mode = 1;

   while (mode)
   {
      printf("\n=============================================\n\n");
      printf("1) Add book information\n");
      printf("2) Update book information\n");
      printf("3) Delete book information\n");
      printf("4) Search book information\n");
      printf("5) Display a list of all books\n");
      printf("6) Add author information\n");
      printf("7) Update author information\n");
      printf("8) Delete author information\n");
      printf("9) Search author information\n");
      printf("0) Quit\n");

      printf("\nSelect the menu: ");
      scanf("%d", &menu);
      getchar();

      printf("\n=============================================\n\n");

      switch (menu)
      {
      case 1:
         addBookInfo();

         break;

      case 2:
         updateBookInfo();

         break;

      case 3:
         deleteBookInfo();

         break;

      case 4:
         searchBookInfo();

         break;

      case 5:
         showBookInfo();

         break;

      case 6:
         addAuthorInfo();

         break;

      case 7:
         updateAuthorInfo();

         break;

      case 8:
         deleteAuthorInfo();

         break;

      case 9:
         searchAuthorInfo(0);

         break;

      case 0:
         mode = 0;

         break;

      default:
         printf("Invaild Input\n");

         break;
      }
   }

   return 0;
}