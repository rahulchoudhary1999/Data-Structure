#include<stdio.h>
int main()
{
int x[8]={-10,-2,3,7,-5,8,6,-2};
int lmax,gmax,i,j,si,ei;
lmax=x[0];
gmax=x[0];
si=0;
ei=0;
for(i=1;i<=7;i++)
{
j=lmax+x[i];
if(x[i]>j)
{
lmax=x[i];
si=i;
}
else
{
lmax=j;
}
if(lmax>gmax)
{
gmax=lmax;
ei=i;
}
}
printf("(%d-%d)--->%d\n",si,ei,gmax);
return 0;
}