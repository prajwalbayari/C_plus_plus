//Breadth First Search

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=1e5+2;
vector<bool> vis(N,false);
vector<int> adj[N];

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
    queue<int> q;
    q.push(1);
    vis[1]=true;
    cout<<"Order of Breadth First Search is: ";
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++)
        {
            if(!vis[adj[node][i]])
            {
                q.push(adj[node][i]);
                vis[adj[node][i]]=true;
            }
        }
        cout<<node<<" "<<endl;
    }
    return 0;
}