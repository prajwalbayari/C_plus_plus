//Connected component in a graph

#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> components;
int n,m;

int get_size(int src)
{
    if(vis[src]==true)
        return 0;
    vis[src]=true;
    int ans=1;
    for(auto i:adj[src])
    {
        if(!vis[i])
        {
            ans+=get_size(i);
            vis[i]=true;
        }
    }
    return ans;
}

int main()
{
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis =vector<bool>(n);
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
        if(!vis[i])
        {
            components.push_back(get_size(i));
        }
    }
    for(auto i:components)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}