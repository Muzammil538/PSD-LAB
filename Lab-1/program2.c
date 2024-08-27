#include <stdio.h>
#include <string.h>

// Function to convert an integer to a Roman numeral
void intToRoman(int num, char* result) {
    struct roman {
        int value;
        char symbol[3];
    } romanNumerals[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    result[0] = '\0';
    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= romanNumerals[i].value) {
            strcat(result, romanNumerals[i].symbol);
            num -= romanNumerals[i].value;
        }
    }
}

// Function to convert a Roman numeral to an integer
int romanToInt(char* roman) {
    struct roman {
        int value;
        char symbol[3];
    } romanNumerals[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    int num = 0;
    for (int i = 0; i < 13; i++) {
        while (strstr(roman, romanNumerals[i].symbol) == roman) {
            num += romanNumerals[i].value;
            roman += strlen(romanNumerals[i].symbol);
        }
    }
    return num;
}

int main() {
    int number = 2168;
    char roman[20];

    intToRoman(number, roman);
    printf("Integer: %d, Roman: %s\n", number, roman);

    char romanInput[] = "DLXXXVI";
    int integer = romanToInt(romanInput);
    printf("Roman: %s, Integer: %d\n", romanInput, integer);

    return 0;
}
