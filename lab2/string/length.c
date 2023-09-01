#include<stdio.h>

void main()
{
    char s[100];
    int i;
    printf("Enter a string\n");
    gets(s);
    while(s[i]!=0)
    {
        i++;
    }
    printf("Length of the string is: %d",i);
}
