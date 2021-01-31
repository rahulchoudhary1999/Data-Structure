#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],y,largest,size,num,i;
int *a;
for(y=0;y<10;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<10;y++)
{
if(largest<x[y])
{
largest=x[y];
}
}
size=largest+1;
a=(int *)malloc(sizeof(int)*size);
if(a==NULL)
{
printf("Unable to allocate memory for %d numbers",size);
return 0;
}
for(y=0;y<size;y++) a[y]=0;
for(y=0;y<10;y++)
{
num=x[y];
a[num]+=1;
}
i=0;
for(y=0;y<size;y++)
{
num=a[y];
while(num)
{
x[i]=y;
i++;
num-=1;
}
}

for(y=0;y<10;y++)
{
printf("%d\n",x[y]);
}
return 0;
}