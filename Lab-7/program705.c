#include <stdio.h>

// Function to search in a 2D matrix
int searchMatrix(int matrix[][100], int rows, int cols, int key) {
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == key) {
            return 1; // Key found
        }
        if (matrix[row][col] > key) {
            col--;
        } else {
            row++;
        }
    }
    return 0; // Key not found
}

int main() {
    int rows, cols, key;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    if (searchMatrix(matrix, rows, cols, key)) {
        printf("Key %d found in the matrix.\n", key);
    } else {
        printf("Key %d not found in the matrix.\n", key);
    }

    return 0;
}
