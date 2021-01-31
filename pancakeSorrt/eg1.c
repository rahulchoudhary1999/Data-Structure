#include<stdio.h>
#include<stdlib.h>
void panCakeSort(int *x,int lb,int ub)
{
int size,y,e,f,g,largestIndex;
size=ub-lb+1;
while(size>0)
{
largestIndex=lb;
for(y=1;y<size;y++)
{
if(x[largestIndex]<x[y])largestIndex=y;
}
if(largestIndex==(size-1))
{
size--;
continue;
}
e=lb;
f=largestIndex;
while(e<=f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
e=lb;
f=size-1;
while(e<=f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
e++;
f--;
}
size--;
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
panCakeSort(x,0,i-1);
for(y=0;y<i;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
