#include <stdio.h>
#include <stdbool.h>

int main(void) {

    int ID[100];
    int choice1, choice2, len = 0;
    
    bool found = false;


    while (1) {
        printf("1) Add a Student ID\n2) Delete Student ID\n3) Insert Student ID at a given position or index\n4) Search Student ID\n5) Update Student ID\n6) Display Student IDs\n");
        printf("\nEnter your choice: ");
        scanf_s("%d", &choice1);

        switch (choice1) {
        case 1:
            printf("\nEnter a Student ID to add: ");
            scanf_s("%d", &choice1);
            ID[len] = choice1;
            len++;

            printf("\n\n");
            break;

        case 2:
            printf("\nEnter a Student ID to delete: ");
            scanf_s("%d", &choice1);
            for (int i = 0; i < len; i++) {
                if (choice1 == ID[i]) {
                    for (int j = i; j < len; j++) {
                        ID[j] = ID[j + 1];
                        found = true;
                        len--;
                    }

                    break;
                }
            }
            if (found == true) {
                printf("\n%d is deleted.", choice1);
                found = false;
            }
            else
                printf("\n%d is not in the array.", choice1);

            printf("\n\n");
            break;

        case 3:
            printf("\nEnter a Student ID and Position to insert (Student ID, Position): ");
            scanf_s("%d, %d", &choice1, &choice2);
            if (choice2 < 0 || choice2 > len) {
                printf("Invalid position\n");
                
                printf("\n\n");
                break;
            }
            for (int i = len + 1; i > choice2; i--)
                ID[i] = ID[i - 1];
            ID[choice2] = choice1;
            len++;

            printf("\n\n");
            break;

        case 4:
            printf("\nEnter a Student ID to search: ");
            scanf_s("%d", &choice1);
            for (int i = 0; i < len; i++) {
                if (choice1 == ID[i]) {
                    found = true;
                }
            }
            if (found == true) {
                printf("\n%d is in the array.", choice1);
                found = false;
            }
            else
                printf("\n%d is not in the array.", choice1);

            printf("\n\n");
            break;

        case 5:
            printf("\nEnter a Student ID to update(Student ID 1, Student ID 2): ");
            scanf_s("%d,%d", &choice1, &choice2);
            for (int i = 0; i < len; i++) {
                if (choice1 == ID[i]) {
                    ID[i] = choice2;
                    found = true;
                    break;
                }
            }
            if (found == true) {
                printf("\n%d is updated to %d.", choice1, choice2);
                found = false;
            }
            else
                printf("\n%d is not in the array.", choice1);

            printf("\n\n");
            break;

        case 6:    
    printf("\nCurrent elements in array are: ");
            for (int i = 0; i < len; i++) {
                printf("%d ", ID[i]);
            }

            printf("\n\n\n");
            break;

        default:
            printf("Invalid choice\n");
            return 0;
        }
    }
}
