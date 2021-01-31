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
int num1,num2,l,s,lcm,hcf;
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
hcf=gcd(l,s);
lcm=(num1*num2)/hcf;
printf("LCM of %d and %d is %d",num1,num2,lcm);
return 0;
}