#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to check if a number is a strong number
int isStrongNumber(int num) {
    int sum = 0, originalNum = num;
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    return sum == originalNum;
}

void findStrongNumbers(int lower, int upper) {
    printf("Strong numbers between %d and %d:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isStrongNumber(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a number to check if it is a strong number: ");
    scanf("%d", &num);

    if (isStrongNumber(num)) {
        printf("%d is a strong number.\n", num);
    } else {
        printf("%d is not a strong number.\n", num);
    }

    findStrongNumbers(1, 100000);

    return 0;
}
