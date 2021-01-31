#include<stdio.h>
#include<stdlib.h>
int main()
{
int k,y,*x,r,g,m,count,e,f,si;
printf("Enter requirement: ");
scanf("%d",&r);
if(r<=0)
{
printf("Invalid requirement");
return 0;
}
x=(int *)malloc(sizeof(int)*r);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",r);
return 0;
}
for(y=0;y<r;y++)
{
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter kth value: ");
scanf("%d",&k);
if(k<=0 || k>r)
{
printf("Invalid input");
return 0;
}
//selection sort
count=0;
e=0;
while(e<=(r-2) && count!=k)
{
count++;
si=e;
f=e+1;
while(f<=(r-1))
{
if(x[f]<x[si]) si=f;
f++;
}
g=x[si];
x[si]=x[e];
x[e]=g;
e++;
}
printf("kth smallest number in array is %d",x[k-1]);
free(x);
return 0;
}