#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, char x) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++s->top] = x;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return 1;
    }
    return 0;
}

char* preToInfix(char* pre_exp) {
    Stack s;
    init(&s);

    int length = strlen(pre_exp);
    char* infix = (char*)malloc((length + 1) * sizeof(char));
    int infixIndex = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            char op1 = pop(&s);
            char op2 = pop(&s);

            infix[infixIndex++] = '(';
            infix[infixIndex++] = op1;
            infix[infixIndex++] = pre_exp[i];
            infix[infixIndex++] = op2;
            infix[infixIndex++] = ')';
            infix[infixIndex] = '\0';

            push(&s, infix[infixIndex - 1]);
        } else {
            push(&s, pre_exp[i]);
        }
    }

    return infix;
}

int main() {
    char pre_exp[] = "*-A/BC-/AKL";
    char* infix = preToInfix(pre_exp);
    printf("Infix : %s\n", infix);
    free(infix);
    return 0;
}
