#include <stdio.h>
#include <stdlib.h>

// Bubble sort function
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function pointer type
typedef void (*SortFunc)(int[], int, int);

// Wrapper function for quick sort
void quickSortWrapper(int arr[], int size) {
    quickSort(arr, 0, size - 1);
}

// Function to sort an array using function pointers
void sortArray(int arr[], int size, SortFunc sortFunc) {
    sortFunc(arr, size, size - 1);
}

int main() {
    int size;
    int choice;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    SortFunc sortFunc;
    if (choice == 1) {
        sortFunc = (SortFunc)bubbleSort;
    } else if (choice == 2) {
        sortFunc = (SortFunc)quickSortWrapper;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    sortArray(arr, size, sortFunc);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
