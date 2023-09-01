#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define max_size 100

char* stack;

int top=-1;
char str1[100];
char str2[100];

void push(char item)
{
      /*if(top==max_size-1)
    {
        printf("Stack Overflow\n");
        return;
    }*/
    top=top+1;
    stack[top]=item;

}

char pop()
{
   /* if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }*/
       return stack[top--];
    }

int isPalindrome(char str[])
{
    int length=strlen(str);
    //allocating memory for stack
    stack=(char*)malloc(length*sizeof(char));
    int i,mid=length/2;
    for(i=0;i<mid;i++)
    {
        push(str[i]);
    }
    if(length%2!=0)
    {
        i++;
    }
    //pop elements till end of string
    while(str[i]!='\0')
    {
        char ele=pop();
        if(ele!=str[i])
            return 0;
        i++;
    }
    return 1;
}

int main()
{

    printf("Enter a string\n");
    gets(str1);
    if(isPalindrome(str1))
    {
        printf("is a palindrome");
    }
    else{
        printf("not a palindrome");
    }
    return 0;
}
