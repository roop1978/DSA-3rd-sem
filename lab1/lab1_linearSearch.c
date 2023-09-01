// c program to illustrate linear search

 #include<stdio.h>
 int n,i,key,a[100];
 void main(){
     //input
     printf("enter dimensions of array:\t");
     scanf("%d",&n);
     printf("enter elements:\t");
     for(i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     printf("enter element to be found:");
     scanf("%d",&key);

     //traversing array

     for(i=0;i<n;i++){
        if(a[i]==key)
        {
            printf("key found at index: %d",i);
        }


 }

 }

