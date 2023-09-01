#include<stdio.h>

void main()
{
    char s[100],t[100];
    int i,j=0;
    printf("Enter the string\n");
    gets(s);
    printf("Enter the string to be added\n");
    gets(t);
    while(s[i]!='\0')
    i++;
    while(t[j]!='\0')
    {
        s[i]=t[j];
        j++;
        i++;
    }
    printf("Concatenated string\n");
    puts(s);
}
