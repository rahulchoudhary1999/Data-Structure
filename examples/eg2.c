#include<stdio.h>
int count=0;
int pwr(int b,int c)
{
count++;
if(c==1) return b;
return b*power(b,c-1);
}
int power(int b,int c)
{
if(c==0) return 1;
return pwr(b,c);
}
int main()
{
int x,y;
printf("Enter value for b : ");
scanf("%d",&x);
printf("Enter value for c : ");
scanf("%d",&y);
printf("%d^%d is %d\n",x,y,power(x,y));
printf("%d copies were created\n",count);
return 0;
}