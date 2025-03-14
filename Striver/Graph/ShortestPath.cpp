//Given a graph find the shortest path between given two nodes

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;

void shortestPath(vector<vector<pair<int,int>>>& edges,int start,int goal,vector<int>& ans){
    int n=edges.size();
    vector<int> dist(n,INT_MAX),parent(n,-1);
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int node=pq.top().second,cost=pq.top().first;
        pq.pop();
        if(node==goal)
            break;
        
        for(auto it:edges[node]){
            if(dist[it.first]>cost+it.second){
                dist[it.first]=cost+it.second;
                parent[it.first]=node;
                pq.push({dist[it.first],it.first});
            }
        }
    }

    int temp=goal;

    while(parent[temp]!=-1){
        ans.push_back(parent[temp]);
        temp=parent[temp];
    }
    
    reverse(ans.begin(),ans.end());
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges and their weights: ";
    vector<vector<pair<int,int>>> edges(n+1);
    for(int i=0;i<m;i++){   
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u].push_back({v,cost});
        edges[v].push_back({u,cost});
    }   

    int start,goal;
    cout<<"Enter the start node and goal node: ";
    cin>>start>>goal;

    vector<int> ans;

    shortestPath(edges,start,goal,ans);

    cout<<"The shortest path is: ";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"->";

    cout<<goal<<endl;

    return 0;
}

//Time complexity : O(m*log(n))