#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *));
int myComparator(void *left,void *right)
{
int *a,*b;
a=(void *)left;
b=(void *)right;
return (*a)-(*b);
}
int main()
{
int *x,y,e,f,g,si,req;
printf("Enter your requirement : ");
scanf("%d",&req);
if(req<0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
y=0;
while(y<req)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
selectionSort(x,req,sizeof(int),myComparator);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,si,oep,iep,w;
void *a,*b,*c;
c=(void *)malloc(es);
oep=cs-2;
iep=cs-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
}