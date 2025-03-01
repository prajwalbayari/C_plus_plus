//Given a directed graph find the list of nodes that will eventually enter the safe mode
//A node is safe if it reaches a terminal node

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool DFS(vector<vector<int>>& edges,vector<int>& vis,int src,vector<int>& path){
    vis[src]=1,path[src]=1;
    for(auto node:edges[src]){
        if(!vis[node]){
            if(DFS(edges,vis,node,path))
                return true;
        }else if(path[node])
            return true;
    }
    path[src]=0,vis[src]=2;
    return false;
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    vector<vector<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
    }

    vector<int> vis(n+1,0),path(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0)
            DFS(edges,vis,i,path);
    }

    cout<<"The safe nodes are: ";

    for(int i=1;i<=n;i++){
        if(vis[i]==2)
            cout<<i<<" ";
    }
    cout<<endl;
}


//Space complexity: O(n)
//Time complexity: O(n)