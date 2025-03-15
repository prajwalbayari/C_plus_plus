//Bellman ford algorithm (works for graph with negative edges and detects negative cycle)
//Works only for directed graph if a undirected graph is given then first convert it to 
//Directed graph

#include<bits/stdc++.h>
using namespace std;

int bellmanFord(vector<vector<int>> edges,int src,vector<int>& dist){
    int n=edges.size();
    dist[src]=0;

    for(int k=0;k<n-1;k++){
        for(auto edge:edges){
            int u=edge[0],v=edge[1],cost=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+cost<dist[v])
                dist[v]=dist[u]+cost;
        }
    }

    for(auto edge:edges){
        int u=edge[0],v=edge[1],cost=edge[2];
        if(dist[u]!=INT_MAX && dist[u]+cost<dist[v])
            return 1;
    }
    return 0;
}

int main(){
    int m,n,src;
    cout<<"Enter the number of nodes and edges of a directed graph: ";
    cin>>n>>m;
    vector<vector<int>> edges;
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges.push_back({u,v,cost});
    }
    vector<int> dist(n,INT_MAX);

    cout<<"Enter the source node: ";
    cin>>src;

    if(bellmanFord(edges,src,dist)){
        cout<<"Negative cycle detected\n";
        return 1;
    }

    cout<<"The minimum distnce from source to all nodes:\n";
    for(int i=0;i<n;i++){
        cout<<src<<" -> "<<i<<" = ";
        if(dist[i]==INT_MAX)
            cout<<"Infinity\n";
        else
            cout<<dist[i]<<endl;
    }

    return 0;
}

// Time complexity :O(m*n)