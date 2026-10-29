#include<stdio.h>
int main()
  {
   int N,a[10000],b[10000]={0,0,0,0},most=0,mostnumber;
   scanf("%d",&N);
   for(int i=0;i<N;i++)
     {
      scanf("%d",&a[i]);
      b[a[i]]+=1;
     }
    for(int i=0;i<10000;i++)
     {
      if(b[i]>most)
        {
         most=b[i];
         mostnumber=i;
        } 
     }
    printf("%d",mostnumber);
  }