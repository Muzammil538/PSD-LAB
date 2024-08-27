#include <stdio.h>

void printCommonElements(int arr1[], int size1, int arr2[], int size2) {
    int foundCommon = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                foundCommon = 1;
                break; // To avoid printing the same element multiple times
            }
        }
    }
    if (!foundCommon) {
        printf("No Common Elements\n");
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Common integers in the two arrays are:\n");
    printCommonElements(arr1, size1, arr2, size2);

    return 0;
}
