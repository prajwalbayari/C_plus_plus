//Bipartite graph

#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

int n,m;
bool bipart=true;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> colors;

void color(int u,int curr)
{
    if(colors[u]!=-1 && colors[u]!=curr)
    {
        bipart=false;
        return;
    }
    colors[u]=curr;
    if(visited[u])
        return;
    visited[u]=true;
    for(auto i:adj[u])
    {
        color(i,abs(curr-1));
    }
}

int main()
{
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    visited=vector<bool> (n);
    colors=vector<int> (n,-1);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            color(i,0);
        }
    }
    if(!bipart)
        cout<<"It is not a bipartite graph\n";
    else
        cout<<"It is a bipartite graph\n";
}