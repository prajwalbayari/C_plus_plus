//RMQSQ - Range Minimum Query

//Given a array of N elements and a range (i,j) find the least element present in the array

// Note:Use 0-based indexing

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
    int n,q;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>vec[i];
    int len=sqrt(n)+1;
    vector<int> temp(n+1,INT_MAX);
    for(int i=0;i<n;i++)
        temp[i/len]=min(vec[i],temp[i/len]);
    cout<<"Enter the number of queries: ";
    cin>>q;
    while(q--)
    {
        int l,r;
        cout<<"\nEnter the range of index (0 to "<<n-1<<"): ";
        cin>>l>>r;
        int ans=INT_MAX;
        for(int i=l;i<=r;)
        {
            if(i%len==0 && i+len-1<=r)
            {
                ans=min(ans,temp[i/len]);
                i+=len;
            }
            else
            {
                ans=min(ans,vec[i]);
                i++;
            }
        }
        cout<<"Minimum value in the range "<<l<<" and "<<r<<" is: "<<ans<<endl;
    }
}