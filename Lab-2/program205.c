#include <stdio.h>
#include <math.h>

// Function to check if a number is automorphic
int isAutomorphic(int num) {
    int square = num * num;
    int temp = num;

    while (temp > 0) {
        if (square % 10 != temp % 10) {
            return 0;
        }
        square /= 10;
        temp /= 10;
    }
    return 1;
}

void findAutomorphicNumbers(int lower, int upper) {
    printf("Automorphic numbers between %d and %d:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isAutomorphic(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    findAutomorphicNumbers(1, 1000);
    return 0;
}
