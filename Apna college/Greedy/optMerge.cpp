//Optimal merge pattern

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,sum=0;
    cout<<"Enter the number of files: ";
    cin>>n;
    cout<<"Enter the computation time of all files: ";
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        pq.push(m);
    }
    while(pq.size()!=1)
    {
        int a=pq.top();
        pq.pop();
        a+=pq.top();
        pq.pop();
        sum+=a;
        pq.push(a);
    }
    cout<<"Mimimum time is: "<<sum<<endl;
    return 0;
}