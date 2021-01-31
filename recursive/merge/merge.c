#include<stdio.h>
#include<stdlib.h>
void merge(int *x,int lb,int mid,int ub)
{
int i1,i2,i3,tmpSize,lb1,lb2,lb3,ub1,ub2,ub3;
int *tmp;
tmpSize=(ub-lb)+1;
tmp=(int *)malloc(sizeof(int)*tmpSize);
lb1=lb;
ub1=mid;
lb2=mid+1;
ub2=ub;
lb3=0;
ub3=tmpSize-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i1=lb1;
i3=0;
while(i1<=ub2)
{
x[i1]=tmp[i3];
i3++;
i1++;
}
free(tmp);
}
void mergeSort(int *x,int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergeSort(x,low,mid);
mergeSort(x,mid+1,high);
merge(x,low,mid,high);
}
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
mergeSort(x,0,9);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}