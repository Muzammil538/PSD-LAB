#include <stdio.h>

void printFibonacciSeries(int n) {
    int a = 0, b = 1, c;

    if (n >= 1) printf("%d ", a);
    if (n >= 2) printf("%d ", b);

    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

void printFibonacciInRange(int lower, int upper) {
    int a = 0, b = 1, c = a + b;

    if (lower <= a && a <= upper) printf("%d ", a);
    if (lower <= b && b <= upper) printf("%d ", b);

    while (c <= upper) {
        if (c >= lower) {
            printf("%d ", c);
        }
        a = b;
        b = c;
        c = a + b;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %d terms:\n", n);
    printFibonacciSeries(n);

    printf("Fibonacci numbers between 100 and 10000:\n");
    printFibonacciInRange(100, 10000);

    return 0;
}
