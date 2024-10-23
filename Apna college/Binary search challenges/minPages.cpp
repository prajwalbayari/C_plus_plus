// Allocate m pages to n students such that the maximum number of pages a student can get is minimum 

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int>& v,int n,int m,int min)
{
    int sum=0,students=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]>min)
        {
            return false;
        }
        if(sum+v[i]>min)
        {
            students++;
            sum=v[i];
            if(students>m)
            {
                return false;
            }
        }
        else
        {
            sum+=v[i];
        }
    }
    return true;
}

int minPages(vector<int>& v,int m,int n)
{
    int end=0;
    if(n<m)
    {
        return -1;
    }
    for(int i=0;i<n;i++)
        end+=v[i];
    int start=0,ans=INT_MAX;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(isPossible(v,n,m,mid))
        {
            ans=min(ans,mid);
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    cout<<"The minimum possible number of pages that can be allocated to a student is: "<<minPages(v,2,10);
    return 0;
}