#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

struct CharStack {
    char data[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void initCharStack(struct CharStack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

void charPush(struct CharStack* stack, char value) {
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

char charPop(struct CharStack* stack) {
    return stack->data[stack->top--];
}

char charPeek(struct CharStack* stack) {
    return stack->data[stack->top];
}

int precedence(char op) {
    return op == '+' || op == '-' ? 1 : op == '*' || op == '/' ? 2 : 0;
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluateExpression(char* expression) {
    struct Stack values;
    struct CharStack operators;
    
    initStack(&values);
    initCharStack(&operators);
    
    for (int i = 0; expression[i]; i++) {
        if (isspace(expression[i])) continue;
        
        if (isdigit(expression[i])) {
            int value = 0;
            while (isdigit(expression[i])) {
                value = value * 10 + (expression[i++] - '0');
            }
            i--;
            push(&values, value);
            continue;
        }
        
        if (expression[i] == '(') charPush(&operators, '(');
        else if (expression[i] == ')') {
            while (charPeek(&operators) != '(') {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = charPop(&operators);
                push(&values, applyOperator(val1, val2, op));
            }
            charPop(&operators);
        }
        else if (precedence(expression[i])) {
            while (precedence(charPeek(&operators)) >= precedence(expression[i])) {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = charPop(&operators);
                push(&values, applyOperator(val1, val2, op));
            }
            charPush(&operators, expression[i]);
        }
    }
    
    while (charPeek(&operators)) {
        int val2 = pop(&values);
        int val1 = pop(&values);
        char op = charPop(&operators);
        push(&values, applyOperator(val1, val2, op));
    }
    
    return pop(&values);
}

int main() {
    char expression[MAX];
    printf("Enter the mathematical expression: ");
    fgets(expression, MAX, stdin);
    printf("Result of the expression: %d\n", evaluateExpression(expression));
    return 0;
}