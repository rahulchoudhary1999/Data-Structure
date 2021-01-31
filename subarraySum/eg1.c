#include<stdio.h>
#include<stdlib.h>
int main()
{
int r,*x,y,e,f,sum,largestSum;
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
largestSum=INT_MIN;
for(e=0;e<r;e++)
{
for(sum=0,f=e;f<r;f++)
{
sum+=x[f];
if(sum>largestSum) largestSum=sum;
}
}
printf("Largest Sum : %d",largestSum);
free(x);
return 0;
}