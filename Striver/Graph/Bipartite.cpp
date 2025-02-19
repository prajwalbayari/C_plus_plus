//Bipartite graph

//A graph is bipartite if it does not have a cycle or has a cycle of even length

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Time complexity : O(m+2*m)

bool BFS(vector<vector<int>> graph,vector<int>& vis,int src){
    queue<int> q;
    q.push(src);
    vis[src]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:graph[node]){
            if(vis[it]==-1){
                q.push(it);
                vis[it]=!vis[node];
            }else if(vis[it]==vis[node])
                return false;
        }
    }
    return true;
}

// Time complexity: O(n+2*m)

bool DFS(vector<vector<int>> graph,vector<int>& vis,int src,int color){
    vis[src]=color;
    for(auto node:graph[src]){
        if(vis[node]==color)
            return false;
        else if(vis[node]==-1 && !DFS(graph,vis,node,!color))
            return false;
    }
    return true;
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> vis(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]==-1 && !DFS(graph,vis,i,0)){
            cout<<"This is not a bipartite graph\n";
            return 1;
        }
    }

    cout<<"This is a bipartite graph\n";
    return 0;
}