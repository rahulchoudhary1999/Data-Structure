#include<stdio.h>
#include<stdlib.h>
int main()
{
int k,y,*x,r,swapCount,g;
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
while(1)
{
swapCount=0;
for(y=0;y<k-1;y++)
{
if(x[y]>x[k-1])
{
g=x[y];
x[y]=x[k-1];
x[k-1]=g;
swapCount++;
break;
}
}

for(y=(r-1);y>k-1;y--)
{
if(x[y]<x[k-1])
{
g=x[y];
x[y]=x[k-1];
x[k-1]=g;
swapCount++;
break;
}
}
if(swapCount==0)break;
}
printf("kth smallest number is : %d",x[k-1]);
free(x);
return 0;
}