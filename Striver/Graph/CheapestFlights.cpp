//Given n cities and m edges that show the flights that connect the cities and their costs
//given src,dest,k return the cheapest price from source to destination with at most k stops
//(a stop means change of flight if you go from a to b then b to c number of stops between a to c is 1)

#include<bits/stdc++.h>
using namespace std;

int flightCost(vector<vector<pair<int,int>>> edges,int src,int dest,int k){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{src,0}});
    
    while(!pq.empty()){
        int cost=pq.top().first,city=pq.top().second.first,hop=pq.top().second.second;
        pq.pop();
        if(city==dest)
            return cost;
        if(hop>k)
            continue;
        for(auto node:edges[city]){
            pq.push({cost+node.second,{node.first,hop+1}});
        }
    }

    return -1;
}

int main(){
    int m,n;
    cout<<"Enter the number of cities and edges: ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> edges(n);
    cout<<"Enter the source destination and cost of the flights:\n";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u].push_back({v,cost});
    }
    
    int src,dest,k;
    cout<<"Enter the source destination and the maximum number of flights that can be taken: ";
    cin>>src>>dest>>k;

    cout<<"The minimum cost to reach destination is: "<<flightCost(edges,src,dest,k)<<endl;
}

//Time comlexity : O(m)