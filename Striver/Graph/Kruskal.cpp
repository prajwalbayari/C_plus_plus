//Find Minimum spanning tree using kruskal's algorithm

#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        for(int i=0;i<n+1;i++)
            parent.push_back(i);
    }

    int findUltiPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUltiPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu=findUltiPar(u),pv=findUltiPar(v);
        if(pu==pv)
            return;
        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pv]<rank[pu])
            parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

//Using priority queue

int Kruskal(vector<vector<int>> edges,vector<vector<int>>& ans,DisjointSet& ds){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(auto edge:edges)
        pq.push({edge[2],{edge[0],edge[1]}});
    
    int sum=0;
    while(!pq.empty()){
        int cost=pq.top().first,node1=pq.top().second.first,node2=pq.top().second.second;
        pq.pop();
        if(ds.findUltiPar(node1)!=ds.findUltiPar(node2)){
            sum=sum+cost;
            ds.unionByRank(node1,node2);
            ans.push_back({node1,node2,cost});
        }
    }

    return sum;
}

//Method explained by striver

int kruskal(vector<vector<int>> edges,vector<vector<int>>& ans,DisjointSet& ds){

    sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>& b){
        return a[2]<b[2];
    });

    int sum=0;
    for(auto edge:edges){
        int cost=edge[2],node1=edge[0],node2=edge[1];
        if(ds.findUltiPar(node1)!=ds.findUltiPar(node2)){
            sum=sum+cost;
            ds.unionByRank(node1,node2);
            ans.push_back({node1,node2,cost});
        }
    }

    return sum;
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    DisjointSet ds(n);
    vector<vector<int>> edges;
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges.push_back({u,v,cost});
    }
    vector<vector<int>> ans;
    cout<<"The cost of minimum spanning tree is: "<<kruskal(edges,ans,ds)<<endl;

    cout<<"The edges of the minimum spanning tree are:\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i][0]<<"--"<<ans[i][1]<<" (cost = "<<ans[i][2]<<")\n";

    return 0;
}

//Time complexity : O(m*log(m))
//Space complexity : O(n+m)