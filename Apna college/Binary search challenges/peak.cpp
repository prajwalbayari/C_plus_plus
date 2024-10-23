//Find the peak element in an array(sorted or unsorted)

#include<iostream>
#include<vector>
using namespace std;

int findPeak(vector<int> v,int beg,int end,int n)
{
    int mid=beg+(end-beg)/2;
    if( (mid==0 ||v[mid-1]<=v[mid]) && (mid==n-1 || v[mid+1]<=v[mid]))
    {
        return mid;
    }
    if(mid>0 && v[mid-1]>v[mid])
    {
        return findPeak(v,beg,mid-1,n);
    }
    return findPeak(v,mid+1,end,n);
}

int main()
{
    vector<int> v={0,6,8,5,7,9};
    cout<<"Peak element is: "<<v[findPeak(v,0,5,6)];
    return 0;
}