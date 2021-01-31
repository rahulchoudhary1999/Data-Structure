#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int cs,int es,int(*p2f)(void *,void *))
{
int oep,iep,w,e,f;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
for(e=0;e<=oep;e++)
{
for(f=e+1;f<=iep;f++)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
}
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
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
linearSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}