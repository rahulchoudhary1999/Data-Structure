#include<stdio.h>
int main()
{
int x[]={12,12,92,-3,76,54,12,93,78};
int temp[]={0,0,0,0,0,0,0,0,0};
int found=0;
int e,f,num,i,t;
for(e=0;e<8;e++)
{
num=x[e];
for(i=0;i<9;i++)
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
for(i=0;i<9;i++)
{
temp[i]=0;
}
i=0;
temp[i]=num;
//printf("%d\n",temp[i]);
//printf("%d\n",e);
i++;
for(f=e+1;f<9;f++)
{
if(num<x[f])
{
//printf("%d %d\n",num,x[f]);
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