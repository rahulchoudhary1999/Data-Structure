#include<stdio.h>
void printKLengthString(char *set,char *sequence, int n, int k) 
{
if(k==0)
{
printf("%s\n",sequence);
return;
}
for(int i=0;i<n;i++)
{
char *newSequence;
newSequence=sequence+set[i];
printKLengthString(set, newSequence, n, k - 1);
}
}
int main() 
{
char set[]="0123";
int n = 2;
int k = 3;
printKLengthString(set,"", n, k);
return 0;
}