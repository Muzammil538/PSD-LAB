#include <stdio.h>

void findLargestSmallest(int arr[], int size, int* largest, int* smallest) {
    *largest = arr[0];
    *smallest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *largest) {
            *largest = arr[i];
        }
        if (arr[i] < *smallest) {
            *smallest = arr[i];
        }
    }
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

    int largest, smallest;
    findLargestSmallest(arr, size, &largest, &smallest);

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of largest and smallest: %d\n", largest + smallest);
    printf("Difference between largest and smallest: %d\n", largest - smallest);

    return 0;
}
