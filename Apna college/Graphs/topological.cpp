//Topological sort
//Only directed acyclic graphs have topological sort

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> it(n);
    vector<int> indeg(n,0);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        it[x].push_back(y);
        indeg[y]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
            pq.push(i);
    }
    while(!pq.empty())
    {
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it:it[x])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                pq.push(it);
            }
        }
    }
    cout<<endl;
    return 0;
}