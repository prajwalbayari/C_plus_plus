//Given a graph with its cost matrix with respect to time find the total number of paths 
//from source to destination that takes minimum time 

#include<bits/stdc++.h>
using namespace std;

int MinPath(vector<vector<pair<int,int>>> edges){
    int n=edges.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,INT_MAX),ways(n,0);
    dist[0]=0,ways[0]=1;
    pq.push({0,0});
    while(!pq.empty()){
        int cost=pq.top().first,node=pq.top().second;
        pq.pop();
        for(auto edge:edges[node]){
            int ncost=cost+edge.second;
            if(ncost<dist[edge.first]){
                dist[edge.first]=ncost;
                ways[edge.first]=ways[node];
                pq.push({ncost,edge.first});
            }else if(ncost==dist[edge.first]){
                ways[edge.first]+=ways[node];
            }
        }
    }

    return (dist[n-1]==INT_MAX)? -1:ways[n-1];
}

int main(){
    cout<<"Enter the number of nodes and edges: ";
    int m,n;
    cin>>n>>m;
    vector<vector<pair<int,int>>> edges(n);

    cout<<"Enter the edges and their cost\n";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u].push_back({v,cost});
        edges[v].push_back({u,cost});
    }

    cout<<"The number of paths from source to destination with minimum cost is: "<<MinPath(edges);
}

//Time comlexity : O(m*log(n)) 