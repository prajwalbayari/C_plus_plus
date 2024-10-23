#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void smallSubarray(vector<int> v,int n,int x)
{
    int sum=0,m=INT_MAX,low=0,high=0;
    while(high < n)
    {
        while(sum<=x && high<n)
        {
            sum+=v[high++];
        }
        while(sum>x && low<n)
        {
            if(high-low<m)
            {
                m=high-low;
            }
            sum-=v[low++];
        }
    }
    cout<<"Minimum length of the subarray that has sum greater than "<<x<<" is "<<m<<endl;
}

int main()
{
    vector<int> v={1,4,45,6,10,19};
    smallSubarray(v,6,61);
    return 0;
}