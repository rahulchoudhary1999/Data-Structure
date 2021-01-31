#include<stdio.h>
#include<stdlib.h>
int main()
{
int r,*x,y,lmax,gmax;
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
lmax=x[0];
gmax=x[0];
for(y=1;y<r;y++)
{
if(x[y]>(lmax+x[y]))
{
lmax=x[y];
}
else
{
lmax=(lmax+x[y]);
}
if(lmax>gmax)
{
gmax=lmax;
}
}
printf("Largest Sum : %d",gmax);
free(x);
return 0;
}