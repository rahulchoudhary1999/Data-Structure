#include<stdio.h>
#include<stdlib.h>
void linearSort(int *x,int cs)
{
int oep,iep,e,f,g;
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
}
int main()
{
int *x,y,req;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
linearSort(x,req);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}