 // c program to multiply two matrices.

 #include <stdio.h>
 int i,j,p,q,m,n,a[50][50],b[50][50],c[50][50];
  void main()
  {
      printf("enter dimensions of matrix A:");
      scanf("%d %d",&m,&n);
      printf("enter elements:");
      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++)
          {
              scanf("%d",&a[i][j]);
          }
      }
      printf("enter dimensions of matrix B:");
      scanf("%d %d",&p,&q);
       printf("enter elements:");
      for(i=0;i<p;i++)
      {
          for(j=0;j<q;j++)
          {
              scanf("%d",&b[i][j]);
          }
      }
      //checking if order is same
      if(m==p && n==q)
      {
          for(i=0;i<p;i++)
      {
          for(j=0;j<q;j++)
          {

                  c[i][j]=a[i][j]*b[i][j];
              }

      }
  }

      else{
        printf("invalid");
      }

      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++){
            printf("%d\t",c[i][j]);
          }
          printf("\n");

      }
  }

