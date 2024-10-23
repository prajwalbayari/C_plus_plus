//Maximum subarray sum

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int main()
{
    int n,sum=0,cur=0;
    cout<<"Enter the number of elements in the array:\n";
    cin>>n;
    cout<<"Enter the array elements:\n";
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
    {
        sum=max(cur=cur+v[i],sum);
        if(cur<0)
        {
            cur=0;
        }   
    }
    cout<<"Maximum sum is:\n"<<sum;
    return 0;
}