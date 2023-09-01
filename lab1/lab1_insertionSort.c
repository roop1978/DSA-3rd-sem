//c program to illustrate insertion sort

#include <stdio.h>
int i,j,temp,n,k,a[100];

void main()
{
     //input
     printf("enter dimensions of array:\t");
     scanf("%d",&n);
     printf("enter elements:\t");
     for(k=0;k<n;k++){
        scanf("%d",&a[k]);
     }
     //sorting
     for(i=0;i<n-1;i++){
        for(j=i+1;j>=0 && a[j-1]>a[j];j--){


                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;

        }
     }

for(k=0;k<n;k++)
{
    printf("%d",a[k]);
}
}
