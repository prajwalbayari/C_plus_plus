#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findFeasible(vector<int> v,int n,int mid)
{
    int sum=0,painter=1;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>mid)
        {
            sum=v[i];
            painter++;
        }
    }
    return painter;
}

int minTime(vector<int> v,int m,int n)
{
    if(n<m)
    {
        return -1;
    }
    int ma=0,total=0;
    for(int i=0;i<n;i++)
    {
        ma=max(m,v[i]);
        total+=v[i];
    }
    int beg=ma,end=total;
    while(beg<end)
    {
        int mid=(beg+end)/2;
        int painter=findFeasible(v,n,mid);
        if(painter<=m)
        {
            end=mid;
        }
        else
        {
            beg=mid+1;
        }
    }
    return beg;
}

int main()
{
    vector<int> v={20,30,30,60};
    int n=4,m=2;
    cout<<"Minimum time to paint is: "<<minTime(v,m,n)<<endl;
    return 0;
}