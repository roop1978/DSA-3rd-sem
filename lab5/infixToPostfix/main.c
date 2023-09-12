// C code to convert infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

// Function to return precedence of operators
int precedence(char operator)
{
	switch (operator) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

// Function to check if the scanned character
// is an operator
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
			|| ch == '^');
}

// Main function to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
	int i, j;
	int len = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char) * (len + 2));
	char stack[size];
	int top = -1;

	for (i = 0, j = 0; i < len; i++) {
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;

		// If the scanned character is operand
		// add it to the postfix expression
		if (isalnum(infix[i])) {
			postfix[j++] = infix[i];
		}

		// if the scanned character is '('
		// push it in the stack
		else if (infix[i] == '(') {
			stack[++top] = infix[i];
		}

		// if the scanned character is ')'
		// pop the stack and add it to the
		// output string until empty or '(' found
		else if (infix[i] == ')') {
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(')
				return "Invalid Expression";
			else
				top--;
		}

		// If the scanned character is an operator
		// push it in the stack
		else if (isOperator(infix[i])) {
			while (top > -1
				&& precedence(stack[top])
						>= precedence(infix[i]))
				postfix[j++] = stack[top--];
			stack[++top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while (top > -1) {
		if (stack[top] == '(') {
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}


//main function
int main() {
    char infix[size];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove the newline character from the input
    size_t len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);

    return 0;
}



