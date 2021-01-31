#include<stdio.h>
int gcd(int p,int q)
{
if(q==0)
{
return p;
}
return gcd(q,p%q);
}
int main()
{
int num1,num2,l,s,a;
printf("Enter num1 : ");
scanf("%d",&num1);
printf("Enter num2 : ");
scanf("%d",&num2);
if(num1>num2) 
{
l=num1;
s=num2;
}
else
{
l=num2;
s=num1;
}
a=gcd(l,s);
printf("GCD of %d and %d is %d",num1,num2,a);
return 0;
}