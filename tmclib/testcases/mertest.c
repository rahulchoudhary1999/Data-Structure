#include<stdio.h>
#include<stdlib.h>
int intComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int *x,y,req;
int isSuccessful,errorNumber;
printf("Enter requirement : ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Invalid requirement, Unable to allcate memory for %d\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
mergeSort((void *)x,intComparator,sizeof(int),0,req-1,&isSuccessful,&errorNumber);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}