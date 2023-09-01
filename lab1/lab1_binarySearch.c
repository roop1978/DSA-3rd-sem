// c program to illustrate binary search

#include <stdio.h>
 int i,n,key,a[100];
void main()
{
     //input
     printf("enter dimensions of array:\t");
     scanf("%d",&n);
     printf("enter elements:\t");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     printf("enter element to be found:");
     scanf("%d",&key);

 int l=0;
     int h=n-1;

     for(i=l;i<=h;i++)
     {


     int mid=(l+h)/2;
         if(key==a[mid])
         {
             printf("key found at : %d",mid);
             break;
         }
         else if(key<a[mid])
         {
             l=0;
             h=mid-1;
         }
         else{
            l=mid+1;
            h=n-1;
         }
     }

}
