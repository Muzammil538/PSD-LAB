#include <stdio.h>

void mergeDescending(int arr1[], int arr2[], int n, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (arr1[i] > arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n) {
        result[k++] = arr1[i++];
    }
    while (j < n) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    int arr1[n], arr2[n], result[2*n];

    printf("Enter elements of the first array (sorted in descending order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of the second array (sorted in descending order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    mergeDescending(arr1, arr2, n, result);

    printf("Merged array in descending order:\n");
    for (int i = 0; i < 2*n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
