//Given a directed graph find the list of nodes that will eventually enter the safe mode
//A node is safe if it reaches a terminal node

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//Using DFS

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

//Using BFS
//1)Reverse all the edges and perform Toposort

void BFS(vector<vector<int>>& edges,vector<int>& ans){
    int n=edges.size();
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++){
        for(int node:edges[i])
            indeg[node]++;
    }
    queue<int> q;
    for(int i=1;i<n;i++){
        if(indeg[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int child:edges[node]){
            indeg[child]--;
            if(indeg[child]==0)
                q.push(child);
        }
    }
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
        // edges[u].push_back(v); //For DFS
        edges[v].push_back(u); //For BFS reversing the nodes
    }

    //For DFS

    // vector<int> vis(n+1,0),path(n+1,0);
    // for(int i=1;i<=n;i++){
    //     if(vis[i]==0)
    //         DFS(edges,vis,i,path);
    // }

    // cout<<"The safe nodes are: ";

    // for(int i=1;i<=n;i++){
    //     if(vis[i]==2)
    //         cout<<i<<" ";
    // }
    // cout<<endl;

    //For BFS

    vector<int> ans;
    BFS(edges,ans);
    sort(ans.begin(),ans.end());
    cout<<"The eventual safe nodes are: ";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

//DFS
//Space complexity: O(n)
//Time complexity: O(n)

//BFS
//Space complexity: O(n*m) for storing the reversed edges
//Time complexity : O(n+m+n(logn)) For sorting and Topological sort