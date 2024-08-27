#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to find the longest common prefix
char* longestCommonPrefix(char* strs[], int strsSize) {
    if (strsSize == 0) return "";

    char* prefix = strs[0];
    int prefixLen = strlen(prefix);

    for (int i = 1; i < strsSize; i++) {
        while (strncmp(prefix, strs[i], prefixLen) != 0) {
            prefixLen--;
            if (prefixLen == 0) return "";
            prefix[prefixLen] = '\0';
        }
    }
    return prefix;
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char strs[MAX_STRINGS][MAX_LENGTH];
    char* pointers[MAX_STRINGS];

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);
        pointers[i] = strs[i];
    }

    char* prefix = longestCommonPrefix(pointers, n);
    printf("Longest common prefix: %s\n", prefix);

    return 0;
}
