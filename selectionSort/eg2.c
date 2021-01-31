#include<stdio.h>
void selectionSort(int *data,int size);
int main()
{
int x[5],y,e,f,g,si;
y=0;
while(y<=4)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
y++;
}
selectionSort(x,5);
y=0;
while(y<=4)
{
printf("%d\n",x[y]);
y++;
}
return 0;
}
void selectionSort(int *data,int size)
{
int e,f,g,si,oep,iep;
oep=size-2;
iep=size-1;
e=0;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
if(data[f]<data[si])
{
si=f;
}
f++;
}
g=data[si];
data[si]=data[e];
data[e]=g;
e++;
}
}