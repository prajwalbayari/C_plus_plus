//Topological sort only applcable for DAG

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(vector<vector<int>>& edges,vector<int>& vis,stack<int>& st,int src){
    vis[src]=1;
    for(auto node:edges[src]){
        if(!vis[node])
            DFS(edges,vis,st,node);
    }
    st.push(src);
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges: ";
    vector<vector<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
    }
    vector<int> vis(n+1,0);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i])
            DFS(edges,vis,st,i);
    }

    cout<<"Topological sorting order is: ";

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}

//Time complexity: O(n+m)
//Space complexity: O(n)