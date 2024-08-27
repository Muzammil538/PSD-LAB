#include <stdio.h>
#include <string.h>

void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
    } else {
        for (int i = left; i <= right; i++) {
            // Swap characters
            char temp = str[left];
            str[left] = str[i];
            str[i] = temp;

            // Recur for the rest of the string
            permute(str, left + 1, right);

            // Backtrack
            temp = str[left];
            str[left] = str[i];
            str[i] = temp;
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);
    printf("Permutations are:\n");
    permute(str, 0, length - 1);

    return 0;
}
