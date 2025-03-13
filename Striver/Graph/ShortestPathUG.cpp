//Find the shortest path in an undirected graph that has unit weight

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

void BFS(vector<vector<int>>& edges,vector<int>& ans,int source){
    queue<vector<int>> q;
    ans[source]=0;
    q.push({source,0});
    while(!q.empty()){
        int node=q.front()[0],cost=q.front()[1];
        q.pop();    

        for(int i=0;i<edges[node].size();i++){
            if(ans[edges[node][i]]>cost+1){
                ans[edges[node][i]]=cost+1;
                q.push({edges[node][i],cost+1});
            }
        }
    }
}

int main(){
    cout<<"Enter the number of nodes and edges: ";
    int m,n,src;
    string s="Infinity";
    cin>>n>>m;
    vector<vector<int>> edges(n); // 0 indexed

    cout<<"Enter the edges (consider that the first node is 0):\n";

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cout<<"Enter the source of the graph: ";
    cin>>src;

    vector<int> ans(n,INT_MAX);

    BFS(edges,ans,src);

    cout<<"Node\tDistance from source\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t";
        if(ans[i]==INT_MAX)
            cout<<"Infinity"<<endl;
        else
            cout<<ans[i]<<endl;
    }
}

//Time complexity: O(n+2*m)