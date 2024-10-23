#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the array elements: ";             
    for(int i=0;i<n;i++)
        cin>>v[i];
    int s=0,ans=INT_MAX,k;
    cout<<"Enter the size of the subarray: ";
    cin>>k;
    for(int i=0;i<k;i++)
        s+=v[i];
    ans=min(ans,s);
    for(int i=k;i<n;i++)
    {
        s+=v[i]-v[n-k-1];
        ans=min(ans,s);
    }
    cout<<"The minimum sum of the elements of subarray having given size is: "<<ans<<endl;
    return 0;
}