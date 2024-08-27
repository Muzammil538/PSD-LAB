#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* single_digits[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
char* two_digits[] = { "", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
char* tens_multiple[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
char* tens_power[] = { "Hundred", "Thousand", "Million", "Billion" };

void numToWords(int n, char* result) {
    if (n == 0) {
        strcat(result, "Zero");
        return;
    }

    if (n >= 1000) {
        int thousands = n / 1000;
        numToWords(thousands, result);
        strcat(result, " Thousand ");
        n %= 1000;
    }

    if (n >= 100) {
        int hundreds = n / 100;
        strcat(result, single_digits[hundreds]);
        strcat(result, " Hundred ");
        n %= 100;
    }

    if (n >= 20) {
        int tens = n / 10;
        strcat(result, tens_multiple[tens]);
        n %= 10;
        if (n > 0) {
            strcat(result, " ");
            strcat(result, single_digits[n]);
        }
    } else if (n >= 10) {
        strcat(result, two_digits[n - 10]);
    } else if (n > 0) {
        strcat(result, single_digits[n]);
    }
}

int wordsToNum(char* str) {
    char* token = strtok(str, " ");
    int result = 0, temp = 0;
    
    while (token != NULL) {
        if (strcmp(token, "Thousand") == 0) {
            result += temp * 1000;
            temp = 0;
        } else if (strcmp(token, "Hundred") == 0) {
            temp *= 100;
        } else {
            for (int i = 0; i < 10; i++) {
                if (strcmp(token, single_digits[i]) == 0) {
                    temp += i;
                }
            }
            for (int i = 1; i < 10; i++) {
                if (strcmp(token, two_digits[i]) == 0) {
                    temp += 10 + i;
                }
            }
            for (int i = 2; i < 10; i++) {
                if (strcmp(token, tens_multiple[i]) == 0) {
                    temp += i * 10;
                }
            }
        }
        token = strtok(NULL, " ");
    }
    return result + temp;
}

int main() {
    int number = 25678;
    char result[100] = "";
    
    printf("Number: %d\n", number);
    numToWords(number, result);
    printf("In Words: %s\n", result);

    char words[] = "One Thousand Twenty Four";
    int num = wordsToNum(words);
    printf("Words: %s\n", words);
    printf("In Number: %d\n", num);

    return 0;
}
