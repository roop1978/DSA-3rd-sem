#include <stdio.h>
#include <stdlib.h>

int main(){
    char a[50],b[50];
    int i,j,m,f;
    printf("enter a string:");
    gets(a);
    printf("enter another string:");
    gets(b);

    for(i=0;a[i]!='\0'||b[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        {
            f=1;
            break;
        }

    }
    if(f==0)
    {
        printf("strings are equal");
    }
    else if(a[i]>b[i])
    {
        printf("string 1 is greater");
    }
    else
    {
        printf("string 2 is greater");
    }

return 0;
}
