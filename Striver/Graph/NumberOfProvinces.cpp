#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

//Adjacency list

void DFSList(vector<vector<int>> adj,vector<int>& vis,int src){
    vis[src]=1;
    for(auto i:adj[src]){
        if(!vis[i])
            DFSList(adj,vis,i);
    }
}

void BFSList(vector<vector<int>> adj,vector<int>& vis,int src){
    queue<int> q;
    q.push(src);
    vis[src]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(vis[i]!=1){
                vis[i]=1;
                q.push(i);
            }
        }
    }
}

//Adjacency matrix

void DFSMatrix(vector<vector<int>> adj,vector<int>& vis,int src){
    vis[src]=1;
    for(int j=0;j<vis.size();j++){
        if(adj[src][j]==1 && !vis[j] && src!=j)
            DFSMatrix(adj,vis,j);
    }
}

void BFSMatrix(vector<vector<int>> adj,vector<int>& vis,int src){
    queue<int> q;
    q.push(src);
    vis[src]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<vis.size();i++){
            if(vis[i]!=1 && adj[node][i] && i!=node){
                vis[i]=1;
                q.push(i);
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;

    // vector<vector<int>> adj(n+1); //Adjacecny list
    vector<vector<int>> adj(n+1,vector<int>(n+1,0)); //Adjacency matrix
    vector<int> vis(n+1,0);
    cout<<"Enter the edges of the graph: ";

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        //For adjacency list
        // adj[u].push_back(v);
        // adj[v].push_back(u);

        //For adjacency matrix
        adj[u][v]=1,adj[v][u]=1;
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            // BFSList(adj,vis,i);
            // DFSList(adj,vis,i);
            BFSMatrix(adj,vis,i);
            // DFSMatrix(adj,vis,i);
        }
    }

    cout<<"The number of provinces is : "<<cnt<<endl;

}

// Space complexity: O(n)+O(n) for Adjacecny list O(n*n) for matrix
// Time complexity: O(n)+O(n+2*m) for Adjacecny list O(n*n) for matrix