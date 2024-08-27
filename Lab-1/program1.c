#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num, reversed, sum, lastDigit, firstDigit;
    printf("Enter an integer: ");
    scanf("%d", &num);

    reversed = reverseNumber(num);
    printf("Reversed Number: %d\n", reversed);

    // Check if the reversed number is even or odd
    if (reversed % 2 == 0) {
        printf("The reversed number is Even\n");
    } else {
        printf("The reversed number is Odd\n");
    }

    // Find the sum of the digits of the reversed number
    sum = sumOfDigits(reversed);
    printf("Sum of digits of the reversed number: %d\n", sum);

    // Find the difference between the last and first digit of the reversed number
    lastDigit = reversed % 10;
    firstDigit = reversed;
    while (firstDigit >= 10) {
        firstDigit /= 10;
    }
    printf("Difference between the last digit and first digit: %d\n", lastDigit - firstDigit);

    return 0;
}
