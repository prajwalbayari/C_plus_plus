#include<iostream>
#include<vector>
using namespace std;

void maxSubarraySum(vector<int> v,int n,int k,int x)
{
    int sum=0,ans=0;
    for(int i=0;i<k;i++)
        sum+=v[i];
    ans=sum<x? sum:0;
    for(int i=k;i<n;i++)
    {
        sum+=v[i]-v[i-k];
        if(sum<x)
        {
            ans=max(sum,ans);
        }
    }
    cout<<"Maximum possible sum is: "<<ans<<endl;
}

int main()
{

    vector<int> v={23,24,18,27,89,178,87};
    maxSubarraySum(v,7,2,300);
    return 0;
}