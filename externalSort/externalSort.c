#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int *lbStack,*ubStack,top,size,pp,lb,ub;
size=(upperBound-lowerBound)+1;
lbStack=(int *)malloc(sizeof(int)*size);
ubStack=(int *)malloc(sizeof(int)*size);
top=size;
top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;
while(top!=size)    
{
lb=lbStack[top];
ub=ubStack[top];
top++;
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
top--;
lbStack[top]=pp+1;
ubStack[top]=ub;
}
if(lb<pp-1)
{
top--;
lbStack[top]=lb;
ubStack[top]=pp-1;
}
}
free(lbStack);
free(ubStack);
}



int main()
{
int contentOfFile[10],count,smallest,e,i,size,numberOfRecords,total,num1,num2,num;
char fn[100];
char *fileName;
int *elements;
FILE *f1,*f2,*f3;
f1=fopen("data.d","rb");
fseek(f1,0,2);
size=ftell(f1);
fseek(f1,0,SEEK_SET);
numberOfRecords=size/sizeof(int);
total=numberOfRecords/10;
for(e=1;e<=10;e++)
{
sprintf(fn,"data%d.d",e);
fileName=(char *)malloc(sizeof(char)*strlen(fn));
strcpy(fileName,fn);
elements=(int *)malloc(total*sizeof(int));
fread(elements,sizeof(int),total,f1);
quickSort(elements,0,total-1);
f2=fopen(fileName,"wb");
fwrite(elements,sizeof(int),total,f2);
free(fileName);
free(elements);
fclose(f2);
}
fclose(f1);
FILE *f[10];
for(e=0;e<10;e++)
{
sprintf(fn,"data%d.d",e+1);
fileName=(char *)malloc(sizeof(char)*strlen(fn));
strcpy(fileName,fn);
f[e]=fopen(fileName,"rb");
fread(&contentOfFile[e],sizeof(int),1,f[e]);
free(fileName);
}
count=0;
i=0;
f3=fopen("newData1.d","wb");
smallest=contentOfFile[0];
while(1)
{
if(count==10)
{
break;
}
smallest=contentOfFile[0];
i=0;
for(e=1;e<10;e++)
{
if(smallest>contentOfFile[e])
{
smallest=contentOfFile[e];
i=e;
}
}
fwrite(&smallest,sizeof(int),1,f3);
fread(&contentOfFile[i],sizeof(int),1,f[i]);
if(feof(f[i]))
{
count++;
contentOfFile[i]=2147483647;
}
}
for(e=0;e<10;e++)fclose(f[e]);
fclose(f3);
return 0;
}