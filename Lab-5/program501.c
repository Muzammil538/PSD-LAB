#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the sum of the series
double sumOfSeries(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)factorial(i) / i;
    }
    return sum;
}

int main() {
    int n = 5; // As per the series: 1!/1 + 2!/2 + 3!/3 + 4!/4 + 5!/5

    double result = sumOfSeries(n);
    printf("The sum of the series is: %.2f\n", result);

    return 0;
}
