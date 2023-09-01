#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[50];
    int i,len=0;
    printf("enter a string:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        len++;
    }
    printf("length of the string is:%d",len);
    return 0;
}
