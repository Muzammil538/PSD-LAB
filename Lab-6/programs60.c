#include <stdio.h>

int main() {
    // 1. Inverted Hollow Pyramid Star Pattern
    printf("1. Inverted Hollow Pyramid Star Pattern\n");
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // 2. Basic Right Triangle Number Pattern (Inverted)
    printf("2. Basic Right Triangle Number Pattern (Inverted)\n");
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // 3. Diamond Star Pattern
    printf("3. Diamond Star Pattern\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 3; i >= 1; i--) {
        for (int j = 1; j <= 4 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // 4. Basic incrementing Diamond Pattern (Inverted), initialized=3
    printf("4. Basic incrementing Diamond Pattern (Inverted)\n");
    int num = 3;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", num);
        }
        printf("\n");
        num += i;
    }
    for (int i = 3; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", num);
        }
        printf("\n");
        num -= i;
    }

    // 5. Basic incrementing Squared Number-Star Pattern
    printf("5. Basic incrementing Squared Number-Star Pattern\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            printf("%d*", i * j);
        }
        printf("\n");
    }

    return 0;
}