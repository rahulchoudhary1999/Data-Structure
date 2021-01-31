#include<stdio.h>
int m[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int count=0;
int pwr(int b,int c)
{
count++;
if(c==1) return b;
if(m[c]!=0) return m[c];
m[c]=(c%2==0)?pwr(b,c/2)*pwr(b,c/2):b*pwr(b,c/2)*pwr(b,c/2);
return m[c];
}
int power(int b,int c)
{
if(c==0) return 1;
return pwr(b,c);
}
int main()
{
int x,y;
printf("Enter value for b : ");
scanf("%d",&x);
printf("Enter value for c : ");
scanf("%d",&y);
printf("%d^%d is %d\n",x,y,power(x,y));
printf("%d copies were created\n",count);
return 0;
}