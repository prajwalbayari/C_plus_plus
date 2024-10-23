//Smallest subsequence with sum k

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the array elements: ";
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"Enter the minimum sum value: ";
    cin>>k;
    priority_queue<int,vector<int>> pq;
    for(int i=0;i<n;i++)
        pq.push(v[i]);
    int sum=0,cnt=0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop(),cnt++;
        if(sum>=k)
            break;
    }
    cout<<"Minimum length of subsequence required to form a sum of "<<k<<" is "<<cnt<<endl;
    return 0;
}