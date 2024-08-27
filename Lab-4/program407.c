#include <stdio.h>
#include <string.h>

void insertSubstring(char *str, const char *substr, int position) {
    int strLength = strlen(str);
    int substrLength = strlen(substr);

    // Shift the original string to make space for the substring
    for (int i = strLength; i >= position; i--) {
        str[i + substrLength] = str[i];
    }

    // Insert the substring
    for (int i = 0; i < substrLength; i++) {
        str[position + i] = substr[i];
    }
}

int main() {
    char str[100], substr[50];
    int position;

    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter the substring to insert: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter the position to insert the substring: ");
    scanf("%d", &position);

    if (position < 0 || position > strlen(str)) {
        printf("Invalid position.\n");
        return 1;
    }

    insertSubstring(str, substr, position);

    printf("String after insertion: %s\n", str);

    return 0;
}
