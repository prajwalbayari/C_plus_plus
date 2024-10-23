//Prims algorithm

//Mimimum spanning tree

//Based on greedy paradigm

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
using namespace std;
const int N=1e5+6;
vector<vector<int>> g[N];
vector<int> dis(N),parent(N);
vector<bool> vis(N);
int cost=0;
int inf=1e9;

void prims(int src)
{
    for(int i=0;i<N;i++)
        dis[i]=inf;
    dis[src]=0;
    set<vector<int>> s;
    s.insert({0,src});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1],w=x[0],v=parent[x[1]];
        cout<<u<<" "<<v<<" "<<w<<"\t";
        cost+=w;
        for(auto it:g[x[1]])
        {
            if(vis[it[0]])
                continue;
            if(dis[it[0]]>it[1])
            {
                s.erase({dis[it[0]],it[0]});
                dis[it[0]]=it[1];
                s.insert({dis[it[0]],it[0]});
                parent[it[0]]=it[1];
            }
        }
    }
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges respectively:\n";
    cin>>n>>m;
    cout<<"Enter the edges with its weight:\n";
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    prims(0);
    cout<<"The minimum cost is: "<<cost<<endl;
    return 0;
}