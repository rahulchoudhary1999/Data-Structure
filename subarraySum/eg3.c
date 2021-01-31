#include<stdio.h>
int main()
{
int x[8]={10,-2,3,7,-5,8,6,-2};
int lmax,gmax,i,j;
lmax=x[0];
gmax=x[0];
for(i=1;i<=7;i++)
{
j=lmax+x[i];
lmax=(x[i]>j)?x[i]:j;
gmax=(lmax>gmax)?lmax:gmax;
}
printf("%d\n",gmax);
return 0;
}