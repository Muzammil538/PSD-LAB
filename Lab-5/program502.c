#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binary[32]; // Assuming a 32-bit integer
    int index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num /= 2;
    }

    // Print binary in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Binary representation: ");
    decimalToBinary(num);
    printf("\n");

    return 0;
}
