#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a portion of a string
void reverseWords(char *str) {
    int length = strlen(str);
    char temp[length + 1];
    int start = 0, end = 0, i = 0;

    // Reverse the whole string
    while (i < length) {
        // Find the end of the current word
        if (str[i] == ' ' || i == length - 1) {
            end = (i == length - 1) ? i : i - 1;
            while (end >= start) {
                temp[start + end - i] = str[end];
                end--;
            }
            temp[start + (i - start)] = ' ';
            start = i + 1;
        }
        i++;
    }
    temp[length] = '\0'; // Null-terminate the reversed string

    // Copy reversed words back to original string
    strcpy(str, temp);
}

int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove trailing newline character if present
    sentence[strcspn(sentence, "\n")] = '\0';

    reverseWords(sentence);

    printf("Reversed sentence: %s\n", sentence);

    return 0;
}
