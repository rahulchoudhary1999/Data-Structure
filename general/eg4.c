#include<stdio.h>
int fibo(int k)
{
if(k<=1) return k;
return fibo(k-1)+fibo(k-2); 
}
int main()
{
int x,y,z,j,k;
x=0;
y=1;
printf("Enter element number : ");
scanf("%d",&k);
printf("%d\n",fibo(k));
return 0;
}