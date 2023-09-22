#include <stdio.h>
#include <stdlib.h>

#define MAX 100


  char stack[MAX];
  int top;


void push(char item) {
  if (top == (MAX - 1))
    printf("Stack is Full\n");

  else {
    top = top + 1;
    stack[top] = item;
  }
}

void pop() {
  if (top == -1)
    printf("Stack is Empty\n");

  else
    top = top - 1;
}

int checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

int checkBalanced(char expr[], int len){

    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
          push(expr[i]);
        }
        else
        {
            // exp = {{}}}
            // if you look closely above {{}} will be matched with pair, Thus, stack "Empty"
            //but an extra closing parenthesis like '}' will never be matched
            //so there is no point looking forward
        if (top == -1)
            return 0;
        else if(checkPair(stack[top],expr[i]))
        {
            pop();
            continue;
        }
        // will only come here if stack is not empty
        // pair wasn't found and it's some closing parenthesis
        //Example : {{}}(]
        return 0;
        }
    }
    return 1;
}
int main() {
  char exp[MAX];
  printf("enter an expression:\n");
  gets(exp);
  printf("\n%s",exp);
  int i = 0;
  top = -1;

  int len = strlen(exp);
  checkBalanced(exp, len)?printf("\nBalanced"): printf("\nNot Balanced");

  return 0;
}
