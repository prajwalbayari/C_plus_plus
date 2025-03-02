//Cycle detection in an Directed graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Using DFS

bool DFS(vector<vector<int>>& edges,vector<int>& vis,int src,vector<int>& path){
    vis[src]=1;
    path[src]=1;
    for(auto node:edges[src]){
        if(!vis[node]){
            if(DFS(edges,vis,node,path))
                return true;
        }
        else if(path[node])
            return true;
    }
    path[src]=0;
    return false;
}

//Using BFS (Kahn's algorithm)

bool BFS(vector<vector<int>>& edges){
    int n=edges.size(),cnt=0;
    vector<int> indeg(n+1,0);
    for(int i=0;i<n;i++){
        for(int node:edges[i])
            indeg[node]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(int child:edges[node]){
            indeg[child]--;
            if(indeg[child]==0)
                q.push(child);
        }
    }

    return cnt!=n-1;
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
    }
    vector<int> vis(n+1,0),path(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i] && DFS(edges,vis,i,path)){
            cout<<"There is a cycle present\n";
            return 0;
        }
    }

    cout<<"There is no cycle present\n";
    return 0;
}

//Time complexity: O(n+m)
//Space complexity: O(n)