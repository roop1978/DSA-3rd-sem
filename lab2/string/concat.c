#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[50],b[50];
    int i,j,m;
    printf("enter a string:");
    gets(a);
    printf("enter another string:");
    gets(b);
    for(i=0;a[i]!='\0';i++)
    {
        m++;
    }
    for(j=0;b[j]!='\0';j++)
    {
        a[m+j]=b[j];
    }
    a[m+j+1]='\0';
    puts(a);
}

