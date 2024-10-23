//Minimum number of numbers required to represent the given number as sum of squares of numbers

#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> dp(1e5+7,1e9);

int dynamic(int n)
{
    if(n<4) 
        return n;
    if(dp[n]!=1e9)
        return dp[n];
    for(int i=1;i*i<=n;i++)
    {
        dp[n]=min(dp[n],1+dynamic(n-i*i));
    }
    return dp[n];
}

int bottom_up(int n)
{
    vector<int> v(n+1,1e9);
    v[0]=0,v[1]=1,v[2]=2,v[3]=3;
    for(int i=1;i*i<=n;i++)
    {
        for(int j=0;i*i+j<=n;j++)
        {
            v[i*i+j]=min(v[i*i+j],1+v[j]);
        }
    }
    return v[n];
}

int square(int n)
{
    if(n<4)
        return n;
    int ans=1e9+7;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,1+square(n-i*i));
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    // cout<<"Minimum number of numbers required is: "<<square(n);
    // cout<<"Minimum number of numbers required is: "<<dynamic(n);
    cout<<"Minimum number of numbers required is: "<<bottom_up(n);
    return 0;
}