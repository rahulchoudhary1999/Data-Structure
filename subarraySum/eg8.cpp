#include<iostream>
#include<map>
using namespace std;
int main()
{
int x[]={10,-3,7,6,-2,4,3,9,-5,12};
int tempSum,givenSum,i,j,t;
map<int,int> map;
givenSum=5;
tempSum=0;
i=0;
j=0;
t=0;
while(j<10)
{
tempSum+=x[j];
if(tempSum==givenSum)
{
t=1;
break;
}
auto found=map.find(tempSum-givenSum);
if(found!=map.end())
{
i=found->second+1;
t=1;
break;
}
else
{
map.insert({tempSum,j});
}
j++;
}
if(t==1)cout<<"StartIndex :"<<i<<",EndIndex :"<<j<<" for given sum "<<givenSum;
else cout<<"There is no subarray whose sum of elements is equal to given sum "<<givenSum;
return 0;
}