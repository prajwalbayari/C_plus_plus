//Bellman ford algorithm (Negative weights are allowed)

#include<stdlib.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int inf=1e9;

int main()
{
    int m,n,src;
    cout<<"Enter the number of nodes and edges:\n";
    cin>>n>>m;
    vector<vector<int>> edges;
    cout<<"Enter the edges with their weight:\n";
    for(int i=0;i<m;i++)
    {
        int u,w,v;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    cout<<"Enter the source node:\n";
    cin>>src;
    vector<int> dis(n,inf);
    set<vector<int>> s;
    dis[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0],v=it[1],w=it[2];
            dis[v]=min(dis[v],w+dis[u]);
        }
    }
    cout<<"Minimum distance from source to all other nodes is:\n";
    for(auto i:dis)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}