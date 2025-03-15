//Find the city with smallest number of neighbours at a threshold distance
//Find the city from whom minimum number of cities can be traversed if the cost is restricted 
//to threshold in case of multiple such nodes are found return the node with maximum value

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
    int m,n,threshold;
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
        edges[v][u]=cost;
    }
    cout<<"Enter the threshold: ";
    cin>>threshold;

    floydWarshall(edges);

    int cur=1e9,node=-1;

    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            if(edges[i][j]<=threshold)
                temp++;
        }
        if(cur>=temp)
            cur=temp,node=i;
    }    

    cout<<"The city with minimum reachable neighbours with the threshold is: "<<node<<endl;
    return 0;
}

//Time complexity : O(n^3) 