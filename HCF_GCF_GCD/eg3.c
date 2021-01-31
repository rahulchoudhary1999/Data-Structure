#include<stdio.h>
#include<stdlib.h>
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
int r,*x,y,num,z,p,q;
printf("Enter requirement :");
scanf("%d",&r);
if(r<0)
{
printf("Invalid requirement: ");
return 0;
}
x=(int *)malloc(sizeof(int)*r);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",&r);
return 0;
}
for(y=0;y<r;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
for(y=1;y<r;y++)
{
for(num=x[y],z=y-1;z>=0 && x[z]<num;z--) x[z+1]=x[z];
x[z+1]=num;
}
for(p=x[0],y=1;y<r;y++)
{
q=x[y];
p=gcd(p,q);
}
printf("GCD of given numbers is: %d",p);
free(x);
return 0;
}