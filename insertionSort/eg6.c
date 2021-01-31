#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *x,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int y,z;
void *block;
block=(int *)malloc(es);
y=lb+1;
while(y<=ub)
{
memcpy(block,(void *)(x+(y*es)),es);
z=y-1;
while(z>=0 && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
z--;
}
memcpy(x+((z+1)*es),(const void *)block,es);
y++;
}
free(block);
}
int intComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main()
{
int *x,y,num,z,req,start,end;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
printf("Enter start point : ");
scanf("%d",&start);
if(start<0 || start>=req)
{
printf("Invalid start point %d in case of collection of %d numbers\n",start,req);
return 0;
}
printf("Enter end point : ");
scanf("%d",&end);
if(end<start || end>=req)
{
printf("Invalid end point %d in case of start as %d and collection of %d numbers\n",end,start,req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers.",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
insertionSort(x,start,end,sizeof(int),intComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}