//Dijkstras algorithm

//Find the shortest distance from one node to other(Weight of the edges must be positive)

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
using namespace std;
const int inf=1e7;

int main()
{
    int n,m,src;
    cout<<"Enter the number of nodes and edges:\n";
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> dis(n+1,inf);
    cout<<"Enter the edges with their weight: ";
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cout<<"Enter the source:\n";
    cin>>src;
    dis[src]=0;
    set<vector<int>> s;
    s.insert({0,src});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto i:graph[x[1]])
        {
            if(dis[i.first]>dis[x[1]]+i.second)
            {
                s.erase({dis[i.first],i.first});
                dis[i.first]=dis[x[1]]+i.second;
                s.insert({dis[i.first],i.first});
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        if(dis[i]!=inf)
        {
            cout<<dis[i]<<" ";
        }
        else
        {
            cout<<"-1 ";
        }
    }
    cout<<endl;
    return 0;
}