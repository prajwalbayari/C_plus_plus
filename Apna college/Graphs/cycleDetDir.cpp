//Cycle detection in directed graphs

#include<iostream>
#include<vector>
using namespace std;

bool isCycle(int src,vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& stack)
{
    stack[src]=true;
    if(visited[src]!=true)
    {
        visited[src]=true;
        for(auto i:adj[src])
        {
            if(!visited[i] && isCycle(i,adj,visited,stack))
            {
                return true;
            }
            if(stack[i])
                return true;
        }
    }
    stack[src]=false;
    return false;
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> adj(n);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bool cycle;
    vector<bool> stack(n,false);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && isCycle(i,adj,visited,stack))
        {
            cycle=true;
        }
    }
    if(cycle==true)
        cout<<"Cycle is present\n";
    else    
        cout<<"Cycle is not present\n";
    return 0;
}