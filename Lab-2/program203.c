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

void printPalindromesInRange(int lower, int upper) {
    for (int i = lower; i <= upper; i++) {
        if (isPalindrome(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    printf("Palindrome numbers between 100 and 100000:\n");
    printPalindromesInRange(100, 100000);

    return 0;
}
