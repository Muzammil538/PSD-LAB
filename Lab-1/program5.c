#include <stdio.h>

int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int sum = sumOfDivisors(num);
    printf("Sum of the divisors of %d is: %d\n", num, sum);

    return 0;
}
