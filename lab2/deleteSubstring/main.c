#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100],b[100];
    int i,flag=0,j,l=-1;
    printf("enter string:");
    gets(a);
    printf("enter string to be deleted:");
    gets(b);
    int la=strlen(a);
    int lb=strlen(b);
    for(i=0;i<la-lb;i++)//traversing remaining length of string a left after b is removed
    {
        for(j=i;j<i+lb;j++)
        {
            flag=1;
            if(a[j]!=b[j-1]){
                flag=0;
                break;

            }

            if(flag==1){
                    l=i;
            break;
            }

        }
    }

    if(l==-1)
    {
        printf("substring not found");

    }
    else{
        for(i=0;i<la-l;i++)
            {
            a[l+i]=a[l+lb+i];

            }
            puts(a);
        }
        return 0;
}
