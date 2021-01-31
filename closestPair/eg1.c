#include<stdio.h>
#include<math.h>
#include<float.h>
int main()
{
int x[10][2]={{2,3},{1,2},{2,1},{10,2},{1,1},{4,0},{0,2},{0,0},{12,-6},{5,6}};
int x1,y1,x2,y2,e,f;
double distance,smallestDistance;
x1=x[0][0];
y1=x[0][1];
x2=x[1][0];
y2=x[1][1];
smallestDistance=DBL_MAX;
e=0;
while(e<=8)
{
f=e+1;
while(f<=9)
{
distance=sqrt(pow(x[e][0]-x[f][0],2)+pow(x[e][1]-x[f][1],2));
if(distance<smallestDistance)
{
smallestDistance=distance;
x1=x[e][0];
y1=x[e][1];
x2=x[f][0];
y2=x[f][1];
}
f++;
}
e++;
}
printf("(%d,%d),(%d,%d) are the pairs having smallest distance %0.2lf",x1,y1,x2,y2,smallestDistance);
return 0;
}