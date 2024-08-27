#include <stdio.h>

// Function to calculate the sum of elements in the array
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of elements in the array
float averageArray(int arr[], int size) {
    return (float)sumArray(arr, size) / size;
}

// Function to find the maximum element in the array
int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Sum of the array elements: %d\n", sumArray(arr, size));
    printf("Average of the array elements: %.2f\n", averageArray(arr, size));
    printf("Maximum element in the array: %d\n", maxElement(arr, size));

    return 0;
}
