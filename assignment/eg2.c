#include<stdio.h>
#include<stdlib.h>
int main()
{
int k,y,*x,r,swapCount,g;
int ci,ri,lci,rci,swi;
printf("Enter requirement: ");
scanf("%d",&r);
if(r<=0)
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
printf("Enter a number :");
scanf("%d",&x[y]);
}
printf("Enter kth value: ");
scanf("%d",&k);
if(k<=0 || k>r)
{
printf("Invalid input");
return 0;
}
//min heap
y=1;
while(y<r)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ci]<x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else
{
break;
}
}
y++;
}
y=r-1;
k--;
while(k--)
{
x[0]=x[y];
y--;
ri=0;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y)break;
rci=lci+1;
if(rci>y)
{
swi=lci;
}
else
{
if(x[lci]<x[rci])
{
swi=lci;
}
else
{
swi=rci;
}
}
if(x[swi]<x[ri])
{
g=x[swi];
x[swi]=x[ri];
x[ri]=g;
}
else
{
break;
}
ri=swi;
}
}
printf("kth smallest number is : %d",x[0]);
free(x);
return 0;
}