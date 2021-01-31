#include<stdio.h>
int power(int b,int c)
{
int i,pw;
pw=1;
for(i=1;i<=c;i++) pw*=b;
return pw;
}
int main()
{
int x,y;
x=2;
y=5;
printf("%d^%d is %d",x,y,power(x,y));
return 0;
}