#include<stdio.h>
#include<stdlib.h>


void gnomeSort(int *x,int lb,int ub)
{
int j,e,f,g;
j=lb;
while(j<=ub)
{
if(j==lb) j++;
if(x[j]<x[j-1])
{
g=x[j];
x[j]=x[j-1];
x[j-1]=g;
j--;
}
else
{
j++;
}
}
}



int main()
{
int *x,y,r;
printf("Enter requirement : ");
scanf("%d",&r);
if(r<0)
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
printf("Enter a number : ");
scanf("%d",&x[y]);
}
gnomeSort(x,0,r-1);
for(y=0;y<r;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
