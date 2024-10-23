#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
    int lo=1,hi=1e9+1;
    int ans=-1,cnt=0;
    while(lo<hi)
    {
        int m=(lo+hi)/2;
        cout<<m<<endl;
        cout<<flush;
        string s;
        cin>>s;
        if(s=="<")  
            hi=m-1;
        else
        {
            ans=max(ans,m);
            lo=m+1;
        }
        cnt++;
    }
    cout<<"! "<<ans<<" count= "<<cnt<<endl;
    cout<<flush;
}