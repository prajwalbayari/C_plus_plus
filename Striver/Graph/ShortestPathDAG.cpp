//Find the shortest path from given source to all the destinations in the graph that 
//is 0 indexed (Use topological sorting) 

//Only works for graph not forest

#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

void ShortestPath(stack<int>& st,vector<int>& cost,vector<vector<pair<int,int>>>& edges,int& src){
    cost[st.top()]=0;
    src=st.top();       //Dynamically setting the source 
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto edge:edges[node]){
            if(cost[node]+edge.second<cost[edge.first])
                cost[edge.first]=cost[node]+edge.second;
        }
    }
}

void BFS(vector<vector<pair<int,int>>>& edges,vector<int>& vis,stack<int>& st,int src){
    vis[src]=1;
    for(auto node:edges[src]){
        if(!vis[node.first])
            BFS(edges,vis,st,node.first);
    }
    st.push(src);
}

int main(){
    int n,m,src=0;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<pair<int,int>>> edges(n);
    cout<<"Enter the edges and their cost:\n";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u].push_back({v,cost});
    }  
    vector<int> vis(n,0);
    stack<int> st; 
    for(int i=0;i<n;i++){
        if(vis[i]==0)
            BFS(edges,vis,st,i);
    }

    vector<int> cost(n,INT_MAX);
    ShortestPath(st,cost,edges,src);

    cout<<"Shortest path between nodes:\n";
    for(int i=0;i<n;i++){
        if(cost[i]!=INT_MAX)
            cout<<src<<"->"<<i<<" = "<<cost[i]<<endl;
        else 
            cout<<src<<"->"<<i<<" = Infinity"<<endl;
    }

    return 0;
}

//Time complexity: O(m+n)
//Space complexity: O(n)