#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESSFUL 1
#define FAILED 0
typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int elementSize;
int size;
}Stack;
void initStack(Stack *stack,int elementSize,int *successful,int *error)
{
if(successful!=NULL) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
if(error) *error=1;
return;
}
if(elementSize<=0)
{
if(error) *error=2;
return;
}
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
if(successful) *successful=SUCCESSFUL;
}
void push(Stack *stack,void *ptr,int *successful,int *error)
{
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
*error=1;
return;
}
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL)
{
if(error) *error=3;
return;
}
if(ptr!=NULL)
{
node->ptr=(void *)malloc(stack->elementSize);
if(node->ptr==NULL)
{
free(node);
if(error) *error=3;
return;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else
{
node->ptr=ptr;
}
node->next=stack->top;
stack->top=node;
stack->size++;
if(successful) *successful=SUCCESSFUL;
}
void pop(Stack *stack,void *ptr,int *successful,int *error)
{
int j;
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL || ptr==NULL)
{
if(error) *error=1;
return;
}
if(stack->top==NULL)
{
if(error) *error=4;
return;
}
if(stack->top->ptr==NULL)
{
for(j=0;j<stack->elementSize;j++)
{
*((char *)(ptr+j))=(char)0;
}
}
else
{
memcpy(ptr,(const void *)stack->top->ptr,stack->elementSize);
}
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
stack->size--;
if(successful) *successful=SUCCESSFUL;
}
int isEmpty(Stack *stack,int *successful,int *error)
{
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
if(error) *error=1;
return 1; // returning true because stack is empty
}
if(successful) *successful=SUCCESSFUL;
if(stack->size==0) return 1;
return 0;
}
void clearStack(Stack *stack,int *successful,int *error)
{
StackNode *node;
if(successful) *successful=FAILED;
if(error) *error=0;
if(stack==NULL)
{
*error=1;
return;
}
while(stack->top!=NULL)
{
node=stack->top;
stack->top=stack->top->next;
if(node->ptr!=NULL) free(node->ptr);
free(node);
}
stack->size=0;
if(successful) *successful=SUCCESSFUL;
}
void merge(void *x,int (*p2f)(void *,void *),int es,int lb1,int ub1,int lb2,int ub2,int *successful,int *error)
{
int size1,size2,size3;
void *tmp;
int i1,i2,i3;
if(successful) *successful=FAILED;
if(error) *error=0;
if(x==NULL || p2f==NULL)
{
if(error) *error=1;
return;
}
if(es<=0)
{
if(error) *error=2;
return;
}
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(void *)malloc(es*size3);
if(tmp==NULL)
{
if(error) *error=3;
return;
}
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
//if(x[i1]<x[i2])
if(p2f(x+(i1*es),x+(i2*es))<0)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
}
else
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
//tmp[i3]=x[i1];
memcpy(tmp+(i3*es),(const void *)(x+(i1*es)),es);
i1++;
i3++;
}
while(i2<=ub2)
{
//tmp[i3]=x[i2];
memcpy(tmp+(i3*es),(const void *)(x+(i2*es)),es);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
//x[i1]=tmp[i3];
memcpy(x+(i1*es),(const void *)(tmp+(i3*es)),es);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
//x[i2]=tmp[i3];
memcpy(x+(i2*es),(const void *)(tmp+(i3*es)),es);
i2++;
i3++;
}
free(tmp);
if(successful) *successful=SUCCESSFUL;
}
void mergeSort(void *x,int (*p2f)(void *,void *),int es,int lowerBound,int upperBound,int *successful,int *error)
{
struct LBUB
{
int lb,ub;
};
int isSuccessful,errorNumber;
struct LBUB lbub;
int a,b;
Stack stack1;
Stack stack2;
int mid;
if(successful) *successful=FAILED;
if(error) *error=0;
initStack(&stack1,sizeof(struct LBUB),&isSuccessful,&errorNumber);
initStack(&stack2,sizeof(struct LBUB),&isSuccessful,&errorNumber);
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
while(!isEmpty(&stack1,&isSuccessful,&errorNumber))
{
pop(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
// no verification required
push(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
if(a<mid)
{
lbub.lb=a;
lbub.ub=mid;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(mid+1<b)
{
lbub.lb=mid+1;
lbub.ub=b;
push(&stack1,(void *)&lbub,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
}
while(!isEmpty(&stack2,&isSuccessful,&errorNumber))
{
pop(&stack2,(void *)&lbub,&isSuccessful,&errorNumber);
a=lbub.lb;
b=lbub.ub;
mid=(a+b)/2;
merge(x,p2f,es,a,mid,mid+1,b,&isSuccessful,&errorNumber);
if(!isSuccessful)
{
*error=errorNumber;
clearStack(&stack1,&isSuccessful,&errorNumber);
clearStack(&stack2,&isSuccessful,&errorNumber);
return;
}
}
if(successful) *successful=SUCCESSFUL;
}
int intComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int x[10],y;
int isSuccessful,errorNumber;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
mergeSort((void *)x,intComparator,sizeof(int),0,9,&isSuccessful,&errorNumber);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}