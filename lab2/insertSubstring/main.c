#include<stdio.h>
#include <stdlib.h>

int main()
{
    char a[100],b[100];
    int n,la,lb,i,j;
    printf("enter a string:");
    gets(a);
    printf("enter substring to be inserted:");
    gets(b);
    printf("enter location:");
    scanf("%d",&n);
    la=strlen(a);
    lb=strlen(b);
    for(i=1;i<(la-n);i++)
    {
        a[la+lb-i]=a[la-i];
    }
        a[la+lb]='\0';

    for(j=0;j<lb;j++)
    {
        a[n+j]=b[j];
    }
    puts(a);
    return 0;
    }

