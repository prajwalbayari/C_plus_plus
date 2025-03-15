//Find the minimum spanning tree of a graph using prims algorithm

#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int,int>>> edges,vector<vector<int>>& ans){
    int n=edges.size(),sum=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<int> vis(n,0);
    pq.push({0,{0,-1}});
    while(!pq.empty()){
        int cost=pq.top().first,node=pq.top().second.first,par=pq.top().second.second;
        pq.pop();
        if(vis[node])
            continue;
        sum=sum+cost,vis[node]=1;

        if(par!=-1)
            ans.push_back({par,node});
        for(auto edge:edges[node]){
            if(!vis[edge.first])
                pq.push({edge.second,{edge.first,node}});
        }
    }

    return sum;
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    vector<vector<pair<int,int>>> edges(n);
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u].push_back({v,cost});
        edges[v].push_back({u,cost});
    }

    vector<vector<int>> ans;
    cout<<"The sum of edges of Minimum spanning tree: "<<prims(edges,ans)<<endl;

    cout<<"The edges included in Minimum Spanning Tree are:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<"--"<<ans[i][1]<<endl;
    }
}

//Time comlexity : O(m*log(m))