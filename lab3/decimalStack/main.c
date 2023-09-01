/*Write a C program to convert a given decimal number to a number in any base using
stack*/



#include <stdio.h>
#include <stdlib.h>
#define max_size 100
int stack[max_size];
int top=-1;
int item,rem;

int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is :");
        DecToBin(num);
        printf("Octal Equivalent is :");
        DecToOct(num);

       /* printf("Octal Equivalent is : %d",DecToOct(num));*/

        return 0;

}
void DecToBin(int num)
{

        while(num!=0)
        {
                rem = num%2;
                push(rem);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop());
        printf("\n");
}

void DecToOct(int num)
{

        while(num!=0)
        {
                rem = num%8;
                push(rem);
                num/=8;
        }
        while(top!=-1)
                printf("%d", pop());
        printf("\n");
}



void push(int item)
{
        if(top == max_size -1){
                printf("Stack Overflow\n");
        }
        else
        {
                top=top+1;
                stack[top] = item;
        }
}

int pop()
{

        if(top == -1)
        {
                printf("Stack Underflow\n");
               return -1;
        }

               int item = stack[top];
               top=top-1;

        return item;
}
