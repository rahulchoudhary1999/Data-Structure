#include<stdio.h>
#include<stdlib.h>
int main()
{
int num;
FILE * f;
f=fopen("tmp.tmp","wb");
int i=0;
for(i=0;i<5000;i++)
{
num=rand();
fwrite(&num,sizeof(int),1,f);
}
fclose(f);
return 0;
}