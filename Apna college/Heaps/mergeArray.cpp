// Merge k Sorted arrays to form a sorted array

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int k,m=1,n;
    cout<<"Enter the number of arrays: ";
    cin>>k;
    vector<vector<int>> v;
    vector<int> idx(k),ans;
    for(int i=0;i<k;i++)
    {
        cout<<"Enter the size of array "<<m++<<" : ";
        cin>>n;
        idx[m-2]=n;
        vector<int> vec(idx[m-2]);
        cout<<"Enter the array elements: ";
        for(int j=0;j<idx[m-2];j++)
        {
            cin>>vec[j];
        }
        v.push_back(vec);
        cout<<endl;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({v[i][0],i});
        idx[i]--;
    }
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int x=p.second,y=v[x].size();
        if(idx[x]==0)
        {
            ans.push_back(p.first);
            continue;
        }
        ans.push_back(p.first);
        pq.push({v[x][y-(--idx[x])-1],x});
    }
    m=ans.size();
    cout<<"Sorted array is : ";
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}