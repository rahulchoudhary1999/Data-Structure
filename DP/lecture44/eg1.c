#include<stdio.h>
#include<string.h>

void stringGenerator(char *x,int e,int f)
{
int i;
if(e==f)
{
printf("%s\n",x);
}
else
{
for(int m=e;m<=f;m++)
{
int g;
g=x[e];
x[e]=x[m];
x[m]=g;
stringGenerator(x,e+1,f);
g=x[e];
x[e]=x[m];
x[m]=g;
}
}
}





int main()
{
char x[]="ABC";
int size=strlen(x);
//printf("%s",x);
stringGenerator(x,0,size-1);
return 0;
}