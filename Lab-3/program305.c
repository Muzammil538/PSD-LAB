#include <stdio.h>

int main() {
    int size;
    float sum = 0.0, average;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    float arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    average = sum / size;
    printf("The average of the elements is: %.2f\n", average);

    return 0;
}
