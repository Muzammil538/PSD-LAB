#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for storing operators
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

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // If the character is an operand, add it to the output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If it's an opening parenthesis, push it to the stack
        else if (ch == '(') {
            push(&stack, ch);
        }
        // If it's a closing parenthesis, pop and output until '(' is encountered
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop '(' from stack
        }
        // If it's an operator, pop operators with higher or equal precedence and push current operator
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    
    postfix[k] = '\0';  // Null terminate the result
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);
    
    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
