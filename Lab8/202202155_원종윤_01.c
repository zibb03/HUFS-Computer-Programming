#include <stdio.h>

int i, j, choice, num1, num2, flag, factorial, term1 = 0, term2 = 1, nextTerm;

void even(int num1) {
    i = 1;
    
    while (i <= num1) {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
}

void odd(int num1) {
    i = 1;

    while (i <= num1) {
        if (i % 2 == 1)
        {
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
}

void prime(int num1) {
    flag = 1;

    for (i = 2; i < num1; i++) {
        if (num1 % i == 0) {
            flag = 0;
            break;
        }
    }
    if (num1 <= 1)
        flag = 0;

    if (flag == 1) {
        printf("%d is a prime number\n", num1);
    }
    else {
        printf("%d is not a prime number\n", num1);
    }
}

void prime_range(int num1, int num2) {
    printf("Prime numbers between %d and %d are ", num1, num2);

    for (i = num1; i <= num2; i++) {
        if (i == 1 || i == 0)
            continue;

        flag = 1;
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%d ", i);
    }
    printf("\n");
}

void factorial_num(int num1) {
    factorial = 1;

    for (i = 1; i <= num1; i++) {
        factorial = factorial * i;
    }
    printf("Factorial of %d is %d\n", num1, factorial);
}

void factorial_range(int num1, int num2) {
    while (num1 <= num2) {
        factorial = 1;
        for (i = 1; i <= num1; i++) {
            factorial = factorial * i;
        }
        printf("Factorial of %d is %d\n", num1, factorial);
        num1++;
    }
}

void fibonacci(int num1) {
    term1 = 0, term2 = 1;
    nextTerm = term1 + term2;

    printf("Fibonacci Series: %d %d\n", term1, term2);
    for (i = 3; i <= num1; ++i) {
        printf("%d ", nextTerm);
        term1 = term2;
        term2 = nextTerm;
        nextTerm = term1 + term2;
    }
    printf("\n");
}


int main(void) {
    do {
        printf("\n1: Display a list of even numbers.\n2: Display a list of odd numbers.\n3: For a given number n check if n  is a prime number.\n4: Display a list of prime numbers between numbers n and m.\n5: Display a factorial of a given number n.\n6: Find factorial of all numbers between numbers n and m.\n7: Generate the Fibonacci sequence up to a number n.\n8: EXIT");
        printf("\nEnter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the range: ");
            scanf_s("%d", &num1);
            even(num1);
            break;

        case 2:
            printf("Enter the range: ");
            scanf_s("%d", &num1);
            odd(num1);
            break;

        case 3:
            printf("Enter the number: ");
            scanf_s("%d", &num1);
            prime(num1);
            break;

        case 4:
            printf("Enter the range(start, end): ");
            scanf_s("%d, %d", &num1, &num2);
            prime_range(num1, num2);
            break;

        case 5:
            printf("Enter the number: ");
            scanf_s("%d", &num1);
            factorial_num(num1);
            break;

        case 6:
            printf("Enter the range(start, end): ");
            scanf_s("%d, %d", &num1, &num2);
            factorial_range(num1, num2);
            break;

        case 7:
            printf("Enter the number: ");
            scanf_s("%d", &num1);
            fibonacci(num1);
            break;

        case 8:
            return;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 8);
    
    return 0;
}
