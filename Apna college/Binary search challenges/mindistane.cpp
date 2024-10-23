//In an array of n elements find K elements such that minimum distance between any 2 numbers is the maximum possible

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isFeasible(vector<int> v,int mid,int n,int k)
{
    int pos=v[0],ele=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]-mid>=pos)
        {
            pos=i;
            ele++;
            if(ele==k)
            {
                return true;
            }
        }
    }
    return false;
}

int isLargeMinDistance(vector<int> v,int n,int k)
{
    sort(v.begin(),v.end());
    int res=-1,left=1,right=n-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(isFeasible(v,mid,n,k))
        {
            res=max(res,mid);
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    return res;
}

int main()
{
    vector<int> v={1,2,4,9,8};
    int n=5,k=3;
    cout<<"Largest minimum distance is: "<<isLargeMinDistance(v,n,k);
    return 0;
}