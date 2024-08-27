#include <stdio.h>

int isPalindrome(int num) {
    int reversed = 0, original = num, remainder;
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return original == reversed;
}

void printPalindromes(int lower, int upper) {
    for (int i = lower; i <= upper; i++) {
        if (isPalindrome(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int lower, upper;
    printf("Enter the lower limit: ");
    scanf("%d", &lower);
    printf("Enter the upper limit: ");
    scanf("%d", &upper);

    printf("Palindrome numbers between %d and %d are:\n", lower, upper);
    printPalindromes(lower, upper);

    return 0;
}
