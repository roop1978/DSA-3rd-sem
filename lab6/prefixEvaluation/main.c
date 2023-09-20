#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isOperand(char c)
{
    return isdigit(c);
}

double evaluatePrefix(char* exprsn)
{
    double* Stack = (double*)malloc(sizeof(double) * strlen(exprsn));
    int top = -1;

    for (int j = strlen(exprsn) - 1; j >= 0; j--) {
        if (isOperand(exprsn[j]))
            Stack[++top] = exprsn[j] - '0';
        else {
            double o1 = Stack[top--];
            double o2 = Stack[top--];

            switch (exprsn[j]) {
                case '+':
                    Stack[++top] = o1 + o2;
                    break;
                case '-':
                    Stack[++top] = o1 - o2;
                    break;
                case '*':
                    Stack[++top] = o1 * o2;
                    break;
                case '/':
                    Stack[++top] = o1 / o2;
                    break;
            }
        }
    }

    double result = Stack[top];
    free(Stack);
    return result;
}

int main()
{
    char exprsn[] = "+9*26";
    printf("%f\n", evaluatePrefix(exprsn));
    return 0;
}
