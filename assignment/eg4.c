#include<stdio.h>
#include<stdlib.h>
int main()
{
int k,y,*x,r,g,m,count,e,f;
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
//bubble sort
m=r-2;
count=0;
while(m>=0 && count!=k)
{
count++;
e=0;
f=1;
while(e<=m)
{
if(x[f]>x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
e++;
f++;
}
m--;
}
printf("kth smallest number in array is %d",x[r-k]);
free(x);
return 0;
}