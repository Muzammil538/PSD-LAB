#include <stdio.h>

// Function to find the Greatest Common Divisor using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Greatest Common Divisor of %d and %d is %d\n", a, b, gcd(a, b));

    return 0;
}
