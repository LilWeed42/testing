#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to calculate taxi fee based on distance
int calculateTaxiFee(int distance) {
    if (distance <= 1) {
        return 15000; // 15 thousand VND for the first km
    } else {
        return 15000 + 12000 * (distance - 1); // 15 thousand VND for the first km, 12 thousand VND per km thereafter
    }
}

// Function to calculate the sum of all digits in an integer where sign is exclusive
int sumOfDigitsExclusive(int num) {
    int sum = 0;
    num = abs(num); // Make number positive

    while (num != 0) {
        sum += num % 10; // Add the last digit to sum
        num /= 10;       // Remove the last digit
    }

    return sum;
}

// Function to count the number of integer strings in a given string
int countIntegerStrings(const char *str) {
    int count = 0;
    int inNumber = 0;

    while (*str) {
        if (isdigit(*str)) {
            if (!inNumber) {
                count++;
                inNumber = 1;
            }
        } else {
            inNumber = 0;
        }
        str++;
    }

    return count;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;  // Numbers less than or equal to 1 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;  // Not a prime if divisible by any number other than 1 and itself
    }
    return 1;  // Prime number
}

// Function to create an array of primes less than n
void primesLessThanN(int n) {
    printf("Primes less than %d are: ", n);

    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int choice, num;
    char str[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Calculate taxi fee for a given distance\n");
        printf("2. Calculate sum of digits in an integer where sign is exclusive\n");
        printf("3. Count integer strings in a string\n");
        printf("4. List primes less than n\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter distance in km: ");
                scanf("%d", &num);
                printf("Taxi fee: %d VND\n", calculateTaxiFee(num));
                break;
            case 2:
                printf("Enter an integer: ");
                scanf("%d", &num);
                printf("Sum of digits: %d\n", sumOfDigitsExclusive(num));
                break;
            case 3:
                printf("Enter a string: ");
                getchar(); // Consume newline left in input buffer
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; // Remove newline character if present
                printf("Integer strings count: %d\n", countIntegerStrings(str));
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &num);
                primesLessThanN(num);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
