//A edge is called a brdge if it's removal will break the graph into 2 components
//Find the total number of bridges in a undirected graph

#include<iostream>
#include<vector>
using namespace std;

int timer=0;

void DFS(int src,int parent,vector<vector<int>>& edges,vector<int>& time,vector<int>& low,vector<int>& vis,vector<vector<int>>& bridges){
    vis[src]=1;
    time[src]=low[src]=timer;
    timer++;
    for(auto edge:edges[src]){
        if(edge!=parent){
            if(vis[edge]==0){
                DFS(edge,src,edges,time,low,vis,bridges);
                low[src]=min(low[src],low[edge]);
                if(low[edge]>low[src])
                    bridges.push_back({edge,src});
            }else
                low[src]=min(low[src],low[edge]);
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges: ";
    vector<vector<int>> edges(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> time(n),low(n),vis(n,0);
    vector<vector<int>> bridges;
    DFS(0,-1,edges,time,low,vis,bridges);

    cout<<"The bridges are:\n";
    for(auto edge:bridges)
        cout<<edge[0]<<"---"<<edge[1]<<endl;

    return 0;
}

//Time complexity : O(n+2*m)