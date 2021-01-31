#include<stdio.h>
int main()
{
int x,y,z,j;
x=0;
y=1;
j=1;
while(j<10)
{
z=x+y;
x=y;
y=z;
j++;
}
printf("%d",y);
return 0;
}