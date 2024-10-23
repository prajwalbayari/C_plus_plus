#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
    int a,i,sum=0;
   cin>>a;
     for(i=0;i<=a;i++)
     {
        sum=sum+i;
     }
     cout<<sum;
}