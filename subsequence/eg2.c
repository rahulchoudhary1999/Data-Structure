#include<stdio.h>
int main()
{
int x[]={12,3,92,-3,76,54,12,93,78,19,20,100,-2,6,12,17,55,67,2,10};
int temp[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int found=0;
int e,f,num,i,t;
for(e=0;e<19;e++)
{
num=x[e];
for(i=0;i<20;i++)
{
if(temp[i]==num)
{
found=1;
break;
}
}
if(found==1)
{
found=0;
continue;
}
for(i=0;i<20;i++)
{
temp[i]=0;
}
i=0;
temp[i]=num;
i++;
for(f=e+1;f<20;f++)
{
if(num<x[f])
{
num=x[f];
temp[i]=num;
i++;
}
}
t=0;
while(t<i)
{
printf("%d ",temp[t]);
t++;
}
printf("\n");
}
return 0;
}