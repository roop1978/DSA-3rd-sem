#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack structure
struct Stack {
    char items[MAX_STACK_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to push an element onto the stack
void push(struct Stack *s, char item) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to return the precedence of an operator
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int infixLength = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = infixLength - 1; i >= 0; i--) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) && precedence(operatorStack.items[operatorStack.top]) >= precedence(ch)) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        } else if (ch == ')') {
            push(&operatorStack, ch);
        } else if (ch == '(') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != ')') {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] == ')') {
                pop(&operatorStack); // Pop the '('
            }
        } else {
            // Operand
            prefix[prefixIndex++] = ch;
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the final result
    int prefixLength = strlen(prefix);
    for (int i = 0; i < prefixLength / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[prefixLength - i - 1];
        prefix[prefixLength - i - 1] = temp;
    }
}

int main() {
    char infix[MAX_STACK_SIZE];
    char prefix[MAX_STACK_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Equivalent prefix expression: %s\n", prefix);

    return 0;
}
