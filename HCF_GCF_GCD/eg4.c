#include<stdio.h>
int main()
{
int num1,num2,l,s,r,lcm,hcf;
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
while(s>0)
{
r=l%s;
l=s;
s=r;
}
hcf=l;
lcm=(num1*num2)/hcf;
printf("LCM of %d and %d is %d",num1,num2,lcm);
return 0;
}