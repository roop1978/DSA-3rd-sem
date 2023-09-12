#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int is_operand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char *postfix_to_infix(char *postfix) {
    Stack s;
    s.top = -1;
    int len = strlen(postfix);
    char *infix = (char *) malloc((len + 1) * sizeof(char));
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (is_operand(postfix[i])) {
            push(&s, postfix[i]);
        } else {
            char op1 = pop(&s);
            char op2 = pop(&s);
            infix[j++] = '(';
            infix[j++] = op2;
            infix[j++] = postfix[i];
            infix[j++] = op1;
            infix[j++] = ')';
            push(&s, infix[j - 1]);
        }
    }
    infix[j] = '\0';
    return infix;
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    char *infix = postfix_to_infix(postfix);
    printf("Fully parenthesized infix expression: %s\n", infix);
    free(infix);
    return 0;
}
