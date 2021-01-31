#include<stdio.h>
#include<stdlib.h>
int *arr;
int fibo(int k)
{
if(k<=1) return k;
if(arr[k]!=-1) return arr[k];
arr[k]=fibo(k-1)+fibo(k-2); 
return arr[k];
}
int main()
{
int k,y;
printf("Enter element number : ");
scanf("%d",&k);
if(k<0)
{
printf("Invalid input");
return 0;
}
arr=(int *)malloc(sizeof(int)*(k+1));
if(arr==NULL)
{
printf("Unable to allocate memory");
return 0;
}
for(y=0;y<(k+1);y++)
{
arr[y]=-1;
}
if(k==0)
{
arr[0]=0;
}
else
{
arr[0]=0;
arr[1]=1;
}
printf("%d\n",fibo(k));
free(arr);
return 0;
}