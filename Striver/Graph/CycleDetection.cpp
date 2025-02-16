//Cycle Detection in undirected graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool cycleBFS(vector<vector<int>> adj,vector<int> vis,int src,int n){
    queue<pair<int,int>> q;
    q.push({src,-1});

    while(!q.empty()){
        int node=q.front().first,par=q.front().second;
        q.pop();
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,src});
            }else if(i!=par)
                return true;
        }
    }
    return false;
}

bool cycleDFS(vector<vector<int>> adj,vector<int>& vis,int src,int par){
    vis[src]=1;
    for(auto i:adj[src]){
        if(!vis[i]){
            if(cycleDFS(adj,vis,i,src))
                return true;
        }else if(i!=par)
            return true;
    }
    return false;
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges: ";
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycleBFS(adj,vis,i,n)){
                cout<<"Cycle detected";
                return 1;
            }
        }
    }

    cout<<"No cycle deteced\n";

    return 0;
}

//BFS => Time complexity: O(n+2*m) Space complexity: O(n)
//DFS => Time complexity: O(n+2*m) Spave complexity: O(n)