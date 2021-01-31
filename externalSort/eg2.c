#include<stdio.h>
#include<stdlib.h>
int main()
{
int num;
FILE * f;
f=fopen("data.d","wb");
int i=0;
for(i=0;i<131072000;i++)
{
num=rand();
fwrite(&num,sizeof(int),1,f);
}
num=fread(&num,sizeof(int),1,f);
printf("%d\n",num);
fclose(f);
return 0;
}