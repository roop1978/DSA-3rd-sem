// c program to illustrate selection sort


#include <stdio.h>
int i,j,n,a[100],k,temp;
void main()
{
     //input
     printf("enter dimensions of array:\t");
     scanf("%d",&n);
     printf("enter elements:\t");
     for(k=0;k<n;k++){
        scanf("%d",&a[k]);
     }
     for(i=0;i<n-1;i++)
     {
         int mini=i;
         for(j=i+1;j<n;j++){
            if(a[j]<a[mini])
            {
                mini=j;
            }
            if(mini!=i){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
            }
         }






for(k=0;k<n;k++)
{
    printf("%d\t",a[k]);
}
}

