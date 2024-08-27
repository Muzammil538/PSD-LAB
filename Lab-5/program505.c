#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char *str;
    int length;

    printf("Enter the length of the string: ");
    scanf("%d", &length);
    getchar(); // Consume newline character left by scanf

    // Allocate memory for the string
    str = (char *)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the string: ");
    fgets(str, length + 1, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character

    reverseString(str);

    printf("Reversed string: %s\n", str);

    // Free allocated memory
    free(str);

    return 0;
}
