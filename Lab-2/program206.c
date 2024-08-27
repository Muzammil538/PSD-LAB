#include <stdio.h>

// Function to check if a number is a SPY number
int isSpyNumber(int num) {
    int sum = 0, product = 1;

    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }

    return sum == product;
}

int main() {
    int num;
    printf("Enter a number to check if it is a SPY number: ");
    scanf("%d", &num);

    if (isSpyNumber(num)) {
        printf("%d is a SPY number.\n", num);
    } else {
        printf("%d is not a SPY number.\n", num);
    }

    return 0;
}
