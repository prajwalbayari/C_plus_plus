#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> ans;

void DFS(vector<vector<int>> adj,int src,vector<int>& vis){
    vis[src]=1;
    ans.push_back(src);

    for(auto i:adj[src]){
        if(!vis[i]){
            DFS(adj,i,vis);
        }
    }
}

int main(){
    int n,m,src;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Enter the source for the traversal: ";
    cin>>src;

    cout<<"The order of BFS traversal is: ";
    DFS(adj,src,vis);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    cout<<endl;
    return 0;
}

//Time complextity for undirected graph: O(n+2*m)
//For directed graph : depends on number of edges
