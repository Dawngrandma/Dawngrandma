#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
  {
   int num,n,flag=0;
   srand(time(NULL));
   num=rand()%100+1;
   while (flag!=1)
   {
    scanf("%d",&n);
    if(n==num)
    {
     flag=1;
     printf("猜对了！\n");
    }
    else if(n<num)
    {
     printf("太小了\n");
    }
    else if(n>num)
    {
     printf("太大了\n");
    }
   }
  }