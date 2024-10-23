#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure for storing characters
struct Stack {
    char data[MAX];
    int top;
};

// Initialize an empty stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push a character onto the stack
void push(struct Stack* stack, char value) {
    if (stack->top < MAX - 1) {
        stack->data[++stack->top] = value;
    }
}

// Pop a character from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return 0;
}

// Peek the top element of the stack
char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return 0;
}

// Utility function to check if a character is an opening bracket
int isOpeningBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// Utility function to check if a character is a matching closing bracket
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if parentheses are balanced
int isBalanced(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        
        // If it's an opening bracket, push it onto the stack
        if (isOpeningBracket(ch)) {
            push(&stack, ch);
        }
        
        // If it's a closing bracket, check for a matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), ch)) {
                return 0;  // Unbalanced
            }
        }
    }
    
    // If the stack is empty, all brackets were balanced
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

    printf("Enter the expression with parentheses: ");
    fgets(expression, MAX, stdin);

    if (isBalanced(expression)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
    }

    return 0;
}
