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
startIndex=0;
endIndex=0;
sum=0;
t=0;
while(endIndex<r)
{
sum+=x[endIndex];
if(sum<givenSum)
{
endIndex++;
}
else
{
if(sum==givenSum)
{
t=1;
break;
}
else
{
sum=0;
startIndex++;
endIndex=startIndex;
}
}
}
if(t==1) printf("StartIndex is %d , endIndex is %d ",startIndex,endIndex);
else printf("There is no subarray exists whose sum is equal to given sum %d",givenSum);
free(x);
return 0;
}