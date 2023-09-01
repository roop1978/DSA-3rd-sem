// c program to illustrate bubble sort


#include <stdio.h>
int i,j,n,a[100],temp,k;
void main()
{
     //input
     printf("enter dimensions of array:\t");
     scanf("%d",&n);
     printf("enter elements:\t");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     //sorting
     for(i=0;i<n-1;i++)
     {
         for(j=i;j<n;j++)
         {
             if(a[i]>a[j])
             {
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
             }
         }

     }
     for(k=0;k<n;k++)
     {
         printf("%d",a[k]);
     }
}
