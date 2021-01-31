#include<stdio.h>
void insertionSort(int *x,int size)
{
int y,z,num,ep;
ep=size-1;
for(y=1;y<=ep;y++)
{
for(num=x[y],z=y-1;z>=0&&x[z]>num;z--)x[z+1]=x[z];
x[z+1]=num;
}
}
int main()
{
int x[10],y,num,z;
for(y=0;y<10;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
insertionSort(x,10);
for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}