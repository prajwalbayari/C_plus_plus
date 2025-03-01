//Cycle detection in an Directed graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Using BFS

bool BFS(vector<vector<int>>& edges,vector<int>& vis,int src){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int n=q.front();
        q.pop();
        if(vis[n])
            return true;
        vis[n]=1;
        for(int i=0;i<edges[n].size();i++)
            q.push(edges[n][i]);
    }
    return false;
}

//Using DFS

bool DFS(vector<vector<int>>& edges,vector<int>& vis,int src){
    vis[src]=1;
    for(int i=0;i<edges[src].size();i++){
        if(vis[edges[src][i]] || DFS(edges,vis,edges[src][i]))
            return true;
    }
    return false;
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
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i] && DFS(edges,vis,i)){
            cout<<"There is a cycle present\n";
            return 0;
        }
    }

    cout<<"There is no cycle present\n";
    return 0;
}

//Time complexity: O(n+m)
//Space complexity: O(n)