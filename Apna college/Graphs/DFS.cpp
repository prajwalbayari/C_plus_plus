//Depth First Search

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=1e5+2;
vector<bool> vis(N,false);
vector<int> adj[N];

void DFS(int node)
{
    //Preorder
    vis[node]=true;
    cout<<node<<" ";

    //Inorder
    for(int i=0;i<adj[node].size();i++)
    {
        if(!vis[adj[node][i]])
        {
            DFS(adj[node][i]);
        }
    }

    //Postorder
    // cout<<node<<" ";
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    return 0;
}