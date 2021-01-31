#include<stdio.h>
#include<float.h>
#include<math.h>
int main()
{
int x[22][2]={{2,3},{4,4},{1,2},{0,2},{-2,3},{-19,2},{12,2},{2,43},{9,1},{1,1},{8,-6},{7,1},{-2,-2},{4,-19},{-3,4},{3,2},{5,4},{-17,17},{8,17},{0,19},{1,0},{4,-4}};
int size,e,f,g,m,partition,x1,y1,x2,y2,x3,y3,x4,y4,endPoint;
double smallestDistance1,smallestDistance2,distance;
size=22;
m=size-2;
//sort by x
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(x[f]<x[e])
{
g=x[e][0];
x[e][0]=x[f][0];
x[f][0]=g;
g=x[e][1];
x[e][1]=x[f][1];
x[f][1]=g;
}
e++;
f++;
}
m--;
}
partition=size/2;
smallestDistance1=DBL_MAX;
x1=x[0][0];
y1=x[0][1];
x2=x[1][0];
y2=x[1][1];
e=0;
endPoint=partition-1;
while(e<endPoint)
{
f=e+1;
while(f<=endPoint)
{
distance=sqrt(pow((x[e][0]-x[f][0]),2)+pow((x[e][1]-x[f][1]),2));
if(distance<smallestDistance1)
{
smallestDistance1=distance;
x1=x[e][0];
y1=x[e][1];
x2=x[f][0];
y2=x[f][1];
}
f++;
}
e++;
}

smallestDistance2=DBL_MAX;
x3=x[0][0];
y3=x[0][1];
x4=x[1][0];
y4=x[1][1];
e=partition;
endPoint=size-1;
while(e<endPoint)
{
f=e+1;
while(f<=endPoint)
{
distance=sqrt(pow((x[e][0]-x[f][0]),2)+pow((x[e][1]-x[f][1]),2));
if(distance<smallestDistance2)
{
smallestDistance2=distance;
x3=x[e][0];
y3=x[e][1];
x4=x[f][0];
y4=x[f][1];
}
f++;
}
e++;
}

if(smallestDistance1<smallestDistance2)
{
printf("(%d,%d),(%d,%d) are the pairs having smallest distance %0.2lf",x1,y1,x2,y2,smallestDistance1);
}
else
{
printf("(%d,%d),(%d,%d) are the pairs having smallest distance %0.2lf",x3,y3,x4,y4,smallestDistance2);
}
return 0;
}