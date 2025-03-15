//Floyd warhsall algorithm (All source shortest path algorithm) works for directed graph
//Find distance each node to every other node

#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& grid){
    int n=grid.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][k]!=INT_MAX && grid[k][j]!=INT_MAX)
                    grid[i][j]=min(grid[i][j],(grid[i][k]+grid[k][j]));
            }
        }
    }
}

int main(){
    int m,n,src;
    cout<<"Enter the number of nodes and edges of a directed graph: ";
    cin>>n>>m;
    vector<vector<int>> edges(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
        edges[i][i]=0;
    
    cout<<"Enter the edges:\n";
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        edges[u][v]=cost;
    }

    floydWarshall(edges);

    cout<<"The cost matrix after calculation of shortest distance:\n";
    for(int i=0;i<n;i++){
        cout<<"Node "<<i<<": ";
        for(int j=0;j<n;j++){
            cout<<((edges[i][j]==INT_MAX)? -1:edges[i][j])<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//Time complexiity : O(n^3)
//Space complexity : O(n^2)