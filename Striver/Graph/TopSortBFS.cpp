//Kahn's algorithm

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printSolution(vector<int> ans){
    cout<<"The order of topological sort: ";
    for(int node:ans)
        cout<<node<<" ";
    cout<<endl;
}

void BFS(vector<vector<int>>& edges){
    int n=edges.size();
    vector<int> indeg(n,0);
    for(int i=1;i<n;i++){
        for(int j=0;j<edges[i].size();j++)
            indeg[edges[i][j]]++;
    }
    queue<int> q;
    for(int i=1;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int child:edges[node]){
            indeg[child]--;
            if(indeg[child]==0)
                q.push(child);
        }
    }

    printSolution(ans);
}

int main(){
    int m,n;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    vector<vector<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
    }

    BFS(edges);
}

//Time complexity = O(n+m)