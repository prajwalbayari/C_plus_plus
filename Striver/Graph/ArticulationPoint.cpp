//A node in a graph is called articulation point if it's removal will cause the graph to break
//into multiple components

#include<iostream>
#include<vector>
using namespace std;

int timer=0;

void DFS(int src,int parent,vector<vector<int>>& edges,vector<int>& vis,vector<int>& time,vector<int>& low,vector<int>& ans){
    vis[src]=1;
    time[src]=low[src]=timer;
    timer++;
    int child=0;
    for(int node:edges[src]){
        if(node!=parent){
            if(vis[node]==0){
                DFS(node,src,edges,vis,time,low,ans);
                low[src]=min(low[src],low[node]);
                if(low[node]>=time[src] && parent!=-1)
                    ans[src]=1;
                child++;
            }else{
                low[src]=min(low[src],time[node]);
            }
        }
    }
    if(child>1 && parent==-1)   
        ans[src]=1; 
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> edges(n);
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> vis(n,0),time(n),low(n),ans(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i])
            DFS(i,-1,edges,vis,time,low,ans);
    }

    cout<<"The articulation points in the graph are: ";
    for(int i=0;i<n;i++){
        if(ans[i]==1)
            cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}

//Time complexity: O(n+2*m)