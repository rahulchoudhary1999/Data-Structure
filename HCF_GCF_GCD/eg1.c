#include<stdio.h>
int main()
{
int num1,num2,l,s,r;
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
printf("GCD of %d and %d is %d",num1,num2,l);
return 0;
}