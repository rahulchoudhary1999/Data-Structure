#include<stdio.h>
int main()
{
int x[10],y,num,z;
for(y=0;y<10;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
y=1;
while(y<=9)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}