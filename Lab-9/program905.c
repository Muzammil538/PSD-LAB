#include <stdio.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int action) {
    if (top < MAX - 1) stack[++top] = action;
}

void undo() {
    if (top != -1) printf("Undo action: %d\n", stack[top--]);
}

int main() {
    push(1); push(2); push(3);
    undo(); undo();
    return 0;
}
