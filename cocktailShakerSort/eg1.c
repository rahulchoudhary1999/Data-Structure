#include<stdio.h>
#include<stdlib.h>
void cocktailShakerSort(int *x,int lb,int ub)
{
int swap,size,i,g;
size=ub-lb+1;
swap=1;
while(swap)
{
swap=0;
for(i=lb;i<=(size-2);i++)
{
if(x[i+1]<x[i])
{
g=x[i+1];
x[i+1]=x[i];
x[i]=g;
swap=1;
}
}
if(swap==0) break;
swap=0;
ub--;
for(i=ub-1;i>=lb;i--)
{
if(x[i]>x[i+1])
{
g=x[i];
x[i]=x[i+1];
x[i+1]=g;
swap=1;
}
}
lb++;
}
}

int main()
{
int *x,y,i;
printf("Enter requirement : ");
scanf("%d",&i);
if(i<0)
{
printf("Invalid requirement");
return 0;
}
x=(int *)malloc(sizeof(int)*i);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",i);
return 0;
}
for(y=0;y<i;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
cocktailShakerSort(x,0,i-1);
for(y=0;y<i;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}