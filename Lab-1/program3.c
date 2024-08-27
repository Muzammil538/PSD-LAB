#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void permute(int* arr, int start, int end) {
    if (start == end) {
        printArray(arr, end + 1);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]);  // backtrack
        }
    }
}

int main() {
    int arr[] = {4, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("All possible permutations are:\n");
    permute(arr, 0, n - 1);

    return 0;
}
