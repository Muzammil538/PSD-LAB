#include <stdio.h>

void printStack(int n, int level) {
    printf("Stack Level %d: Factorial(%d)\n", level, n);
}

int factorial(int n, int level) {
    printStack(n, level);
    if (n == 0) return 1;
    return n * factorial(n - 1, level + 1);
}

int main() {
    int n = 5;
    printf("Factorial of %d is %d\n", n, factorial(n, 1));
    return 0;
}
