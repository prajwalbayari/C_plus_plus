//Find the total number of Strongly connected components in a Directed graph

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFSTiming(vector<vector<int>> edges,stack<int>& st,vector<int>& vis,int src){
    vis[src]=1;
    for(int edge:edges[src]){
        if(!vis[edge])
            DFSTiming(edges,st,vis,edge);
    }
    st.push(src);
}

void DFS(vector<vector<int>> edges,vector<int>& vis,int src){
    vis[src]=1;
    for(int edge:edges[src]){
        if(!vis[edge])
            DFS(edges,vis,edge);
    }
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<vector<int>> edges(n),reversed(n);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        reversed[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n,0);
    DFSTiming(edges,st,vis,0);
    for(int i=0;i<n;i++)
        vis[i]=0;
    int ans=0;

    while(!st.empty()){
        if(!vis[st.top()]){
            ans++;
            DFS(reversed,vis,st.top());
        }
        st.pop();
    }

    cout<<"The number of strongly connected components is: "<<ans<<endl;
}

//Time complexity: O(m+n)