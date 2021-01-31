#include<stdio.h>
#include<stdlib.h>
int main()
{
int r,*x,y,e,f,sum,givenSum,startIndex,endIndex,t;
printf("Enter requirement :");
scanf("%d",&r);
if(r<0)
{
printf("Invalid requirement");
return 0;
}
x=(int *)malloc(sizeof(int)*r);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",r);
return 0;
}
for(y=0;y<r;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
printf("Enter sum :");
scanf("%d",&givenSum);
startIndex=-1;
endIndex=-1;
t=0;
for(e=0;e<r;e++)
{
for(sum=0,f=e;f<r;f++)
{
sum+=x[f];
if(sum==givenSum) {
startIndex=e;
endIndex=f;
t=1;
break;
}
}
if(t==1)
{
break;
}
}
if(startIndex==-1)
{
printf("There is no subarray whose sum is equal to %d",givenSum);
return 0;
}
printf("StartIndex is %d , endIndex is %d ",startIndex,endIndex);
free(x);
return 0;
}