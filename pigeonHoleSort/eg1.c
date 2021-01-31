#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};
 
struct node **nodeList;

void insert(int data,int index)
{
struct node *temp,*t;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
if(nodeList[index]==NULL || data<nodeList[index]->data)
{
temp->next=nodeList[index];
nodeList[index]=temp;
return;
}
else
{
t=nodeList[index];
while(t->next!=NULL && t->next->data<data)
{
t=t->next;
}
temp->next=t->next;
t->next=temp;
}
}

void pigeonHoleSort(int *x,int lb,int ub)
{
int y,size,largest,smallest,index,i,range;
size=ub-lb+1;
largest=x[lb];
smallest=x[lb];
for(y=lb+1;y<size;y++)
{
if(largest<x[y])largest=x[y];
if(smallest>x[y])smallest=x[y];
}
range=largest-smallest+1;
nodeList=(struct node **)malloc(sizeof(struct node *)*range);
for(y=0;y<range;y++)
{
nodeList[y]=NULL;
}
for(y=lb;y<size;y++)
{
index=x[y]-smallest;
insert(x[y],index);
}
//copy back
i=0;
for(y=0;y<range;y++)
{
while(nodeList[y]!=NULL)
{
x[i]=nodeList[y]->data;
nodeList[y]=nodeList[y]->next;
i++;
}
}
free(nodeList);
}


int main()
{
int *x,y,i;
printf("Enter requirement : ");
scanf("%d",&i);
if(i<0)
{
printf("Invalid requirement");
return 0;
}
x=(int *)malloc(sizeof(int)*i);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",i);
return 0;
}
for(y=0;y<i;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
pigeonHoleSort(x,0,i-1);
for(y=0;y<i;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}




