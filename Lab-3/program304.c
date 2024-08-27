#include <stdio.h>

void separateOddEven(int arr[], int size, int odd[], int* oddSize, int even[], int* evenSize) {
    *oddSize = 0;
    *evenSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[(*evenSize)++] = arr[i];
        } else {
            odd[(*oddSize)++] = arr[i];
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

    int odd[size], even[size];
    int oddSize, evenSize;
    
    separateOddEven(arr, size, odd, &oddSize, even, &evenSize);

    printf("Odd numbers:\n");
    for (int i = 0; i < oddSize; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    printf("Even numbers:\n");
    for (int i = 0; i < evenSize; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    return 0;
}
