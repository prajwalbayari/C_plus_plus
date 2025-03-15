//Given a grid of size rows X cols you have to go from top left(0,0) to bottom right(row-1,col-1)
//with minimum cost possible each cell represents the cost to come to that cell from adjacent cell

// #include<iostream>
// #include<vector>
// #include<queue>
#include<bits/stdc++.h>
using namespace std;

int dijkstras(vector<vector<int>> grid){
    int m=grid.size(),n=grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    dist[0][0]=0;

    int rdir[]={0,1,0,-1},cdir[]={1,0,-1,0};

    while(!pq.empty()){
        int cost=pq.top().first,row=pq.top().second.first,col=pq.top().second.second;
        pq.pop();
        if(row==m-1 && col==n-1)
            return cost;

        for(int i=0;i<4;i++){
            int nr=row+rdir[i],nc=col+cdir[i];
            if(nr<m && nr>=0 && nc<n && nc>=0){
                int ncost=max(cost,abs(grid[nr][nc]-grid[row][col]));

                if(ncost<dist[nr][nc]){
                    dist[nr][nc]=ncost;
                    pq.push({ncost,{nr,nc}});
                }
            }
        }
    }

    return -1;
}

int main(){
    int m,n;
    cout<<"Enter the order of the grid: ";
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    cout<<"Enter the grid\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    cout<<"The minimum cost to reach destination from source is: "<<dijkstras(grid);
}

//Time complexity : O(n*m*4*log(n*m))
//Space complexity: O(n*m)