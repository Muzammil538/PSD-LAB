#include <stdio.h>
#include <stdlib.h>

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the Kth smallest element
int findKthSmallest(int arr[], int size, int k) {
    quickSort(arr, 0, size - 1);
    return arr[k - 1]; // Kth smallest element
}

int main() {
    int size, k;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    if (k > 0 && k <= size) {
        int kthSmallest = findKthSmallest(arr, size, k);
        printf("The %dth smallest element is %d.\n", k, kthSmallest);
    } else {
        printf("Invalid value of K.\n");
    }

    return 0;
}
