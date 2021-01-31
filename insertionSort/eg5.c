#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *x,int cs,int es,int (*p2f)(void *,void *))
{
int y,z,ep;
ep=cs-1;
void *block;
block=(int *)malloc(es);
y=1;
while(y<=ep)
{
memcpy(block,(void *)(x+(y*es)),es);
//num=x[y];
z=y-1;
//while(z>=0 && x[z]>num)
while(z>=0 && p2f(x+(z*es),block)>0)
{
memcpy(x+((z+1)*es),(const void *)(x+(z*es)),es);
//x[z+1]=x[z];
z--;
}
//x[z+1]=num;
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
int *x,y,num,z,req;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement");
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
insertionSort(x,req,sizeof(int),intComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}